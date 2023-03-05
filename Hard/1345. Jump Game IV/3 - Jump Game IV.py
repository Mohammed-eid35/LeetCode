class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n = len(arr)
        idxs =  defaultdict(list)
        
        for i in range(n):
            idxs[arr[i]].append(i)
        
        return self.BFS(n, idxs, arr)
    
    def BFS(self, n, idxs, arr):
        qu = deque()
        qu.append(0)

        vis = [False] * n
        vis[0] = True

        steps = 0;
        while qu:
            level = len(qu)
            for i in range(level):
                idx = qu.popleft()

                if idx == n - 1: 
                    return steps
                
                nxtIdxs = idxs[arr[idx]]
                nxtIdxs.append(idx - 1)
                nxtIdxs.append(idx + 1)

                for nxt in nxtIdxs:
                    if nxt >= 0 and nxt < n and not vis[nxt]:
                        qu.append(nxt)
                        vis[nxt] = True

                nxtIdxs.clear()

            steps += 1

        return -1
