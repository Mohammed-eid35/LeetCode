/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDeviation = function(nums) {
    let min = Infinity;
    const pq = new MaxPriorityQueue();
        
    for (let num of nums) {
        if (num & 1)
            num <<= 1;
            
        min = Math.min(min, num);
        pq.enqueue(num);
    }

    let res = Infinity;
    while (true) {
        let max = pq.dequeue().priority;

        res = Math.min(res, max - min);

        if (max & 1)
            break;
            
        min = Math.min(min, max >> 1);
        pq.enqueue(max >> 1);
    }

    return res;
};
