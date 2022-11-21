import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class D {

    public static void main(String[] args) {
        int N, i;
        Scanner scan = new Scanner(System.in);
        LinkedList<Integer> p = new LinkedList();
        
        N = scan.nextInt();
        while (N != 0) {
            int Y[] = new int[N];
            i = 0;
            while (i < N) {
                Y[i] = scan.nextInt();
                i++;
            }

            i = 0;
            while (i < N) {
                p.add(Y[N-1-i]);
                i++;
            }
            p.add(0);
            N = scan.nextInt();
        }
        Iterator it = p.iterator();
        
        for(int h: p)
        {
            System.out.println(h);
        }
    }
}
