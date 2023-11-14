/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.maquinadebilhete;

import java.util.Scanner;

/**
 *
 * @author rayla
 */
public class maquinaDeBilhete {

        private int preco,saldo,total,aux1,aux2;
        boolean a;

        public maquinaDeBilhete(int custoBilhete){
          
            preco = custoBilhete;
            saldo = 0;
            total = 0;
        }
        
        public int getPreco(){
            return preco;
        }
        
        public int getSaldo(){
            return saldo;
        }
        
        public void inserirValores(int quantia){
            saldo += quantia;
        }
        
        public void imprimeBilhete(){
            System.out.println("#      Bilhete       #");
            System.out.println("#"+preco+" reais");
            
            total += saldo;
            saldo = 0;
        }
        
        public void main(){
        Scanner leitor = new Scanner(System.in);
            
            System.out.println("Digite o valor do bilhete:");
            aux1 = leitor.nextInt();
            
            do{
              System.out.println("Insira a quantida em reais:"); 
              aux2 = leitor.nextInt();
              
              inserirValores(aux2);
              
              System.out.println("Insira true para digita:"); 
              a = leitor.nextInt();
            }while(a = false);
        }
    }
    
