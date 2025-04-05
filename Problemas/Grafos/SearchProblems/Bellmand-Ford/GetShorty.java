//https://open.kattis.com/problems/getshorty
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.TreeSet;

class Main {
    static final int INF = 2147483647;
    static ArrayList<Edge>[] adjList;
    static char[] state;
    static double[] d;
    static int n;
    static String s;
    static int[] pi;
    public static void main(String[] args) throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String[] l1=bf.readLine().split(" ");
            n=Integer.parseInt(l1[0]);
            int m=Integer.parseInt(l1[1]);
            if(n==0&&m==0)
                break;
            state=new char[n];
            DecimalFormat formato = new DecimalFormat("#0.0000");
            d=new double[n];
            adjList=new ArrayList[n];
            for (int i = 0; i < n; i++)
                adjList[i]=new ArrayList<>();
            for (int i = 0; i < m; i++) {
                String[] l2=bf.readLine().split(" ");
                int a=Integer.parseInt(l2[0]);
                int b=Integer.parseInt(l2[1]);
                double w=Double.parseDouble(l2[2]);
                addEdge(a,b,w);
            }

            bellmanFord(0);
            //System.out.println(Arrays.toString(d));
            System.out.println(formato.format(d[n-1]));
        }
    }
    public static int[] bellmanFord(int s) {
        d[s] = 1;
        boolean hayCambios = true;
        while (hayCambios) {
            hayCambios = false;
            for(int u=0; u<n; u++) {
                for(Edge e : adjList[u]) {
                    int v = e.vertex;
                    double w = e.weight;
                    if (d[u] * w> d[v]) {
                        d[v] = d[u] * w;
                        hayCambios = true;
                    }
                }
            }
        }
        return pi;
    }



    static void addEdge(int a,int b, double w){
        adjList[a].add(new Edge(b,w));
        adjList[b].add(new Edge(a,w));
    }
    private static class Edge implements Comparable<Edge> {
        int vertex;
        double weight;
        Edge(int v, double w) {
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
