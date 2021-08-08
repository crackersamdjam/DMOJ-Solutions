import java.util.Scanner;
import java.util.Stack;

public class ccc14s3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        boolean isPossible = true;
        int test = input.nextInt();
        for(int i = 0; i < test; i++){
        int counter;
            counter = 1;
            int numCars = input.nextInt();
            Stack<Integer> mountain = new Stack<Integer>();
            Stack<Integer> branch = new Stack<Integer>();
            for(int j = 1; j <= numCars; j++){
                mountain.push(input.nextInt());
            }
            
            while(!mountain.isEmpty()){
                if(mountain.peek()==counter){
                    mountain.pop();
                    counter++;
                   } 
                else if(!branch.isEmpty() && branch.peek()==counter){
                    branch.pop();
                    counter++;
                }else{
                    branch.push(mountain.pop());
                }
            }
                isPossible = true;
                while(!branch.isEmpty()){
                    if(branch.peek()==counter){
                        branch.pop();
                        counter++;
                    }else{
                        isPossible = false;
                        branch.pop();
                    }
                } 
                if(isPossible){
                    System.out.println("Y");
                }else{
                    System.out.println("N");
                }
    }
}
}