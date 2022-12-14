/*
*   =========================================================================================
*   AUTORES: 	
*   			Henrique Almeida de Oliveira

*   Disciplina: Programacao Orientada a Objetos
*   Trabalho de POO1 - Camadas
*   =========================================================================================
*/

package control;

import dao.*;
import domain.Pokemon;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Vector;

public class ControladoraPokemons {
    private Vector<Pokemon> pokes;
    private int marcador;
    PokemonFileDao pokeDao;
    
    private String obterNomeColunaBanco(String colunm) {
        if (colunm.equals("Code"))
            return "code";
        if (colunm.equals("Name"))
            return "name";
        if (colunm.equals("Type"))
            return "type";
        if (colunm.equals("Hp"))
            return "hp";
        if (colunm.equals("Attack"))
            return "attack";
        if (colunm.equals("Defense"))
            return "defense";
        if (colunm.equals("SpAtk"))
            return "spatk";

        return "id";
    }

    public ControladoraPokemons() {
        this.pokeDao = new PokemonFileDao();
    }
    
    private void atualizarPokemon(Pokemon poke, Vector line){
        poke.setCode(line.get(0).toString());
        poke.setName(line.get(1).toString());
        poke.setTypes(line.get(2).toString());
        poke.setHp(Integer.parseInt(line.get(3).toString()));
        poke.setAttack(Integer.parseInt(line.get(4).toString()));
        poke.setDefense(Integer.parseInt(line.get(5).toString()));
        poke.setSpAtk(Float.parseFloat(line.get(6).toString()));
    }
    
    private Vector criarLinhaPokemon(Pokemon poke) {
        Vector line = new Vector();
        line.addElement(poke.getCode());
        line.addElement(poke.getName());
        line.addElement(poke.getTypes());
        line.addElement(poke.getHp());
        line.addElement(poke.getAttack());
        line.addElement(poke.getDefense());
        line.addElement(poke.getSpAtk());
        return line;
    }
         
    public void inserirNovoPokemon(Vector line) throws FileNotFoundException, IOException, ClassNotFoundException{
        Pokemon poke = new Pokemon();
        this.atualizarPokemon(poke, line);
        this.pokes.add(poke);
        pokeDao.salvarPokemons(this.pokes);
    }
    
    public void setMarcador(int marcador){
        this.marcador = marcador;
    }

    public void alterarPokemon(Vector line) throws FileNotFoundException, IOException, ClassNotFoundException {
        Pokemon poke = pokes.get(marcador);
        this.atualizarPokemon(poke, line);
        pokeDao.salvarPokemons(this.pokes);
    }
    
    public void  excluirPokemon() throws FileNotFoundException, IOException, ClassNotFoundException{
        pokes.remove(marcador);
        pokeDao.salvarPokemons(this.pokes);
    }
    
    private Vector<Pokemon> obterPokemon(String colunm, boolean crescente) throws FileNotFoundException, IOException, ClassNotFoundException{
        String nomeColunaBanco = this.obterNomeColunaBanco(colunm);
        pokes = pokeDao.obterPokemons(nomeColunaBanco, crescente);
        return pokes; 
    }

    public Vector obterLinhasPokemons(String coluna, boolean crescente) throws FileNotFoundException, IOException, ClassNotFoundException {
        Vector<Pokemon> pokemons = obterPokemon(coluna, crescente);
        Vector linhas = new Vector();
        
        // Montando as linhas
        for(int i = 0; i < pokemons.size(); i++){
            Pokemon poke = pokemons.get(i);
            linhas.addElement(this.criarLinhaPokemon(poke));
        }
        return linhas;
    }
}
