class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.length;
        int[][] projects = new int[n][2];

        for (int i = 0; i < n; ++i) {
            projects[i][0] = capital[i];
            projects[i][1] = profits[i];
        }
        
        Arrays.sort(projects, (A, B) -> Integer.compare(A[0], B[0]));

        PriorityQueue<Integer> maxProfit = new PriorityQueue<>(Collections.reverseOrder());
        int idx = 0;
        while (k-- > 0) {
            while (idx < n && projects[idx][0] <= w)
                maxProfit.add(projects[idx++][1]);

            if (maxProfit.isEmpty())
                break;
            
            w += maxProfit.poll();
        }

        return w;
    }
}
