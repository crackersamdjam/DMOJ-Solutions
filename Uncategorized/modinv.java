import java.util.Scanner;
import java.math.BigInteger;

public class Main{

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        BigInteger a = in.nextBigInteger(), b = in.nextBigInteger();
        System.out.println(a.modInverse(b));
    }
}