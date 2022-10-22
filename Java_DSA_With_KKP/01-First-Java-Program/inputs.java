import java.util.Scanner;

public class inputs {
    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            /*
             * System.out.print("Enter SOme Input : ");
             * int rollno = input.nextInt();
             * System.out.println("ROll No is " + rollno);
             * int a = 234_000_000;
             * System.out.println(a);
             */
            // String name = input.next();
            // System.out.println(name);
            float marks = input.nextFloat();
            System.out.println(marks);
            double mar = input.nextDouble();
            System.out.println(mar);
        }
    }
}
