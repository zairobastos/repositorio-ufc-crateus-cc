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
public class Item {
    private String titulo;
    private int duracao;
    private boolean tenho;
    private String comentario;
    
   public Item(String titulo,int duracao){
       this.titulo = titulo;
       this.duracao = duracao;
       tenho = false;
       comentario = "";
   }
   
   public void setComentario(String comentario){
       this.comentario = comentario;
   }
   
   public String getComentario(){
       return comentario;
   }
   
   public void setTenho(boolean tenho){
       this.tenho = tenho; 
   }
   
   public boolean getTenho(){
       return tenho;
   }
   
   public void print(){
       System.out.println("Título" + titulo + " (" + duracao + "min)");
       if(tenho){
           System.out.println("*");
       }
       else{
           System.out.println();
       }
       System.out.println("  " + comentario);
   }
}
