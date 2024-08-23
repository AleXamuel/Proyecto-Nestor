//https://open.kattis.com/problems/quiteaproblem
import java.io.*;
import java.util.*;
class Main {
    static ArrayList<Integer>[] adj;
    static boolean[] state;

    public static void main(String[] args) throws Exception{
        Scanner sc=new Scanner();
        PrintWriter out=new PrintWriter(System.out);
        String t="problem";
        while (true){
            String s=sc.nextLine();
            if(s==null)
                return;
            if(s.length()<t.length())
                System.out.println("no");
            else {
                s = s.toLowerCase();
                System.out.println(KMP(s, t) ? "yes" : "no");
            }
        }

    }
    static int[] table(String pattern){
        int size=pattern.length();
        int APL=0;
        int[] table=new int[size];
        if(size==1)
            return table;
        for(int i=1;i<size;i++){
            while(APL>0 && pattern.charAt(APL)!= pattern.charAt(i))
                APL=table[APL-1];
            if(pattern.charAt(APL)==pattern.charAt(i))
                APL++;
            table[i]=APL;
        }
        return table;
    }

    static boolean KMP(String text, String pattern){
        int[] table=table(pattern);
        LinkedList<Integer> res=new LinkedList<>();
        int textSize=text.length();
        int patternSize= pattern.length();
        int index=0;
        int strIndex=0;
        int patIndex=0;
        while((textSize-index)>patternSize){
            while(patIndex<patternSize && text.charAt(strIndex)==pattern.charAt(patIndex)){
                strIndex++;
                patIndex++;
            }
            if(patIndex>=patternSize)
                return true;

            if(patIndex>0&&table[patIndex-1]>0){
                index=strIndex-table[patIndex-1];
                patIndex=table[patIndex-1];
            }
            else{
                if(strIndex==index)
                    strIndex++;
                index=strIndex;
                if(patIndex>0)
                    patIndex=table[patIndex-1];
            }

        }
        index=textSize-patternSize;
        int c=0;
        for (int i = 0; i < patternSize; i++) {
            if(text.charAt(index+i)==pattern.charAt(i))
                c++;
        }
        return c == patternSize;
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
