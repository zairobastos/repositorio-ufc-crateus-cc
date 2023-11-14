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
public class MostradorRelogio {
    private MostradorNumero horas;
    private MostradorNumero min;
    private String mostradorString;
    
    public MostradorRelogio(){
        this.horas = new MostradorNumero(24);
        this.min = new MostradorNumero(60);
        atualizaMostrador();
    }
    
    public MostradorRelogio(int hora, int min){
        this.horas = new MostradorNumero(24);
        this.min = new MostradorNumero(60);
        setTime(hora,min);
    }
    
    public void timeTick(){
        min.incrementar();
        if(min.getValor() == 0){
            horas.incrementar();
        }
        atualizaMostrador();
    }
    
    public void setTime(int hora,int min){
        horas.setValor(hora);
        this.min.setValor(min);
    }
    
    public String getTime(){
        return mostradorString;
    }
    
    public void atualizaMostrador(){
        mostradorString = horas.getMostraValor() + ":" + min.getMostraValor();
    }
}
