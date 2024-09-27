import java.util.*;
import java.io.*;

public class Bididibus {
	public static void main(String[] args) {
		Input in = new Input(System.in);
		int t = in.nextInt();
		for (int cases = 0; cases < t; cases++) {
			String s = in.next();
			Stack<Integer> stack = new Stack<>();
			int ans = 0;
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == '/' && stack.isEmpty())
					continue;
				if (s.charAt(i) == '\\')
					stack.push(i);
				else if (s.charAt(i) == '/')
					ans += i - stack.pop();
			}
			System.out.println(ans);
		}
	}

	static class Input {
		BufferedReader br;
		StringTokenizer st;

		public Input(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		public boolean hasNext() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(br.readLine());

			} catch (Exception e) {
				return false;
			}
			return true;
		}

	}

}
