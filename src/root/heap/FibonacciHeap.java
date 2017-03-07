package root.heap;

/**
 * Mont�culo de Fibonacci de m�nimos para contener enteros
 */
public class FibonacciHeap {

	public FibonacciHeap() {
		min = null;
		num = 0;
	}
	/**
	 * Inserta un nuevo elemento
	 * @param key Clave del elemento
	 */
	public void insert(int key) {
		Node node = new Node(key);
		if (this.min == null)
			this.min = node;
		else {
			node.concatenate(min);
			if(key < this.min.key)
				this.min = node;
		}
		this.num++;
	}
	/**
	 * Une ambos mont�culos, devolviendo el mont�culo uni�n
	 * a trav�s del par�metro implicito.
	 * @param other Segundo mont�culo a unir. Ser� destruido en el proceso
	 */
	public void union(FibonacciHeap other) {
		if (this.min == null)
			this.min = other.min;
		else if (other.min != null) {
			this.min.concatenate(other.min);
			if (this.min == null || (other.min != null && other.min.key < this.min.key))
				this.min = other.min;
		}
		this.num += other.num;
		other = null;
	}
	
	public int minimum() {
		if (min != null)
			return min.key;
		else
			return 0;
	}
	/**
	 * Devuelve el m�nimmo del mont�culo, elimin�ndolo de �ste.
	 * Si el mint�culo est� vac�o, devuelve 0
	 */
	public int extractMin() {
		int key = 0;
		if (this.min != null) {
			key = this.min.key;
			
			//A�adir hijos a la lista de raices
			int degree = this.min.degree;
			if (this.min.child != null) { 
				Node aux = this.min.child;
				Node sig = aux.right;
				for(int i=0; i<degree; i++) {
					aux.extract();
					aux.concatenate(min);
				//	this.paint();
					aux = sig;
					sig = sig.right;
				}
			}
			//Extraer y consolidar
			if (this.num == 1)
				this.min = null;
			else {
				Node minRight = this.min.right;
				this.min.extract();
				this.min = minRight;
				consolidate();
			}
			this.num--;	
		}
		return key;
	}
	
	private void consolidate() {
		// Creaci�n del array de grados
		int rootDegree = this.min.countSiblings();
		Node[] degreeArray = new Node[this.num];
		
		//Fusion para asegurar la no repeticion de grados
		Node node = this.min; //Nodo cualquiera de la lista de raices
		Node nodeD;			//Nodo del mismo grado que el anterior
		for (int i=0; i < rootDegree; i++) {
			nodeD = degreeArray[node.degree];
			while (nodeD != null && node != nodeD) {
				degreeArray[node.degree] = null;
				if (node.key > nodeD.key) {
					Node aux = node;
					node = nodeD;
					nodeD = aux;
				}
				nodeD.extract();
				node.addChild(nodeD);
				if (this.min.parent != null)
					this.min = this.min.parent;
				nodeD = degreeArray[node.degree];
			//	this.paint();
			}
			degreeArray[node.degree] = node;
			node = node.right;
		}
		
		//Elecci�n de m�nimo
		rootDegree = this.min.countSiblings();
		node = this.min.right;
		for (int i=1; i < rootDegree; i++) {
			if (node.key < this.min.key)
				this.min = node;
			node = node.right;
		}
	}
	
	public boolean isEmpty() {
		return (this.num == 0);
	}
	
	public void paint() {
		System.out.println("(heap)");
		int degree = 0;
		if (this.min != null)
			degree = this.min.countSiblings();
		Node node = this.min;
		for (int i=0; i < degree; i++) {
			node.paint(1);
			node = node.right;
		}
		
	}
	
	private Node min;
	private int num;
	
	private static class Node {
		/**
		 * Crea una lista de un nodo
		 * @param key Clave del nodo
		 */
		public Node(int key) {
			this.key = key;
			
			this.degree = 0;
			this.marked = false;
			
			this.parent = null;
			this.child = null;
			
			this.left = this;
			this.right = this;
		}
		/**
		 * Concatena la lista actual con otra
		 * @param other La otra lista
		 */
		public void concatenate(Node other) {
			Node thisLeft = this.left;
			this.left.right = other;
			this.left = other.left;
			other.left.right = this;
			other.left = thisLeft;
		}
		/**
		 * A�ade al par�metro como hijo del nodo actual
		 * @param child Nuevo hijo
		 */
		public void addChild(Node child) {
			if (this.child == null)
				this.child = child;
			else
				this.child.concatenate(child);
			
			child.parent = this;
			this.degree++;
		}
		/**
		 * Extrae un nodo de la lista de hermanos, convirti�ndolo en una lista unitaria.
		 *  Si tiene padre, asegura que tenga a nulo u otro hermano como hijo, y le reduzco el grado.
		 *  No modifica a sus hijos.
		 */
		public void extract() {
			if (this.left == this && this.parent != null) {
				this.parent.child = null;
				this.parent.degree--;
				this.parent = null;
			}
			else {
				if (this.parent != null) {
					this.parent.child = this.left;
					this.parent.degree--;
					this.parent = null;
				}
				this.left.right = this.right;
				this.right.left = this.left;
			}
			this.left = this;
			this.right = this;
		}
		/**
		 * Corta el nodo a�adiendolo a la lista de ra�ces. Si el padre no estaba marcado, lo marca.
		 * Si lo estaba, se corta al apdre tambi�n, repitiendo el proceso recursivamente.
		 * @param root Lista de ra�ces
		 */
		public void cut(Node root) {
			Node parent = this.parent;
			this.extract();
			
			this.parent = null;
			this.marked = false;
			this.concatenate(root); //A�adir a la lista de raices
			
			if(parent.parent != null) { //Si el padre no es raiz...
				if (parent.marked)	//... y estaba marcado...
					parent.cut(root); //... es el segundo hijo que pierde, as� que se corta...
				else						
					parent.marked = true; //... Si no, se marca
			}
		}
		/**
		 * Cuenta el n�mero de nodos de la lista de hermanos. Se cuenta tambi�n el nodo
		 * del par�metro impl�cito
		 * @return N�mero de nodos de la lista
		 */
		public int countSiblings() {
			Node aux = this.right;
			int num = 1;
			while (aux != this) {
				aux = aux.right;
				num++;
			}
			return num;
		}
		
		public void paint(int depth) {
			for (int i=0; i < depth; i++)
				System.out.print("  |");
			
			System.out.println("--" + this.key);
			Node node = this.child;
			for (int i=0; i < this.degree; i++) {
				node.paint(depth+1);
				node = node.right;
			}

		}

		private int key;
		private int degree;
		private boolean marked;
		private Node parent;
		private Node child;
		private Node left;
		private Node right;
	}
}
