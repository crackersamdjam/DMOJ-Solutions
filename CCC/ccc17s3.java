import java.util.*;
import java.io.*;
public class ccc17s3{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int n = readInt();
		int[] cnt = new int[4005];
		int[] len = new int[4005];
		while(n --> 0){
			cnt[readInt()]++;
		}
		for(int i = 1; i <= 2000; i++){
			for(int j = 1; j < i; j++)
				len[i+j] += Math.min(cnt[i], cnt[j]);
			len[i+i] += cnt[i]/2;
		}
		int maxlen = 0;
		for(int i = 1; i <= 4000; i++)
			if(len[i] > maxlen)
				maxlen = len[i];
	
		int ways = 0;
		for(int i = 1; i <= 4000; i++)
			if(len[i] == maxlen)
				ways++;

		System.out.println(maxlen+" "+ways);
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