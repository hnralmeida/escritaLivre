/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package provamusica;

public class ProvaMusica {

    public static void main(String[] args) {
        // Música sertaneja informa se é universitário (nesse caso false) e as demais informações de qualquer 
        // música (nome, compositor, interprete e ano de criação)
        Musica m1 = new Sertanejo(false, "Rancho Fundo", "Chitaozinho e Xororó", "Chitaozinho e Xororó", 1996);
       
        // Forró além de ser uma música precisa informar de que regiao veio (nesse caso Itaúnas)
        Musica m2 = new Forro("Itaúnas", "Xote da Alegria", "Falamansa", "Ricardo", 2004);
        
        if (m1.toqueBase().equals(m2.toqueBase())){
            System.out.println("As músicas possuem mesmo toque base");
        }else{
            System.out.println("Os toques base são diferentes: m1 = " + m1.toqueBase() + " e m2 = " + m2.toqueBase());
        }
        
        Musica musicas[] = new Musica[3];
        musicas[0] = m1;
        musicas[1] = m2;
        
        // Rock além de ser música precisa informar o album (nesse caso Love at First Sting)
        musicas[2] = new Rock("Love at First Sting", "Rock You Like A Hurricane", "Scorpions", "Rudolf Schenker", 1980);
        
        Musica m3 = (Rock)musicas[2];
        // São equivalentes se o álbum, nome e compositor são iguais (não é para comparar interprete e ano)
        if(musicas[2].equals(m3)){
            System.out.println("Será que são iguais? Sim");
        }else{
            System.out.println("São diferentes");
        }
    }
}