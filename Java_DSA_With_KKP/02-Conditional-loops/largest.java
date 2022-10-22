import java.util.Scanner;

public class largest {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            System.out.println(a + b + c);
            int maxi = Math.max(a, Math.max(b, c));
            System.out.println(maxi);
        }
    }
}
