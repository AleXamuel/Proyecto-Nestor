import java.util.*;
  public class Main{
    public static void main(String args[]){
        Main grafo=new Main();
        for(int i=0;i<8;i++){
            for(int j = 1; j < 9; j++) {
                String s=(char)('a'+i)+""+j;
                grafo.addVertex(s);
            }
        }
        for(int i=0;i<8;i++){
            for(int j = 1; j < 9; j++) {
                String s=(char)('a'+i)+""+j;
                grafo.addEdge(s,""+(char)('a'+i+1)+(j+2));
                grafo.addEdge(s,""+(char)('a'+i+2)+(j+1));
                grafo.addEdge(s,""+(char)('a'+i+2)+(j-1));
                grafo.addEdge(s,""+(char)('a'+i+1)+(j-2));
                grafo.addEdge(s,""+(char)('a'+i-1)+(j-2));
                grafo.addEdge(s,""+(char)('a'+i-2)+(j-1));
                grafo.addEdge(s,""+(char)('a'+i-2)+(j+1));
                grafo.addEdge(s,""+(char)('a'+i-1)+(j-2));
            }
        }
        Scanner tec=new Scanner(System.in);
        while (tec.hasNext()){
            String s=tec.nextLine();
            String[] ss=s.split(" ");
            System.out.println("To get from "+ss[0]+" to "+ss[1]+" takes "+(grafo.shortestPath(ss[0],ss[1]).size()-1)+" knight moves.");
        }
    }
    private int n, m;
    private Map<String, List<String>> adjList;

    public Main() {
        n = 0;
        m = 0;
        adjList = new HashMap<String, List<String>>();
    }
    public Map<String,List<String>> getAdjList(){
        return adjList;
    }
    public int size(){
        return n;
    }
    public Map<String, String> bfs(String s) {
        Map<String,Integer> d = new HashMap<>();
        Map<String,String> pi = new HashMap<>();
        Map<String,Character> state = new HashMap<>();
        d.put(s,0);
        pi.put(s,null);
        state.put(s,'D');
        Queue<String> Q = new LinkedList<>();
        Q.add(s);
        while (!Q.isEmpty()) {
            String u = Q.poll();
            for(String v : adjList.get(u))
                if (state.get(v) == null) {
                    d.put(v,d.get(u)+1);
                    pi.put(v,u);
                    state.put(v,'D');
                    Q.add(v);
                }
            state.put(u,'E');
        }
        return pi;
    }


    public List<String> shortestPath(String s, String t) {
        Map<String,String> pi = bfs(s);
        if (pi.get(t) == null && !Objects.equals(t, s)) return null;
        List<String> path = new LinkedList<String>();
        while (t!=null) {
            path.add(0, t);
            t = pi.get(t);
        }
        return path;
    }
    public boolean addVertex(String vertex) {
        if (adjList.get(vertex) != null)
            return false;
        adjList.put(vertex, new LinkedList<String>());
        n++;
        return true;
    }



    public boolean addEdge(String a, String b) {
        if (adjList.get(a) == null)
            return false;
        if (adjList.get(b) == null)
            return false;
        adjList.get(a).add(b);
        adjList.get(b).add(a);
        m++;
        return true;
    }




    public String toString() {
        String s = "";
        for (String v : adjList.keySet()) {
            s += "<" + v + ", " + adjList.get(v) + "\n";
        }
        return s;
    }

}
