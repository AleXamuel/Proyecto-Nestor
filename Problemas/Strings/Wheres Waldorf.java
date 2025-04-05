// https://open.kattis.com/problems/stringmatching
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(bf.readLine());
        for (int time = 0; time < t; time++) {
            bf.readLine();
            String[] l1=bf.readLine().split(" ");
            int m=Integer.parseInt(l1[0]);
            int n=Integer.parseInt(l1[1]);
            char[][] l=new char[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    char c=(char)bf.read();
                    if(c>='A'&&c<='Z')
                        c+=32;
                    l[i][j]=c;
                }
                bf.readLine();
            }
            int cases=Integer.parseInt(bf.readLine());
            for (int times = 0; times < cases; times++) {
                String s=bf.readLine().toLowerCase();
                ArrayList<int[]> ans=solve(l,s);
                Collections.sort(ans,new CustomComparator());
                System.out.println(ans.get(0)[0]+" "+ans.get(0)[1]);
            }
            if(time!=t-1)
                System.out.println();
        }
    }
    static ArrayList<int[]> solve(char[][] m,String s){
        ArrayList<int[]> l=new ArrayList<>();
        for (int i = 0; i < m.length; i++) {
            int index=0;
            for (int j = 0; j < m[0].length; j++) {
                if(m[i][j]==s.charAt(index))
                    index++;
                else if(index>0){
                    index=0;
                    j--;
                }
                if(index==s.length()) {
                    l.add(new int[]{i + 1, j + 2 - index});
                    break;
                }
            }
        }
        for (int i = m.length-1; i >=0; i--) {
            int index=0;
            for (int j = m[0].length-1; j >=0; j--) {
                if(m[i][j]==s.charAt(index))
                    index++;
                else if(index>0){
                    index=0;
                    j++;
                }
                if(index==s.length()){
                    l.add(new int[]{i + 1, j + index});
                    break;
                }
            }
        }
        for (int i = 0; i < m[0].length; i++) {
            int index=0;
            for (int j = 0; j < m.length; j++) {
                if(m[j][i]==s.charAt(index))
                    index++;
                else if(index>0) {
                    index = 0;
                    j--;
                }
                if(index==s.length()){
                    l.add(new int[]{j + 2-index, i + 1});
                    break;
                }

            }
        }
        for (int i = 0; i <m.length ; i++) {
            for (int j = 0; j < m[0].length; j++) {
                if(m[i][j]==s.charAt(0))
                    if(searchDownUp(m,s,i,j))
                        l.add(new int[]{i+1,j+1});
            }
        }
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m[0].length; j++) {
                if(m[i][j]==s.charAt(0)) {
                    int d=searchDiagonal(m,s,i,j);
                    if (d==0) {
                        l.add(new int[]{i + 1, j + 1});
                        break;
                    }
                    else if(d==1){
                        l.add(new int[]{i + 1, j + 1});
                        break;
                    }
                    else if(d==2){
                        l.add(new int[]{i + 1, j + 1});
                        break;
                    }
                    else if(d==3){
                        l.add(new int[]{i + 1, j + 1});
                        break;
                    }
                }
            }
        }
        return l;
    }
    static boolean searchDownUp(char[][]m,String s,int a,int b){
        int index=0;
        for (int i = a; i >=0; i--) {
            if(m[i][b]==s.charAt(index))
                index++;
            else
                return false;
            if(index==s.length())
                return true;

        }
        return false;
    }
    static int searchDiagonal(char[][]m,String s,int a,int b){
        int index=0;
        for (int i = 0; i < m.length&&a+i<m.length&&b+i<m[0].length; i++) {
            if(m[a+i][b+i]==s.charAt(index))
                index++;
            else break;
            if(index==s.length())
                return 0;
        }index=0;
        for (int i = 0; i < m.length&&a+i<m.length&&b-i>=0; i++) {
            if(m[a+i][b-i]==s.charAt(index))
                index++;
            else break;
            if(index==s.length())
                return 1;
        }index=0;
        for (int i = 0; i < m.length&&a-i>=0&&b+i<m[0].length; i++) {
            if(m[a-i][b+i]==s.charAt(index))
                index++;
            else break;
            if(index==s.length())
                return 2;
        }index=0;
        for (int i = 0; i < m.length&&a-i>=0&&b-i>=0; i++) {
            if(m[a-i][b-i]==s.charAt(index))
                index++;
            else break;
            if(index==s.length())
                return 3;
        }
        return -1;
    }
    public static class CustomComparator implements Comparator<int[]> {
        @Override
        public int compare(int[] a, int[] b) {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            } else {
                return Integer.compare(a[1], b[1]);
            }
        }
    }
}
