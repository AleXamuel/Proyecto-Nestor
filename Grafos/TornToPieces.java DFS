import java.io.*;
import java.util.*;
public class TornToPieces {
    static int n;
    static HashMap<String, ArrayList<String>> adj;
    static HashMap<String, Boolean> state;
    static HashMap<String, String> pi;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(in.readLine());
        StringTokenizer st;
        adj = new HashMap<>();
        for(int i=0; i<n; i++) {
            st = new StringTokenizer(in.readLine());
            String u = st.nextToken();
            int m = st.countTokens();
            for(int j=0; j<m; j++) {
                    String x = st.nextToken();
                if (!adj.containsKey(u))
                    adj.put(u, new ArrayList<>());
                if (!adj.containsKey(x))
                    adj.put(x, new ArrayList<>());
                adj.get(u).add(x);
                adj.get(x).add(u);
            }
        }
        st = new StringTokenizer(in.readLine());
        String s = st.nextToken();
        String t = st.nextToken();
        LinkedList<String> ans = solve(s,t);
        if(ans.size()<=1)
            System.out.println("no route found");
        else
            System.out.println(String.join(" ",ans));
    }
    static LinkedList<String> solve(String s, String t){
        if(!adj.containsKey(t))
            return new LinkedList<>();
        state = new HashMap<>();
        pi = new HashMap<>();
        pi.put(s, null);
        dfs(s);
        LinkedList<String> caminos = new LinkedList<>();
        caminos.add(0, t);
        while(pi.get(t)!=null) {
            t = pi.get(t);
            caminos.add(0, t);
        }
       return caminos;
    }
    static void dfs(String u){
        state.put(u, true);
        for(String v: adj.get(u))
            if(state.get(v)==null) {
                pi.put(v, u);
                dfs(v);
            }
    }
}
