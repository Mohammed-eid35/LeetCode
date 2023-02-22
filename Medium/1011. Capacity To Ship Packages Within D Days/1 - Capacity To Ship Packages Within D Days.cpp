class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeights = 0, maxWeight = 0;
        for (auto &weight : weights) {
            totalWeights += weight;
            maxWeight = max(maxWeight, weight);
        }

        return BinarySearch(maxWeight, totalWeights, days, weights);
    }

    int BinarySearch(int lo, int hi, int days, vector<int> &weights) {
        int res = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo >> 1);

            if (numOfDaysNeeded(mid, weights) <= days) {
                res = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        return res;
    }

    int numOfDaysNeeded(int capacity, vector<int> &weights) {
        int days = 1, curCapacity = 0;
        for (auto &weight : weights) {
            if (curCapacity + weight > capacity) {
                days++;
                curCapacity = 0;
            }

            curCapacity += weight;
        }
        
        return days;
    }
};
