import java.util.*;
import java.io.*;
public class pwindsor18p5{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException{
		final long mod = (long)1e9+7;
		long ans = 1;
		int n = readInt();

		while(n >= 5){
			ans = ans*3%mod;
			n -= 3;
		}
		ans = ans*n%mod;

		System.out.println(ans);
	}


	static String next() throws IOException{
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong() throws IOException{
		return Long.parseLong(next());
	}
	static int readInt() throws IOException{
		return Integer.parseInt(next());
	}
	static double readDouble() throws IOException{
		return Double.parseDouble(next());
	}
	static char readCharacter() throws IOException{
		return next().charAt(0);
	}
	static String readLine() throws IOException{
		return br.readLine().trim();
	}
}