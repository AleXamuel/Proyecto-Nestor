//https://leetcode.com/problems/n-queens/description/
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
class Solution {
public:
    vector<vector<int>> state;
    int n;
    vector<vector<string>> ans;
    void rellenar(int x, int y) {
        For(i, 0, n) state[x][i]++;
        For(i, 0, n) if (i != x) state[i][y]++;
        int i = x + 1;
        int j = y + 1;
        while (i < n && j < n)
            state[i++][j++]++;
        i = x - 1;
        j = y - 1;
        while (i >= 0 && j >= 0)
            state[i--][j--]++;
        i = x + 1;
        j = y - 1;
        while (i < n && j >= 0)
            state[i++][j--]++;
        i = x - 1;
        j = y + 1;
        while (i >= 0 && j < n)
            state[i--][j++]++;
    }

    void desrellenar(int x, int y) {
        For(i, 0, n) state[x][i]--;
        For(i, 0, n) if (i != x) state[i][y]--;
        int i = x + 1;
        int j = y + 1;
        while (i < n && j < n)
            state[i++][j++]--;
        i = x - 1;
        j = y - 1;
        while (i >= 0 && j >= 0)
            state[i--][j--]--;
        i = x + 1;
        j = y - 1;
        while (i < n && j >= 0)
            state[i++][j--]--;
        i = x - 1;
        j = y + 1;
        while (i >= 0 && j < n)
            state[i--][j++]--;
    }
    void f(int i, vector<string>& cur) {
        if (i == n) {
            ans.push_back(cur);
            return;
        }
        For(j, 0, n) {
            if (state[i][j] == 0) {
                rellenar(i, j);
                cur[i][j] = 'Q';
                f(i + 1, cur);
                desrellenar(i, j);
                cur[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int N) {
        n = N;
        vector<string> grid(n, string(n, '.'));
        state.assign(n, vector<int>(n, 0));
        f(0, grid);
        return ans;
    }
};
