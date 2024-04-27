import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main{
    static ArrayList<Integer>[] adjList;
    static int[] d,t;
    static int time;
    static int contador;
    static int N;
    static char[] state;
    static Stack<Integer> tsort;
    public static void main (String[] args) throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        int cases=Integer.parseInt(bf.readLine());
        for(int i =0;i<cases;i++){
            String[] l1=bf.readLine().split(" ");
            contador=0;
            N=Integer.parseInt(l1[0]);
            adjList=new ArrayList[N];
            d=new int[N];
            state=new char[N];
            t=new int[N];
            Arrays.fill(state,'N');
            int m=Integer.parseInt(l1[1]);
            for (int j = 0; j < N; j++)
                adjList[j]=new ArrayList<>();
            for (int j = 0; j < m; j++) {
                String[] l2=bf.readLine().split(" ");
                int a=Integer.parseInt(l2[0])-1;
                int b=Integer.parseInt(l2[1])-1;
                addEdge(a,b);
            }
            int[] arr=top_sort();
            int index=0;
            for (int j = 0; j < arr.length; j++)
                if(state[arr[j]]=='N'){
                    contador++;
                    bfs(arr[j]);
                }
            System.out.println(contador);


        }
    }

    static char[] bfs(int s) {
        state[s] = 'D';
        Queue<Integer> Q = new LinkedList<Integer>();
        Q.add(s);
        while (!Q.isEmpty()) {
            int u = Q.poll();
            for(int v : adjList[u])
                if (state[v] == 'N') {
                    state[v] = 'D';
                    Q.add(v);
                }
            state[u] = 'E';
        }
        return state;
    }
    static void addEdge(int a, int b){
        if(adjList[a]==null)
            adjList[a]=new ArrayList<>();
        adjList[a].add(b);
    }
    static void dfs(int u) {
        d[u] = time++;
        for(int v:adjList[u]) {
            if (d[v]!=0) continue;
            dfs(v);
        }
        t[u] = time++;
        tsort.add(u);
    }

    static int[] top_sort() {
        d = new int[N];
        t = new int[N];
        time = 1;
        tsort = new Stack<>();
        for(int u=0; u<N; u++) {
            if (d[u] == 0) dfs(u);
        }
        int[] tsort_arr = new int[N];
        for (int i = 0; i < N; i++)
            tsort_arr[i] = tsort.pop();
        return tsort_arr;
    }

}
