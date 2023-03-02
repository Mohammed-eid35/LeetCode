class Solution:
    def compress(self, chars: List[str]) -> int:
        n = len(chars)

        i = j = 0
        while i < n:
            cnt = 1
            while i < n - 1 and chars[i] == chars[i + 1]:
                cnt += 1
                i += 1

            chars[j] = chars[i]
            j += 1
            i += 1

            if cnt > 1:
                num = str(cnt)

                for digit in num:
                    chars[j] = digit
                    j += 1

        return j
