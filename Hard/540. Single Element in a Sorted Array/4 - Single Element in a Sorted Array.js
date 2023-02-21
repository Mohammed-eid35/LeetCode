/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNonDuplicate = function(nums) {
    const n = nums.length;
    let lo = 0, hi = n >> 1, res = -1;
    
    while (lo <= hi) {
        const mid = lo + (hi - lo >> 1);
        const idx = mid << 1;

        if (idx + 1 >= n || nums[idx] != nums[idx + 1]) {
            res = nums[idx];
            hi = mid - 1;
        }
        else
            lo = mid + 1
    }

    return res
};
