import java.util.*;
import java.io.*;
public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String str = in.readLine();
        long n;
        if(str.length()>9) n = 100000;
        else n = Integer.parseInt(str);
        long[] list = {0, 9, 18, 108, 198, 1098, 1998, 10998, 19998, 109998, 199998, 1099998, 1999998, 10999998, 19999998, 109999998, 199999998, 1099999998, 1999999998};
        if (n > list.length - 1) System.out.println(999999998);
        else{
            int m = (int) n;
            System.out.println(list[m]);
        }
    }
}