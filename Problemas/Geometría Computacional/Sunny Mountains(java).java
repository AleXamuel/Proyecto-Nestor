//https://vjudge.net/problem/UVA-920
import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception{
        Scanner sc=new Scanner();
        DecimalFormat f=new DecimalFormat("#0.00");
        PrintWriter out=new PrintWriter(System.out);
        int t=sc.nextInt();
        for (int times = 0; times < t; times++) {
            int n=sc.nextInt();
            Point[] a=new Point[n];
            for (int i = 0; i < n; i++)
                a[i]=new Point(sc.nextInt(),sc.nextInt());
            Arrays.sort(a);
            double c=d(a[n-1],a[n-2]);
            Point s=a[n-2];

            for (int i = n-3; i >=0 ; i--) {
                if(a[i].y>s.y){
                    double m= (a[i+1].y - a[i].y) /(a[i+1].x-a[i].x);
                    double x= (s.y-a[i].y+a[i].x*m)/m;
                    c+=d(a[i],new Point(x,s.y));
                    s=a[i];
                }
            }
            out.println(f.format(c));
        }
        out.close();
    }
    static double d(Point a,Point b){
        return Math.hypot(a.x-b.x,a.y-b.y);
    }
    static class Point implements Comparable<Point>{
        double x,y;
        public Point(double a, double b){
            x=a;
            y=b;
        }

        public int compareTo(Point o) {
            if(x<o.x)return -1;
            return 1;
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
