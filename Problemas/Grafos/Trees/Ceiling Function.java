//https://open.kattis.com/problems/ceiling
import java.util.*;
import java.io.*;

class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		Tree A[] = new Tree[n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(in.readLine());
			A[i] = new Tree(Integer.parseInt(st.nextToken()));
			while (st.hasMoreTokens())
				A[i].add(Integer.parseInt(st.nextToken()));
		}
		ArrayList<Tree> unique = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			Tree cur = A[i];
			boolean cond = true;
			for (Tree v : unique) {
				if (cur.equals(v)) {
					cond = false;
					break;
				}
			}
			if (cond) {
				unique.add(cur);
			}
		}
		out.println(unique.size());
		out.close();

	}

	static class Tree {
		Node root;

		Tree(int x) {
			root = new Node(x);
		}

		public void add(int val) {
			root = add(val, root);
		}

		public boolean equals(Tree o) {
			return equals(root, o.root);
		}

		private boolean equals(Node r1, Node r2) {
			if (r1 == null && r2 == null)
				return true;
			if (r1 == null && r2 != null)
				return false;
			if (r1 != null && r2 == null)
				return false;
			return equals(r1.left, r2.left) && equals(r1.right, r2.right);
		}

		private Node add(int val, Node subroot) {
			if (subroot == null)
				return new Node(val);
			if (val < subroot.val)
				subroot.left = add(val, subroot.left);
			else
				subroot.right = add(val, subroot.right);
			return subroot;
		}

		private void dfs(Node cur, StringBuilder ans) {
			if (cur == null)
				return;
			dfs(cur.left, ans);
			ans.append(cur.val + ", ");
			dfs(cur.right, ans);
		}

		public String toString() {
			StringBuilder ans = new StringBuilder();
			dfs(root, ans);
			return new String(ans);
		}

	}

	static class Node {
		int val;
		Node left, right;

		Node(int x) {
			this.val = x;
		}

		Node(int x, Node l, Node r) {
			this.val = x;
			this.left = l;
			this.right = r;
		}
	}

}
