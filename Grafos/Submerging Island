import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static int contador;
    static HashMap<String, Integer> indices;
    static ArrayList<Integer>[] adj;
    static int[] d, low;
    static int time;
    static boolean[] ap;

    public static void main(String[] args) throws IOException {
        BufferedReader bf= new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String[] l1=bf.readLine().split(" ");
            int n=Integer.parseInt(l1[0]);
            int m=Integer.parseInt(l1[1]);
            if(n==0&&m==0)
                return;
            N=n;
            adj=new ArrayList[n];
            for (int i = 0; i < n; i++)
                adj[i]=new ArrayList<>();
            for (int i = 0; i < m; i++) {
                String[] l2=bf.readLine().split(" ");
                int a=Integer.parseInt(l2[0]);
                int b=Integer.parseInt(l2[1]);
                addEdge(a-1,b-1);
            }
            get_articulation_points();
            int contador=0;
            for (int i = 0; i < n; i++) {
                if(ap[i])
                    contador++;
            }
            //System.out.println(Arrays.toString(ap));
            System.out.println(contador);
            


        }

    }

    static void addEdge(int a, int b){
        adj[a].add(b);
        adj[b].add(a);
    }
    static void dfs(int u, int par) {
        d[u] = time++;
        low[u] = d[u];
        int children = 0;
        contador++;
        for(int v:adj[u]) {
            if (v==par) continue;
            else if (d[v]>0)
                low[u] = Math.min(low[u], d[v]);
            else {
                children++;
                dfs(v, u);
                low[u] = Math.min(low[u], low[v]);
                if (par!=-1 && low[v]>=d[u]) ap[u] = true;
            }
        }
        if (par==-1 && children>1) ap[u] = true;
    }

    static void get_articulation_points() {
        d = new int[N];
        low = new int[N];
        time = 1;
        ap = new boolean[N];
        dfs(0,   -1);
    }
}
