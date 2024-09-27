/*https://vjudge.net/problem/SPOJ-SHOP*/

import java.io.*;
import java.util.*;

public class Shopping {

    static ArrayList<Edge>[] adjList;
    static char[] state;
    static int[] d;
    static final int INF = 2147483647;
    
    public static void main(String[] args) throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String[] l1=bf.readLine().split(" ");
            int w=Integer.parseInt(l1[0]);
            int h=Integer.parseInt(l1[1]);
            if(w==0&&h==0)
                break;
            int n =w*h;
            adjList=new ArrayList[n];
            state=new char[n];
            d=new int[n];
            String s="";
            for (int i = 0; i < n; i++)
                adjList[i]=new ArrayList<>();
            for (int i = 0; i < h; i++)
                s+=bf.readLine();
            int goal=-1;
            int start=-1;
            boolean cerca=false;
            for (int i = 0; i < s.length(); i++) {
                if(s.charAt(i)=='X')
                    continue;
                if(s.charAt(i)=='S'){
                    start=i;
                    if(i%w!=0&&s.charAt(i-1)=='D'||(i+1)%w!=0&&i+1<n&&s.charAt(i+1)=='D'||i+w<n&&s.charAt(i+w)=='D'||i-w>=0&&s.charAt(i-w)=='D'){
                        System.out.println(0);
                        cerca=true;
                        break;
                    }
                }
                else if(s.charAt(i)=='D'){
                    goal=i;
                    if(i%w!=0&&s.charAt(i-1)!='X')
                        addEdge(i,i-1, 0);
                    if((i+1)%w!=0&&i+1<n&&s.charAt(i+1)!='X')
                        addEdge(i,i+1, 0);
                    if(i+w<n&&s.charAt(i+w)!='X')
                        addEdge(i,i+w, 0);
                    if(i-w>=0&&s.charAt(i-w)!='X')
                        addEdge(i,i-w, 0);
                }
                else {
                    if(i%w!=0&&s.charAt(i-1)!='X')
                        addEdge(i,i-1, s.charAt(i)-'0');
                    if((i+1)%w!=0&&i+1<n&&s.charAt(i+1)!='X')
                        addEdge(i,i+1, s.charAt(i)-'0');
                    if(i+w<n&&s.charAt(i+w)!='X')
                        addEdge(i,i+w, s.charAt(i)-'0');
                    if(i-w>=0&&s.charAt(i-w)!='X')
                        addEdge(i,i-w, s.charAt(i)-'0');
                }
            }
            if(!cerca) {
                dijkstra(start);
                System.out.println(d[goal]);
            }
            bf.readLine();
        }
    }

    static void addEdge(int a,int b, int w){
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
                        if (d[u] + w < d[v]) {
                            d[v] = d[u] + w;
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
