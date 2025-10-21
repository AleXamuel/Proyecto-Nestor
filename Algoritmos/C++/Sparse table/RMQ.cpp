int st[20][MAX],lg[MAX+1];;
int getMin(int L , int R) {
    int i = lg[R - L + 1];
    return min(st[i][L], st[i][R - (1 << i) + 1]);
}
lg[1] = 0;
for (int i = 2; i <= MAX; i++)
    lg[i] = lg[i/2] + 1;
copy(array.begin(), array.end(), st[0]);
for (int i = 1; i <= 19; i++)
    for (int j = 0; j + (1 << i) <= s.size(); j++)
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
