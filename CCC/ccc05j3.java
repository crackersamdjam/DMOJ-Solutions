import java.util.Scanner;
import java.util.Stack;

public class CCC05J3 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Stack turn = new Stack();
        Stack street = new Stack();
        while(input.hasNext()){
            String dir = input.next();
            if("R".equals(dir)) turn.add("LEFT");
            else turn.add("RIGHT");
            
            String str = input.next();
            if("SCHOOL".equals(str)) break;
            street.add(str);
        }
        while(!street.isEmpty()){
            System.out.println("Turn " + turn.pop() + " onto " + street.pop() + " street.");
        }
        System.out.println("Turn " + turn.pop() + " into your HOME.");
    }
}