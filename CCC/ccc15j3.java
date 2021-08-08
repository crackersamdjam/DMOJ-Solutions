import java.util.*;
public class CCC15J4 {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        char[] word = str.toCharArray();
        for(int i = 0; i < str.length(); i++){
            System.out.print(word[i]);
            if(word[i] == 'a' || word[i] == 'e'|| word[i] == 'i' || word[i] == 'o'|| word[i] == 'u'){
                
            }else{
                int a = word[i] - 'a';
                if(a > 17) System.out.print('u');
                else if(a > 11) System.out.print('o');
                else if(a > 6) System.out.print('i');
                else if(a > 2) System.out.print('e');
                else System.out.print('a');
                
                if(a == 25){
                    System.out.print('z');
                }else if(a+1 != 4 && a+1 != 8 && a+1 != 14 && a+1 != 20){
                    System.out.print((char) (a + 1 + 'a'));
                }else{
                    System.out.print((char) (a + 2 + 'a'));
                }
            }
        }
    }
    
}