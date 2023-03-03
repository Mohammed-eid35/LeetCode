// solution - 1
class Solution {
    public int strStr(String haystack, String needle) {
        return haystack.indexOf(needle);
    }
}

// solution - 2
class Solution {
    public int strStr(String haystack, String needle) {
        int n = haystack.length(), m = needle.length();

        for (int i = 0; i <= n - m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (needle.charAt(j) != haystack.charAt(i + j))
                    break;
                
                if (j == m - 1)
                    return i;
            }
        }

        return -1;
    }
}
