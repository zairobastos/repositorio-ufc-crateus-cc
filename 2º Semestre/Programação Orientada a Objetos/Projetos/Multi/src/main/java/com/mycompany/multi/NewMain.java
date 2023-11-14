/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.multi;
import classes.DataBase;
import classes.CD;
import classes.DVD;
/**
 *
 * @author rayla
 */
public class NewMain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        DVD item1 = new DVD("Snow","Stivem",180);
        item1.getComentario("Primeiro dvd");
        DVD item2 = new DVD("Dek","Lwan",50);
        
        DataBase estante = new DataBase();
        
        
    }
    
}
