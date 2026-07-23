#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l,int r){
    return uniform_int_distribution<int>(l,r)(rng);
}

//////////////////////////////////////////////////////////////////
// BRUTE FORCE
//////////////////////////////////////////////////////////////////

int brute(int L,int C,const vector<array<int,4>>& ops){

    vector<int> tape(L,1);

    for(auto [P,X,A,B]:ops){

        int S=0;
        for(int c:tape)
            if(c==P) S++;

        int l=(A+1LL*S*S)%L;
        int r=(A+1LL*(S+B)*(S+B))%L;

        if(l>r) swap(l,r);

        for(int i=l;i<=r;i++)
            tape[i]=X;
    }

    vector<int> F(C+1);

    for(int c:tape)
        F[c]++;

    return *max_element(F.begin(),F.end());
}

//////////////////////////////////////////////////////////////////
// PEGA TU SOLUCION AQUI
//////////////////////////////////////////////////////////////////

int mySolve(int L,int C,const vector<array<int,4>>& ops){

    struct T{
        int i,j,c;
        bool operator<(const T&o)const{
            if(i!=o.i) return i<o.i;
            return j<o.j;
        }
    };

    vector<int> F(C+1);
    F[1]=L;

    set<T> st;
    st.insert({0,L-1,1});

    for(auto [p,x,a,b]:ops){

        int s = F[p];
        int l = (a + s * s) % L;
        int r = (a + (b + s) * (b + s)) % L;
        if (l > r)
            swap(l, r);
        auto it = st.lower_bound({l, r, 0});
        if (it != st.begin())
            --it;
        while (true) {
            if (it==st.end())
                break;
            if (it->i > r)
                break;
            auto [aa,bb,cc] = *it;
            if (bb<l) {
                ++it;
                continue;
            }
            it=st.erase(it);
            if (cc==x) {
                F[x]-=bb-aa+1;
                l=min(l,aa);
                r=max(r,bb);
                continue;
            }
            if (aa>=l&&bb<=r) {
                F[cc]-=bb-aa+1;
                continue;
            }
            if (aa<=l&&bb>=r) {
                F[cc]-=r-l+1;
                if (l-1>=aa)
                    st.insert({aa,l-1,cc});
                if (r+1<=bb)
                    st.insert({r+1,bb,cc});
                continue;
            }
            if (l<=bb&&l>=aa) {
                F[cc]-=bb-l+1;
                st.insert({aa,l-1,cc});
            }
            else if (r>=aa&&r<=bb) {
                F[cc]-=r-aa+1;
                st.insert({r+1,bb,cc});
            }
        }
        F[x]+=r-l+1;
        st.insert({l,r,x});
    }
    return *max_element(F.begin(),F.end());
}

//////////////////////////////////////////////////////////////////

int main(){

    for(long long tc=1;;tc++){

        int L=rnd(2,20);
        int C=rnd(2,20);
        int N=rnd(5,55);

        vector<array<int,4>> ops;

        for(int i=0;i<N;i++){

            int P=rnd(1,C);
            int X=rnd(1,C);
            int A=rnd(0,500);
            int B=rnd(0,500);

            ops.push_back({P,X,A,B});
        }

        int a=brute(L,C,ops);
        int b=mySolve(L,C,ops);

        if(a!=b){

            cout<<"Found!\n";
            cout<<L<<" "<<C<<" "<<N<<"\n";

            for(auto [P,X,A,B]:ops)
                cout<<P<<" "<<X<<" "<<A<<" "<<B<<"\n";

            cout<<"\nCorrect = "<<a<<"\n";
            cout<<"Yours   = "<<b<<"\n";

            return 0;
        }

        if(tc%100000==0)
            cerr<<tc<<" cases\n";
    }
}
