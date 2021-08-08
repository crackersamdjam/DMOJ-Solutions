import java.io.*;
import java.util.*;
public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int[][] adj = new int[26][26];
        HashSet<String> order = new HashSet<>();
        while(true){
            String str = in.readLine();
            if(str.equals("**")) break;
            int a = str.charAt(0) - 'A';
            int b = str.charAt(1) - 'A';
            adj[a][b] = 1;
            adj[b][a] = 1;
            order.add(str);
        }
        ArrayList<pair> roads = new ArrayList<>();
        for(int i = 0; i < 26; i++){
            for(int j = i; j < 26; j++){
                if(adj[i][j] != 1) continue;
                adj[i][j] = 0;
                adj[j][i] = 0;
                boolean[] vis = new boolean[26];
                int st = 0;
                Outer:
                for(int k = 0; k < 26; k++) {
                    for (int l = 0; l < 26; l++) {
                        if (adj[k][l] == 1) {
                            st = k;
                            break Outer;
                        }
                    }
                }
                Queue<Integer> q = new LinkedList<>();
                q.add(st);
                vis[st] = true;
                while(!q.isEmpty()){
                    int cur = q.poll();
                    for(int k = 0; k < 26; k++) {
                        if(adj[cur][k] == 1 && !vis[k]) {
                            q.add(k);
                            vis[k] = true;
                        }
                    }
                }
                if(!vis[0] || !vis[1]) roads.add(new pair(i, j));
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    for(pair p: roads) {
        String str2 = (char) (p.a + 65) + "" + (char) (p.b + 65);
        if(order.contains(str2))
        System.out.println(str2);
        else System.out.println((char) (p.b + 65) + "" + (char) (p.a + 65));
    }
    System.out.println("There are " + roads.size() + " disconnecting roads.");
    }
    static class pair{
        int a, b;
        pair(int a, int b){
            this.a = a;
            this.b = b;
        }
    }
}