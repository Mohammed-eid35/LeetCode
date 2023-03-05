/**
 * @param {number[]} arr
 * @return {number}
 */
var minJumps = function(arr) {
    const n = arr.length;
    const idxs = {};
    
    for (let i = 0; i < n; ++i)
        if (idxs[arr[i]])
            idxs[arr[i]].push(i);
        else
            idxs[arr[i]] = [i];
    
    return BFS(n, idxs, arr);
};

const BFS = (n, idxs, arr) => {
    const qu = [0];

    const vis = Array(n).fill(false);
    vis[0] = true;

    let steps = 0;
    while (qu.length) {
        let level = qu.length;
        while (level--) {
            const idx = qu.shift();

            if (idx == n - 1) 
                return steps;
            
            
            idxs[arr[idx]].push(idx - 1);
            idxs[arr[idx]].push(idx + 1);

            for (const nxt of idxs[arr[idx]]) {
                if (nxt >= 0 && nxt < n && !vis[nxt]) {
                    qu.push(nxt);
                    vis[nxt] = true;
                }
            }

            idxs[arr[idx]] = [];
        }

        steps++;
    }

    return -1;
};
