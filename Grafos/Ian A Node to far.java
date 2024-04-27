import java.util.*;

public class Main {
	static HashMap<Integer, List<Integer>> adjList;
	static HashMap<Integer, Integer> signal;
	static HashMap<Integer, Boolean> visitado;
	static int c = 1;

	public static void main(String[] args) {
		Scanner key = new Scanner(System.in);
		while (true) {
			int nc = key.nextInt();
			if (nc == 0)
				break;
			adjList = new HashMap<Integer, List<Integer>>();
			for (int i = 0; i < nc; i++) {
				int a = key.nextInt();
				int b = key.nextInt();
				addEdge(a, b);
			}
			while (true) {
				int q1 = key.nextInt();
				int q2 = key.nextInt();
				if (q1 == 0 && q2 == 0)
					break;
				System.out.println(ans(q1, q2, c));
				c++;
			}
		}
	}

	static String ans(int s, int ttl, int caso) {
		visitado = new HashMap<Integer, Boolean>();
		visitado.put(s, true);
		bfs(s, ttl);
		int k = 0;
		for (Map.Entry<Integer, Integer> entry : signal.entrySet())
			if (entry.getValue() >= 0)
				k++;
		return "Case " + caso + ": " + (adjList.keySet().size() - k) + " nodes not reachable from node " + s
				+ " with TTL = " + ttl + ".";
	}

	static void bfs(int s, int ttl) {
		signal = new HashMap<>();
		if (adjList.get(s) == null)
			return;
		signal.put(s, ttl);
		Queue<Integer> Q = new LinkedList<Integer>();
		Q.add(s);
		int new_ttl = ttl;
		while (!Q.isEmpty()) {
			int u = Q.poll();
			new_ttl = signal.get(u) - 1;
			for (int v : adjList.get(u))
				if (visitado.get(v) == null) {
					visitado.put(v, true);
					signal.put(v, new_ttl);
					Q.add(v);
				}
		}
	}

	static void addEdge(int a, int b) {
		if (adjList.get(a) == null)
			adjList.put(a, new LinkedList<Integer>());
		if (adjList.get(b) == null)
			adjList.put(b, new LinkedList<Integer>());
		adjList.get(a).add(b);
		adjList.get(b).add(a);
	}
}
