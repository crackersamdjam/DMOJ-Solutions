import java.util.Scanner;
public class CCC11J1 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt(), e = input.nextInt();
        if(a>=3 && e<=4) System.out.println("TroyMartian");
        if(a<=6 && e>=2) System.out.println("VladSaturnian");
        if(a<=2 && e<=3) System.out.println("GraemeMercurian");
    }
    
}