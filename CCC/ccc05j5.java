import java.util.Scanner;

public class CCC05J5 {
    
    public static boolean isMonkeyWord(String str){
        if(isAWord(str)) return true;
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == 'N'){
                if(isAWord(str.substring(0, i))&& isMonkeyWord(str.substring(i+1)))
                    return true;
            }
        }
        return false;
    }
    public static boolean isAWord(String str){
        if(str.length()==0) return false;
        if(str.length()==1)
            return str.equals("A");
        if(str.startsWith("B")&&str.endsWith("S")){
            if(isMonkeyWord(str.substring(1, str.length()-1))) return true;
        }
        return false;
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while(true){
            String str = input.next();
            if(str.equals("X")) break;
            System.out.println(isMonkeyWord(str)? "YES": "NO");
        }
    }
}