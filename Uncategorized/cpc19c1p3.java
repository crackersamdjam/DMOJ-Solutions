import java.io.*;
public class Main{

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

    static final int MM = 1000010;

    static int[] dp = new int[MM], psa = new int[MM], psb = new int[MM];
    static boolean[] a = new boolean[MM], b = new boolean[MM];

    static int on(int l, int r){
        return psa[r] - psa[l-1];
    }

    static int off(int l, int r){
        return psb[r] - psb[l-1];
    }

    public static void main(String[] args) throws IOException{

        int N = Integer.parseInt(in.readLine());

        String sa = in.readLine(), sb = in.readLine();

        dp[0] = dp[1] = dp[2] = dp[3] = 1000000000;
        for(int i = 5; i < N+5; i++){
            dp[i] = 1000000000;
            a[i] = sa.charAt(i-5) == '1';
            b[i] = sb.charAt(i-5) == '1';
            psa[i] = psa[i-1] + (a[i]?1:0);
            psb[i] = psb[i-1] + (b[i]?1:0);

            if(a[i] == b[i])
                dp[i] = dp[i-1];
            if(!a[i] && b[i])
                dp[i] = dp[i-1] + 1;

            if(i > 6)
                dp[i] = Math.min(dp[i], dp[i-3] + (3-on(i-2, i) + 1 + off(i-2, i)));
            if(i > 7)
                dp[i] = Math.min(dp[i], dp[i-4] + (4-on(i-3, i) + 1 + off(i-3, i)));
        }

        System.out.println(dp[N+4]);
    }
}