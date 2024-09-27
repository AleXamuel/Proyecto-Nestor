//https://codeforces.com/problemset/problem/1994/B
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >>t;
    for(int times=0;times<t;times++){
        int n;
        string s,t;
        cin>>n;
        cin>>s;
        cin>>t;
        bool c=true;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cout<<"YES"<<endl;
                c=false;
                break;
            }
            if(t[i]=='1'){
                cout<<"NO"<<endl;
                c=false;
                break;
            }
        }
        if(c){
            cout<<"YES"<<endl;
        }
    }
}
