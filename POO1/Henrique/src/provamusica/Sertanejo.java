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
public class Sertanejo extends Musica {
    private final boolean universitario;

    public Sertanejo(boolean universitario, String nome, String compositor, String inteprete, int ano) {
        super("turun taran turun taran turun", nome, compositor, inteprete, ano);
        this.universitario = universitario;
    }

    public boolean isUniversitario() {
        return universitario;
    }
    
}
