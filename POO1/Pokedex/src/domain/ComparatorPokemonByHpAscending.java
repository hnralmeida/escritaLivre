/*
*   =========================================================================================
*   AUTORES: 	
*   			Henrique Almeida de Oliveira

*   Disciplina: Programacao Orientada a Objetos
*   Trabalho de POO1 - Camadas
*   =========================================================================================
*/
package domain;

import java.util.Comparator;

public class ComparatorPokemonByHpAscending implements Comparator<Pokemon> {
    @Override
    public int compare(Pokemon o1, Pokemon o2) {
        if (o1.getHp() > o2.getHp()) {
            return 1;
        } else if (o1.getHp() < o2.getHp()) {
            return -1;
        } else {
            return 0;
        }
    }

}
