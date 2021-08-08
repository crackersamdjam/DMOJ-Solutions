import java.util.*;
import java.io.*;
public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] s1 = in.readLine().split(" ");
        int r = Integer.parseInt(s1[0]), c = Integer.parseInt(s1[1]);
        String[] s2 = in.readLine().split(" ");
        point start = new point(Integer.parseInt(s2[0]), Integer.parseInt(s2[1]));
        String[] s3 = in.readLine().split(" ");
        point office = new point(Integer.parseInt(s3[0]), Integer.parseInt(s3[1]));
        char[][] map = new char[r][c];
        for(int i = 0; i < r; i++){
            String str = in.readLine();
            for(int j = 0; j < c; j++){
                map[i][j] = str.charAt(j);
            }
        }
        int t = Integer.parseInt(in.readLine());
        for(int i = 0; i < t; i++){
            String[] str2 = in.readLine().split(" ");
            map[Integer.parseInt(str2[0])][Integer.parseInt(str2[1])] = 'T';
        }

        boolean[][] vis = new boolean[r][c];
        vis[start.x][start.y] = true;
        int[][] dis = new int[r][c];
        dis[start.x][start.y] = 0;
        Queue<point> Q = new LinkedList<>();
        Q.add(start);
        int td = Integer.MAX_VALUE;
        int wd = Integer.MAX_VALUE;
        while(!Q.isEmpty()){
            point cur = Q.poll();
            if(cur.x == office.x && cur.y == office.y){
                wd = Math.min(wd, dis[cur.x][cur.y]);
            }
            if(map[cur.x][cur.y] == 'T'){
                td = Math.min(td, dis[cur.x][cur.y]);
            }
            if(cur.x != r-1 && !vis[cur.x+1][cur.y] && map[cur.x+1][cur.y] != 'X'){
                vis[cur.x+1][cur.y] = true;
                dis[cur.x+1][cur.y] = dis[cur.x][cur.y] + 1;
                Q.add(new point(cur.x+1, cur.y));
            }
            if(cur.x != 0 && !vis[cur.x-1][cur.y] && map[cur.x-1][cur.y] != 'X'){
                vis[cur.x-1][cur.y] = true;
                dis[cur.x-1][cur.y] = dis[cur.x][cur.y] + 1;
                Q.add(new point(cur.x-1, cur.y));
            }
            if(cur.y != c-1 && !vis[cur.x][cur.y+1] && map[cur.x][cur.y+1] != 'X'){
                vis[cur.x][cur.y+1] = true;
                dis[cur.x][cur.y+1] = dis[cur.x][cur.y] + 1;
                Q.add(new point(cur.x, cur.y+1));
            }
            if(cur.y != 0 && !vis[cur.x][cur.y-1] && map[cur.x][cur.y-1] != 'X'){
                vis[cur.x][cur.y-1] = true;
                dis[cur.x][cur.y-1] = dis[cur.x][cur.y] + 1;
                Q.add(new point(cur.x, cur.y-1));
            }
        }
        System.out.println(wd - td);
    }

    static class point{
        int x, y;
        public point(int x, int y){
            this.x = x; this.y = y;
        }
    }
}