import java.util.*;
public class Main{

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);

        int N = in.nextInt(), M = in.nextInt();

        int[] m = new int[N], p = new int[N];
        boolean[][] no = new boolean[N][N];

        for(int i = 0; i < N; i++){
            m[i] = in.nextInt();
            p[i] = in.nextInt();
        }

        for(int i = 0,a,b; i < M; i++){
            a = in.nextInt() - 1;
            b = in.nextInt() - 1;
            no[a][b] = no[b][a] = true;
        }

        long ans = 0;

        for(int i = 0; i < N; i++){
            ans = Math.max(ans, p[i]);

            for(int j = 0; j < N; j++){
                if(i == j || no[i][j])
                    continue;

                ans = Math.max(ans, p[i]*m[j]+p[j]);

                for(int k = 0; k < N; k++){
                    if(i == k || j ==k || no[i][k] || no[j][k])
                        continue;

                    ans = Math.max(ans, (p[i]*m[j]+p[j])*m[k]+p[k]);
                }
            }
        }

        System.out.println(ans);
    }
}