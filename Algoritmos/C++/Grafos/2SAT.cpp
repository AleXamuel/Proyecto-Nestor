struct TwoSatSolver {
    int n_vars;
    int n_vertices;
    vector<vector<int> > adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    TwoSatSolver(int _n_vars) : n_vars(_n_vars), n_vertices(2 * n_vars), adj(n_vertices), adj_t(n_vertices),
                                used(n_vertices), order(), comp(n_vertices, -1), assignment(n_vars) {
        order.reserve(n_vertices);
    }

    void dfs1(int v) {
        used[v] = true;
        for (int u: adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u: adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n_vertices, false);
        for (int i = 0; i < n_vertices; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n_vertices, -1);
        for (int i = 0, j = 0; i < n_vertices; ++i) {
            int v = order[n_vertices - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n_vars, false);
        for (int i = 0; i < n_vertices; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    void add_disjunction(int a, bool na, int b, bool nb) {
        a = 2 * a ^ na;
        b = 2 * b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }
};


TwoSatSolver solver(x);

//PATRONES 2-SAT COMPLETOS

// 1. A debe ser verdadero (Forzar A = true)
// Cláusula: (A ∨ A), equivale a ¬A ⇒ A
solver.add_disjunction(i, false, i, false);

// 2. A debe ser falso (Forzar A = false)
// Cláusula: (¬A ∨ ¬A), equivale a A ⇒ ¬A
solver.add_disjunction(i, true, i, true);

// 3. Si A entonces B (A ⇒ B)
// Cláusula: (¬A ∨ B), equivale a A ⇒ B, ¬B ⇒ ¬A
solver.add_disjunction(i, true, j, false);

// 4. Si no A entonces no B (¬A ⇒ ¬B)
// Cláusula: (A ∨ ¬B), equivale a ¬A ⇒ ¬B, B ⇒ A
solver.add_disjunction(i, false, j, true);

// 5. No ambos falsos (Al menos uno verdadero: A o B)
// Cláusula: (A ∨ B), equivale a ¬A ⇒ B, ¬B ⇒ A
solver.add_disjunction(i, false, j, false);

// 6. No ambos verdaderos (Al menos uno falso: ¬A o ¬B)
// Cláusula: (¬A ∨ ¬B), equivale a A ⇒ ¬B, B ⇒ ¬A
solver.add_disjunction(i, true, j, true);

// 7. A y B deben ser iguales (A ↔ B)
// Cláusulas: (A ∨ ¬B) y (¬A ∨ B), equivale a A ⇒ B y B ⇒ A
solver.add_disjunction(i, false, j, true);   // (A ∨ ¬B): B ⇒ A
solver.add_disjunction(i, true, j, false);   // (¬A ∨ B): A ⇒ B

// 8. A y B deben ser diferentes (A ⊕ B)
// Cláusulas: (A ∨ B) y (¬A ∨ ¬B), equivale a ¬A ⇒ B, ¬B ⇒ A, A ⇒ ¬B, B ⇒ ¬A
solver.add_disjunction(i, false, j, false);  // (A ∨ B): ¬A ⇒ B, ¬B ⇒ A
solver.add_disjunction(i, true, j, true);    // (¬A ∨ ¬B): A ⇒ ¬B, B ⇒ ¬A

══════════════════════════════════════════════════════════════════════════════
