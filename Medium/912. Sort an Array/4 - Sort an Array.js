/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    let lo = nums[0], hi = nums[0];
    const freq = {};

    for (const num of nums) {
        freq[num] = freq[num] + 1 || 1;
        lo = Math.min(lo, num);
        hi = Math.max(hi, num);
    }

    let idx = 0;
    for (let num = lo; num <= hi; ++num)
        while (freq[num]--)
            nums[idx++] = num;
    
    return nums;
};
