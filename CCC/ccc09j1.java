import java.util.Scanner;
public class CCC09J1 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt(), b = input.nextInt(), c = input.nextInt();
        int out = 91 + a + b*3 + c;
        System.out.println("The 1-3-sum is " + out);
        
    }
    
}