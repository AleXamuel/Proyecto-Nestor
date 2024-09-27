//https://vjudge.net/problem/UVA-10927
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        Scanner sc=new Scanner();
        PrintWriter out=new PrintWriter(System.out);
        int ds=1;
        while (true){
            int n=sc.nextInt();
            if(n==0)
                break;
            HashMap<Double,Integer> map=new HashMap<>();
            TreeSet<T> set=new TreeSet<>();
            Point[] a=new Point[n];
            for (int i = 0; i < n; i++)
                a[i]=new Point(sc.nextInt(),sc.nextInt(),sc.nextInt());
            Arrays.sort(a);
            for (int i = 0; i < n; i++) {
                double m=m(a[i]);
                if(!map.containsKey(m))
                    map.put(m,a[i].z);
                else
                    if(map.get(m)>=a[i].z) {
                        int x=a[i].x;
                        int y=a[i].y;
                        set.add(new T(x,y));
                    }
                    else if(map.get(m)<a[i].z)
                        map.put(m,a[i].z);

            }
            out.println("Data set "+ds+":");
            if(set.size()==0)
                out.println("All the lights are visible.");
            else{
                out.println("Some lights are not visible:");
                while (set.size()>1){
                    T s=set.pollFirst();
                    out.println("x = "+s.x+", y = "+s.y+";");
                }
                T s=set.pollFirst();
                out.println("x = "+s.x+", y = "+s.y+".");
            }
            ds++;
        }
        out.close();
    }
    static double m(Point a){
        return (double) (a.y) /(a.x);
    }
    static class T implements Comparable<T>{
        int x,y;
        public T(int a, int b){
            x=a;
            y=b;
        }

        public int compareTo(T o) {
            if(x<o.x) return -1;
            if(x>o.x) return 1;
            if(y<o.y) return -1;
            if(y>o.y) return 1;
            return 0;
        }
        public String toString(){
            return "("+x+", "+y+")";
        }
    }
    static class Point implements Comparable<Point>{
        int x,y,z;
        public Point(int a, int b, int c ){
            x=a;
            y=b;
            z=c;
        }

        public int compareTo(Point o) {
            if(Math.abs(x)<Math.abs(o.x)) return -1;
            if(Math.abs(x)>Math.abs(o.x)) return 1;
            if(Math.abs(y)<Math.abs(o.y)) return -1;
            if(Math.abs(y)>Math.abs(o.y)) return 1;
            return 0;
        }
        public String toString(){
            return "("+x+", "+y+")";
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
        double nextDouble(){
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
