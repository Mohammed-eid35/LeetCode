// solution - 1
class Solution {
    List<int> twoSum(List<int> nums, int target) {
        final n = nums.length;
        for (var i = 0; i < n; ++i) {
            for (var j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                   return [i, j];
                }
            }
        }
        return [];
    }
}



// solution - 2
import 'dart:collection';

class Solution {
    List<int> twoSum(List<int> nums, int target) {
        final idx = HashMap<int, int>();
        final n = nums.length;

        for (var i = 0; i < n; ++i) {
            if (idx.containsKey(target - nums[i])) {
                return [idx[target - nums[i]]!, i];
            }
    
            idx[nums[i]] = i;
        }

        return [];
    }
}