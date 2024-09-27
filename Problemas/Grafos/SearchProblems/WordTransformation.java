/* https://vjudge.net/problem/UVA-429 */
import java.util.*;
import java.io.*;

public class Main {
	static int n, m;
	static HashMap<String, HashSet<String>> adj;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(in.readLine());
		String line = in.readLine();
		for (int i = 0; i < t; i++) {
			adj = new HashMap<>();
			HashSet<String> dicc = new HashSet<>();
			while (true) {
				String word = in.readLine();
				if (word.equals("*"))
					break;
				dicc.add(word);
			}
			connectVertex(dicc);
			while (true) {
				String queri = in.readLine();
				if (queri == null || queri.isEmpty())
					break;
				StringTokenizer st = new StringTokenizer(queri, " ");
				String a = st.nextToken();
				String b = st.nextToken();
				System.out.println(a + " " + b + " " + bfs(a, b));
			}
			if (i != t - 1)
				System.out.println();
		}
	}

	static void connectVertex(HashSet<String> dicc) {
		for (String i : dicc)
			for (String j : dicc)
				if (sePuede(i, j))
					addEdge(i, j);
	}

	static boolean sePuede(String a, String b) {
		if (a.equals(b))
			return false;
		if (a.length() != b.length())
			return false;
		int cambios = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a.charAt(i) != b.charAt(i))
				cambios++;
			if (cambios > 1)
				return false;
		}
		return true;
	}

	static int bfs(String s, String t) {
		if (s.equals(t))
			return 0;
		HashMap<String, Integer> d = new HashMap<>();
		HashMap<String, String> pi = new HashMap<>();
		HashMap<String, Boolean> visitado = new HashMap<>();
		d.put(s, 0);
		pi.put(s, s);
		visitado.put(s, true);
		Queue<String> Q = new LinkedList<>();
		Q.add(s);
		while (!Q.isEmpty()) {
			String u = Q.poll();
			for (String v : adj.get(u))
				if (visitado.get(v) == null) {
					d.put(v, d.get(u) + 1);
					pi.put(v, u);
					visitado.put(v, true);
					Q.add(v);
				}
		}
		List<String> path = new LinkedList<String>();
		while (t != s) {
			path.add(t);
			t = pi.get(t);
		}
		return path.size();
	}

	static void addEdge(String a, String b) {
		if (adj.get(a) == null)
			adj.put(a, new HashSet<String>());
		if (adj.get(b) == null)
			adj.put(b, new HashSet<String>());
		adj.get(a).add(b);
		adj.get(b).add(a);

	}
}
