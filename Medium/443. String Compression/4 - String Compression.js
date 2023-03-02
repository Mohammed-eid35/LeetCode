/**
 * @param {character[]} chars
 * @return {number}
 */
var compress = function(chars) {
    const n = chars.length;

    let i = 0, j = 0;
    while (i < n) {
        let cnt = 1;
        while (i < n - 1 && chars[i] == chars[i + 1]) {
            cnt++;
            i++;
        }

        chars[j++] = chars[i++];
        if (cnt > 1) {
            const num = cnt.toString();

            for (const digit of num)
                chars[j++] = digit;
        }
    }

    return j;
};
