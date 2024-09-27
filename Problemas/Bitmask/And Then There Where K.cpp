//https://codeforces.com/problemset/problem/1527/A
#include <iostream>
using namespace std;
int countSetBits(int n){
    int count = 0;
    while (n){
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {
    int t;
    cin >>t;
    for(int times=0;times<t;times++){
        int n;
        cin>>n;
        int aux=n;
        int c=0;
        while(n){
            aux=n-1;
            n&=n-1;
            c++;
        }
        cout<<(aux)<<endl;
    }
}
