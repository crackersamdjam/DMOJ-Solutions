import java.util.*;
import java.io.*;
public class dmopc20c1p2{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int n = readInt(), d = readInt();
		int[] a = new int[n+1];
		int[] psa = new int[n+1];
		for(int i = 1; i <= n; i++){
			a[i] = readInt();
			psa[i] = psa[i-1] + a[i];
		}
		int l = 1, r = n;
		while(d --> 0){
			int m = readInt();
			m += l-1;
			int ls = psa[m] - psa[l-1];
			int rs = psa[r] - psa[m];
			if(ls >= rs){
				System.out.println(ls);
				l = m+1;
			}
			else{
				System.out.println(rs);
				r = m;
			}
		}
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