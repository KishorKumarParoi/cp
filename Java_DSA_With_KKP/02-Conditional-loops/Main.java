import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            int salary = input.nextInt();
            if (salary > 1000)
                salary += 1000;
            else if (salary > 2000)
                salary += 2000;
            else
                salary += 10000;
            System.out.println(salary);
        }
    }
}
