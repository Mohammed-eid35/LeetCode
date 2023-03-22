// solution - 1
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] === target) {
                return [i, j];
            }
        }
    }
    return [];
};



// solution - 2
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const idx = {};

    for (let i = 0; i < nums.length; ++i) {
        if (target - nums[i] in idx)
            return [idx[target - nums[i]], i];

        idx[nums[i]] = i;
    }
    
    return [];
};