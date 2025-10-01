vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = min(r - i, p[l + (r - i)]);
        while (s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for (auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}
void f(){
  vector<int> A = manacher(s), Dood(s.size(),0), Deven(s.size(),0);
  For(i, 0, A.size()) {
      if (i & 1) {
          Deven[i>>1]=A[i]/2;
          //Deven[i>>1]*=2;
      }
      else {
          Dood[i>>1]=(A[i]+1)/2;
          //Dood[i>>1]+=Dood[i>>1]-1;
        }
    }
}
