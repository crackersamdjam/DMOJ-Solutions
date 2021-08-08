import java.util.*;
import java.io.*;
public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        for(int t = 0; t < n; t++){
            String[] s1 = in.readLine().split(" ");
            int m = Integer.parseInt(s1[0]), k = Integer.parseInt(s1[1]);
            HashSet<String> list = new HashSet<>();
            ArrayList<String>[] arr = new ArrayList[1001];
            int top = 1;
            for(int i = 1; i <= 1000; i++)
                arr[i] = new ArrayList<>();
            for(int i = 0; i < m; i++){
                String str = in.readLine();
                if(list.contains(str)){
                    for(int j = 1; i < 1000; j++){
                        if(arr[j].contains(str)){
                            arr[j+1].add(str);
                            arr[j].remove(str);
                            top = Math.max(top, j+1);
                            break;
                        }
                    }
                }else{
                    list.add(str);
                    arr[1].add(str);
                }
            }
            String pt;
            if(k%100 >10 && k%100 < 14){
                pt = ""+k+"th most common word(s):";
            }else{
                switch(k%10){
                    case 1:
                        pt = ""+k+"st most common word(s):";
                        break;
                    case 2:
                        pt = ""+k+"nd most common word(s):";
                        break;
                    case 3:
                        pt = ""+k+"rd most common word(s):";
                        break;
                    default:
                        pt = ""+k+"th most common word(s):";
                }
            }
            System.out.println(pt);
            for(int i = top; i >= 1; i--){
                if(arr[i].size()!=0){
                    if(k==1){
                        for(String strpt: arr[i]){
                            System.out.println(strpt);
                        }
                        k--;
                    }else k-=arr[i].size();
                }
            }
            System.out.println();
        }
    }
}