/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hashmap1;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 *
 * @author 2021122760046
 */
public class HashMap_Generics {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int capInit = 20;
        float loadFactor = (float) 0.9;
        Map<Integer,Pessoa> hash = new HashMap<Integer,Pessoa>(capInit, loadFactor);
        Scanner leitor = new Scanner(System.in);
        
        String nome[] = {"Amanda", "Gustavo", "Henrique", "Luiz", "Giovanny"};
        String cpf[] = {"198", "158", "205", "605", "082"};
        
        for(int i=0; i<5; i++){
            Pessoa p =  new Pessoa(nome[i], cpf[i]);
            hash.put(p.getCode(), p);
        }
        
        Set<Integer> chaves = hash.keySet();
        for(Integer chave: chaves){
            Pessoa p = hash.get(chave);
            System.out.println(p);
        }
    }
    
}
