import java.util.Scanner;
import java.util.Stack;

public class PrefixPostfix {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Outer:
        while(true){
            String s = input.nextLine();
            if(s.equals("0")) break;
            String[] str = s.split(" ");
            Stack<String> st = new Stack<>();
            for(int i = str.length-1; i >= 0; i--){
                if("+".equals(str[i]) || "-".equals(str[i])){
                    String temp3 = st.pop() + st.pop() + str[i];
                    st.push(temp3);
                }else{
                    st.push(str[i]);
                }
            }
            String out = st.pop();
            for(int i = 0; i < out.length()-1; i++){
                System.out.print(out.charAt(i) + " ");
            }
            System.out.println(out.charAt(out.length()-1));
        }
    }
    
}