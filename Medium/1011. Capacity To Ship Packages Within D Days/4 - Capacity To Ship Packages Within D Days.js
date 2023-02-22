/**
 * @param {number[]} weights
 * @param {number} days
 * @return {number}
 */
var shipWithinDays = function(weights, days) {
    let totalWeights = 0, maxWeight = 0;
    for (const weight of weights) {
        totalWeights += weight;
        maxWeight = Math.max(maxWeight, weight);
    }

    return BinarySearch(maxWeight, totalWeights, days, weights);
};

const BinarySearch = (lo, hi, days, weights) => {
    let res = 0;
    while (lo <= hi) {
        const mid = lo + (hi - lo >> 1);

        if (numOfDaysNeeded(mid, weights) <= days) {
            res = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    return res;
}

const numOfDaysNeeded = (capacity, weights) => {
    let days = 1, curCapacity = 0;
    for (const weight of weights) {
        if (curCapacity + weight > capacity) {
            days++;
            curCapacity = 0;
        }

        curCapacity += weight;
    }

    return days;
}
