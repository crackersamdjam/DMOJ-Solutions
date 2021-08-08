import java.util.*;
import java.io.*;
public class dmopc17c4p3{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Edge>[] adj;
	static long[] dis;
	static int far = 1;

	static void dfs(int cur, int pre){
		if(dis[cur] > dis[far])
			far = cur;
		for(Edge e: adj[cur]){
			if(e.u != pre){
				dis[e.u] = dis[cur]+e.w;
				dfs(e.u, cur);
			}
		}
	}

	static void go(int u){
		dis[u] = 0;
		dfs(u, 0);
	}

	public static void main(String[] args) throws IOException{
		int n = readInt();
		adj = new ArrayList[n+1];
		dis = new long[n+1];
		for(int i = 1; i <= n; i++)
			adj[i] = new ArrayList<>();
		
		for(int i = 0,a,b,c; i < n-1; i++){
			a = readInt();
			b = readInt();
			c = readInt();
			adj[a].add(new Edge(b, c));	
			adj[b].add(new Edge(a, c));	
		}

		long ans = 0;
		go(1);

		int a = far;
		go(a);
		int b = far;
		for(int i = 1; i <= n; i++)
			if(i != b)
				ans = Math.max(ans, dis[i]);

		go(b);
		for(int i = 1; i <= n; i++)
			if(i != a)
				ans = Math.max(ans, dis[i]);
		System.out.println(ans);
	}

	static class Edge{
		int u, w;
		Edge(int _u, int _w){
			u = _u; w = _w;
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