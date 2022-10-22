import java.util.Scanner;

public class do_while {
    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            int num = input.nextInt();

            do {
                System.out.println(--num);
            } while (num > 0);
        }
    }
}
