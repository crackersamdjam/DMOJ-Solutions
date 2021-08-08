import java.util.*;
import java.io.*;
public class cco14p2{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int n = readInt();
		int m = readInt();
		int st = readInt();
		int ed = readInt();
		
		ArrayList<Edge>[] adj = new ArrayList[n+1];
		ArrayList<Edge>[] radj = new ArrayList[n+1];
		for(int i = 1; i <= n; i++){
			adj[i] = new ArrayList<>();
			radj[i] = new ArrayList<>();
		}

		int[] dis = new int[n+1];
		int[] rdis = new int[n+1];
		Arrays.fill(dis, Integer.MAX_VALUE/3);		
		Arrays.fill(rdis, Integer.MAX_VALUE/3);

		int[] a = new int[m];
		int[] b = new int[m];
		int[] c = new int[m];
		int[] d = new int[m];

		for(int i = 0; i < m; i++){
			a[i] = readInt();
			b[i] = readInt();
			c[i] = readInt();
			d[i] = readInt();
			adj[a[i]].add(new Edge(b[i], c[i]));
			radj[b[i]].add(new Edge(a[i], c[i]));
		}

		PriorityQueue<Vertex> q = new PriorityQueue<Vertex>();
		q.add(new Vertex(st, dis[st] = 0));
		while(!q.isEmpty()){
			Vertex rm = q.poll();
			int cur = rm.node, curd = rm.dist;
			if(curd > dis[cur])
				continue;
			for(Edge e: adj[cur]){
				if(curd+e.len < dis[e.to]){
					q.add(new Vertex(e.to, dis[e.to] = curd+e.len));
				}
			}
		}

		q.add(new Vertex(ed, rdis[ed] = 0));
		while(!q.isEmpty()){
			Vertex rm = q.poll();
			int cur = rm.node, curd = rm.dist;
			if(curd > rdis[cur])
				continue;
			for(Edge e: radj[cur]){
				if(curd+e.len < rdis[e.to]){
					q.add(new Vertex(e.to, rdis[e.to] = curd+e.len));
				}
			}
		}

		int[] tot = new int[m];
		for(int i = 0; i < m; i++){
			tot[i] = c[i]+dis[a[i]]+rdis[b[i]];
			q.add(new Vertex(d[i], tot[i]));
		}

		int qt = readInt();
		Pair[] qs = new Pair[qt];
		for(int i = 0; i < qt; i++){
			int x = readInt();
			qs[i] = new Pair(x, i);
		}
		Arrays.sort(qs);
		long[] ans = new long[qt];
		long sum = 0;

		for(int i = 0; i < qt; i++){
			while(!q.isEmpty() && q.peek().dist <= qs[i].a)
				sum += q.poll().node;
			ans[qs[i].b] = sum;
		}

		for(int i = 0; i < qt; i++)
			System.out.println(ans[i]);
	}

	static class Edge{
		int to, len;
		Edge(int _to, int _len){
			to = _to;
			len = _len;
		}
	}

	static class Vertex implements Comparable<Vertex>{
		int node, dist;
		Vertex(int _node, int _dist){
			node = _node;
			dist = _dist;
		}
		public int compareTo(Vertex o){
			return this.dist-o.dist;
		}
	}

	static class Pair implements Comparable<Pair>{
		int a, b;
		Pair(int _a, int _b){
			a = _a;
			b = _b;
		}
		public int compareTo(Pair o){
			return this.a-o.a;
		}
	}

	static String next() throws IOException{
		while(st == null || !st.hasMoreTokens())
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