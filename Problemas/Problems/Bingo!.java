//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3391
import java.util.*;
import java.io.*;

public class Bingo {

	static HashSet<Integer> h;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		while (true) {
			st = new StringTokenizer(in.readLine());
			int n = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if (n == 0 && b == 0)
				break;
			int[] arr = new int[b];
			st = new StringTokenizer(in.readLine());
			h = new HashSet<>();
			for (int i = 0; i < arr.length; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
				h.add(arr[i]);
			}
			Arrays.sort(arr);
			System.out.println(solve(n, arr) ? "Y" : "N");
		}

	}

	static boolean solve(int n, int[] A) {
		int j = 0;
		for (int i = 0; i < A.length; i++) {
			if (A[i] != j) {
				if (!find(j, A))
					return false;
				i--;
			}
			j++;
		}
		if (j >= n + 1)
			return true;
		return false;
	}

	static boolean find(int x, int[] A) {
		if (x == 0 && !h.contains(x))
			return false;
		for (int i = 0; i < A.length; i++)
			if (h.contains(A[i] + x))
				return true;
		return false;

	}

}
