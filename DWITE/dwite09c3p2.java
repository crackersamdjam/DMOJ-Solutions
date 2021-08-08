import java.util.Scanner;
public class Question3 {

    public static int Flist(int[] a, int i){
        if(i==0)  return 0;
        if(i==1)  return 1;
        return fibonacci(i);
    }
    
    public static int fibonacci(double a){
        if(a == 1 || a ==0)
            return 1;
        return fibonacci(a-1) + fibonacci(a-2);
    }
    
    public static double round(double a, int[] list){
        double closest = 1000000000;
        for(int i = 0; i < 40; i++){
            if(list[i]<a){
                closest = a-list[i];
            }else{
                if(closest >= list[i] -a){
                    closest = list[i]-a;
                    return list[i];
                }
                return list[i-1];
            }
        }
        return 0;
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] list = new int[40];
        for(int i = 0 ; i < 40; i++){
            list[i] = Flist(list, i);
        }
        for(int i = 0; i < 5; i++){
            double a = input.nextInt();
            System.out.println((int)round(a, list));
        }
    }
    
}