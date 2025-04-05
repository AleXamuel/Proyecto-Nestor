//https://vjudge.net/problem/SPOJ-DIGOKEYS
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static ArrayList<Integer>[] adj;
    static boolean[] state;
    static int[] pi;
    public static void main(String[] args)throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(bf.readLine());
        for (int times = 0; times < t; times++) {
            int n=Integer.parseInt(bf.readLine());
            adj=new ArrayList[n+1];
            pi=new int[n+1];
            state=new boolean[n+1];
            for (int i = 0; i < n+1; i++)
                adj[i]=new ArrayList<>();

            for (int i = 1; i < n; i++) {
                String[] l1=bf.readLine().split(" ");
                int m=Integer.parseInt(l1[0]);
                for (int j = 1; j <=m ; j++)
                    adj[i].add(Integer.parseInt(l1[j]));
            }
            if(!bfs(1,n))
                System.out.println(-1);
            else {
                StringBuffer ans = new StringBuffer();
                int s = n ;
                int c = 0;
                while (s > 0) {
                    s = pi[s];
                    if(s<1)
                        break;
                    c++;
                    ans.insert(0, (s ) + " ");
                }
                System.out.println(c);
                System.out.println(ans);
            }
            System.out.println();
        }
    }

    static boolean bfs(int s, int t) {
        state[s] = true;
        pi[s]=-1;
        int time=0;
        TreeSet<Key> Q = new TreeSet<>();
        Q.add(new Key(s,time));
        while (!Q.isEmpty()) {
            time++;
            int u = Q.pollFirst().n;
            if(u==t)
                return true;
            for(int v : adj[u]) {
                if (!state[v]) {
                    state[v] =true;
                    pi[v]=u;
                    Q.add(new Key(v,time));
                }
            }
            state[u] = true;
        }
        return false;
    }
    private static class Key implements Comparable<Key>{
        int n;
        int time;
        Key(int v,int t){
            n=v;
            time=t;
        }
        public int compareTo(Key o){
            if(time<o.time)
                return -1;
            if(time>o.time)
                return 1;
            if(n<o.n)
                return -1;
            if(n>o.n)
                return 1;
            return 0;
        }

    }
}
