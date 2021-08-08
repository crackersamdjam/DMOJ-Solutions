import java.util.*;
import java.io.*;
public class Main {
/*
Since test cases are small, can try to remove every edge and test if works
BFS complexity of O(Edges), so doing that for each edge is EOE == O(E^2)
 */
public static ArrayList<Integer> remove(Object obj, ArrayList<Integer> a){
    a.remove(obj);
    return a;
}
public static boolean check(edge e, ArrayList<edge> a){
    for(edge i: a){
        if(i.a == e.a && i.b == e.b) return true;
    }
    return false;
}

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        for(int i = 0; i < 5; i++) {
            int n = Integer.parseInt(in.readLine());
            int m = Integer.parseInt(in.readLine());
            ArrayList<Integer>[] adj = new ArrayList[n+1];
            for(int j = 0; j <= n; j++){
                adj[j] = new ArrayList<>();
            }
            for(int j = 0; j < m; j++){
                String[] str = in.readLine().split(" ");
                int a = Integer.parseInt(str[0]), b = Integer.parseInt(str[1]);
                adj[a].add(b); adj[b].add(a);
            }
            ArrayList<edge> e = new ArrayList<>();
            HashSet<Integer> ax = new HashSet<>();
            HashSet<Integer> bx = new HashSet<>();
            for(int j = 1; j <= n; j++) {
                for(int z = 0; z < adj[j].size(); z++) {
                    int k = adj[j].get(z);
                    boolean[] vis = new boolean[n + 1];
                    Queue<Integer> Q = new LinkedList<>();
                    //adj[j].remove(z);
                    //adj[k].remove(j);
                    remove(j, adj[k]);
                    remove(k, adj[j]);
                    Q.add(1);
                    vis[1] = true;
                    while(!Q.isEmpty()){
                        int cur = Q.poll();
                        for(int a: adj[cur]){
                            if(!vis[a]){
                                vis[a] = true;
                                Q.add(a);
                            }
                        }
                    }

                    boolean is = true;
                    for(int l = 1; l < vis.length; l++){
                        if(vis[l] != true){
                            is = false;
                            //System.out.println(l);
                            break;
                        }
                    }

                    edge a = new edge(j, k);
                    edge b = new edge(k, j);
                    if(!is){
                        if(!check(a, e) && !check(b, e)) {
                            e.add(a);
                            e.add(b);
                        }
                        /*if(!ax.contains(j) || !bx.contains(k)){
                            if(!ax.contains(k) || !bx.contains(j)){
                                ax.add(j);
                                bx.add(k);
                            }
                        }*/
                        //num.add(new edge(j, k));
                        //num.add(new edge(k, j));
                    }
                    adj[j].add(k);
                    adj[k].add(j);
                }
            }
            System.out.println(e.size()/2);
        }
    }
    static class edge{
        int a, b;
        public edge(int a, int b){
            this.a = a;
            this.b = b;
        }
    }
}

/*    5
1 2 3 4
  1 3
 */