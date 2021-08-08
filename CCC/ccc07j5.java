import java.util.*;
import java.io.*;
public class ccc07j5{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws IOException{
        int[] pre = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
        int A = readInt(), B = readInt(), n = readInt();
        int[] loc = new int[n+pre.length];
        for(int i = 0; i < n; i++)
            loc[i] = readInt();
        for(int i = 0; i < pre.length; i++)
            loc[i+n] = pre[i];
        Arrays.sort(loc);
        
        long[] dp = new long[loc.length];
        dp[0] = 1;

        for(int i = 1; i < loc.length; i++){
            for(int j = 0; j < i; j++){
                if(loc[i]-loc[j] >= A && loc[i]-loc[j] <= B)
                    dp[i] += dp[j];
            }
        }

        System.out.println(dp[loc.length-1]);
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