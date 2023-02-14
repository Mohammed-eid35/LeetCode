class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int sum = 0, carry = 0;
        string res = "";

        while (i >= 0 || j >= 0 || carry) {
            sum = carry;
            sum += i >= 0 ? a[i--] - '0' : 0;
            sum += j >= 0 ? b[j--] - '0' : 0;

            carry = sum > 1;

            res += to_string(sum % 2);
        }
        
        reverse(res.begin(), res.end());

        return res;
    }
};
