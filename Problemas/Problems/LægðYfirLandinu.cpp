//https://open.kattis.com/problems/laegdyfirlandinu
#include <iostream>
#include<vector>
using namespace std;

bool cond(vector<vector<int>> grid, int r, int c) {
	return grid[r - 1][c] > grid[r][c] && grid[r + 1][c] > grid[r][c] && grid[r][c - 1] > grid[r][c] && grid[r][c + 1] > grid[r][c];
}

string solve(vector<vector<int>> grid, int n, int m) {
	for (int i = 1; i < n-1; i++)
		for (int j = 1; j < m-1; j++) 
			if (cond(grid, i, j))
				return "Jebb";
	return "Neibb";
}
int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<vector<int>> grid(n,vector<int>(m,0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int k; cin >> k;
			grid[i][j] = k;
		}
	cout << solve(grid, n, m);
	return 0;
}
