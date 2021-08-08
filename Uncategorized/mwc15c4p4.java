import java.util.*;
public class Main {

    public static void main(String[] args) {
	Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        ArrayList<Integer>[] adj = new ArrayList[1001];
        for(int i = 0; i < 1001; i++){
            adj[i] = new ArrayList<Integer>();
        }
        for(int i = 1; i <= n; i++){
            int a = input.nextInt(), b = input.nextInt();
            adj[a].add(b);
        }
        int st = input.nextInt();
        int ed = input.nextInt();
        Queue<Integer> Q = new LinkedList<Integer>();
        boolean vis[] = new boolean[1001];
        Q.add(st);
        vis[st] = true;
        while(!Q.isEmpty()){
            int cur = Q.poll();
            for(int v: adj[cur]){
                if(!vis[v]){
                    Q.add(v);
                    vis[v] = true;
                }
            }
        }
        System.out.println(vis[ed]? "Tangled": "Not Tangled");
    }
}