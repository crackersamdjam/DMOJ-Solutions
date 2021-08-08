import java.util.*;
import java.io.*;
public class dph{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt();
		char[][] a = new char[n+1][m+1];
		long[][] dp = new long[n+1][m+1];
		final long mod = 1000000007;
		for(int i = 1; i <= n; i++){
			a[i] = (" "+readLine()).toCharArray();
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(i == 1 && j == 1)
					dp[i][j] = 1;
				else if(a[i][j] == '.')
					dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
			}
		}
		System.out.println(dp[n][m]);
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