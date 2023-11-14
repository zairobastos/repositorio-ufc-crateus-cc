/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lexico;

/**
 *
 * @author rayla
 */
public class Token {
    public static final int INDENFIER = 0;
    public static final int NUMBER = 1;
    public static final int OPERATOR = 2;
    public static final int PONTUACION = 3;
    public static final int ASSIGN = 4;
    
    private int type;
    private String text;

    public Token(int type, String text) {
        super();
        this.type = type;
        this.text = text;
    }

    public int getType() {
        return type;
    }

    public void setType(int type) {
        this.type = type;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    @Override
    public String toString() {
        return "Token{" + "type=" + type + ", text=" + text + '}';
    }
        
}
