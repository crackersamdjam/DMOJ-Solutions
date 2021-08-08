import java.util.Scanner;

public class CCC09J3 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int o = input.nextInt();
        int lo = o+2400;
        System.out.println(o + " in Ottawa");
        System.out.println((lo-300)%2400 + " in Victoria");
        System.out.println((lo-200)%2400 + " in Edmonton");
        System.out.println((lo-100)%2400 + " in Winnipeg");
        System.out.println(o + " in Toronto");
        System.out.println((o+100)%2400 + " in Halifax");
        if(o%100 + 30 < 60){
            System.out.println((o+130)%2400 + " in St. John's");
        }else{
            System.out.println((o+130)%2400+100-60 + " in St. John's");
        }
    }
    
}