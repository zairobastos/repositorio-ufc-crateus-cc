package pratica2;

import java.util.Random;

public class MyRunnable implements Runnable {
	
	 int i,j,y;
	 int vetor[] = new int[1000];
	 
	 	Random gerador = new Random();
	 
	    public MyRunnable(int i) {
	        this.i = i;
	        
	    }
	 
	    @Override
	    public void run() {
	    	if(i == 0) {
	    		for(j = 0;j<=99;j++) {
	    			vetor[j] = gerador.nextInt(1000);
	    			System.out.println(j+"-"+vetor[j]);
	    		}
	    	}
	    	if(i == 1) {
		    	for(j = 100;j<=199;j++) {
		    		vetor[j] = gerador.nextInt(1000);
		    		System.out.println(j+"-"+vetor[j]);
		    	}
		    }
	    	if(i == 2) {
		    	for(j = 200;j<=299;j++) {
		    		vetor[j] = gerador.nextInt(1000);
		    		System.out.println(j+"-"+vetor[j]);
		    	}
		    }
	    	if(i == 3) {
		    	for(j = 300;j<=399;j++) {
		    		vetor[j] = gerador.nextInt(1000);
		    		System.out.println(j+"-"+vetor[j]);
		    	}
		    }
	    	if(i == 4) {
		    	for(j = 400;j<=499;j++) {
		    		vetor[j] = gerador.nextInt(1000);
		    		System.out.println(j+"-"+vetor[j]);
		    	}
		    }
	    	if(i == 5) {
		    	for(j = 500;j<=599;j++) {
		    		vetor[j] = gerador.nextInt(1000);
		    		System.out.println(j+"-"+vetor[j]);
		    	}
		    }
	    	if(i == 6) {
		    	for(j = 600;j<699;j++) {
		    		vetor[j] = gerador.nextInt(1000);
		    		System.out.println(j+"-"+vetor[j]);
		    	}
		    }
	    	if(i == 7) {
		    	for(j = 700;j<=799;j++) {
		    		vetor[j] = gerador.nextInt(1000);
		    		System.out.println(j+"-"+vetor[j]);
		    	}
		    }
	    	if(i == 8) {
		    	for(j = 800;j<=899;j++) {
		    		vetor[j] = gerador.nextInt(1000);
		    		System.out.println(j+"-"+vetor[j]);
		    	}
		    }
	    	if(i == 9) {
		    	for(j = 900;j<=999;j++) {
		    		vetor[j] = gerador.nextInt(1000);
		    		System.out.println(j+"-"+vetor[j]);
		    	}
	    	}
	    	
	    }
}
