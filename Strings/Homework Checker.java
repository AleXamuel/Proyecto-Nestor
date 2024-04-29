

import java.util.Scanner;

public class Main {
    public static void main(String[] args)throws Exception {
        Scanner tec=new Scanner(System.in);
        int sum=0;
        while (tec.hasNext()){
            String s=tec.nextLine();
            if(s.charAt(s.length()-1)=='?')
                continue;
            int a=-1;
            int b=-1;
            int c=-1;
            int i=0;
            while (s.charAt(i)!='+'&&s.charAt(i)!='-')
                i++;
            int j=i;
            while (s.charAt(j)!='=')
                j++;
            a=Integer.parseInt(s.substring(0,i));
            b=Integer.parseInt(s.substring(i+1,j));
            c=Integer.parseInt(s.substring(j+1));
            
          
            if(s.charAt(i)=='+')
                if(a+b==c){
                    sum++;
                    continue;
                }
            if (a-b==c){
                sum++;
               
            }
           

        }
        System.out.println(sum);
    }
}
