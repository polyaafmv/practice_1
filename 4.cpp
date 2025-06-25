#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> inverse_permutation(const vector<int>& P) {
    int n = P.size();
    vector<int> P_inv(n);
    for (int i = 0; i < n; ++i) {
        P_inv[P[i] - 1] = i;
    }
    return P_inv;
}
string apply_permutation(const string& s, const vector<int>& P) {
    int n = s.size();
    string result(n, ' ');
    for (int i = 0; i < n; ++i) {
        result[i] = s[P[i]];
    }
    return result;
}
string decrypt(const string& encrypted, const vector<int>& P, int k) {
    int n = encrypted.size();
    vector<int> P_inv = inverse_permutation(P);
    string current = encrypted;
    for (int i = 0; i < k; ++i) {
        current = apply_permutation(current, P_inv);
    }
    return current;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> P(n);
    for (int i = 0; i < n; ++i) {
        cin >> P[i];
    }
    string encrypted;
    cin.ignore();
    getline(cin, encrypted);
    string original = decrypt(encrypted, P, k);
    cout << original << endl;
    return 0;
}