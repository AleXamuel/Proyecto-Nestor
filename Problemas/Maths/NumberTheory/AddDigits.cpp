#https://leetcode.com/problems/add-digits/?envType=problem-list-v2&envId=number-theory

# use congruence formula:  https://en.wikipedia.org/wiki/Digital_root
class Solution {
public:
    int addDigits(int num) {
        return (num == 0) ? 0:1 +(num - 1) % 9;
    }
};

#iterative version:
class Solution {
public:
    int addDigits(int num) {
        int dig=0;
        while(num!=0){
            dig=dig+num%10;
            num/=10;
            if(num==0 && dig>=10){
                num=dig;
                dig=0;
            }
            }
            return dig;
        }  
};
