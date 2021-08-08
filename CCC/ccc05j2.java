import java.util.Scanner;

public class CCC05J2 {

    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int l = input.nextInt(), h = input.nextInt();
        int counter;
        int rsa = 0;
        for(int i = l; i <= h; i++){
            counter = 0;
            for(int j = 1; j <= i; j++){
                if(i%j==0) counter++;
                if(counter > 4) break;
            }
            if(counter == 4){
                rsa++;
            }
        }
        System.out.println("The number of RSA numbers between " + l + " and " + h + " is " + rsa);
    }
    
}