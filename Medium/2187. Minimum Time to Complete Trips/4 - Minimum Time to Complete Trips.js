/**
 * @param {number[]} time
 * @param {number} totalTrips
 * @return {number}
 */
var minimumTime = function(time, totalTrips) {
    let lo = 0, hi = Math.min(...time) * totalTrips, res = 0;
    while (lo <= hi) {
        const mid = lo + Math.floor((hi - lo) / 2);
        const numOfTrips = time.reduce((acc, cur) => acc + Math.floor(mid / cur), 0);
        
        if (numOfTrips >= totalTrips) {
            res = mid;
            hi = mid - 1;
        } else 
            lo = mid + 1;
    }
    return res;
};
