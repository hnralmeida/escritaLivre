/*
 * classe convertedora
 */
package convertedora;

/**
 *
 * @author 2021122760046
 */
public class UsandoConvertedora {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int i1 = Convertedora.paraInteiro("123");
        int i2 = Convertedora.paraInteiro(23.5);
        System.out.println("O valor de i1+i2 é: " + (i1+i2));
        
        String s1 = Convertedora.paraString(123);
        String s2 = Convertedora.paraString(23.5);
        System.out.println("O valor de s1+s2 é: " + (s1+s2));
    }
    
}
