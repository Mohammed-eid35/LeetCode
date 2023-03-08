class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = maxPiles(piles), k = -1;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (numOfHours(mid, piles) <= h) {
                k = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        return k;
    }

    long long numOfHours(int k, vector<int>& piles) {
        long long totalHours = 0;

        for (int pile : piles)
            totalHours += (pile + k - 1) / k;
        
        return totalHours;
    }

    int maxPiles(vector<int>& piles) {
        return *max_element(piles.begin(), piles.end());
    }
};
