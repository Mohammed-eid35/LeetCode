// solution - 1
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    return haystack.indexOf(needle);
};


// solution - 2
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    const n = haystack.length, m = needle.length;

    for (let i = 0; i <= n - m; ++i) {
        for (let j = 0; j < m; ++j) {
            if (needle[j] != haystack[i + j])
                break;
            
            if (j == m - 1)
                return i;
        }
    }

    return -1;
};
