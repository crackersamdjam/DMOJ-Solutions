import java.util.*;
import java.io.*;
public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        for(int nn = 0; nn < t; nn++) {
            String[] s1 = in.readLine().split(" ");
            int l = Integer.parseInt(s1[0]), w = Integer.parseInt(s1[1]);
            char[][] map = new char[w][l];
            point cp = new point(0,0);
            for (int i = 0; i < w; i++) {
                String str = in.readLine();
                for (int j = 0; j < l; j++) {
                    map[i][j] = str.charAt(j);
                    if(map[i][j] == 'C') {
                        cp.x = i;
                        cp.y = j;
                    }
                }
            }
            Queue<point> Q = new LinkedList<>();
            Q.add(cp);
            int[][] dis = new int[w][l];
            dis[cp.x][cp.y] = 0;
            int d = Integer.MAX_VALUE;
            while(!Q.isEmpty()){
                point cur = Q.poll();
                //System.out.println(cur.x + " " + cur.y + " " + map[cur.x][cur.y] + " " + dis[cur.x][cur.y]);
                if(map[cur.x][cur.y] == 'W'){
                    d = dis[cur.x][cur.y];
                }
                if(cur.x > 0 && map[cur.x-1][cur.y] != 'X' && dis[cur.x-1][cur.y] == 0){
                    Q.add(new point(cur.x-1, cur.y));
                    dis[cur.x-1][cur.y] = dis[cur.x][cur.y] + 1;
                }
                if(cur.x < w-1 && map[cur.x+1][cur.y] != 'X' && dis[cur.x+1][cur.y] == 0){
                    Q.add(new point(cur.x+1, cur.y));
                    dis[cur.x+1][cur.y] = dis[cur.x][cur.y] + 1;
                }
                if(cur.y > 0 && map[cur.x][cur.y-1] != 'X' && dis[cur.x][cur.y-1] == 0){
                    Q.add(new point(cur.x, cur.y-1));
                    dis[cur.x][cur.y-1] = dis[cur.x][cur.y] + 1;
                }
                if(cur.y < l-1 && map[cur.x][cur.y+1] != 'X' && dis[cur.x][cur.y+1] == 0){
                    Q.add(new point(cur.x, cur.y+1));
                    dis[cur.x][cur.y+1] = dis[cur.x][cur.y] + 1;
                }
            }
            if(d < 60) System.out.println(d);
            else System.out.println("#notworth");
            }
        }

    static class point{
        int x, y;
        public point(int x, int y){
            this.x = x; this.y = y;
        }
    }
}