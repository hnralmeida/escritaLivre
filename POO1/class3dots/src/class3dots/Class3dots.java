/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package class3dots;

/**
 *
 * @author 2021122760046
 */
public class Class3dots {

    private static String valores[];

    public static void mostrarValores() {
        for (String s : Class3dots.valores) {
            System.out.println(s);
        }
    }

    public static void lerValores(String... valores) {
        Class3dots.valores = valores;
    }

    public static void lerValores(String valor, int... numeros) {
        Class3dots.valores = new String[numeros.length + 1];
        Class3dots.valores[0] = valor;
        for (int i = 0; i < numeros.length; i++) {
            Class3dots.valores[i + 1] = String.valueOf(numeros[i]);
        }
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        lerValores("a", "b", "c", "c");
        mostrarValores();
        lerValores("teste", 1, 2, 3, 4);
        mostrarValores();
    }
}
