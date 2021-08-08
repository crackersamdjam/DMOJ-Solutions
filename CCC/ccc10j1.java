import java.util.Scanner;

public class Ccc10j1 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int counter = 0;
        for(int i = 0; i <=5; i++){
            for(int j = i; j <=5; j++){
                if(i+j==n) counter++;
            }
        }
        System.out.println(counter);
    }
    
}