import java.util.*;
import java.io.*;
public class banknotes{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int n = readInt();
		int[] b = new int[n];
		int[] c = new int[n];

		for(int i = 0; i < n; i++)
			b[i] = readInt();
		for(int i = 0; i < n; i++)
			c[i] = readInt();

		int k = readInt();
		int[] dp = new int[k+1];
		Arrays.fill(dp, 999);
		dp[0] = 0;

		for(int i = 0; i < n; i++){
			for(int j = k; j >= b[i]; j--){
				for(int l = 0; l <= c[i] && j-l*b[i] >= 0; l++)
					dp[j] = Math.min(dp[j], dp[j-l*b[i]]+l);
			}
		}
		System.out.println(dp[k]);
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