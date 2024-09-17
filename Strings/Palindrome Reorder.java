//https://vjudge.net/problem/CSES-1755
//https://vjudge.net/problem/UVA-1223
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        String s=sc.next();
        HashMap<Character, Integer> map=new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            if(!map.containsKey(s.charAt(i)))
                map.put(s.charAt(i),1);
            else
                map.put(s.charAt(i),map.get(s.charAt(i))+1);
        }
        int n=0;
        char c='1';
        char[] ans=new char[s.length()];
        int j=0;
        int k=s.length()-1;
        for (Map.Entry<Character,Integer> e :map.entrySet()){
            char a=e.getKey();
            int f=e.getValue();
            if(f%2==1){
                if(c!='1'){
                    System.out.println("NO SOLUTION");
                    return;
                }
                c=a;
                n=f;
                for (int i = s.length()/2-f/2; i <= s.length()/2+f/2; i++)
                    ans[i]=c;

            }
            else{
                for (int i=0;i<f/2;j++,i++)
                    ans[j]=a;
                for (int i = 0; i < f/2; i++,k--)
                    ans[k]=a;

            }
        }
        System.out.println(ans);
    }
    private static class Edge implements Comparable<Edge>{
        int a;
        char w;
        public Edge(int u, char c){
            a=u;
            w=c;
        }
        public int compareTo(Edge o){
            if(w<o.w)
                return -1;
            if(w>o.w)
                return 1;
            if(a<o.a)
                return -1;
            if(a>o.a)
                return 1;
            return 0;
        }
        public String toString() {
            return "<"+a+", "+w+">";
        }
    }
    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public boolean ready() throws IOException {
            return br.ready();
        }

        String nextLine() throws IOException {
            return br.readLine();
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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        char nextChar() throws IOException {
            return (char) br.read();
        }

    }
}
