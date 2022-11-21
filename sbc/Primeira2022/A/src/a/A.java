package a;

import java.util.Scanner;

public class A {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int qt, x;
        int i;

        do {
            qt = scan.nextInt();
            x = scan.nextInt();

            int vetor[] = new int[qt + 1];

            vetor[x] = x;

            for (i = 0; i < qt - 2; i++) {
                x = scan.nextInt();
                vetor[x] = x;
            }

            for (i = 0; i < qt + 1; i++) {
                if (vetor[i] != i) {
                    System.out.println(i);
                }
            }

        } while (qt != 0);

    }

}
