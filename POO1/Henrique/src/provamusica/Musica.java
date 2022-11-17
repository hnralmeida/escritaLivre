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
public abstract class Musica {
    private final String nome;
    private final String compositor;
    private final String inteprete;
    private final String toqueBase;
    private final int ano;

    public Musica(String toqueBase, String nome, String compositor, String inteprete, int ano) {
        this.nome = nome;
        this.compositor = compositor;
        this.inteprete = inteprete;
        this.ano = ano;
        this.toqueBase = toqueBase;
    }

    public String getNome() {
        return nome;
    }

    public String getCompositor() {
        return compositor;
    }

    public String getInteprete() {
        return inteprete;
    }

    public int getAno() {
        return ano;
    }

    public String toqueBase() {
        return toqueBase;
    }
    
}
