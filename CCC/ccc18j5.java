import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        ArrayList<Integer>[] adj = new ArrayList[n+1];
        for(int i = 1; i <= n; i++){
            adj[i] = new ArrayList<>();
        }
        for(int i = 1; i <= n; i++){
            int m = in.nextInt();
            //System.out.println(i + " has " + m);
            if(m == 0) adj[i].add(0);
            else
            for(int j = 0; j < m; j++){
                int a = in.nextInt();
                //System.out.println(i + " adds " + a);
                adj[i].add(a);
            }
        }
        boolean[] vis = new boolean[n+1];
        int[] dis = new int[n+1];
        Queue<Integer> Q = new LinkedList<>();
        Q.add(1);
        vis[1] = true;
        dis[1] = 1;
        int low = Integer.MAX_VALUE;
        while(!Q.isEmpty()){
            int cur = Q.poll();
            vis[cur] = true;
            if(cur==0) low = Math.min(low, dis[cur]);
            else
            for(int i: adj[cur]){
                if(!vis[i]){
                    Q.add(i);
                    vis[i] = true;
                    dis[i] = dis[cur]+1;
                }
            }
        }
        boolean reach = true;
        for(int i = 1; i <= n; i++){
            if(!vis[i]) reach = false;
        }
        if(reach) System.out.println("Y");
        else System.out.println("N");
        System.out.println(low-1);
    }
}