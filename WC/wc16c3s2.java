import java.util.*;
import java.io.*;
public class wc16c3s2{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	

	public static void main(String[] args) throws IOException{
		int n = readInt();
		int m = readInt();
		ArrayList<Edge>[] adj = new ArrayList[n+1];
		long[] time = new long[n+1];

		for(int i = 1; i <= n; i++){
			time[i] = readLong();
			adj[i] = new ArrayList<Edge>();
		}
		for(int i = 0; i < m; i++){
			int a = readInt();
			int b = readInt();
			int c = readInt();
			adj[a].add(new Edge(b, c));
			adj[b].add(new Edge(a, c));
		}
		int[] best = new int[n+1];
		Arrays.fill(best, Integer.MAX_VALUE);

		PriorityQueue<Edge> q = new PriorityQueue<>();
		q.add(new Edge(1, best[1] = 0));
		
		long ans = 0, level = 1, cost = time[1];

		while(!q.isEmpty()){
			Edge e = q.poll();
			int cur = e.u;
			if(e.d > best[cur])
				continue;

			if(e.d > level){
				ans += (e.d-level)*cost;
				level = e.d;
			}
			cost = Math.min(cost, time[cur]);

			if(cur == n){
				System.out.println(ans);
				return;
			}

			for(Edge ee: adj[cur]){
				if(ee.d < best[ee.u]){
					best[ee.u] = ee.d;
					q.add(ee);
				}
			}
		}
		System.out.println(-1);
	}

	static class Edge implements Comparable<Edge>{
		int u, d;
		Edge(int _u, int _d){
			u = _u;
			d = _d;
		}
		public int compareTo(Edge o){
			return d-o.d;
		}
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