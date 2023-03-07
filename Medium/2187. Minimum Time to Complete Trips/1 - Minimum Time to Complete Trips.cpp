class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo = 0, hi = 1LL * minTime(time) * totalTrips;
        long long res = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (numOfTrips(mid, time) >= totalTrips) {
                res = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return res;
    }

    long long numOfTrips(long long curTime, vector<int>& time) {
        long long counter = 0;
        for (int t : time)
            counter += curTime / t;
        
        return counter;
    }

    long long minTime(vector<int>& time) {
        return *min_element(time.begin(), time.end());
    }
};
