//https://codeforces.com/problemset/problem/405/B
import java.util.*;
import java.io.*;

public class DominoEffect {
	static HashSet<Integer> mid;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		in.readLine();
		String s = in.readLine();
		mid = new HashSet<>();
		find(s);
		int c = 0;
		for (char k : solve(s))
			if (k == Character.MIN_VALUE)
				c++;
		System.out.println(c);

	}

	static void find(String s) {
		int n = s.length();
		for (int i = 0; i < n; i++)
			if (s.charAt(i) == 'R')
				for (int j = i + 1; j < n; j++)
					if (s.charAt(j) == 'L') {
						int val = j - i - 1;
						if (val % 2 != 0)
							mid.add(i + val / 2 + 1);
						break;
					}

	}

	static char[] solve(String s) {
		int n = s.length();
		char[] state = new char[n];
		for (int i = 0; i < n; i++)
			if (s.charAt(i) == 'L') {
				int j = i;
				while (j >= 0 && s.charAt(j) != 'R' && !mid.contains(j))
					state[j--] = 'L';

			} else if (s.charAt(i) == 'R') {
				int j = i;
				while (j < n && s.charAt(j) != 'L' && !mid.contains(j))
					state[j++] = 'R';

			}
		return state;
	}

}
