import java.util.Scanner;
public class CCC11J2 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int h = input.nextInt(), M = input.nextInt();
        boolean bool = false;
        for(int t = 1; t <= M; t++){
            if(-6*t*t*t*t + h*t*t*t + 2*t*t + t <=0){
                System.out.println("The balloon first touches ground at hour: " + "\n" + t);
                bool = true;
                break;
            }
        }
        if(!bool){
            System.out.println("The balloon does not touch ground in the given time.");
        }
    }
    
}