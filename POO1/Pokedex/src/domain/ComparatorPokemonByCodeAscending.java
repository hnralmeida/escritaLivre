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

public class ComparatorPokemonByCodeAscending implements Comparator<Pokemon> {
    @Override
    public int compare(Pokemon o1, Pokemon o2) {
        return o1.getCode().compareTo(o2.getCode());
    }
}
