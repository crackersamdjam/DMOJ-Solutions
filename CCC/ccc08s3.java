import java.util.*;
import java.io.*;
public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        for(int i = 0; i < t; i++){
            int r = Integer.parseInt(in.readLine()), c = Integer.parseInt(in.readLine());
            char[][] map = new char[r][c];
            for(int j = 0; j < r; j++){
                String str = in.readLine();
                for(int k = 0; k < c; k++){
                    map[j][k] = str.charAt(k);
                }
            }
            Queue<point> Q = new LinkedList<>();
            Q.add(new point(0,0));
            int[][] dis = new int[r][c];
            dis[0][0] = 1;
            while(!Q.isEmpty()){
                point cur = Q.poll();
                if(cur.x > 0 && map[cur.x-1][cur.y] != '*' && map[cur.x][cur.y] != '-' && dis[cur.x-1][cur.y] == 0){
                    Q.add(new point(cur.x-1, cur.y));
                    dis[cur.x-1][cur.y] = dis[cur.x][cur.y] + 1;
                }
                if(cur.x < r-1 && map[cur.x+1][cur.y] != '*' && map[cur.x][cur.y] != '-' && dis[cur.x+1][cur.y] == 0){
                    Q.add(new point(cur.x+1, cur.y));
                    dis[cur.x+1][cur.y] = dis[cur.x][cur.y] + 1;
                }
                if(cur.y > 0 && map[cur.x][cur.y-1] != '*' && map[cur.x][cur.y] != '|' && dis[cur.x][cur.y-1] == 0){
                    Q.add(new point(cur.x, cur.y-1));
                    dis[cur.x][cur.y-1] = dis[cur.x][cur.y] + 1;
                }
                if(cur.y < c-1 && map[cur.x][cur.y+1] != '*' && map[cur.x][cur.y] != '|' && dis[cur.x][cur.y+1] == 0){
                    Q.add(new point(cur.x, cur.y+1));
                    dis[cur.x][cur.y+1] = dis[cur.x][cur.y] + 1;
                }
            }
            if(dis[r-1][c-1] == 0) System.out.println(-1);
            else System.out.println(dis[r-1][c-1]);
        }
    }

    static class point{
        int x, y;
        public point(int x, int y){
            this.x = x; this.y = y;
        }
    }
}