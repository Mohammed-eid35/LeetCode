class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mn = INT_MAX;
        priority_queue<int> pq;
        
        for (int &num : nums) {
            if (num & 1)
                num <<= 1;
            
            mn = min(mn, num);
            pq.push(num);
        }

        int res = INT_MAX;
        while (true) {
            int mx = pq.top();
            pq.pop();

            res = min(res, mx - mn);

            if (mx & 1)
                break;
            
            mn = min(mn, mx >> 1);
            pq.push(mx >> 1);
        }

        return res;
    }
};
