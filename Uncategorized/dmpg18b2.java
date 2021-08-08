import java.io.*;
public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] str = in.readLine().split(" ");
        int n = Integer.parseInt(str[0]), m = Integer.parseInt(str[1]);
        System.out.println(n>=m ? m-1 : n);
    }
}