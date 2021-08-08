import java.util.*;
import java.io.*;
public class Main {
static int n;
static ArrayList<Integer>[] adj;

    public static int[] bfs(int a){
        Queue<Integer> Q = new LinkedList<>();
        Q.add(a);
        boolean[] vis = new boolean[n+1];
        vis[a] = true;
        int[] dis = new int[n+1];
        dis[a] = 0;
        while(!Q.isEmpty()){
            int cur = Q.poll();
            for(int i: adj[cur]){
                if(!vis[i]){
                    vis[i] = true;
                    Q.add(i);
                    dis[i] = dis[cur] + 1;
                }
            }
        }
        return dis;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] fst = in.readLine().split(" ");
        n = Integer.parseInt(fst[0]);
        int m = Integer.parseInt(fst[1]), t = Integer.parseInt(fst[2]);
        adj = new ArrayList[n+1];
        for(int i = 1; i <= n; i++){
            adj[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++){
            String[] ml = in.readLine().split(" ");
            int a = Integer.parseInt(ml[0]); int b = Integer.parseInt(ml[1]);
            adj[a].add(b);
        }
        int q = Integer.parseInt(in.readLine());
        boolean[] hasDone = new boolean[n+1];
        int[][] ans = new int[n+1][n+1];
        for(int i = 0; i < q; i++){
            String[] ql = in.readLine().split(" ");
            int a = Integer.parseInt(ql[0]); int b = Integer.parseInt(ql[1]);
            if(!hasDone[a]){
                hasDone[a] = true;
                ans[a] = bfs(a);
                //for(int j = 0; j < ans[a].length; j++) System.out.println(a + " to " + j + " is " + ans[a][j]);
            }
            if(ans[a][b] == 0) System.out.println("Not enough hallways!");
            else System.out.println(ans[a][b]*t);
        }
    }
}