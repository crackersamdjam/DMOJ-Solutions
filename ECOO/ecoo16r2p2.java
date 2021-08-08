import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for(int i = 0; i < 10; i++){
            int n  = in.nextInt();
            String z = in.nextLine();
            String str = in.nextLine();
            if(str.contains(" ")) {
                int cnt = 1;
                for (int j = 0; j < str.length(); j++) {
                    if (str.charAt(j) == ' ') cnt++;
                }
                String[] word = str.split(" ");
                char[] ans = new char[str.length() + 3];
                ans[0] = (char) (cnt / 26 + 97);
                ans[1] = (char) (cnt % 26 + 97);
                int lastIndex = 2;
                for (String sb : word) {
                    ans[lastIndex] = (char) (sb.length() + 97);
                    lastIndex++;
                }
                for (String sb : word) {
                    for (int j = 0; j < sb.length(); j++) {
                        ans[lastIndex] = sb.charAt(j);
                        lastIndex++;
                    }
                }
                int ct = 0;
                for (int j = ans.length - 1; j >= 0; j--) {
                    int temp = ans[j] - 97;
                    int shift = temp + n + ct;
                    ans[j] = (char) ((shift % 26) + 97);
                    ct += temp;
                    //System.out.println(ans[j]);
                }
                for(int j = 0; j < ans.length; j++) System.out.print(ans[j]);
                System.out.println();
            }else{
                //decode
                char[] ans = new char[str.length()];
                for(int j = 0; j < str.length(); j++){
                    ans[j] = str.charAt(j);
                }
                int ct = 0;
                for(int j = ans.length-1; j >= 0; j--){
                    int temp = ans[j] - 97;
                    int shift = temp - ct - n;
                    while(shift<0){
                        shift+=26;
                    }
                    ans[j] = (char)(shift + 97);
                    ct += shift;
                    //System.out.println(ans[j]);
                }
                int nWords = (ans[0]-97)*26;
                nWords += ans[1]-97;
                int[] space = new int[nWords-1];
                for(int j = 0; j < nWords-1; j++){
                    space[j] = ans[j+2]-97;
                }
                for(int j = 1; j < space.length; j++){
                    space[j] += space[j-1];
                    //System.out.println(space[j]);
                }
                for(int j = nWords+2; j < ans.length; j++){
                    for(int k = 0; k < space.length; k++)
                        if(space[k]+2+nWords == j)
                            System.out.print(" ");
                    System.out.print(ans[j]);
                }
                System.out.println();
            }
        }
    }
}