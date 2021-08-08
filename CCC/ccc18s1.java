import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        double[] v = new double[num];
        for (int i = 0; i < num; i++) {
            v[i] = input.nextDouble();
        }
        double[] dif = new double[num-1];
        Arrays.sort(v);
        for(int i = 1; i < num-1; i++){
            double a = (v[i] - v[i-1])/2;
            double b = (v[i+1] - v[i])/2;
            dif[i] = (v[i] - v[i-1])/2 + (v[i+1] - v[i])/2;
        }
        double low = Double.MAX_VALUE;
        for(int i = 1; i < dif.length; i++){
            double n = dif[i];
            if (n < low) low = n;
        }
        System.out.printf("%.1f\n", low);
    }
}