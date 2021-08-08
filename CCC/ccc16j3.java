import java.util.*;
public class CCC16J3 {

    /**
     * @param args the command line arguments
     */
    
    public static boolean isPalindrome(String c){
        Stack<Character> b = new Stack<>();
        for(int i = 0; i < c.length(); i++){
            b.push(c.charAt(i));
        }
        String reverse = "";
        while(!b.isEmpty()){
            reverse += b.pop();
        }
        return(c.equals(reverse));
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        int longest = 1;
        for(int i = 0; i <= str.length()-1; i++){
            for(int j = i+1; j <= str.length(); j++){
                if(isPalindrome(str.substring(i, j))){
                    if(j-i > longest) longest = j-i;
                }
            }
        }
        System.out.println(longest);
    }
    
}