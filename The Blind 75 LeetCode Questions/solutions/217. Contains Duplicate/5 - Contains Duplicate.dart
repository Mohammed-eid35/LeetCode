// solution - 1
class Solution {
    bool containsDuplicate(List<int> nums) {
        nums.sort();

        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] == nums[i]) {
                return true;
            }
        }

        return false;
    }
}



// solution - 2
class Solution {
    bool containsDuplicate(List<int> nums) {
        Set<int> seen = Set<int>();
        for (int num in nums) {
            if (seen.contains(num))
                return true;
            
            seen.add(num);
        }
        return false;
    }
}