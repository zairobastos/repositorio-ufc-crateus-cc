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
public class CD extends Item{
    
    private String artista;
    private int numeroDeFaixas;
    
    public CD(String artista,int numeroDeFaixas,String titulo, int duracao) {
        super(titulo, duracao);
        this.artista = artista;
        this.numeroDeFaixas = numeroDeFaixas;
    }
    
    public String getArtista(){
        return artista;
    }
    
    public int getNumeroDeFaixas(){
        return numeroDeFaixas;
    }    
}

