import java.io.*;
import java.util.*;

public class test {
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main (String [] args) throws IOException{
       int n = nextInt();
       String inst = nextLine();
       char[][] grid = new char[2*n + 1][n];
       for(int i = 0;i < 2*n + 1;i++){
           for(int j = 0;j < n;j++){
               grid[i][j] = '.';
           }
       }
       int lowest = 0;
       int highest = 9999;
       int y = n;
       for(int i = 0;i < inst.length();i++){
           if(inst.charAt(i) == '>'){
               grid[y][i] = '_';
               if(y > lowest)lowest = y;
               if(y < highest)highest = y;
           }else if(inst.charAt(i) == 'v'){
               y++;
               grid[y][i] = '\\';
               if(y > lowest)lowest = y;
               if(y < highest)highest = y;
           }else if(inst.charAt(i) == '^'){
               grid[y][i] = '/';
               if(y > lowest)lowest = y;
               if(y < highest)highest = y;
               y--;
           }
       }
       for(int i = highest; i <= lowest;i++){
           for(int j = 0;j < n;j++){
               System.out.print(grid[i][j]);
           }
           System.out.println();
       }
    }
	
    static String next() throws IOException {
	while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(in.readLine().trim());
        return st.nextToken();
            
    }

    static int nextInt() throws IOException {
	return Integer.parseInt(next());
    }
    
    static long nextLong() throws IOException {
	return Long.parseLong(next());
    }

    static double nextDouble() throws IOException {
	return Double.parseDouble(next());
    }

    static String nextLine() throws IOException {
	return in.readLine().trim();
    }
    
}