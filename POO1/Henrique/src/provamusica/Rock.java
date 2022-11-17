/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package provamusica;

import java.util.Objects;

/**
 *
 * @author 2021122760046
 */
public class Rock extends Musica {
    private final String album;

    public Rock(String album, String nome, String compositor, String inteprete, int ano) {
        super("run run run", nome, compositor, inteprete, ano);
        this.album = album;
    }

    public String getAlbum() {
        return album;
    }

    @Override
    public int hashCode() {
        int hash = 5;
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Rock other = (Rock) obj;
        return (Objects.equals(this.album, other.album) 
                && Objects.equals(this.getCompositor(), other.getCompositor())
                && Objects.equals(this.getNome(),other.getNome()));
    }
}
