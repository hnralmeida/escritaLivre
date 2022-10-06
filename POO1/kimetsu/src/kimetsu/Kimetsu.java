/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kimetsu;

public class Kimetsu {

    public static void ataqueOros(Oni onis[]) {
        for (int i = 1; i < 6; i++) {
            onis[0].atacar(onis[i]);
        }
    }

    public static void ataqueMukago(Oni onis[]) {
        for (int i = 0; i < 5; i++) {
            onis[5].atacar(onis[i]);
        }
    }

    public static void ataqueKosushibo(Oni onis[]) {
        onis[2].atacar(onis[0]);
        onis[2].atacar(onis[1]);
        onis[2].atacar(onis[3]);
        onis[2].atacar(onis[4]);
        onis[2].atacar(onis[5]);
    }

    public static void imprimirEnergia(Oni onis[]) {
        for (int i = 0; i < 6; i++) {
            System.out.println("O oni " + onis[i].getNome()
                    + " possui energia de " + onis[i].getEnergia());
        }
    }

    public static void main(String[] args) {
        Oni onis[] = new Oni[6];
        onis[0] = new Simples("Oros");
        onis[1] = new Simples("Nabara");
        onis[2] = new LuaSuperior("Kokushibo", 250);
        onis[3] = new LuaSuperior("Akaza", 150);
        onis[4] = new LuaInferior("Rui", 50);
        onis[5] = new LuaInferior("Mukago", 30);
        System.out.println("Foram criados " + Oni.getQt() + " onis ");
        ataqueOros(onis);
        imprimirEnergia(onis);
        System.out.println("===================================");
        ataqueMukago(onis);
        imprimirEnergia(onis);
        System.out.println("===================================");
        ataqueKosushibo(onis);
        imprimirEnergia(onis);
    }
}
