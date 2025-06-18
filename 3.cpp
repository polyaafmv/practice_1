#include <iostream>
#include <vector>

class FenwickTree {
private:
    std::vector<long long> bit;
    int size;

public:
    FenwickTree(int n) : size(n), bit(n + 1, 0) {}

    void update(int idx, int delta) {
        for (; idx <= size; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    FenwickTree ft(n);
    std::vector<long long> results;

    for (int op = 0; op < k; ++op) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int i, x;
            std::cin >> i >> x;
            ft.update(i, x);
        } else {
            int u, r;
            std::cin >> u >> r;
            results.push_back(ft.query(r) - ft.query(u - 1));
        }
    }

    for (long long res : results) {
        std::cout << res << std::endl;
    }

    return 0;
}