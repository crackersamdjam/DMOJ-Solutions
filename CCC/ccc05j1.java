import java.util.Scanner;

public class CCC05J1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int d = input.nextInt(), e = input.nextInt(), w = input.nextInt();
        int t1 = 0, t2 = 0;
        int d2 = d;
        if(d>100){
            d-=100;
            t1 += 25*d;
        }
        if(d2>250){
            d2-=250;
            t2 += 45*d2;
        }
        t1 += 15*e;
        t2 += 35*e;
        t1 += 20*w;
        t2+= 25*w;
        System.out.println("Plan A costs " + t1/100 + "." + t1%100);
        System.out.println("Plan B costs " + t2/100 + "." + t2%100);
        if(t1<t2){
            System.out.println("Plan A is cheapest.");
        }else if(t2<t1){
            System.out.println("Plan B is cheapest.");
        }else{
            System.out.println("Plan A and B are the same price.");
        }
    }
    
}