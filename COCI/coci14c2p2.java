import java.util.*;
import java.io.*;
public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        HashMap<String, Integer> hm = new HashMap<String, Integer>();
        for(int i = 0; i < n; i++){
            String str = in.readLine();
            hm.put(str, hm.getOrDefault(str, 0)+1);
        }
        for(int i = 0; i < n-1; i++){
            String str = in.readLine();
            hm.put(str, hm.get(str)-1);
            if(hm.get(str) == 0) hm.remove(str);
        }
        for(String s: hm.keySet()){
            System.out.println(s);
        }
        /*int ans = 0;
        for(int i = 0; i < n; i++){
            ans^=Integer.parseInt(in.readLine());
        }
        for(int i = 0; i < n-1; i++){
            ans^=Integer.parseInt(in.readLine());
        }
        System.out.println(String.valueOf(ans));*/
    }
}