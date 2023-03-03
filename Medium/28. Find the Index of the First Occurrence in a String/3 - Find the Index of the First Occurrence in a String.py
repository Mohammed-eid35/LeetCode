# solution - 1
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)


# solution - 2
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n, m = len(haystack), len(needle)

        for i in range(0, n - m + 1):
            for j in range(0, m):
                if needle[j] != haystack[i + j]:
                    break
                
                if j == m - 1:
                    return i

        return -1
