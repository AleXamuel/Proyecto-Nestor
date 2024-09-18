#include <iostream>
using namespace std;
#include <vector>
#include <stack>
int m;
vector<vector<int>> adj;
vector<vector<int>> adjT;
stack<int> top_sort;
vector<int> scc;
vector<bool> state;
int nscc;
vector<bool> variables;

void TWOSAT() {
	adj.resize(m);
	adjT.resize(m);
}

void addEdge(int a, int b) {
	adj[a].push_back(b);
	adjT[b].push_back(a);
}

void dfs(int u) {
	state[u] = true;
	for (int v : adj[u])
		if (!state[v])
			dfs(v);
	top_sort.push(u);
}

void dfs_kos(int u) {
	scc[u] = nscc;
	state[u] = true;
	for (int v : adjT[u])
		if (!state[v])
			dfs_kos(v);
}

void strongly_cc() {
	state.resize(m,false);
	for (int i = 0; i < m; i++)
		if (!state[i])
			dfs(i);
	scc.resize(m);
	nscc = 1;
	fill(state.begin(), state.end(), false);
	while (!top_sort.empty()) {
		int u = top_sort.top();
		top_sort.pop();
		if (!state[u]) {
			dfs_kos(u);
			nscc++;
		}
	}
}

void asignarVariables() {
	variables.resize(m, false);
	for (int i = 0; i < m/2; i++)
		variables[i] = scc[i] > scc[i + (m / 2)];
}


int main() {
	int n,o;
	cin >> n >>o;
	m = 2 * o;
	TWOSAT();
	for (int i = 0; i < n; i++){
		char signo1,signo2;
		int num1, num2;
		cin >> signo1 >>num1>>signo2>>num2;
		num1--;
		num2--;
		if (signo1=='+' && signo2=='+') {
			addEdge(num1 + o, num2);
			addEdge(num2 + o, num1);
		}
		else if (signo1=='+' && signo2=='-') {
			addEdge(num1 + o, num2 + o);
			addEdge(num2, num1);
		}
		else if (signo1=='-' && signo2=='+') {
			addEdge(num1, num2);
			addEdge(num2 + o, num1 + o);
		}
		else {
			addEdge(num1, num2 + o);
			addEdge(num2, num1 + o);
		}
	}
	strongly_cc();
	for (int i = 0; i < o; i++)
		if (scc[i] == scc[i + o]) {
			cout<<"IMPOSSIBLE";
			return 0;
		}
	asignarVariables();
	for (int i = 0; i < o; i++)
		cout<< (variables[i] ? "+ " : "- ");

	
	return 0;
}
