import java.io.*;
import java.util.*;

public class TouristGuide {
    static int n;
    static ArrayList<Integer>[] adj;
    static int[] d, low;
    static int time;
    static Boolean[] ap;

    public static void main(String[] args) throws Exception {
        Input in = new Input(System.in);
        int map = 1;
        while(true){
            n = in.nextInt();
            if(n == 0) break;
            Map<String, Integer> cities = new HashMap<>();
            HashMap<Integer,String> citiesinv = new HashMap<>();
            for (int i = 0; i < n; i++){
                String city = in.nextLine();
                cities.put(city, i);
                citiesinv.put(i, city);
            }
            adj = new ArrayList[n];
            for(int i = 0; i < n; i++)
                adj[i] = new ArrayList<>();
            int m = in.nextInt();
            for (int i = 0; i < m; i++){
                String a = in.next();
                String b = in.next();
                adj[cities.get(a)].add(cities.get(b));
                adj[cities.get(b)].add(cities.get(a));
            }
            get_articulation_points();
            int count = 0;
            for (boolean x : ap)
                if (x) count++;
            if (map != 1) System.out.println();
            System.out.printf("City map #%d: %d camera(s) found\n", map, count);
            TreeSet<String> arbol = new TreeSet<>();
            for (int i = 0; i < ap.length; i++)
                if (ap[i]) arbol.add(citiesinv.get(i));
            map += 1;
            for (String city : arbol) System.out.println(city);
        }
    }

    static void dfs(int u, int par) {
        d[u] = time++;
        low[u] = d[u];
        int children = 0;
        for(int v : adj[u]) {
            if (v == par) continue;
            else if (d[v] > 0)
                low[u] = Math.min(low[u], d[v]);
            else {
                children++;
                dfs(v, u);
                low[u] = Math.min(low[u], low[v]);
                if (par != -1 && low[v] >= d[u]) ap[u] = true;
            }
        }
        if (par == -1 && children > 1) ap[u] = true;
    }

    static void get_articulation_points() {
        d = new int[n];
        low = new int[n];
        time = 1;
        ap = new Boolean[n];
        Arrays.fill(ap, false);
        for (int i = 0; i < n; i++)
            if (d[i] == 0) dfs(i, -1);
    }

    static class Input {
        BufferedReader br;
        StringTokenizer st;

        public Input(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() throws Exception {
            return br.readLine();
        }

        public boolean hasNext() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(br.readLine());

            } catch (Exception e) {
                return false;
            }
            return true;
        }
    }
}
