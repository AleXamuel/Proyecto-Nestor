https://vjudge.net/problem/UVA-455
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Objects;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(bf.readLine());
        bf.readLine();
        for (int h = 0; h < n; h++) {
            String s=bf.readLine();
            LinkedList<Integer> divisores=new LinkedList<>();
            for (int i = 1; i <= s.length()/2; i++)
                if(s.length()%i==0)
                    divisores.add(i);
            int size=0;
            for(int i: divisores){
                if(size!=0)
                    break;
                boolean cambio= true;
                String p1=s.substring(0,i);
                for (int j = i; j+i <=s.length() ; j+=i) {
                    if(!cambio)
                        break;
                    String p2=s.substring(j,j+i);
                    if(!p1.equals(p2))
                        cambio=false;
                }
                if(cambio)
                    size = i;
            }
            if(size==0)
                System.out.println(s.length());
            else
                System.out.println(size);
            
            if(h+1<n) {
                System.out.println();
                bf.readLine();
            }
        }
    }
}
