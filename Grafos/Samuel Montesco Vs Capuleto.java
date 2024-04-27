import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main{
    static int[] pi;
    static int n, m;
    static LinkedList<Integer>[] adjList;
    static char[] state;
    static int numero;
    static boolean[] grupo;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(bf.readLine());
        for (int i = 0; i < t; i++) {
            bf.readLine();
            int n=Integer.parseInt(bf.readLine());
            adjList=new LinkedList[n];
            state= new char[n];
            grupo=new boolean[n];
            pi=new int[n];
            numero=0;
            Arrays.fill(state,'N');
            for (int j = 0; j < n; j++) {
                adjList[j]=new LinkedList<>();
            }
            for (int j = 0; j < n; j++) {
                String[] l1=bf.readLine().split(" ");
                int k=Integer.parseInt(l1[0]);
                for (int l = 1; l < k+1; l++) {
                    int b=Integer.parseInt(l1[l]);
                    if(b>n)
                        continue;
                    addEdge(j,b-1);
                }
            }
            for (int j = 0; j < n; j++) {
                if(state[j]=='N')
                    bfs(j);
            }
            //System.out.println(Arrays.toString(grupo));
            System.out.println(numero);
            //System.out.println(Arrays.toString(adjList));
        }
    }


    static void bfs(int s) {
        state[s]='D';
        pi[s]=-1;
        grupo[s]=true;
        int grupo1=0;
        int grupo2=0;
        boolean ciclo=false;
        Queue<Integer> Q = new LinkedList<Integer>();
        Q.add(s);
        while (!Q.isEmpty()) {
            int u = Q.poll();
            if(grupo[u])
                grupo1++;
            else
                grupo2++;
            for (int v : adjList[u]) {
                if (state[v] == 'N') {
                    state[v] = 'D';
                    grupo[v] = !grupo[u];
                    Q.add(v);
                    pi[v] = u;
                }
                if (state[v] == 'D')
                    if(pi[v]!=u)
                        if(grupo[v]==grupo[u])
                            ciclo=true;

            }
            state[u] = 'E';

        }
        if(!ciclo)
            numero+=Math.max(grupo1,grupo2);
    }

    static void addEdge(int a, int b) {
        adjList[a].add(b);
        adjList[b].add(a);
    }

}
