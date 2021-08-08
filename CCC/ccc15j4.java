import java.util.*;
public class CCC15J4actually {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int t = 0;
        int[] friends = new int[101];
        Arrays.fill(friends, 0);
        for(int i = 0 ; i < n; i++){
            String tz = in.next();
            int a = in.nextInt();
            switch(tz){
                case "R":
                    friends[a] -= t;
                    t++;
                    break;
                case "S":
                    friends[a] += t;
                    t++;
                    break;
                case "W":
                    t += a-1;
                    break;
            }
        }
        for(int i = 0; i < 101; i++){
            if(friends[i] > 0){
                System.out.println(i + " " + friends[i]);
            }else if(friends[i] < 0){
                System.out.println(i + " -1");
            }
        }
    }
    
}