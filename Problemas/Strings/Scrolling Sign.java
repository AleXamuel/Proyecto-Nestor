// https://vjudge.net/problem/UVA-11576
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(bf.readLine());
        for (int i = 0; i < n; i++) {
            String[] l1=bf.readLine().split(" ");
            int k=Integer.parseInt(l1[0]);
            int m=Integer.parseInt(l1[1]);
            String s=bf.readLine();
            for (int j = 0; j < m-1; j++) {
                String t=bf.readLine();
                int index=0;
                int start=-1;
                for (int l = s.length()-k; l < s.length(); l++) {
                    if(s.charAt(l)==t.charAt(index)) {
                        index++;
                        if (start == -1)
                            start = l;
                    }
                    else if(start!=-1){
                        l=start;
                        index=0;
                        start=-1;
                    }
                }
                for (int l = index; l < t.length(); l++)
                    s=s.concat(String.valueOf(t.charAt(l)));
            }
            System.out.println(s.length());
        }
    }
}
