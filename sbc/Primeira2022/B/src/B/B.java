package B;

import java.util.Scanner;

public class B {

    public static void main(String[] args) {
        int N, i;
        Scanner scan = new Scanner(System.in);
        N = scan.nextInt();
        while (N != 0) {
            int Y[] = new int[N];
            i = 0;
            while (i < N) {
                Y[i] = scan.nextInt();
                i++;
            }
            i = 0;
            while (i < (N / 2)) {
                int aux = Y[N - 1 - i];
                Y[N - 1 - i] = Y[i];
                Y[i] = aux;
                i++;
            }
            i = 0;
            while (i < N) {
                System.out.println(Y[i]);
                i++;
            }
            System.out.println("0");
            N = scan.nextInt();
        }
    }
}
