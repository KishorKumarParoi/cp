public class Basics {
    public static void main(String[] args) {
        int a = 10;
        if (a == 10)
            System.out.println("true");
        else if (a > 10)
            System.out.println("Bigger");
        else
            System.out.println("Smaller");
        while (a > 0) {
            System.out.println(a);
            a--;
        }
    }
}
