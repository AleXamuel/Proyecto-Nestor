
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static HashMap<String, List<String>> adjList;
    static Map<String,Integer> d = new HashMap<>();
    static Map<String,String> pi = new HashMap<>();
    static Map<String,Character> state = new HashMap<>();
    static int c = 1;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(bf.readLine());
        adjList=new HashMap<>();
        for (int i = 0; i < n; i++) {
            String[] l1=bf.readLine().split(" ");
            String a=l1[0];
            for (int j = 1; j < l1.length; j++) {
                addEdge(a,l1[j]);
            }
        }
        String[] l2=bf.readLine().split(" ");
        if(adjList.get(l2[0])==null||adjList.get(l2[1])==null){
            System.out.println("no route found");
            return;
        }
        LinkedList<String> res=shortestPath(l2[0],l2[1]);
        if(res==null)
            System.out.println("no route found");
        else{
            String s="";
            for(String i: res)
                s+=i+" ";
            System.out.println(s);
        }
    }
    public static Map<String, String> bfs(String s) {
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

    static LinkedList<String> shortestPath(String t, String s) {
        bfs(s);
        if (pi.get(t) == null && !Objects.equals(t, s)) return null;
        LinkedList<String> path = new LinkedList<>();
        while (t!=null) {
            path.add(t);
            t = pi.get(t);
        }
        return path;
    }
    static void addEdge(String a, String b) {
        if (adjList.get(a) == null)
            adjList.put(a, new LinkedList<String>());
        if (adjList.get(b) == null)
            adjList.put(b, new LinkedList<String>());
        adjList.get(a).add(b);
        adjList.get(b).add(a);
    }
}
