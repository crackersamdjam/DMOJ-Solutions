import java.util.Scanner;

public class CCC10J2 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt(), b = input.nextInt(), c = input.nextInt(), d = input.nextInt(), s = input.nextInt();
        int bd = 0, nd = 0, temp1 = a, temp2 = c;
        boolean dir1 = true, dir2 = true;
        for(int i = 0; i < s; i++){
            if(temp1 ==0){
                if(dir1){
                    dir1 = false;
                    temp1 = b;
                }else{
                    dir1 = true;
                    temp1 = a;
                }
            }
            if(temp2 ==0){
                if(dir2){
                    dir2 = false;
                    temp2 = d;
                }else{
                    dir2 = true;
                    temp2 = c;
                }
            }
            if(dir1){
                bd++;
                temp1--;
            }else{
                bd--;
                temp1--;
            }
            if(dir2){
                nd++;
                temp2--;
            }else{
                nd--;
                temp2--;
            }
        }
        if(bd<nd){
            System.out.println("Byron");
        }else if(bd > nd){
            System.out.println("Nikky");
        }else{
            System.out.println("Tied");
        }
    }
    
}