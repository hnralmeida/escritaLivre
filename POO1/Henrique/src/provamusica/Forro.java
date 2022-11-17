/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package provamusica;

/**
 *
 * @author 2021122760046
 */
public class Forro extends Musica {
    
    private final String regiao;
            
    public Forro(String regiao, String nome, String compositor, String inteprete, int ano) {
        super("nanananana nanananana", nome, compositor, inteprete, ano);
        this.regiao = regiao;
    }

    public String getRegiao() {
        return regiao;
    }
    
}
