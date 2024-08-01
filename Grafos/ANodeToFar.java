/*https://vjudge.net/problem/UVA-336*/

import java.util.*;

public class Main{
    int INF=2000000000;
    public static void ANodeToFar (String[] args){
        Scanner tec=new Scanner(System.in);
        int j =1;
        while(true){
            int n= tec.nextInt();
            if(n==0) break;
            Main grafo=new Main();
            for(int i =0;i<n;i++){
                int a=tec.nextInt();
                int b=tec.nextInt();
                grafo.addVertex(a);
                grafo.addVertex(b);
                grafo.addEdge(a,b);
                grafo.addEdge(b,a);
            }

            while(true){
                int a=tec.nextInt();
                int b=tec.nextInt();
                if(a==0&&b==0)
                    break;
                System.out.println("Case "+ j+ ": "+TTL(grafo,a,b)+" nodes not reachable from node "+a+" with TTL = "+b+".");
                j++;

            }
        }
    }
    private int n, m;
    private Map<Integer, List<Integer>> adjList;

    public Main() {
        n = 0;
        m = 0;
        adjList = new HashMap<Integer, List<Integer>>();
    }
    public Map<Integer,List<Integer>> getAdjList(){
        return adjList;
    }
    public int size(){
        return n;
    }
    public Map<Integer, Integer> bfs(int s) {
        Map<Integer,Integer> d = new HashMap<>();
        Map<Integer,Integer> pi = new HashMap<>();
        Map<Integer,Character> state = new HashMap<>();
        d.put(s,0);
        pi.put(s,-1);
        state.put(s,'D');
        Queue<Integer> Q = new LinkedList<>();
        Q.add(s);
        while (!Q.isEmpty()) {
            int u = Q.poll();
            for(int v : adjList.get(u))
                if (state.get(v) == null) {
                    d.put(v,d.get(u)+1);
                    pi.put(v,u);
                    state.put(v,'D');
                    Q.add(v);
                }
            state.put(u,'E');
        }
        return d;
    }
    static int TTL(Main grafo, int vertice, int pasos){
      if(grafo.getAdjList().get(vertice)==null)
          return grafo.size();
      else if(pasos==0){
          return grafo.size()-1;
      }
      Map<Integer, Integer> pi = grafo.bfs(vertice);
      int r=0;
      for (Map.Entry<Integer, Integer> entry : pi.entrySet()) {
          if (entry.getValue() <= pasos) {
            r++;
          }
      }
      return grafo.size()-r;

    }


    public List<Integer> shortestPath(Integer s, Integer t) {
        Map<Integer,Integer> pi = bfs(s);
        if (pi.get(t) == -1 && !Objects.equals(t, s)) return null;
        List<Integer> path = new LinkedList<Integer>();
        while (t!=-1) {
            path.add(0, t);
            t = pi.get(t);
        }
        return path;
    }
    public boolean addVertex(int vertex) {
        if (adjList.get(vertex) != null)
            return false;
        adjList.put(vertex, new LinkedList<Integer>());
        n++;
        return true;
    }

    public boolean removeVertex(int vertex) {
        if (adjList.get(vertex) == null)
            return false;
        m -= adjList.get(vertex).size();
        adjList.remove(vertex);
        for (Integer v : adjList.keySet()) {
            Iterator<Integer> it = adjList.get(v).iterator();
            while (it.hasNext())
                if (it.next() == vertex) {
                    it.remove();
                    m--;
                }
        }
        n--;
        return true;
    }

    public boolean addEdge(int a, int b) {
        if (adjList.get(a) == null)
            return false;
        if (adjList.get(b) == null)
            return false;
        adjList.get(a).add(b);
        adjList.get(b).add(a);
        m++;
        return true;
    }

    public boolean removeEdge(int a, int b) {
        List<Integer> list_a = adjList.get(a);
        if (list_a == null)
            return false;
        if (!list_a.contains(b))
            return false;
        list_a.remove(b);
        m--;
        return true;
    }

    public List<Integer> edgesTo(int b) {
        List<Integer> vertices = new LinkedList<Integer>();
        for (Integer v : adjList.keySet()) {
            if (adjList.get(v).contains(b))
                vertices.add(v);
        }
        return vertices;
    }

    public String toString() {
        String s = "";
        for (Integer v : adjList.keySet()) {
            s += "<" + v + ", " + adjList.get(v) + "\n";
        }
        return s;
    }

}
