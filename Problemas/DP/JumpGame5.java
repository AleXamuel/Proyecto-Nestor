//https://leetcode.com/problems/jump-game-v/description/
import java.util.*;

public class Main {
	static int solve(int[] A, int d) {
		int n = A.length;
		Jump[] arr = new Jump[n];
		for (int i = 0; i < n; i++)
			arr[i] = new Jump(A[i], i);
		Arrays.sort(arr, (j1, j2) -> {
			if (j1.val < j2.val)
				return -1;
			if (j1.val > j2.val)
				return 1;
			return j1.index - j2.index;
		});
		int[] dp = new int[n];
		int ans = -1;
		for (int u = 0; u < n; u++) {
			int index = arr[u].index;
			int max = 0;
			for (int i = index - 1; i >= index - d; i--) {
				if (i < 0 || i >= n || A[i] >= A[index])
					break;
				max = Math.max(dp[i], max);
			}
			for (int i = index + 1; i <= index + d; i++) {
				if (i < 0 || i >= n || A[i] >= A[index])
					break;
				max = Math.max(dp[i], max);
			}
			dp[index] = 1 + max;
			ans = Math.max(dp[index], ans);
		}
		return ans;
	}

	static class Jump {
		int val, index;

		Jump(int v, int i) {
			this.val = v;
			this.index = i;
		}

	}
}
