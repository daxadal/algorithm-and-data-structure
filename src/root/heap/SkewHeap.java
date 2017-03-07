package root.heap;

public class SkewHeap {
	
	public SkewHeap() {
		this.root = null;
	}
	
	public void insert(int key) {
		Node node = new Node(key);
		this.root = Node.union(this.root, node);
	}
	
	public void union(SkewHeap other) {
		this.root = Node.union(this.root, other.root);
	}
	
	public int minimum() {
		return this.root.key;
	}
	
	public int extractMin() {
		int key = 0;
		if (this.root != null) {
			key = this.root.key;
			this.root = Node.union(this.root.left, this.root.right);
		}
		return key;
	}
	
	private Node root;
	
	private static class Node {
		
		public Node(int key) {
			this.key = key;
			this.left = null;
			this.right = null;
		}
		
		private Node(Node left, int key, Node right) {
			this.key = key;
			this.left = left;
			this.right = right;
		}
		
		public static Node union(Node one, Node other) {
			Node united;
			if (one == null)
				united =  other;
			else if (other == null)
				united = one;
			else {
				if (one.key < other.key)
					united = new Node(union(one.right, other), one.key, one.left);
				else
					united = new Node(union(other.right, one), other.key, other.left);
			}
			return united;
		}
		
		private int key;
		private Node left;
		private Node right;
	}
}
