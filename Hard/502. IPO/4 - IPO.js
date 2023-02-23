/**
 * @param {number} k
 * @param {number} w
 * @param {number[]} profits
 * @param {number[]} capital
 * @return {number}
 */
var findMaximizedCapital = function(k, w, profits, capital) {
    const n = profits.length;
    let projects = [];

    for (let i = 0; i < n; ++i)
        projects.push([capital[i], profits[i]]);

    projects.sort((A, B) => A[0] - B[0]);

    let maxProfit = new MaxPriorityQueue();
    let idx = 0;
    while (k--) {
        while (idx < n && projects[idx][0] <= w)
            maxProfit.enqueue(projects[idx++][1]);

        if (maxProfit.isEmpty())
            break;

        w += maxProfit.dequeue().priority;
    }

    return w;
};
