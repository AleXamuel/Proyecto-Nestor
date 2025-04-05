//https://codeforces.com/problemset/problem/467/B
#include <iostream>
using namespace std;
int countSetBits(int n){
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {
    int n,m,k;
    cin >> n>>m>>k;
    int arr[m+1];
    for(int i=0 ; i<m+1;i++){
        cin>>arr[i];
    }
    int c=0;
    for(int i=0;i<m;i++){
        int a=(arr[i]^arr[m]);
        if(countSetBits(a)<=k){
            c++;
        }
    }
    cout<<c;
}
