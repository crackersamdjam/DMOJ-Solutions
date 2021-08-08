import java.util.*;
import java.io.*;
public class ccc15s3_2{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		TreeSet<Integer> t = new TreeSet<Integer>();
		int n = readInt();
		int m = readInt();
		for(int i = 0; i <= n; i++)
			t.add(i);

		for(int i = 0; i < m; i++){
			int a = readInt();

			int b = t.lower(a+1);

			if(b == 0){
				System.out.println(i);
				return;
			}
			t.remove(b);
		}
		System.out.println(m);
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