import java.util.Scanner;
import static java.util.Arrays.sort;
public class Question2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] ints = new int[4];
        for(int i = 0; i < 4; i++){
            ints[i] = input.nextInt();
        }
        sort(ints);
        System.out.println(ints[0]*ints[2]);
    }
    
}