import java.util.*;
import java.io.*;
public class Main {
static ArrayList<Integer>[] adj = new ArrayList[101];
static int[] dis = new int[101];
static int[] vis = new int[101];
static int len = Integer.MIN_VALUE;

static void bfs(int cur, int pre){
    vis[cur] = 1;
    for(int i: adj[cur]){
        /*if(i == pre){
            continue;
        }else */if(vis[i]==0){
            dis[i] = dis[cur]+1;
            vis[i] = 1;
            bfs(i, cur);
        }else if(vis[i]==1){
            len = dis[cur] - dis[i] + 1;
            System.out.println(len);
        }
    }
    vis[cur] = 2;
}

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        for(int i = 0; i < 101; i++) adj[i] = new ArrayList<>();
        for(int i = 0; i < 5; i++){
            int n = Integer.parseInt(in.readLine());
            for(int j = 0; j < n; j++){
                String[] str = in.readLine().split(" ");
                adj[Integer.parseInt(str[0])].add(Integer.parseInt(str[1]));
            }
            /*for(int j = 1; j < vis.length; j++){
                if(!vis[j]){
                    vis[j] = true;
                    dis[j] = 0;
                    len = 0;
                    bfs(j, 0);
                }
            }*/
            bfs(1, 0);

            Arrays.fill(vis, 0);
            Arrays.fill(dis, 0);
            len = 0;
            for(int j = 0; j < 101; j++)
                adj[j].clear();
        }
    }
}