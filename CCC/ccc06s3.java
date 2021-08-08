import java.util.*;
import java.awt.geom.*;

public class Main{

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);

        int a1 = in.nextInt(), a2 = in.nextInt(), a3 = in.nextInt(), a4 = in.nextInt();

        int N = in.nextInt(), ans = 0;

        for(int i = 0; i < N; i++){
            int n = in.nextInt();
            int[] x = new int[n], y = new int[n];

            for(int j = 0; j < n; j++){
                x[j] = in.nextInt();
                y[j] = in.nextInt();
            }

            for(int j = 0; j < n; j++){
                if(Line2D.linesIntersect(a1, a2, a3, a4, x[j], y[j], x[(j+1)%n], y[(j+1)%n])){
                    ans++;
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}