import java.util.*;
import java.io.*;
public class ccc09s5{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int m = readInt();
		int n = readInt();
		int k = readInt();

		int[][] a = new int[n+1][m+1];
		while(k --> 0){
			int x = readInt();
			int y = readInt();
			int r = readInt();
			int b = readInt();
			for(int i = Math.max(1, x-r); i <= Math.min(n, x+r); i++){
				int d = (int)Math.sqrt(r*r - (x-i)*(x-i));
				a[i][Math.max(1, y-d)] += b;
				if(y+d+1 <= m)
					a[i][y+d+1] -= b;
			}
		}
		int best = 0, cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				a[i][j] += a[i][j-1];
				if(a[i][j] > best){
					best = a[i][j];
					cnt = 1;
				}
				else if(a[i][j] == best)
					cnt++;
			}
		}
		System.out.println(best);
		System.out.println(cnt);
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