import java.util.Scanner;

public class count {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            long num = in.nextLong();

            long cnt = 0;
            while (num > 0) {
                long tmp = num % 10L;
                if (tmp == 7) {
                    cnt++;
                }
                num /= 10L;
            }

            System.out.println(cnt);
        }
    }
}
