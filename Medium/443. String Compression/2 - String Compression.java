class Solution {
    public int compress(char[] chars) {
        int n = chars.length;

        int i = 0, j = 0;
        while (i < n) {
            int cnt = 1;
            while (i < n - 1 && chars[i] == chars[i + 1]) {
                cnt++;
                i++;
            }

            chars[j++] = chars[i++];
            if (cnt > 1) {
                char[] num = String.valueOf(cnt).toCharArray();

                for (char digit : num)
                    chars[j++] = digit;
            }
        }

        return j;
    }
}
