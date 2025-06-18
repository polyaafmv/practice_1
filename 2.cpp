#include <iostream>
#include <vector>
#include <numeric>

struct DSU {
    std::vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
            parent[root_i] = root_j;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;

    DSU dsu(n);

    for (int k = 0; k < m; ++k) {
        int u, v;
        std::cin >> u >> v;
        dsu.unite(u, v);
    }

    int components = 0;
    for (int i = 1; i <= n; ++i) {
        if (dsu.parent[i] == i)
            components++;
    }

    std::cout << components - 1 << std::endl;

    return 0;
}


