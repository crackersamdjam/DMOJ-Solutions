import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{

    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        String str = in.readLine().toLowerCase();

        if(str.length() < 9)
            System.out.println("other user");
        else if(str.equals("darcy_liu"))
            System.out.println("real");
        else if(str.startsWith("darcy") && str.endsWith("liu")){
            for(int i = 5; i < str.length()-3; i++){
                if(str.charAt(i) != '_'){
                    System.out.println("other user");
                    return;
                }
            }
            System.out.println("fake");
        }
        else
            System.out.println("other user");
    }
}