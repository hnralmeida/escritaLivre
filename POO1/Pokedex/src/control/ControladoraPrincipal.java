/*
*   =========================================================================================
*   AUTORES: 	
*   			Henrique Almeida de Oliveira

*   Disciplina: Programacao Orientada a Objetos
*   Trabalho de POO1 - Camadas
*   =========================================================================================
*/

package control;

import windows.JanelaPrincipalPokemon;
import windows.JanelaVisualizarPokemon;


public class ControladoraPrincipal {
    public static void main(String argsp[])
    {
        JanelaVisualizarPokemon janela = new JanelaPrincipalPokemon();
        janela.executar();
    }

}
