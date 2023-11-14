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
public class DVD extends Item{
    
    private String diretor;
    
    public DVD(String titulo,String diretor, int duracao) {
        super(titulo, duracao);
        this.diretor = diretor;
    }
    
    public String getDiretor(){
        return diretor;
    }
    
}
