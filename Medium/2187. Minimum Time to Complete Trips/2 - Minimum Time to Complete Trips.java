class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        long lo = 0, hi = 1L * minTime(time) * totalTrips;
        long res = 0;
        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;

            if (numOfTrips(mid, time) >= totalTrips) {
                res = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return res;
    }

    public long numOfTrips(long curTime, int[] time) {
        long counter = 0;
        for (int t : time)
            counter += curTime / t;
        
        return counter;
    }

    public long minTime(int[] time) {
        int min = Integer.MAX_VALUE;
        for (int t : time) {
            if (t < min) {
                min = t;
            }
        }
        return min;
    }
}
