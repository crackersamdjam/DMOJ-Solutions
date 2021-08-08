import java.util.*;

public class test{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt();
        int[] dis = new int[n+1];
        ArrayList<Edge>[] adj = new ArrayList[n+1];
        for(int i = 0; i <= n; i++){
            dis[i] = Integer.MAX_VALUE;
            adj[i] = new ArrayList();
        }
        for(int i = 0,a,b,c; i < m; i++){
            a = in.nextInt();
            b = in.nextInt();
            c = in.nextInt();
            adj[a].add(new Edge(b, c));
            adj[b].add(new Edge(a, c));
        }

        PriorityQueue<Edge> q = new PriorityQueue();
        dis[1] = 0;
        q.add(new Edge(1, 0));
        while(!q.isEmpty()){
            Edge rm = q.poll();
            int cur = rm.node;
            if(rm.dis > dis[cur])
                continue;

            for(Edge e: adj[cur]){
                if(dis[cur] + e.dis < dis[e.node]){
                    dis[e.node] = dis[cur] + e.dis;
                    q.add(new Edge(e.node, dis[e.node]));
                }
            }
        }

        for(int i = 1; i <= n; i++){
            if(dis[i] == Integer.MAX_VALUE)
                dis[i] = -1;
            System.out.println(dis[i]);
        }
    }


    static class Edge implements Comparable<Edge>{
        int node, dis;
        Edge(int _node, int _dis){
            node = _node;
            dis = _dis;
        }
        public int compareTo(Edge o){
            return Integer.compare(dis, o.dis);
        }
    }
}