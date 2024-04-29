

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        while (true){
            String s=bf.readLine();
            if(s.equals("e/o/i"))
                break;
            String[] l=s.split("/");
            String[] l1=l[0].split("\\s+");
            String[] l2=l[1].split("\\s+");
            String[] l3=l[2].split("\\s+");
            int c1=0;
            int c2=0;
            int c3=0;
            for (String string : l1) {
                boolean vowel = false;
                for (int j = 0; j < string.length(); j++) {
                    if (!vowel && (string.charAt(j) == 'a' || string.charAt(j) == 'e' || string.charAt(j) == 'i' || string.charAt(j) == 'o' || string.charAt(j) == 'u' || string.charAt(j) == 'y')) {
                        vowel = true;
                        c1++;
                    } else if (string.charAt(j) != 'a' && string.charAt(j) != 'e' && string.charAt(j) != 'i' && string.charAt(j) != 'o' && string.charAt(j) != 'u' && string.charAt(j) != 'y')
                        vowel = false;
                }
            }
            for (String string : l2) {
                boolean vowel = false;
                for (int j = 0; j < string.length(); j++) {
                    if (!vowel && (string.charAt(j) == 'a' || string.charAt(j) == 'e' || string.charAt(j) == 'i' || string.charAt(j) == 'o' || string.charAt(j) == 'u' || string.charAt(j) == 'y')) {
                        vowel = true;
                        c2++;
                    } else if (string.charAt(j) != 'a' && string.charAt(j) != 'e' && string.charAt(j) != 'i' && string.charAt(j) != 'o' && string.charAt(j) != 'u' && string.charAt(j) != 'y')
                        vowel = false;
                }
            }
            for (String string : l3) {
                boolean vowel = false;
                for (int j = 0; j < string.length(); j++) {
                    if (!vowel && (string.charAt(j) == 'a' || string.charAt(j) == 'e' || string.charAt(j) == 'i' || string.charAt(j) == 'o' || string.charAt(j) == 'u' || string.charAt(j) == 'y')) {
                        vowel = true;
                        c3++;
                    } else if (string.charAt(j) != 'a' && string.charAt(j) != 'e' && string.charAt(j) != 'i' && string.charAt(j) != 'o' && string.charAt(j) != 'u' && string.charAt(j) != 'y')
                        vowel = false;
                }
            }
            if(c1==5&&c2==7&&c3==5)
                System.out.println("Y");
            else if(c1!=5)
                System.out.println(1);
            else if (c2!=7)
                System.out.println(2);
            else
                System.out.println(3);




        }
    }
}
