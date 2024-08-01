import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

class SecretLetters {
    static HashMap<Character,LinkedList<Character>> adj;
    public static void main(String[] args) throws IOException {
        BufferedReader bf= new BufferedReader(new InputStreamReader(System.in));
        adj=new HashMap<>();
        String[] l1=bf.readLine().split(" ");
        int n=Integer.parseInt(l1[0]);
        int m=Integer.parseInt(l1[1]);
        for (int i=0;i<n;i++){
            String l2=bf.readLine();
            addEdge(l2.charAt(0),l2.charAt(2));
        }
        //System.out.println(adj);
        for (int i = 0; i < m; i++) {
            String[] l2=bf.readLine().split(" ");
            try{
                if(solve(l2[0],l2[1]))
                    System.out.println("yes");
                else
                    System.out.println("no");
            }catch (NullPointerException e) {
                System.out.println("no");
            }
        }
    }

    static boolean solve(String a, String b){
        if(a.length()!=b.length())
            return false;
        for (int i = 0; i < a.length(); i++) {
            if(a.charAt(i)==b.charAt(i))
                continue;
            if(!bfs(a.charAt(i),b.charAt(i)))
                return false;
        }
        return true;
    }
    static void addEdge(char a, char b){
        if (adj.get(a) == null)
            adj.put(a, new LinkedList<>());
        if (adj.get(b) == null)
            adj.put(b, new LinkedList<>());
        adj.get(a).add(b);
    }
    static boolean bfs(char s,char t) {
        HashMap<Character,Character> state=new HashMap<>();
        state.put(s,'D');
        Queue<Character> Q = new LinkedList<>();
        Q.add(s);
        while (!Q.isEmpty()) {
            char u = Q.poll();
            if(u==t) {
                return true;
            }
            for(char v : adj.get(u))
                if (state.get(v)==null) {
                    state.put(v,'D');
                    Q.add(v);
                }
            state.put(u,'E');
        }
        return false;
    }
}
