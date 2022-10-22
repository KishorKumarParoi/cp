import java.util.Scanner;

public class fibonacchi {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int tc = in.nextInt();
            for (int j = 0; j < tc; ++j) {
                int n = in.nextInt();
                int a = 0;
                int b = 1;
                int i = 2;
                int val = 0;
                while (i <= n) {
                    val = a + b;
                    b = a;
                    a = val;
                    i++;
                    System.out.print(val);
                    System.out.print(" ");
                    System.out.print(a);
                    System.out.print(" ");
                    System.out.println(b);
                }
                System.out.println(val);
            }
        }
    }
}
