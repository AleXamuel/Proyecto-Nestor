//https://vjudge.net/contest/738626#problem/G
import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {

	static int grid[][];
	static int n;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		PrintWriter out = new PrintWriter(System.out);
		while (true) {
			st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			BigInteger c = new BigInteger(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			if (n == 0)
				break;
			grid = new int[n][n];
			int k = n * n - 1;
			for (int i = n - 1; i >= 0; i--)
				for (int j = 0; j < n; j++) {
					if (!c.shiftRight(k).and(BigInteger.ONE).equals(BigInteger.ZERO))
						grid[i][j] = 1;
					else
						grid[i][j] = 0;
					k--;
				}
			y = n - y;
			out.println(f(y, x - 1, 0) ? "Yes" : "Kaputt!");
		}
		out.close();

	}

	// 0: left, 1:right
	// up = 0, down = 1, left = 2, right =3
	static boolean f(int i, int j, int dir) {
		if (i < 0 || i >= n || j < 0 || j >= n)
			return false;
		if (i == 0 && j == n - 1)
			return true;
		int color = grid[i][j];
		grid[i][j] ^= 1;
		if (dir == 0) {
			if (color == 0)
				return f(i, j - 1, 2);
			return f(i, j + 1, 3);

		}
		if (dir == 1) {
			if (color == 0)
				return f(i, j + 1, 3);
			return f(i, j - 1, 2);
		}
		if (dir == 2) {
			if (color == 0)
				return f(i + 1, j, 1);
			return f(i - 1, j, 0);
		}
		if (color == 0)
			return f(i - 1, j, 0);
		return f(i + 1, j, 1);

	}

}
