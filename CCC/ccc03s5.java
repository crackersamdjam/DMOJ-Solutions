import java.util.*;
import java.io.*;
public class ccc03s5{

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static String next() throws IOException{
		while(st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	
	static int readInt() throws IOException{
		return Integer.parseInt(next());
	}
	
	static ArrayList<Edge>[] adj;
	static int[] par;
	static boolean[] dest;
	static int ans = Integer.MAX_VALUE;

	static int find(int x){
		while(x != par[x]){
			x = par[x];
			par[x] = par[par[x]];
		}
		return x;
	}

	static boolean dfs(int cur, int pre, int w){
		boolean t = dest[cur];
		for(Edge e: adj[cur]){
			if(e.a != pre)
				t |= dfs(e.a, cur, e.b);
		}
		if(t) ans = Math.min(ans, w);
		return t;
	}

	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(System.in);
		int n = readInt(), m = readInt(), d = readInt();
		adj = new ArrayList[n+1];
		par = new int[n+1];
		for(int i = 1; i <= n; i++){
			adj[i] = new ArrayList<Edge>();
			par[i] = i;
		}

		Edge[] e = new Edge[m];;
		for(int i = 0,a,b,c; i < m; i++){
			a = readInt();
			b = readInt();
			c = readInt();
			e[i] = new Edge(a, b, c);
		}
		Arrays.sort(e);
		for(int i = 0; i < m; i++){
			int fa = find(e[i].a), fb = find(e[i].b);
			if(fa != fb){
				par[fa] = fb;
				adj[e[i].a].add(new Edge(e[i].b, e[i].c, 0));
				adj[e[i].b].add(new Edge(e[i].a, e[i].c, 0));
			}
		}

		dest = new boolean[n+1];
		for(int i = 0,a; i < d; i++){
			a = readInt();
			dest[a] = true;
		}

		dfs(1, 0, ans);
		System.out.println(ans);
	}

	static class Edge implements Comparable<Edge>{
		int a, b, c;
		Edge(int _a, int _b, int _c){
			a = _a; b = _b; c = _c;
		}
		public int compareTo(Edge o){
			return o.c-c;
		}
	}
}