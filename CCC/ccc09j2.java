import java.util.Scanner;

public class CCC09J2 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int bt = input.nextInt(), np = input.nextInt(), yp = input.nextInt();
        int total = input.nextInt();
        int counter = 0;
        for(int i = 0; i*bt <= total; i++){
            for(int j = 0; i*bt + j*np <= total; j++){
                for(int k = 0; k*yp + j*np + i*bt <= total; k++){
                    if(i+j+k!=0){
                        System.out.println(i + " Brown Trout, " + j + " Northern Pike, " + k + " Yellow Pickerel");
                        counter++;
                    }
                }
            }
        }
        System.out.println("Number of ways to catch fish: " + counter);
    }
    
}