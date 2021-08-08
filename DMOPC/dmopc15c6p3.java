import java.util.*;
import java.io.*;
public class dmopc15c6p3{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt();
		long k = readLong();
		long[] dif = new long[n+2];
		dif[1] = m;
		while(m --> 0){
			int l = readInt();
			int r = readInt();
			dif[l]--;
			dif[r+1]++;
		}
		for(int i = 1; i <= n; i++)
			dif[i] += dif[i-1];
		
		int ans = Integer.MAX_VALUE;
		int l = 1, r = 0;
		long sum = 0;
		while(r <= n){
			// System.out.println(l+" "+r+" "+sum);
			if(sum < k){
				sum += dif[++r];
			}
			else{
				ans = Math.min(ans, r-l+1);
				sum -= dif[l++];
			}
		}
		if(ans == Integer.MAX_VALUE)
			ans = -1;
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