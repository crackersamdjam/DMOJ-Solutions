import java.util.*;
import java.io.*;

public class Main {
    static String[][] sheet = new String[11][10];
    static int[][] num = new int[11][10];
    static int[][] vis = new int[11][10];

    static int dfs(int i, int j){
        //System.out.println(i + " " + j);
        //System.out.println(num[i][j]);
        if(vis[i][j] == 1 && num[i][j] == -1)return -2;
        vis[i][j] = 1;
        String[] places = sheet[i][j].split("\\+");
        int sum = 0;
        //System.out.println(sheet[i][j]);
        boolean any = false;
        for(String str: places){
            //System.out.println(str);
            int x = str.charAt(0) - 'A' + 1;
            //System.out.println(x + " try "+ (str.charAt(1)-'1'+1));
            if(num[x][str.charAt(1)-'1'+1] != -1){
                sum += num[x][str.charAt(1)-'1'+1];
                any = true;
                //System.out.println("sum: "+sum);
            }else{
                //System.out.println("12)");
                //System.out.println("else " +str);
                if(dfs(x, str.charAt(1) - '1' + 1)== -2){
                    //System.out.println("return -2");
                    sum = -2; continue;
                }
                sum += dfs(x, str.charAt(1) - '1' + 1);
            }
        }
        //System.out.println("return: "+sum);
        if(/*any && */sum>=0) {
            num[i][j] = sum;
            return sum;
        }
        return -2;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        for(int i = 1; i <= 10; i++){
            String[] str = in.readLine().split(" ");
            for(int j = 1; j <= 9; j++){
                sheet[i][j] = str[j-1];
                if(str[j-1].charAt(0)-'A'+1 <= 0){
                    num[i][j] = Integer.parseInt(str[j-1]);
                    //System.out.println(i+" "+j+" "+num[i][j]);
                }else{
                    //System.out.println(i+" "+j+" -1");
                    num[i][j] = -1;
                }
            }
        }
        for(int i = 1; i <= 10; i++){
            for(int j = 1; j <= 9; j++){
                if(num[i][j] == -1){
                    for(int k = 1; k <= 10; k++)Arrays.fill(vis[k], 0);
                    num[i][j] = dfs(i, j);
                }
            }
        }
        for(int i = 1; i <= 10; i++){
            for(int j = 1; j <= 9; j++){
                if(num[i][j] == -2) System.out.print("* ");
                else System.out.print(num[i][j] + " ");
            }
            System.out.println();
        }
    }
}