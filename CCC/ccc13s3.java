import java.util.*;

public class test {
    public static void combination(match g[][], int S[], int T) {
        int count = 0;
        int n = g.length;
        int update[] = new int[4];
        int combination[] = new int[n];
        while(true) {
            for(int i = 0; i < 4;i++) 
                update[i] = S[i];
            for(int i = 0; i < n; i++) {
                int a = g[i][combination[i]].getA();
                int b = g[i][combination[i]].getB();
                update[a] = update[a] + g[i][combination[i]].getApoints();
                update[b] = update[b] + g[i][combination[i]].getBpoints();
            }
            // if(update[T] == Arrays.stream(update).max().getAsInt()) count++;
            int ok = 1;
            for(int j = 0; j < 4; j++)
                if(j != T && update[j] >= update[T])
                    ok = 0;
            count += ok;

            int k = n - 1;
            while(k >= 0 && (combination[k] + 1 >= g[k].length))
                k--;
            
            // if(ok == 1){
                // for(int j = 0; j < 4; j++)
                    // System.out.print(update[j]+" ");
                // System.out.println();
                // for(int j = 0; j < n; j++)
                    // System.out.print(combination[j]+" ");
                // System.out.println();
                // System.out.println("k "+k);
            // }

            if(k < 0) {System.out.print(count); return;}
            combination[k]++;
            for(int i =k+1; i<n;i++)
                combination[i] = 0;
        }

    }
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int k = 0;
        int T = in.nextInt() - 1;
        int G = in.nextInt();
        int S[] = new int[4];
        boolean played[][] = new boolean[4][4];
        match graph[][] = new match[6 - G][3];
        for(int i = 0; i < G; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            int c = in.nextInt();
            int d = in.nextInt();
            played[a][b] = played[b][a] = true;
            if(c != d) {
                S[(c > d)?a:b] = S[(c > d)?a:b] + 3;
            }else {
                S[a]++;
                S[b]++;
            }
        }
        for(int i = 0; i < 4; i++) {
            for(int o = i + 1; o < 4; o++) {
                if(played[i][o]) continue;
                graph[k][0] = new match(i,o,0);
                graph[k][1] = new match(i,o,1);
                graph[k++][2] = new match(i,o,2);
            }
        }
        // System.out.println(Arrays.deepToString(graph));
        combination(graph, S, T);
    }
    static class match{
        int a;
        int b;
        int outcome;
        //if outcome is 0 the match is a tie, 1 = a win, 2 = b win
        public match(int a, int b, int outcome) {
            this.a = a;
            this.b = b;
            this.outcome = outcome;
        }
        public int getOutcome() {
            return this.outcome;
        }
        public int getApoints() {
            if(outcome == 0) {
                return 1;
            }else if(outcome == 1) {
                return 3;
            }else
                return 0;
        }
        public int getBpoints() {
            if(outcome == 0) {
                return 1;
            }else if(outcome == 1) {
                return 0;
            }else
                return 3;
        }
        public int getA() {
            return this.a;
        }
        public int getB() {
            return this.b;
        }
    }
}