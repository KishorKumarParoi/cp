import java.util.Scanner;

public class temparature {
    public static void main(String[] args) {
        double f;
        System.out.print("Enter Farenhite Temparature : ");
        try (Scanner input = new Scanner(System.in)) {
            f = input.nextDouble();
        }
        double c = (5 * f - 160) / 9;
        System.out.println(c);
    }
}
