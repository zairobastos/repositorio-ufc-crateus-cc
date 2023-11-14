/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package classes;
import java.util.ArrayList;
/**
 *
 * @author rayla
 */
public class DataBase {
    
    private ArrayList<Item> itens;
    
    public DataBase(){
        itens = new ArrayList<Item>();
    }
    
    public void add(Item item){
        itens.add(item);
    }
    
    public void lista(){
        for(Item item:itens){
            item.print();
            System.out.println();
        }
    }
}
