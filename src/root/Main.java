package root;

import java.util.Random;
import java.util.Vector;

import root.heap.FibonacciHeap;
import root.heap.SkewHeap;

public class Main {

	public static void main(String[] args) {
		testBSkew(2000, 5000);
	}
	
	public static void testA(int numPrevio) {
		FibonacciHeap fib = new FibonacciHeap();
		SkewHeap skew = new SkewHeap();
		Random rand = new Random(System.currentTimeMillis());
		int num;
		long beg, end;
		
		//Insercion fibonacci (previa)
		beg = System.currentTimeMillis();
		for (int i=0; i<numPrevio; i++) {
			num = rand.nextInt();
			fib.insert(num);
		}
		end = System.currentTimeMillis();
	//	System.out.print("" + (end-beg));
		
		//insercion Skew (previa)
		beg = System.currentTimeMillis();
		for (int i=0; i<numPrevio; i++) {
			num = rand.nextInt();
			skew.insert(num);
		}
		end = System.currentTimeMillis();
	//	System.out.print("	" + (end-beg));
		
		System.out.println("50.000 inserciones Fib	50.000 inserciones Skew	50.000 minimos Fib	50.000 minimos Skew");
		for (int k=0; k<50; k++) {
			//Insercion fibonacci
			beg = System.currentTimeMillis();
			for (int i=0; i<50000; i++) {
				num = rand.nextInt();
				fib.insert(num);
			}
			end = System.currentTimeMillis();
			System.out.print("" + (end-beg));
			
			//insercion Skew
			beg = System.currentTimeMillis();
			for (int i=0; i<50000; i++) {
				num = rand.nextInt();
				skew.insert(num);
			}
			end = System.currentTimeMillis();
			System.out.print("	" + (end-beg));
			
			//minimo Fibonacci
			beg = System.currentTimeMillis();
			for (int i=0; i<50000; i++) {
				num = fib.extractMin();
			}
			end = System.currentTimeMillis();
			System.out.print("	" + (end-beg));
			
			//minimo Fibonacci
			beg = System.currentTimeMillis();
			for (int i=0; i<50000; i++) {
				num = skew.extractMin();
			}
			end = System.currentTimeMillis();
			System.out.println("	" + (end-beg));
		}
		
	}
	public static void testBFib(int numMonticulos, int numElemPorMonticulo) {
		Vector<FibonacciHeap> fibV = new Vector<FibonacciHeap>();
		FibonacciHeap fib;
		Random rand = new Random(System.currentTimeMillis());
		int num;
		long beg, end;
		
		System.out.println("" + numElemPorMonticulo + "inserciones * " + numMonticulos + " fib	" + numMonticulos + " uniones Fib (" + numElemPorMonticulo + " elem)");
		for (int k=0; k<50; k++) {
			//Insercion fibonacci
			beg = System.currentTimeMillis();
			for (int l=0; l<numMonticulos; l++) {
				fib = new FibonacciHeap();
				for (int i=0; i<numElemPorMonticulo; i++) {
					num = rand.nextInt();
					fib.insert(num);
				}
				fibV.add(fib);
			}
			end = System.currentTimeMillis();
			System.out.print("" + (end-beg));
		
			//Union Fibonacci
			beg = System.currentTimeMillis();
			for(int l=numMonticulos-2; l>=0; l--) {
				fibV.get(l).union(fibV.get(l+1));
			}
			end = System.currentTimeMillis();
			System.out.println("	" + (end-beg));
		
			fibV = new Vector<FibonacciHeap>();
		}
	}
	
	public static void testBSkew(int numMonticulos, int numElemPorMonticulo) {
		Vector<SkewHeap> skewV = new Vector<SkewHeap>();
		SkewHeap skew;
		Random rand = new Random(System.currentTimeMillis());
		int num;
		long beg, end;
		
		System.out.println("" + numElemPorMonticulo + "inserciones * " + numMonticulos + " Skew	" + numMonticulos + " uniones Skew (" + numElemPorMonticulo + " elem)");
		for (int k=0; k<50; k++) {
			//Insercion Skew
			beg = System.currentTimeMillis();
			for (int l=0; l<numMonticulos; l++) {
				skew = new SkewHeap();
				for (int i=0; i<numElemPorMonticulo; i++) {
					num = rand.nextInt();
					skew.insert(num);
				}
				skewV.add(skew);
			}
			end = System.currentTimeMillis();
			System.out.print("" + (end-beg));

			//Union Skew
			beg = System.currentTimeMillis();
			for(int l=numMonticulos-2; l>=0; l--) {
				skewV.get(l).union(skewV.get(l+1));
			}
			end = System.currentTimeMillis();
			System.out.println("	" + (end-beg));

			skewV = new Vector<SkewHeap>();
		}
	}
	
	public static void testCfib() {
		FibonacciHeap fib = new FibonacciHeap();
		//SkewHeap skew = new SkewHeap();
		Random rand = new Random(System.currentTimeMillis());
		int num;
		long beg, end;
		System.out.println("inserciones Fib					minimos Fib	");
		System.out.println("0to50	50to100	100to150	150to200	200to250	250to200	200to150	150to100	100to50	50to0");
		for (int k=0; k<50; k++) {
			//Insercion fibonacci 0
			beg = System.currentTimeMillis();
			for (int i=0; i<50000; i++) {
				num = rand.nextInt();
				fib.insert(num);
			}
			end = System.currentTimeMillis();
			System.out.print("" + (end-beg));
			
			//Insercion fibonacci 1-4
			for(int a=1; a<5;a++) {
				beg = System.currentTimeMillis();
				for (int i=0; i<50000; i++) {
					num = rand.nextInt();
					fib.insert(num);
				}
				end = System.currentTimeMillis();
				System.out.print("	" + (end-beg));
			}
			
			//minimo Fibonacci 0-4
			for(int a=1; a<5;a++) {
				beg = System.currentTimeMillis();
				for (int i=0; i<50000; i++) {
					num = fib.extractMin();
				}
				end = System.currentTimeMillis();
				System.out.print("	" + (end-beg));
			}
			
			//minimo Fibonacci 5
			beg = System.currentTimeMillis();
			for (int i=0; i<50000; i++) {
				num = fib.extractMin();
			}
			end = System.currentTimeMillis();
			System.out.println("	" + (end-beg));
		}
	}
	
	public static void testCskew() {
		//FibonacciHeap fib = new FibonacciHeap();
		SkewHeap skew = new SkewHeap();
		Random rand = new Random(System.currentTimeMillis());
		int num;
		long beg, end;
		System.out.println("inserciones Skew					minimos Skew");
		System.out.println("0to50	50to100	100to150	150to200	200to250	250to200	200to150	150to100	100to50	50to0");
		for (int k=0; k<50; k++) {
			//Insercion fibonacci 0
			beg = System.currentTimeMillis();
			for (int i=0; i<50000; i++) {
				num = rand.nextInt();
				skew.insert(num);
			}
			end = System.currentTimeMillis();
			System.out.print("" + (end-beg));
			
			//Insercion fibonacci 1-4
			for(int a=1; a<5;a++) {
				beg = System.currentTimeMillis();
				for (int i=0; i<50000; i++) {
					num = rand.nextInt();
					skew.insert(num);
				}
				end = System.currentTimeMillis();
				System.out.print("	" + (end-beg));
			}
			
			//minimo Fibonacci 0-4
			for(int a=1; a<5;a++) {
				beg = System.currentTimeMillis();
				for (int i=0; i<50000; i++) {
					num = skew.extractMin();
				}
				end = System.currentTimeMillis();
				System.out.print("	" + (end-beg));
			}
			
			//minimo Fibonacci 5
			beg = System.currentTimeMillis();
			for (int i=0; i<50000; i++) {
				num = skew.extractMin();
			}
			end = System.currentTimeMillis();
			System.out.println("	" + (end-beg));
		}
	}

}
