import java.util.*;
public class Main {

    public static void main(String[] args) {
	Scanner in = new Scanner(System.in);
	int[] lev = new int[51];
	boolean[] vis = new boolean[51];
	int[][] g = new int[51][51];
	for(int z = 0; z < 5; z++) {
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			g[a][b] = 1;
			g[b][a] = 1;
		}

		int cur = 0;
		lev[1] = 1;
		ArrayDeque<Integer> nx = new ArrayDeque<>();
		nx.add(1);
		while (!nx.isEmpty()) {
			cur++;
			int a = nx.poll();
			for (int i = 1; i <= n; i++) {
				if (!vis[i] && g[a][i] == 1) {
					/*System.out.println("aaa" + a + "lev[i]" + i + " " + (cur + 1));*/
					nx.add(i);
					if(lev[i]==0){
					lev[i] = lev[a] + 1;
					}
					//System.out.println(i + " at lev " + lev[i]);
					//System.out.println("a " + a + " i " + i + " lev[i] " + lev[i]);


				}
			}
			vis[a] = true;
			//System.out.println(a + " is true");
		}

		int tot = 0;
		for (int i = 1; i < cur; i++) {
			int count = 0;
			for(int k = i+1; k < lev.length; k++) {
				int j = lev[k];
				if( k != i && j != 0 && j == lev[i] && ((g[k][i]==1)|| g[i][k]==1)){
					count++;
					//System.out.println(count + ": " + k + " + " + i);
					//System.out.println(k + " at lev " + lev[k]);
					//System.out.println("Added " + k + " for num " + i);
				}
				}
			//if (count != 0){
				//if(count==1){
					tot+= count;
				//}else{
				//tot += count*(count-1)/2;}
			//System.out.println(i + " i " +count + " " + tot);
			//}
		}
		System.out.println(tot);
		Arrays.fill(lev, 0);
		Arrays.fill(vis, false);
		for(int j = 0; j < 51; j++){
			Arrays.fill(g[j], 0);
		}
	}
    }
}
/*
1 2 3 4
  | |
  5 6 7
fix 4-7

1 2
  |
  4
  |
1 3

1 2 4
1 3 4

1 2
  |
1 3
  |
1 4
  |
  2
 */