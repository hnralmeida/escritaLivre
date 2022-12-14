/*
*   =========================================================================================
*   AUTORES: 	
*   			Henrique Almeida de Oliveira

*   Disciplina: Programacao Orientada a Objetos
*   Trabalho de POO1 - Camadas
*   =========================================================================================
*/
package dao;

import domain.*;
import domain.Pokemon;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Collections;
import java.util.Vector;

public class PokemonFileDao {

    public void salvarPokemons(Vector<Pokemon> pokemons) throws FileNotFoundException, IOException, ClassNotFoundException {
        FileOutputStream arquivo = new FileOutputStream(PokemonFileInformation.getCaminhoArquivo() + PokemonFileInformation.getNomeArquivo());

        //Classe responsavel por inserir os objetos
        ObjectOutputStream objGravar = new ObjectOutputStream(arquivo);

        //Grava o objeto de vetor de filmes no arquivo
        objGravar.writeObject(pokemons);
        objGravar.flush();
        objGravar.close();
        arquivo.flush();
        arquivo.close();
    }

    private boolean estaArquivoVazio() throws FileNotFoundException, IOException {
        //Carrega o arquivo
        String local_arquivo = PokemonFileInformation.getCaminhoArquivo() + PokemonFileInformation.getNomeArquivo();
        FileInputStream arquivoLeitura = new FileInputStream(local_arquivo);
        boolean estaVazio = (arquivoLeitura.read() == -1);
        arquivoLeitura.close();
        return estaVazio;
    }

    public Vector<Pokemon> obterPokemons() throws FileNotFoundException, IOException, ClassNotFoundException {
        //Carrega o arquivo
        if (estaArquivoVazio()) {
            return new Vector();
        } else {
            //Classe responsavel por recuperar os objetos do arquivo
            String local_arquivo = PokemonFileInformation.getCaminhoArquivo() + PokemonFileInformation.getNomeArquivo();
            FileInputStream arquivoLeitura = new FileInputStream(local_arquivo);
            ObjectInputStream objLeitura = new ObjectInputStream(arquivoLeitura);
            Vector<Pokemon> vetor = (Vector<Pokemon>) objLeitura.readObject();
            objLeitura.close();
            arquivoLeitura.close();
            return vetor;
        }
    }

   
    public Vector<Pokemon> obterPokemons(String coluna, boolean crescente) throws FileNotFoundException, IOException, ClassNotFoundException {
        Vector<Pokemon> pokemons = this.obterPokemons();
        if (coluna.equals("code")){
            if (crescente) Collections.sort(pokemons, new ComparatorPokemonByCodeAscending());
            else Collections.sort(pokemons, new ComparatorPokemonByCodeDescending());
        }
        else if (coluna.equals("name")){
            if (crescente) Collections.sort(pokemons, new ComparatorPokemonByNameAscending());
            else Collections.sort(pokemons, new ComparatorPokemonByNameDescending());
        }
        else if (coluna.equals("type")){
            if (crescente) Collections.sort(pokemons, new ComparatorPokemonByTypeAscending());
            else Collections.sort(pokemons, new ComparatorPokemonByTypeDescending());
        }
        else if (coluna.equals("hp")){
            if (crescente) Collections.sort(pokemons, new ComparatorPokemonByHpAscending());
            else Collections.sort(pokemons, new ComparatorPokemonByHpDescending());
        }
        else if (coluna.equals("attack")){
            if (crescente) Collections.sort(pokemons, new ComparatorPokemonByAttackAscending());
            else Collections.sort(pokemons, new ComparatorPokemonByAttackDescending());
        }
        else if (coluna.equals("defense")){
            if (crescente) Collections.sort(pokemons, new ComparatorPokemonByDefenseAscending());
            else Collections.sort(pokemons, new ComparatorPokemonByDefenseDescending());
        }
        else if (coluna.equals("spAtk")){
            if (crescente) Collections.sort(pokemons, new ComparatorPokemonBySpAtkAscending());
            else Collections.sort(pokemons, new ComparatorPokemonBySpAtkDescending());
        }
        return pokemons;
    }
}
