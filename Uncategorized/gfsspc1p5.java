import java.util.*;
import java.io.*;
public class gfsspc1p5{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int n = readInt(), t = readInt();
		int[] a = new int[n+1];
		for(int i = 0; i < n; i++)
			a[i] = readInt();
		a[n] = 0;
		Arrays.sort(a);
		int ans = Integer.MAX_VALUE;
		for(int i = t; i <= n; i++){
			int l = -a[i-t];
			int r = a[i];
			if(l >= 0 && r >= 0)
				ans = Math.min(ans, l+r+Math.min(l, r));
		}
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