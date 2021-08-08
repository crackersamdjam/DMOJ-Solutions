import java.util.*;
import java.io.*;
public class dmopc20c2p2{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int n = readInt();
		int m = readInt();
		int[] first = new int[1000005];
		int[] last = new int[1000005];
		for(int i = 1; i <= n; i++){
			int a = readInt();
			if(first[a] == 0)
				first[a] = i;
			last[a] = i;
		}
		int ans = 0;
		while(m-- > 0){
			int a = readInt();
			int b = readInt();
			if(last[a] != 0 && last[b] != 0)
				ans = Math.max(ans, last[b]-first[a]+1);
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