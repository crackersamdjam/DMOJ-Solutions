import java.util.*;
import java.io.*;
public class rgss4{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int n = readInt();
		int[][] dp = new int[n+2][1001];
		for(int i = 1; i <= n; i++){
			int h = readInt();
			for(int j = 0; j <= 1000; j++){
				dp[i+1][j] = Math.max(dp[i+1][j], dp[i][j]);
				if(h > j)
					dp[i+1][h] = Math.max(dp[i+1][h], dp[i][j]+h);
			}
		}
		int ans = 0;
		for(int j = 0; j <= 1000; j++)
			ans = Math.max(ans, dp[n+1][j]);
		System.out.println(ans);
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