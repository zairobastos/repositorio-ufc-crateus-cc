/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lexico;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 *
 * @author rayla
 */
public class IsiScaner {
    private char[] content;
    private int estado, posicao=0;
    
    public IsiScaner (String filename){
        try {
             String txtConteudo;
             txtConteudo = new String(Files.readAllBytes(Paths.get(filename)),StandardCharsets.UTF_8);
             System.out.println("DEBUG -----------");
             System.out.println(txtConteudo);
             System.out.println("-----------");
             content = txtConteudo.toCharArray();                
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public Token nextoken(){
        char currentChar;
        if(isEOF()){
            return null;
        }
        estado = 0;
        while(true){
            currentChar = nextChar();
            switch(estado){
                case 0:
                    if(isChar(currentChar)){
                        estado = 1;
                    }
                    if(isDigit(currentChar)){
                        estado = 3;
                    }
                    else if(isOperador(currentChar)){
                        estado = 0;
                    }
                break;
                case 1:
                    if(isChar(currentChar) || isDigit(currentChar)){
                        estado = 1;
                    }else{
                        estado = 2;
                    }
                break;
                case 2:
                    Token token = new Token();
                    token.setType(token.INDENFIER);
                    return token;
            }
        }
    } 
   
    private Boolean isDigit(char c){
        return c>= '0' && c<=9;
    }
    
    private Boolean isChar(char c){
        return (c>='a' && c<='z') || (c>='A' && c<='Z');
    }
    
    private Boolean isOperador(char c){
        return c == '<' || c == '>' || c == '=' || c == '!';
    }
    
    private Boolean isSpace(char c){
        return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    }
    
    private char nextChar(){
        return content [posicao ++];
    }
    
    private Boolean isEOF(){
         return posicao == content.length;
    }
    
    private void back(){
        posicao --;
    }
}
