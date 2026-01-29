class Solution {
public:
    int numPrimeArrangements(int n) {
        const int MOD = 1000000007;

        int count = 0;
        for (int num = 2; num <= n; num++) {
            bool isPrime = true;
            for (int i = 2; i <= num / 2; i++) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
                count++;
        }
        int a = n - count;
        long long sum = 1;
        for (int i = 1; i <= count; i++) {
            sum = (sum * i) % MOD;
        }
        long long sum1 = 1;
        for (int i = 1; i <= a; i++) {
            sum1 = (sum1 * i) % MOD;
        }


        long long ans = (sum * sum1) % MOD;
    return ans;
    }
};