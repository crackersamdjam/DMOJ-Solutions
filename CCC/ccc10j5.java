import java.util.*;
public class Main {


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt();
        Queue<Integer> Qx = new LinkedList<>();
        Qx.add(a);
        Queue<Integer> Qy = new LinkedList<>();
        Qy.add(b);
        boolean[][] vis = new boolean[9][9];
        int[][] dis = new int[9][9];
        dis[a][b] = 0;
        vis[a][b] = true;
        while(true){
            int x = Qx.poll();
            int y = Qy.poll();
            //System.out.println(x + ", " + y + ": " + dis[x][y]);
            vis[x][y] = true;
            if(x==c && y==d){
                System.out.println(dis[x][y]);
                break;
            }
            if(x-2 > 0 && y-1 > 0 && !vis[x-2][y-1]){
                Qx.add(x-2); Qy.add((y-1));
                dis[x-2][y-1] = dis[x][y] + 1;
                vis[x-2][y-1] = true;
            }
            if(x-2 > 0 && y+1 <= 8 && !vis[x-2][y+1]){
                Qx.add(x-2); Qy.add((y+1));
                dis[x-2][y+1] = dis[x][y] + 1;
                vis[x-2][y+1] = true;
            }
            if(x+2 <= 8 && y-1 > 0 && !vis[x+2][y-1]){
                Qx.add(x+2); Qy.add((y-1));
                dis[x+2][y-1] = dis[x][y] + 1;
                vis[x+2][y-1] = true;
            }
            if(x+2 <= 8 && y+1 <= 8 && !vis[x+2][y+1]){
                Qx.add(x+2); Qy.add((y+1));
                dis[x+2][y+1] = dis[x][y] + 1;
                vis[x+2][y+1] = true;
            }
            if(x-1 > 0 && y-1 > 0 && !vis[x-1][y-2]){
                Qx.add(x-1); Qy.add(y-2);
                dis[x-1][y-2] = dis[x][y] + 1;
                vis[x-1][y-2] = true;
            }
            if(x+1 <= 8 && y-2 > 0 && !vis[x+1][y-2]){
                Qx.add(x+1); Qy.add(y-2);
                dis[x+1][y-2] = dis[x][y] + 1;
                vis[x+1][y-2] = true;
            }
            if(x+1 <= 8 && y+2 <= 8 && !vis[x+1][y+2]){
                Qx.add(x+1); Qy.add(y+2);
                dis[x+1][y+2] = dis[x][y] + 1;
                vis[x+1][y+2] = true;
            }
            if(x-1 > 0 && y+2 <= 8 && !vis[x-1][y+2]){
                Qx.add(x-1); Qy.add(y+2);
                dis[x-1][y+2] = dis[x][y] + 1;
                vis[x-1][y+2] = true;
            }
        }
    }
}