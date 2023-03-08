class Solution {
    public int minEatingSpeed(int[] piles, int h) {
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

    public long numOfHours(int k, int[] piles) {
        long totalHours = 0;

        for (int pile : piles)
            totalHours += (pile + k - 1) / k;
        
        return totalHours;
    }

    public int maxPiles(int[] piles) {
        int max = piles[0];
        for(int i=1;i<piles.length;i++){
            if(piles[i] > max){
                max = piles[i];
            }
        }
        return max;
    }
}
