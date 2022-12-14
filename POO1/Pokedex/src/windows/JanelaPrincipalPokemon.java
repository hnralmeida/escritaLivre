/*
*   =========================================================================================
*   AUTORES: 	
*   			Henrique Almeida de Oliveira

*   Disciplina: Programacao Orientada a Objetos
*   Trabalho de POO1 - Camadas
*   =========================================================================================
*/
package windows;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class JanelaPrincipalPokemon extends JanelaVisualizarPokemon {

    @Override
    protected void montarCabecalho() {
        super.montarCabecalho();
        Vector colunas = this.obterNomeColunasTabela();
        int qtMenus = colunas.size() * 2;
        System.out.println(" " + (qtMenus + 1) + ") Registrar Novo Pokemon");
        System.out.println(" " + (qtMenus + 2) + ") Alterar Pokemon");
        System.out.println(" " + (qtMenus + 3) + ") Remover Pokemon");
    }

    private Vector lerDados() {
        System.out.println("===========================================================================================================");
        System.out.println("Digite os seguintes dados: ");
        Vector colunas = this.obterNomeColunasTabela();
        Scanner leitor = new Scanner(System.in);
        Vector dados = new Vector();
        String valor;
        for (int i = 0; i < colunas.size(); i++) {
            System.out.println(colunas.get(i));
            valor = leitor.next();
            dados.add(valor);
        }
        System.out.println("");
        System.out.println("===========================================================================================================");
        return dados;
    }



    @Override
    public void executar() {
        Vector colunas = this.obterNomeColunasTabela();
        Scanner leitorOpcao = new Scanner(System.in);
        int opcao;
        int qtMenus = colunas.size() * 2;
        do {
            this.montarLayout();

            opcao = leitorOpcao.nextInt();
            // sair
            if (opcao == 0) {
                break;
            } // ordenação
            else if (opcao <= qtMenus) {
                limparTabelaPokemons();
                this.coluna = (String) colunas.get((opcao - 1) / 2);
                if ((opcao % 2) == 1) {
                    this.crescente = true;
                } else {
                    this.crescente = false;
                }
            } // incluir
            else if (opcao == qtMenus + 1) {
                limparTabelaPokemons();
                Vector dados = lerDados();
                try {
                    this.controladora.inserirNovoPokemon(dados);
                } catch (FileNotFoundException ex) {
                    Logger.getLogger(JanelaPrincipalPokemon.class.getName()).log(Level.SEVERE, null, ex);
                } catch (IOException ex) {
                    Logger.getLogger(JanelaPrincipalPokemon.class.getName()).log(Level.SEVERE, null, ex);
                } catch (ClassNotFoundException ex) {
                    Logger.getLogger(JanelaPrincipalPokemon.class.getName()).log(Level.SEVERE, null, ex);
                }

            } // alterar
            else if (opcao == qtMenus + 2) {
                System.out.println("Digite o número da linha que deseja alterar: ");
                this.controladora.setMarcador(leitorOpcao.nextInt());
                limparTabelaPokemons();
                Vector dados = lerDados();
                try {
                    this.controladora.alterarPokemon(dados);
                } catch (FileNotFoundException ex) {
                    Logger.getLogger(JanelaPrincipalPokemon.class.getName()).log(Level.SEVERE, null, ex);
                } catch (IOException ex) {
                    Logger.getLogger(JanelaPrincipalPokemon.class.getName()).log(Level.SEVERE, null, ex);
                } catch (ClassNotFoundException ex) {
                    Logger.getLogger(JanelaPrincipalPokemon.class.getName()).log(Level.SEVERE, null, ex);
                }

            } // excluir
            else if (opcao == qtMenus + 3) {
                System.out.println("Digite o número da linha que deseja excluir: ");
                this.controladora.setMarcador(leitorOpcao.nextInt());
                try {
                    this.controladora.excluirPokemon();
                } catch (FileNotFoundException ex) {
                    Logger.getLogger(JanelaPrincipalPokemon.class.getName()).log(Level.SEVERE, null, ex);
                } catch (IOException ex) {
                    Logger.getLogger(JanelaPrincipalPokemon.class.getName()).log(Level.SEVERE, null, ex);
                } catch (ClassNotFoundException ex) {
                    Logger.getLogger(JanelaPrincipalPokemon.class.getName()).log(Level.SEVERE, null, ex);
                }

                limparTabelaPokemons();

            } else {
                System.out.println("Falha GERAL");
            }


        } while (true);
        leitorOpcao.close();
    }
}
