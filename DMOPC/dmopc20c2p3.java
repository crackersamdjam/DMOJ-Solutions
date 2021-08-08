import java.util.*;
import java.io.*;
public class dmopc20c2p3{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static long[][] size;
	static int[] p, a, b;
	static ArrayList<Integer>[][] adj;

	static long dfs(int t, int cur){
		if(size[t][cur] != 0)
			return size[t][cur];

		size[t][cur] = p[cur];

		for(int u: adj[t][cur])
			size[t][cur] += dfs(t, u);

		return size[t][cur];
	}

	public static void main(String[] args) throws IOException{
		int n = readInt();
		a = new int[n-1];
		b = new int[n-1];
		p = new int[n+1];
		size = new long[2][n+1];
		adj = new ArrayList[2][n+1];
		long ans = 0, high = 0;

		for(int i = 1; i <= n; i++){
			p[i] = readInt();
			adj[0][i] = new ArrayList<>();
			adj[1][i] = new ArrayList<>();
		}

		for(int i = 0; i < n-1; i++){
			a[i] = readInt();
			b[i] = readInt();
			adj[0][a[i]].add(b[i]);
			adj[1][b[i]].add(a[i]);
		}
		
		for(int i = 1; i <= n; i++){
			ans += p[i]*(dfs(0, i)-1);
			dfs(1, i);
		}

		for(int i = 0; i < n-1; i++){
			high = Math.max(high, (size[0][a[i]] - size[0][b[i]])*(size[1][b[i]] - size[1][a[i]]));
		}
		System.out.println(ans+high);
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