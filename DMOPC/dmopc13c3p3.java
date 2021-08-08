import java.util.*;
import java.io.*;
public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] srt = in.readLine().split(" ");
        int n = Integer.parseInt(srt[0]), h = Integer.parseInt(srt[1]);
        int[][] field = new int[n][n];
        for(int i = 0; i < n; i++){
            String[] str = in.readLine().split(" ");
            for(int j = 0; j < n; j++){
                field[i][j] = Integer.parseInt(str[j]);
            }
        }
        boolean[][] vis = new boolean[n][n];
        Queue<point> Q = new LinkedList<>();
        Q.add(new point(0,0));
        while(!Q.isEmpty()){
            point cur = Q.poll();
            if(cur.x!=0 && !vis[cur.x-1][cur.y] && Math.abs(field[cur.x][cur.y] - field[cur.x-1][cur.y]) <= h){
                Q.add(new point(cur.x-1, cur.y));
                vis[cur.x-1][cur.y] = true;
            }
            if(cur.x!=n-1 && !vis[cur.x+1][cur.y] && Math.abs(field[cur.x][cur.y] - field[cur.x+1][cur.y]) <= h){
                Q.add(new point(cur.x+1, cur.y));
                vis[cur.x+1][cur.y] = true;
            }
            if(cur.y!=0 && !vis[cur.x][cur.y-1] && Math.abs(field[cur.x][cur.y] - field[cur.x][cur.y-1]) <= h){
                Q.add(new point(cur.x, cur.y-1));
                vis[cur.x][cur.y-1] = true;
            }
            if(cur.y!=n-1 && !vis[cur.x][cur.y+1] && Math.abs(field[cur.x][cur.y] - field[cur.x][cur.y+1]) <= h) {
                Q.add(new point(cur.x, cur.y + 1));
                vis[cur.x][cur.y + 1] = true;
            }
        }
        if(vis[n-1][n-1]) System.out.println("yes");
        else System.out.println("no");
    }
    static class point{
        int x, y;
        public point(int x, int y){
            this.x = x; this.y = y;
        }
    }
}