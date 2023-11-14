/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package classes;

/**
 *
 * @author rayla
 */
public class MostradorNumero {
    private int limite;
    private int valor;
    
    public MostradorNumero(int numero){
    this.limite = numero;
    this.valor = 0;
    }
    
    public int getValor(){
        return this.valor;
    }
    
    public void setValor(int valor){
        if((valor>= 0) && (valor <=limite) ){
            this.valor = valor;
        }
    }
    
    public String getMostraValor(){
        if(this.valor < 10){
            return "0" + this.valor;
        }
        else{
            return "" + this.valor;
        }
    }
    
    public void incrementar(){
        valor = (valor + 1)%limite;
    }
}
