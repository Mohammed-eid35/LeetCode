class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;
       Map<Integer, List<Integer>> idxs = new HashMap<>();
        
        for (int i = 0; i < n; ++i)
            idxs.computeIfAbsent(arr[i], v -> new ArrayList<>()).add(i);
        
        return BFS(n, idxs, arr);
    }

    int BFS(int n, Map<Integer, List<Integer>> idxs, int[] arr) {
        Queue<Integer> qu = new LinkedList<>();
        qu.add(0);

        boolean[] vis = new boolean[n];
        vis[0] = true;

        int steps = 0;
        while (!qu.isEmpty()) {
            int level = qu.size();
            while (level-- > 0) {
                int idx = qu.poll();

                if (idx == n - 1) 
                    return steps;
                
                List<Integer> nxtIdxs = idxs.get(arr[idx]);
                nxtIdxs.add(idx - 1);
                nxtIdxs.add(idx + 1);

                for (int nxt : nxtIdxs) {
                    if (nxt >= 0 && nxt < n && !vis[nxt]) {
                        qu.add(nxt);
                        vis[nxt] = true;
                    }
                }

                nxtIdxs.clear();
            }

            steps++;
        }

        return -1;
    }
}
