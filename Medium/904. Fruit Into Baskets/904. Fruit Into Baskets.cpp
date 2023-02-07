class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> baskets;
        int n = fruits.size(), left = 0, right = 0;

        while (right < n) {
            baskets[fruits[right]]++;
            
            if (baskets.size() > 2) {
                if (--baskets[fruits[left]] == 0)
                    baskets.erase(fruits[left]);

                left++;
            }

            right++;
        }

        return right - left;
    }
};
