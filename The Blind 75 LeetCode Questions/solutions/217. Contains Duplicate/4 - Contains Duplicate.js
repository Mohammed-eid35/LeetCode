// solution - 1
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    nums.sort();
    
    for (let i = 1; i < nums.length; i++) {
        if (nums[i - 1] === nums[i]) {
            return true;
        }
    }
    
    return false;
};



// solution - 2
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    const seen = {};
    for (let i = 0; i < nums.length; ++i) {
        if (seen[nums[i]])
            return true;
        
        seen[nums[i]] = seen[nums[i]] + 1 || 1;
    }
    
    return false;
};