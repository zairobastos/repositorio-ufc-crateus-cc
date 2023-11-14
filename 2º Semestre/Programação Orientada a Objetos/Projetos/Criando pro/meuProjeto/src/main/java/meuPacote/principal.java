/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package meuPacote;

import java.util.Scanner;

/**
 *
 * @author rayla
 */
public class principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int varInteira;
        float varFloat;
        String palavra;
        boolean status;
        
        Scanner leitor = new Scanner(System.in);
        System.out.println("Digite um número inteiro:");
        varInteira = leitor.nextInt();
        System.out.println("Digite um número float:");
        varFloat = leitor.nextFloat();
        leitor.nextLine();
        System.out.println("Digite uma String:");
        palavra = leitor.nextLine();
       
        System.out.println("O valor inserido: "+ varInteira);
        System.out.println("O valor inserido: "+ varFloat);
        System.out.println("O valor inserido: "+ palavra);
    }
    
}
