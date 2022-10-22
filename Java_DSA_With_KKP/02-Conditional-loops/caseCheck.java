import java.util.Scanner;

public class caseCheck {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            char ch = in.next().trim().charAt(4);
            System.out.println(ch);
        }
    }
}
