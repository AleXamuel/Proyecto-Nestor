/* https://vjudge.net/problem/SPOJ-DIGOKEYS */
import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class FindTreasure {

    static int n;
    static ArrayList<Integer>[] adj;
    static boolean[] state;

    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        for (int i=0; i<t; i++ ){
            n = Integer.parseInt(in.readLine());
            adj = new ArrayList[n];
            for(int k = 0; k < n; k++)
                adj[k] = new ArrayList<>();
            for (int j=0; j<n-1; j++){
                StringTokenizer st = new StringTokenizer(in.readLine());
                st.nextToken();
                while(st.hasMoreTokens())
                    adj[j].add(Integer.parseInt(st.nextToken())-1);
                Collections.sort(adj[j]);
            }
            state = new boolean[n];
            LinkedList<Integer> result = bfs();
            if (result.getFirst() == -1) System.out.println(-1);
            else {
                System.out.println(result.size());
                System.out.println(result.stream().map(String::valueOf).collect(Collectors.joining(" ")));
            }
        }
    }

    static LinkedList<Integer> bfs() {
        int[] pi = new int[n];
        Arrays.fill(pi, -1);
        pi[0] = -1;
        state[0] = true;
        Queue<Integer> Q = new LinkedList<>();
        Q.add(0);
        while (!Q.isEmpty()) {
            int u = Q.poll();
            for (int v : adj[u]) {
                if (!state[v]) {
                    state[v] = true;
                    pi[v] = u;
                    Q.add(v);
                }
            }
        }
        LinkedList<Integer> caminos = new LinkedList<>();
        if (pi[n - 1] == -1) {
            caminos.add(-1);
        }
        else{

            int pos = pi[n-1];
            caminos.add(pos+1);
            while(pi[pos]!=-1){
                pos = pi[pos];
                caminos.addFirst(pos+1);
            }
        }
        return caminos;
    }
}
