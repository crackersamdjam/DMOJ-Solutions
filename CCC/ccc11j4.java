import java.util.Scanner;
public class CCC11J4 {
    
    public static void printDanger(int x, int y){
        System.out.println(x-200 + " " + y*-1 + " DANGER");
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        boolean[][] map = new boolean[400][201];
        for(int i = 1; i < 3; i++){
            map[200][i] = true;
        }
        for(int i = 200; i < 203; i++){
            map[i][3] = true;
        }
        for(int i = 3; i < 5; i++){
            map[203][i] = true;
        }
        for(int i = 203; i < 205; i++){
            map[i][5] = true;
        }
        for(int i = 5; i > 3; i--){
            map[205][i] = true;
        }
        for(int i = 205; i < 207; i++){
            map[i][3] = true;
        }
        for(int i = 3; i < 7; i++){
            map[207][i] = true;
        }
        for(int i = 207; i > 199; i--){
            map[i][7] = true;
        }
        for(int i = 7; i >= 5; i--){
            map[199][i] = true;
        }
        
        
        
        
        int x = 199;
        int y = 5;
        /*
        y is positive instead of negative
        x is [0-400]
        0 is 200
        */
        Outer:
        while(true){
            String str = input.next();
            if(str.equals("q")) break Outer;
            int n = input.nextInt();
            switch (str) {
                case "d":
                    for(int i = y+1; i <= y+n; i++){
                        if(map[x][i]==true){
                            printDanger(x,y+n);
                            break Outer;
                        }
                        map[x][i] = true;
                    }
                    y+=n;
                    break;
                case "u":
                    for(int i = y-1; i >= y-n; i--){
                        if(map[x][i]==true){
                            printDanger(x,y-n);
                            break Outer;
                        }
                        map[x][i] = true;
                    }
                    y-=n;
                    break;
                case "l":
                    for(int i = x-1; i >= x-n; i--){
                        if(map[i][y]==true){
                            printDanger(x-n,y);
                            break Outer;
                        }
                        map[i][y] = true;
                    }
                    x-=n;
                    break;
                case "r":
                    for(int i = x+1; i <= x+n; i++){
                        if(map[i][y]==true){
                            printDanger(x+n,y);
                            break Outer;
                        }
                        map[i][y] = true;
                    }
                    x+=n;
                    break;
                default:
                    break;
            }
            System.out.println(x-200 + " " + y*-1 + " safe");
        }
    }
    
}