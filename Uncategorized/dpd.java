import java.util.*;
import java.io.*;
public class dpd{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws IOException{
        int n = readInt(), w = readInt();
        long[] dp = new long[w+1];

        for(int i = 1; i <= n; i++){
            int cost = readInt();
            int val = readInt();
            for(int j = w; j >= cost; j--)
                dp[j] = Math.max(dp[j], dp[j-cost]+val);
        }
        System.out.println(dp[w]);
    }


    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}