import java.util.*;
import java.io.*;
public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        TreeSet<Integer> map = new TreeSet<>();
        for(int i = 0; i < n; i++){
            map.add(Integer.parseInt(in.readLine()));
        }
        for(int i = 0; i < n; i++){
            System.out.println(map.pollFirst());
        }
    }
}