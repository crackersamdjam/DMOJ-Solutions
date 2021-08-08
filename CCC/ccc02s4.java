import java.util.*;
import java.io.*;
public class ccc02s4{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int m = readInt(), n = readInt();
		int[] a = new int[n];
		String[] name = new String[n];
		for(int i = 0; i < n; i++){
			name[i] = readLine();
			a[i] = readInt();
		}

		int[] dp = new int[n+1], pre = new int[n+1];
		Arrays.fill(dp, 99999);
		dp[0] = 0;
		for(int i = 0; i < n; i++){
			int val = 0;
			for(int j = i; j < i+m && j < n; j++){
				val = Math.max(val, a[j]);
				if(dp[i]+val < dp[j+1]){
					dp[j+1] = dp[i]+val;
					pre[j+1] = i;
				}
			}
		}
		System.out.println("Total Time: " + dp[n]);
		ArrayList<Integer> out = new ArrayList<>();
		
		{
			int i = n;
			while(i > 0){
				out.add(i);
				i = pre[i];
			}
		}
		for(int i = out.size()-1, l = 0; i >= 0; i--){
			while(l < out.get(i))
				System.out.print(name[l++]+" ");
			System.out.println();
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