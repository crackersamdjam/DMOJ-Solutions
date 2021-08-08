import java.util.*;
import java.io.*;
public class Main {
static ArrayList<Integer>[] adj = new ArrayList[8];
static int[] vis = new int[8];
static boolean[] done = new boolean[8];
static TreeSet<Integer> next = new TreeSet<>();
static boolean cycle = false;
static Queue<Integer> q = new LinkedList<>();
    static void dfs(int cur){
        if(cycle) return;
        vis[cur] = 1;
        if(adj[cur].size()==0)
            next.add(cur);
        else{
            for(int i: adj[cur]){
                if(vis[i] == 0)
                    dfs(i);
                else if(vis[i] == 1){
                    cycle = true;
                    return;
                }
            }
        }
        vis[cur] = 2;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        for(int i = 1; i < 8; i++)
            adj[i] = new ArrayList<>();
        adj[7].add(1); adj[4].add(1); adj[1].add(2); adj[4].add(3);
        adj[5].add(3);
        while(true){
            int a = Integer.parseInt(in.readLine()), b = Integer.parseInt(in.readLine());
            if(a==0 && b ==0) break;
            adj[b].add(a);
        }
        while(!cycle){
            for(int i = 1; i <= 7; i++){
                if(vis[i]==0 && !done[i]){
                    dfs(i);
                }
            }
            if(cycle) break;
            int rm = next.pollFirst();
            done[rm] = true;
            q.add(rm);
            for(int i = 1; i < 8; i++)
                if(adj[i].contains(rm)) {
                    adj[i].remove(adj[i].indexOf(rm));
                }
            boolean check = true;
            for(int i = 1; i < 8; i++){
                if(!done[i]){
                    check = false;
                    break;
                }
            }
            if(check) break;
            next.clear();
            Arrays.fill(vis, 0);
        }
        if(cycle) System.out.println("Cannot complete these tasks. Going to bed.");
        else{
            System.out.print(q.poll());
            while(!q.isEmpty())
                System.out.print(" "+q.poll());
        }
    }
}