import java.util.Scanner;
public class CCC08S1 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int coldest = Integer.MAX_VALUE;
        String city = "?";
        String current = "";
        while(!current.equals("Waterloo")){
            current = input.next();
            int in = input.nextInt();
            if(in<coldest){
                coldest = in;
                city = current;
            }
        }
        System.out.println(city);
    }
    
}