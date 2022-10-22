import java.util.Scanner;

public class Nested {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int employeeID = input.nextInt();
        String dep = input.nextLine();

        switch (employeeID){
            case 1:
                System.out.println("Marketing");
                break;
            case 2: {
                switch (dep) {
                    case "IT":
                        System.out.println("Kotipoti");
                        break;
                    case "CSE":
                        System.out.println("Borolox");
                        break;
                    default:
                        System.out.println("Gorib");
                }
            }
            case 3:
                System.out.println("Business");
                break;
            default:
                System.out.println("Jobless");

        }
    }
}
