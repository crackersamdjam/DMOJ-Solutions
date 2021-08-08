import java.io.*;
import java.util.*;
public class Main {
    static boolean[][] vis;
    static int cnt = 0;
    static int r, c;
    static boolean[][] map;
    public static void bfs(point cur){
        cnt++;
        vis[cur.r][cur.c] = true;
        if(cur.r > 0 && map[cur.r-1][cur.c] && !vis[cur.r-1][cur.c]) bfs(new point(cur.r-1, cur.c));
        if(cur.r < r-1 && map[cur.r+1][cur.c] &&!vis[cur.r+1][cur.c]) bfs(new point(cur.r+1, cur.c));
        if(cur.c > 0 && map[cur.r][cur.c-1] &&!vis[cur.r][cur.c-1]) bfs(new point(cur.r, cur.c-1));
        if(cur.c < c-1 && map[cur.r][cur.c+1] && !vis[cur.r][cur.c+1]) bfs(new point(cur.r, cur.c+1));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        r = Integer.parseInt(in.readLine());
        c = Integer.parseInt(in.readLine());
        map = new boolean[r][c];
        vis = new boolean[r][c];
        for(int i = 0; i < r; i++){
            String str = in.readLine();
            for(int j = 0; j < c; j++){
                if(str.charAt(j) == '.') map[i][j] = true;
                else map[i][j] = false;
            }
        }
        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(!vis[i][j] && map[i][j]) {
                    bfs(new point(i, j));
                    list.add(cnt);
                    cnt = 0;
                }
            }
        }
        int room = 0;
        Collections.sort(list);
        while(!list.isEmpty()){
            int u = list.get(list.size()-1);
            list.remove(list.size()-1);
            if(n >= u){
                n-=u;
                room++;
            }else break;
        }
        if(room == 1) System.out.print(room + " room, " + n + "  square metre(s) left over");
        else System.out.print(room + " rooms, " + n + "  square metre(s) left over");
    }
    static class point{
        int r, c;
        public point(int a, int b){
            r = a;
            c = b;
        }
    }
}