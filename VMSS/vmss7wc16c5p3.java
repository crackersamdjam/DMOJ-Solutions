import java.util.*;
public class Main {
    static int n, Len = 0, far = 0;
    static ArrayList<Integer>[] adj;

    public static void bfs(int st){
        Queue<Integer> Q = new LinkedList<>();
        int dis[] = new int[n+1];
        boolean vis[] = new boolean[n+1];
        Len = 0;
        far = 0;
        Q.add(st);
        vis[st] = true;
        while(!Q.isEmpty()){
            int cur = Q.poll();
            if(dis[cur] > Len){
                Len = dis[cur];
                far = cur;
            }
            for(int v: adj[cur]){
                if(!vis[v]){
                    vis[v] = true;
                    Q.add(v);
                    dis[v] = dis[cur]+1;
                }
            }
        }
    }


    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        adj = new ArrayList[n+1];
        int[] len = new int[n+1];
        boolean[] vis = new boolean[n+1];
        for(int i = 0; i <= n; i++){
            adj[i] = new ArrayList<Integer>();
        }
        for(int i = 1; i < n; i++){
            int a = input.nextInt(), b = input.nextInt();
            adj[a].add(b); adj[b].add(a);
        }

        bfs(1);
        bfs(far);
        System.out.println(Len);

    }
}