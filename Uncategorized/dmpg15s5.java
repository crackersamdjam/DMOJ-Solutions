import java.util.*;
import java.io.*;
public class dmpg15s5{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int n = readInt();
		int m = readInt();
		byte[][] a = new byte[n+2][n+2];
		while(m --> 0){
			int x = readInt();
			int y = readInt();
			int l = readInt();
			int w = readInt();
			x++;
			y++;
			a[x][y] ^= 1;
			a[x][y+w] ^= 1;
			a[x+l][y] ^= 1;
			a[x+l][y+w] ^= 1;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				a[i][j] ^= a[i-1][j]^a[i][j-1]^a[i-1][j-1];
				ans += a[i][j];
			}
		}
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