import java.util.ArrayList;
import java.util.Scanner;
public class CCC11J3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(input.nextInt());
        arr.add(input.nextInt());
        int i = 2;
        while(arr.get(i-2) - arr.get(i-1) >=0){
            arr.add(arr.get(i-2) - arr.get(i-1));
            i++;
        }
        System.out.println(arr.size());
    }
    
}