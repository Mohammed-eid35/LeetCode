class Solution {
    public int minimumDeviation(int[] nums) {
        int min = Integer.MAX_VALUE;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for (int num : nums) {
            if ((num & 1) == 1)
                num <<= 1;
            
            min = Math.min(min, num);
            pq.add(num);
        }

        int res = Integer.MAX_VALUE;
        while (true) {
            int max = pq.poll();

            res = Math.min(res, max - min);

            if ((max & 1) == 1)
                break;
            
            min = Math.min(min, max >> 1);
            pq.add(max >> 1);
        }

        return res;
    }   
}
