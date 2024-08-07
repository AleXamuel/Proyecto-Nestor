//https://open.kattis.com/problems/cats
import java.io.*;
import java.util.*;
class AFeastForCats {
    static ArrayList<Edge>[] adjList;
    static char[] state;
    static int[] d;
    static final int INF = 2147483647;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int t=bf.read()-'0';
        bf.readLine();
        for (int times = 0; times < t; times++) {
            String[] l1=bf.readLine().split(" ");
            int milk=Integer.parseInt(l1[0]);
            int n=Integer.parseInt(l1[1]);
            state=new char[n];
            d=new int[n];
            adjList=new ArrayList[n];
            for (int i = 0; i < n; i++)
                adjList[i]=new ArrayList<>();
            int size=(n*(n-1))/2;
            for (int i = 0; i < size; i++) {
                String[] l2=bf.readLine().split(" ");
                int a=Integer.parseInt(l2[0]);
                int b=Integer.parseInt(l2[1]);
                int w=Integer.parseInt(l2[2]);
                addEdge(a,b,w);
            }
            dijkstra(0);
            int c=0;
            for (int i:d)
                c+=1+i;
            if(c<=milk)
                System.out.println("yes");
            else
                System.out.println("no");
        }
    }
    static void addEdge(int a,int b, int w){
        adjList[a].add(new Edge(b,w));
        adjList[b].add(new Edge(a,w));
    }
    static void dijkstra(int s) {
        Arrays.fill(d, INF);
        Arrays.fill(state, 'N');
        d[s] = 0; state[s] = 'D';
        TreeSet<Edge> Q = new TreeSet<Edge>();
        Q.add(new Edge(s, d[s]));
        while (!Q.isEmpty()) {
            Edge e = Q.pollFirst();
            int u = e.vertex;
            if (state[u] != 'E') {
                for (Edge ee : adjList[u]) {
                    int v = ee.vertex;
                    int w = ee.weight;
                    if (state[v] != 'E') {
                        if (w < d[v]) {
                            d[v] = w;
                            state[v] = 'D';
                            Q.add(new Edge(v, d[v]));
                        }
                    }
                }
                state[u] = 'E';
            }
        }

    }

    private static class Edge implements Comparable<Edge> {
        int vertex;
        int weight;
        Edge(int v, int w) {
            vertex = v;
            weight = w;
        }
        public boolean equals(Object o) {
            if (o instanceof Edge)
                return (vertex==((Edge)o).vertex && weight==((Edge)o).weight);
            return false;
        }
        public int compareTo(Edge o) {
            if (weight < o.weight) return -1;
            if (weight > o.weight) return 1;
            if (vertex < o.vertex) return -1;
            if (vertex > o.vertex) return 1;
            return 0;
        }
        public String toString() {
            return "(" + vertex + ", " + weight + ")";
        }
    }
}
