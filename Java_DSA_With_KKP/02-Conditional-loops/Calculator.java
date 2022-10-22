import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            while (true) {
                System.out.print("Enter Operator : ");
                char c = in.next().trim().charAt(0);

                if (c == '+' || c == '*' || c == '-' || c == '/') {
                    System.out.print("Enter two number : ");
                    int a = in.nextInt();
                    int b = in.nextInt();

                    if (c == '+')
                        System.out.println(a + b);
                    else if (c == '-')
                        System.out.println(a - b);
                    else if (c == '*')
                        System.out.println(a * b);
                    else {
                        if (b != 0)
                            System.out.println((double) a / b);
                        else
                            System.out.println("Can't Devide By Zero");
                    }
                } else if (c == 'X' || c == 'x')
                    break;
                else {
                    System.out.println("Invalid Operation");
                }
            }
        }
    }
}
