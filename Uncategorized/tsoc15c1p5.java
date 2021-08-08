import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt();
        ArrayList<Integer>[] adj = new ArrayList[n+1];
        int[] dis = new int[n+1];
        boolean[] vis = new boolean[n+1];
        boolean[] ant = new boolean[n+1];
        for(int i = 1; i<= n; i++){
            adj[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++){
            int a = in.nextInt(), b = in.nextInt();
            adj[a].add(b);
            adj[b].add(a);
        }
        int w = in.nextInt();
        ArrayList<Integer> ants = new ArrayList<>();
        for(int i = 0; i < w; i++){
            int aaa = in.nextInt();
            ants.add(aaa);
            ant[aaa] = true;
        }
        int t = 1, low = Integer.MAX_VALUE;
        boolean canReach = false;
        Queue<Integer> Q = new LinkedList<>();
        Q.add(1);
        vis[1] = true;
        dis[1] = 0;
        Outer:
        while(!Q.isEmpty()){
            int cur = Q.poll();
            vis[cur] = true;
            for(int i: adj[cur]){
                if(i==n && !ant[i]){
                    canReach = true;
                    dis[i] = dis[cur]+1;
                    low = dis[i];
                    //System.out.println(i + " " + dis[i]);
                    //break Outer;
                }
                if(!vis[i] && !ant[i]){
                    vis[i] = true;
                    dis[i] = dis[cur]+1;
                    //System.out.println(i + " " + dis[i] + " last " + cur + " was " + dis[cur]);
                    Q.add(i);
                }
            }
            if(t%4==0){
                ArrayList<Integer> add = new ArrayList<>();
                for(int an: ants){
                    for(int i: adj[an]){
                        ant[i] = true;
                        //ants.add(i);
                        add.add(i);
                    }
                }
                ants.clear();
                for(int nx: add){
                    ants.add(nx);
                }
                add.clear();
            }
            t++;
        }
        if(canReach) System.out.println(low);
        else System.out.println("sacrifice bobhob314");
    }
}