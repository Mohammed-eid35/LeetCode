/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */
var minEatingSpeed = function(piles, h) {
    let lo = 1, hi = Math.max(...piles), k = -1;
    
    while (lo <= hi) {
        const mid = lo + ((hi - lo) >> 1);
        const numOfHours = piles.reduce((total, pile) => total + Math.ceil(pile / mid), 0);
        
        if (numOfHours <= h) {
            k = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    
    return k;
};
