import java.util.ArrayDeque;
import java.util.Scanner;

public class CCC10J4 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while(true){
            int n = input.nextInt();
            if(n==0){
                break;
            }
            
            int[] p = new int[n];
            for(int i = 0; i < n; i++){
                p[i] = input.nextInt();
            }
            int[] dif = new int[n];
            for(int i = 0; i < n-1; i++){
                dif[i] = p[i+1] - p[i];
            }
            //System.out.println("$" + n);
            int shortest = n;
            ArrayDeque<Integer> pattern = new ArrayDeque<>();
            Outer:
            for(int i = 1; i <= n-1; i++){
                pattern.clear();
                boolean match = true;
                for(int j = 0; j <i; j++){
                    pattern.add(dif[j]);
                    //System.out.println(" * "+dif[j] + ") " + i);
                }
                for(int j = 0; j < n-1; j++){
                    //System.out.println(" f"+pattern.getFirst() + " . " + dif[j]);
                    if(dif[j]==pattern.getFirst()){
                        pattern.addLast(pattern.removeFirst());
                    }else{
                        match = false;
                        break;
                    }
                }
                if(match){
                    shortest = i;
                    break Outer;
                }
            }
            if(n==1)
                shortest = 0;
            System.out.println(shortest);
        }
    }
    
}