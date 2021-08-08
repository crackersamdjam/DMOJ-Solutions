import java.util.*;
import java.io.*;
public class ccc05s4{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int L = readInt();
		while(L --> 0){
			int n = readInt();
			ArrayList<String> st = new ArrayList<>();

			String[] s = new String[n+1];
			for(int i = 1; i <= n; i++)
				s[i] = next();
			s[0] = s[n];
			
			int dep = -1, mx = 0;

			for(int i = 0; i <= n; i++){
				// System.out.println("at "+i+" "+s[i]);
				if(st.size() >= 2 && st.get(st.size()-2).equals(s[i])){
					// System.out.println("rm "+st.get(st.size()-1));
					st.remove(st.size()-1);
					dep--;
				}
				else{
					// System.out.println("add");
					st.add(s[i]);
					dep++;
				}
				mx = Math.max(mx, dep);
			}
			// System.out.println(mx);
			// System.out.println(dep+" "+st.size());
			System.out.println((n-2*mx)*10);
		}
	}


	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}