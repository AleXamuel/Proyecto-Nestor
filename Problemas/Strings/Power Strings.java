// https://vjudge.net/problem/UVA-10298#google_vignette
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner();
        PrintWriter pw = new PrintWriter(System.out);
        while (true){
            String r=sc.next();
            if(r.equals("."))
                break;
            LinkedList<Integer> div=new LinkedList<>();
            for (int i = 1; i <=r.length()/2 ; i++)
                if(r.length()%i==0)
                    div.add(i);
            boolean flag=true;
            int ans=-1;
            for(int i : div){
                String s = r.substring(0,i);
                flag=true;
                for (int j = i; j <= r.length()-i; j+=i) {
                    String t=r.substring(j,j+i);
                    if(!s.equals(t)){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    ans=i;
                    break;
                }
            }
            if(ans<1)
                System.out.println(1);
            else
                System.out.println(r.length()/ans);

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
