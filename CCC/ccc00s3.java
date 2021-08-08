import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static ArrayList<Integer>[] adj = new ArrayList[102];
    static HashMap<String, Integer> name = new HashMap<>();
    static String[] names = new String[102];
    public static void main(String[] args) throws IOException{
        for(int i = 0; i < 102; i++) adj[i] = new ArrayList<>();
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine().trim());
        int cnt = 0;
        for(int nu = 0; nu < n; nu++){
            String site = in.readLine();
            int cur;
            if(name.containsKey(site)){
                cur = name.get(site);
            }else{
                cur = cnt; name.put(site, cnt); names[cur] = site; cnt++;
            }
            site = in.readLine();
            while(!site.equals("</HTML>")){
                int st = site.indexOf ("<A HREF=\"");
                while (st >= 0) {
                    int end = site.indexOf ("\">", st + 9);
                    String to = site.substring (st + 9, end);
                    System.out.println("Link from " + names[cur] + " to " + to);
                    int nx;
                    if(name.containsKey(to)){
                        nx = name.get(to);
                    }else{
                        nx = cnt; name.put(to, cnt); names[cnt] = to; cnt++;
                    }
                    adj[cur].add(nx);
                    site = site.substring (end + 2);
                    st = site.indexOf ("<A HREF=\"");
                }
                site = in.readLine();
            }
        }
        while(true){
            String link = in.readLine();
            if(link.equals("The End")) break;
            String link2 = in.readLine();
            int a = name.get(link);
            int b = name.get(link2);
            System.out.println(bfs(a, b) ? "Can surf from " + link + " to " + link2 +"." : "Can't surf from " + link + " to " + link2 +".");
        }
    }
    static boolean bfs(int a, int b){
        boolean[] vis = new boolean[102];
        vis[a] = true;
        Queue<Integer> q = new LinkedList<>();
        q.add(a);
        while(!q.isEmpty()){
            int u = q.poll();
            if(u == b) return true;
            for(int v: adj[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.add(v);
                }
            }
        }
        return false;
    }
}