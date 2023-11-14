package pratica2;

public class Main {

	 public static void main(String[] args) {        
	        Thread t1 = new Thread(new MyRunnable(0));
	        t1.start();
	        Thread t2 = new Thread(new MyRunnable(1));
	        t2.start();
	        Thread t3 = new Thread(new MyRunnable(2));
	        t3.start();
	        Thread t4 = new Thread(new MyRunnable(3));
	        t4.start();
	        Thread t5 = new Thread(new MyRunnable(4));
	        t5.start();
	        Thread t6 = new Thread(new MyRunnable(5));
	        t6.start();
	        Thread t7 = new Thread(new MyRunnable(6));
	        t7.start();
	        Thread t8 = new Thread(new MyRunnable(7));
	        t8.start();
	        Thread t9 = new Thread(new MyRunnable(8));
	        t9.start();
	        Thread t10 = new Thread(new MyRunnable(9));
	        t10.start();
	        
	 }
}
