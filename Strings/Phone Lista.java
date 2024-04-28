
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.TreeSet;

public class Main {
//junacho
    public static void main(String[] args)throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(bf.readLine());
        for (int times = 0; times < t; times++) {
            int n=Integer.parseInt(bf.readLine());
            HashSet<String> nums=new HashSet<>();
            //System.out.println("Hash: "+nums+" "+nums.size());
            for (int i = 0; i < n; i++)
                nums.add(bf.readLine());
            boolean call=false;
            for(String i:nums){
                if(call)
                    break;
                if(i.length()==1)
                    continue;
                for (int j = 0; j < i.length(); j++) {
                    String p=i.substring(0,j);
                    if(nums.contains(p)){
                        call=true;
                        //System.out.println(p);
                        System.out.println("NO");
                        break;
                    }
                }

            }
            if(!call)
                System.out.println("YES");
        }
    }
}
