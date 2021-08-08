import java.util.*;
import java.io.*;
public class nccc6j5{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int n = readInt(), k = readInt();
		int[] cnt = new int[n+1];
		long[][] dp = new long[n+1][k+1];
		for(int i = 0; i < n; i++)
			cnt[readInt()]++;
		
		dp[0][0] = 1;
		for(int i = 1; i <= n; i++){
			dp[i][0] = dp[i-1][0];
			for(int j = 1; j <= k; j++){
				dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*cnt[i])%998244353;
			}
		}
		System.out.println(dp[n][k]);
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