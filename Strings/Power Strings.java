// https://vjudge.net/problem/UVA-10298#google_vignette
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Objects;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String s=bf.readLine();
            if(Objects.equals(s,"."))
                break;
            LinkedList<Integer> divisores=new LinkedList<>();
            for (int i = 1; i <= s.length()/2; i++)
                if(s.length()%i==0)
                    divisores.add(i);
            int size=1;
            for(int i: divisores){
                if(size!=1)
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
                    size = s.length()/i;


            }
            System.out.println(size);

        }
    }
}
