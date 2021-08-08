import java.util.*;
public class CCC16J4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String time = in.next();
        int h = Integer.parseInt(time.substring(0, 2));
        int s = Integer.parseInt(time.substring(3, 5));
        int t = h*60 + s;
        while(t>=24*60){
            t-=24*60;
        }
        for(int i = 0; i < 240; t++){
            if(t >= 7*60 && t < 10*60) i++;
            else if(t >= 15*60 && t < 19*60) i++;
            else i+=2;
        }
        while(t>=24*60){
            t-=24*60;
        }
        System.out.printf("%02d:%02d\n", t/60, t%60);
    }
}