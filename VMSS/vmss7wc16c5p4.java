import java.util.Scanner;
import java.util.Arrays;
public class VM7WC16 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt(), x = input.nextInt(), y = input.nextInt(), z = input.nextInt();
        int[] dp = new int[n+1];
        Arrays.fill(dp,Integer.MIN_VALUE);
        dp[0] = 0;
        for(int i = x; i <= n; i++){
            if(dp[i-x] + 1>dp[i]) dp[i] = dp[i-x]+1;
        }
        for(int i = y; i <= n; i++){
            if(dp[i-y] + 1>dp[i]) dp[i] = dp[i-y]+1;
        }
        for(int i = z; i <= n; i++){
            if(dp[i-z] + 1>dp[i]) dp[i] = dp[i-z]+1;
        }
        System.out.println(dp[n]);
    }
    
}