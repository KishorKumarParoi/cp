import java.util.Scanner;

public class fruits {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String fruit = input.next();

        if(fruit.equals("Apple")){
            System.out.println("Round Fruit");
        }
        switch (fruit){
            case "Mango" :
                System.out.println("Sweet fruit");
                break;
            case "Apple":
                System.out.println("ROund fruit");
                break;
            case "Nashpati":
                System.out.println("A sweet red fruit");
                break;
            default:
                System.out.println("Not fruit at all");
        }
    }
}
