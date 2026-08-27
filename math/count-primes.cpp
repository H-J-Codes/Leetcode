class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> is_prime(n, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 4; i < n; i += 2)
            is_prime[i] = false;

        for (int i = 3; 1LL * i * i < n; i += 2) {
            if (is_prime[i]) {
                for (long long j = 1LL * i * i; j < n; j += 2 * i) {
                    is_prime[j] = false;
                }
            }
        }

        int ans = 1;

        for (int i = 3; i < n; i += 2) {
            if (is_prime[i])
                ans++;
        }

        return ans;
    }
};
