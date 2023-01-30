class Solution {
public:
    int tribonacci(int n) {
        vector<int> seq(3);
        seq[1] = seq[2] = 1;

        for (int i = 3; i <= n; ++i)
            seq[i % 3] = seq[(i - 1) % 3] + seq[(i - 2) % 3] + seq[(i - 3) % 3];

        return seq[n % 3];
    }
};
