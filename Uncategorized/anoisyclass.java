import java.util.*;
import java.io.*;
public class Main {
    static ArrayList<Integer>[] adj = new ArrayList[10001];

    //static int[] vis = new int[10001];
    //static boolean cycle = false;
    /*static void dfs(int cur){
        if(cycle) return;

        vis[cur] = 1;
        for(int i: adj[cur]){
            if(vis[i] == 0) dfs(i);
            else if(vis[i] == 1){
                cycle = true;
                return;
            }
        }
        vis[cur] = 2;
        return;
    }*/

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        int m = Integer.parseInt(in.readLine());
        int[] indeg = new int[n+1];
        for(int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
        for(int i = 0, a, b; i < m; i++){
            String str[] = in.readLine().split(" ");
            a = Integer.parseInt(str[0]);
            b = Integer.parseInt(str[1]);
            adj[a].add(b);
            indeg[b]++;
        }
        int cnt = 0;
        Queue<Integer> q = new LinkedList<>();
        for(int i = 1; i <= n; i++) if(indeg[i] == 0) q.add(i);
        while(!q.isEmpty()){
            int i = q.poll(); cnt++;
            for(int j: adj[i]){
                indeg[j]--;
                if(indeg[j] == 0) q.add(j);
            }
        }
        System.out.println(cnt == n ? "Y" : "N");
        //n
        /*for(int i = 1; i <= n; i++) {
            if(cycle) break;
            if(vis[i] == 0) dfs(i);
        }
        System.out.println(!cycle ? "Y" : "N");*/
    }
}