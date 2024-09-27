import java.util.LinkedList;
import java.util.Scanner;

public class ATrivialProblem {
    public static void main(String[] args) {
        Scanner tec=new Scanner(System.in);
        LinkedList<Integer> nums=new LinkedList<>();
        int n=tec.nextInt();
        boolean c=false;
        for (int i = 1; i <=n*10; i++) {
            if(findTrailingZeros(i)==n) {
                nums.add(i);
                c=true;
            }
            else if(c)
                break;

        }
        System.out.println(nums.size());
        if(!nums.isEmpty())
            for (int i : nums)
                System.out.print(i+" ");

    }
    static int findTrailingZeros(int n) {
        int count = 0;
        for (int i = 5; n / i >= 1; i *= 5)
            count += n / i;

        return count;
    }
}
