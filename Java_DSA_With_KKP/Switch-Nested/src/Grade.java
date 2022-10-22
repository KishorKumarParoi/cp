import java.util.Scanner;

public class Grade {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int grade = input.nextInt();

        switch (grade / 10) {
            case 10, 9 -> System.out.println("A+");
            case 8 -> System.out.println("A");
            case 7 -> System.out.println("A-");
            case 6 -> System.out.println("B");
            case 5 -> System.out.println("Passed");
            default -> System.out.println("Failed");
        }
    }
}
