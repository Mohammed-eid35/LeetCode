# Data Stream as Disjoint Intervals

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/data-stream-as-disjoint-intervals/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/y-SBX7-1prc)

<br>

## code

```cpp
class SummaryRanges {
private:
    set<int> nums;
public:
    SummaryRanges() {

    }
    
    void addNum(int value) {
        nums.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if (nums.empty()) return {};

        vector<vector<int>> intervals;
        int left = -1, right = -1;
        for (auto &num : nums) {
            if (left < 0)
                left = right = num;
            else if (num == right + 1)
                right = num;
            else {
                intervals.push_back({left, right});
                left = right = num;
            }
        }
        intervals.push_back({left, right});

        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
```
