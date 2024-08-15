// https://vjudge.net/problem/UVA-422
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        int l= Integer.parseInt(bf.readLine());
        char[][] m=new char[l][l];
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                m[i][j]=(char)bf.read();
            }
            bf.readLine();
        }
        while(true){
            String s=bf.readLine();
            if(s.length()>l){
                System.out.println("Not found");
                return;
            }
            if(s.equals("0"))
                return;
            System.out.println(solve(m,s));
        }
    }
    static String solve(char[][] m,String s){
        for (int i = 0; i < m.length; i++) {
            int index=0;
            for (int j = 0; j < m.length; j++) {
                if(m[i][j]==s.charAt(index))
                    index++;
                else if(index>0){

                    index=0;
                    j--;
                }
                if(index==s.length())
                    return (i+1)+","+(j+2-index)+" "+(i+1)+","+(j+1);
            }
        }
        for (int i = m.length-1; i >=0; i--) {
            int index=0;
            for (int j = m.length-1; j >=0; j--) {
                if(m[i][j]==s.charAt(index))
                    index++;
                else if(index>0){
                    index=0;
                    j++;
                }
                if(index==s.length())
                    return (i+1)+","+(j+index)+" "+(i+1)+","+(j+1);
            }
        }
        for (int i = 0; i < m.length; i++) {
            int index=0;
            for (int j = 0; j < m.length; j++) {
                if(m[j][i]==s.charAt(index))
                    index++;
                else if(index>0) {

                    index = 0;
                    j--;
                }
                if(index==s.length())
                    return ((j+2)-index)+","+(i+1)+" "+(j+1)+","+(i+1);
            }
        }
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m.length; j++) {
                if(m[i][j]==s.charAt(0)) {
                    int d=searchDiagonal(m,s,i,j);
                    if (d==0)
                        return (i + 1) + "," + (j + 1) + " " + (i + s.length()) + "," + (j + s.length());
                    else if(d==1)
                        return (i + 1) + "," + (j + 1) + " " + (i + s.length()) + "," + (j +2- s.length());
                    else if(d==2)
                        return (i + 1) + "," + (j + 1) + " " + (i +2- s.length()) + "," + (j + s.length());
                    else if(d==3)
                        return (i + 1) + "," + (j + 1) + " " + (i +2- s.length()) + "," + (j +2- s.length());
                }
            }
        }
        return "Not found";
    }
    static int searchDiagonal(char[][]m,String s,int a,int b){
        int index=0;
        for (int i = 0; i < m.length&&a+i<m.length&&b+i<m.length; i++) {
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
        for (int i = 0; i < m.length&&a-i>=0&&b+i<m.length; i++) {
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
}
