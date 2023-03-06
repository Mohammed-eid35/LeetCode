// solution - 1
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var findKthPositive = function(arr, k) {
    for (let num of arr) {
        if (num <= k)
            k++;
        else
            break;
    }
    
    return k;
};

// solution - 2
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var findKthPositive = function(arr, k) {
    let lo = 0, hi = arr.length - 1;
    while (lo <= hi) {
        const mid = lo + (hi - lo >> 1);
        
        if (arr[mid] - mid - 1 < k)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo + k;
};
