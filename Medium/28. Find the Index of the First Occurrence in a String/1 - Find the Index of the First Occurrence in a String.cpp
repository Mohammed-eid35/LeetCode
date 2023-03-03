// solution - 1
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};


// solution - 2
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();

        for (int i = 0; i <= n - m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (needle[j] != haystack[i + j])
                    break;
                
                if (j == m - 1)
                    return i;
            }
        }

        return -1;
    }
};
