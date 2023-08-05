// AtCoder ABC 250 E - Prefix Equality (水色, 500 点)
#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
} rng;

int main(void) {
    int N;
    cin >> N;
    auto hasing = [&]() -> vector<uint64_t> {
        vector<uint64_t> hash(N + 1, 0);
        set<long long> S;
        for (int i = 0; i < N; i++) {
            long long x;
            cin >> x;
            if (S.count(x)) {
                hash[i + 1] = hash[i];
                continue;
            }
            S.insert(x);
            hash[i + 1] = hash[i] ^ rng(x);
        }
        return hash;
    };
    const auto& hashA = hasing();
    const auto& hashB = hasing();
    int Q;
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        if (hashA[x] == hashB[y])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}