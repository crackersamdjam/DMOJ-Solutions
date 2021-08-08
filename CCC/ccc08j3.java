import java.util.Scanner;

public class CCC08J3 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
    /*    String word = input.nextLine();
        int current = 0;
        int counter = 0;
        for(int i = 0; i < word.length(); i++){
            if(word.charAt(i)==' '){
                int num = 26;
            }else if(word.charAt(i)=='-'){
                int num = 27;
            }else if(word.charAt(i)=='.'){
                int num = 28;
            }
            int num = (int) word.charAt(i);
            num -= 65;
            while(current + 6 <= num){
                num-=5;
            }
            while(current - 6 >= num){
                num+=5;
            }
            counter += Math.abs(current-num);
            current = num;
        }
        counter += Math.abs(current-29);
        System.out.println(counter);
        
     */   
        //Ans
        
        char s[] = input.nextLine().toCharArray();
        int r = 0, c = 0, move = 0;
        for(int i = 0; i <s.length; i++){
            //nr new row, nc new collum,
            int dis = s[i] - 'A', nr = dis/6, nc = dis%6;
            if(s[i] == ' '){ nr = 4; nc = 2;}
            else if(s[i] == '-'){ nr = 4; nc = 3;}
            else if(s[i] == '.'){ nr = 4; nc = 4;}
            move += Math.abs(nr - r) + Math.abs(nc - c);
            r = nr; c = nc;
        }
        move += Math.abs(4-r) + Math.abs(5-c);
        System.out.println(move);
    }
    
}