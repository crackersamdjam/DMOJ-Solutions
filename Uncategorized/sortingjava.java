import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = readInt();
        Integer[] arr = new Integer[N];
        for(int i = 0; i < N; i++)
            arr[i] = readInt();
        Arrays.sort(arr);
        long ret = 0;
        for(int i = 0; i < arr.length; i++) {
            ret = (3137 * ret + arr[i]) % 1000000007;
        }
        System.out.println(ret);
    }
    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
}