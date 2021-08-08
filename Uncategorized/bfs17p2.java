import java.util.*;
import java.io.*;
public class Main {
  public static void main(String[] args)throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(in.readLine());
    int[] c = new int[6];
    String[] str = in.readLine().split(" ");
    for(int i = 0; i < str.length; i++){
      String s = str[i];
      switch(s){
        case "red":
          c[0]++;
          break;
          case "orange":
            c[1]++;
            break;
            case "yellow":
              c[2]++;
              break;
            case "green":
              c[3]++;
              break;
              case "blue":
                c[4]++;
                break;
                case "black":
                  c[5]++;
                  break;
      }
    }
    int max = Integer.MIN_VALUE;
    int col = -1;
    for(int i = 0; i < 6; i++){
      if(c[i] > max){
         max = c[i]; col = i;
      }
    }
    int sum = 0;
    for(int i = 0; i < 6; i++){
      if(i != col){
        sum+= c[i];
      }
    }
    if(max <= sum) System.out.println(sum + max);
    else System.out.println(sum*2+1);
  }
}