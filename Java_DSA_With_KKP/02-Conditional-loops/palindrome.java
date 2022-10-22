import java.util.Scanner;

public class palindrome {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            long num = in.nextLong();

            long ans = 0;
            while (num > 0) {
                long rem = (num % 10);
                num /= 10;
                ans = ans * 10 + rem;
            }
            System.out.println(ans);
        }
    }
}
