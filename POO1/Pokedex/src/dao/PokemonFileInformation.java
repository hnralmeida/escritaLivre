/*
*   =========================================================================================
*   AUTORES: 	
*   			Henrique Almeida de Oliveira

*   Disciplina: Programacao Orientada a Objetos
*   Trabalho de POO1 - Camadas
*   =========================================================================================
*/

package dao;

public class PokemonFileInformation {
    private static String nomeArquivo = "pokemon.txt";
    private static String caminhoArquivo = "";

    public static String getCaminhoArquivo() {
        return caminhoArquivo;
    }

    public static String getNomeArquivo() {
        return nomeArquivo;
    }

    
}
