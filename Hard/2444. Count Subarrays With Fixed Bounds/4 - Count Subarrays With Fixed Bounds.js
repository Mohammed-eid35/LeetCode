/**
 * @param {number[]} nums
 * @param {number} minK
 * @param {number} maxK
 * @return {number}
 */
var countSubarrays = function(nums, minK, maxK) {
    const n = nums.length;
    let res = 0, minPos = -1, maxPos = -1, leftBound = -1;

    for (let i = 0; i < n; ++i) {
        if (nums[i] < minK || nums[i] > maxK)
            leftBound = i;
        
        if (nums[i] == minK) 
            minPos = i;
        
        if (nums[i] == maxK)
            maxPos = i;

        res += Math.max(0, Math.min(maxPos, minPos) - leftBound);
    }
    
    return res;
};
