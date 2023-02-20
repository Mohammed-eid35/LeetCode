/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let lo = 0, hi = nums.length - 1;
    while (lo <= hi) {
        const mid = Math.floor((lo + hi) / 2);
        if (nums[mid] == target) return mid;
        
        if (nums[mid] < target) 
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
};
