/*
*   =========================================================================================
*   AUTORES: 	
*   			Henrique Almeida de Oliveira

*   Disciplina: Programacao Orientada a Objetos
*   Trabalho de POO1 - Camadas
*   =========================================================================================
*/
package windows;

import control.*;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.*;

public class JanelaVisualizarPokemon {

    protected ControladoraPokemons controladora;
    protected String coluna;
    protected boolean crescente;
    private Vector colunas = null;
    
    public JanelaVisualizarPokemon() {
        controladora = new ControladoraPokemons();
        this.obterNomeColunasTabela();
        this.coluna = colunas.get(0).toString();
        this.crescente = true;
    }

    protected Vector obterNomeColunasTabela() {
        if (colunas == null) {
            colunas = new Vector(10);

            colunas.addElement("Code");
            colunas.addElement("Name");
            colunas.addElement("Type");
            colunas.addElement("Hp");
            colunas.addElement("Attack");
            colunas.addElement("Defense");
            colunas.addElement("SpAtk");
            
        }

        return colunas;
    }

    protected void limparTabelaPokemons() {
        for (int i = 0; i < 25; i++) {
            System.out.println();
        }
    }

    protected void preencherTabelaPokemons() {
        try {
            Vector lines;
            lines = controladora.obterLinhasPokemons(coluna, crescente);

            System.out.println("Legenda da ordem das colunas");
            for (int i = 0; i < colunas.size() - 1; i++) {
                System.out.print(colunas.get(i) + "   -   ");
            }
            System.out.print(colunas.get(colunas.size() - 1));
            System.out.println("");
            System.out.println("===========================================================================================================");

            int numLines = lines.size();
            for (int i = 0; i < numLines; i++) {
                Vector line = (Vector) lines.get(i);
                for (int j = 0; j < colunas.size() - 1; j++) {
                    System.out.print(line.get(j) + "   -   ");
                }
                System.out.print(line.get(colunas.size() - 1));/*String valor = (String) line.get(colunas.size() - 1);
                if (valor.equals("")) {
                    System.out.print(" null ");
                } else {
                    System.out.print(valor);
                }*/
                System.out.println("");
                System.out.println("----------------------------------------------------------------------------------------------------------");

            }
            System.out.println("===========================================================================================================");
        } catch (FileNotFoundException ex) {
            Logger.getLogger(JanelaVisualizarPokemon.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(JanelaVisualizarPokemon.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(JanelaVisualizarPokemon.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    protected void montarCabecalho() {

        System.out.println(" Escolha uma das opções abaixo:");
        System.out.println(" 0) Sair");
        int desloque = 0;
        for (int i = 0; i < colunas.size(); i++) {
            System.out.println(" " + (i + 1 + desloque) + ") " + colunas.get(i) + " - Crescente");
            System.out.println(" " + (i + 2 + desloque) + ") " + colunas.get(i) + " - Decrescente");
            desloque++;
        }

    }

    protected void montarLayout() {
        // Montar cabeçalho
        System.out.println("===========================================================================================================");
        this.montarCabecalho();
        System.out.println("===========================================================================================================");
        // Preenchendo a Tabela de Filmes
        this.preencherTabelaPokemons();
    }

    public void executar() {
        Scanner leitorOpcao = new Scanner(System.in);
        int opcao;
        do {
            this.montarLayout();

            opcao = leitorOpcao.nextInt();
            
            limparTabelaPokemons();
            // sair
            if (opcao == 0) {
                break;
            }

            this.coluna = (String) this.colunas.get((opcao - 1) / 2);
            if ((opcao % 2) == 1) {
                this.crescente = true;
            } else {
                this.crescente = false;
            }

        } while (true);
        leitorOpcao.close();
    }
}
