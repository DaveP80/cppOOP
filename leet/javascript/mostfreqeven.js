/**
 * @param {number[]} nums
 * @return {number}
 * LeetCode No. 2404
 * 
 */
var mostFrequentEven = function(nums) {
    let stor = {}
    let maxF = -Infinity;

    for (let n of nums) {
        if (n % 2 === 0) {
            stor[n] = (stor[n] || 0) + 1;
            //dynamically get the max frequency
            maxF = Math.max(maxF, stor[n]);
        }
    }
    let acc = Number.MAX_SAFE_INTEGER;
    for (let [k,v] of Object.entries(stor)) {
        if (v==maxF) {
     //the min value is the Min of selected key +            
     //value
        acc = Math.min(acc, +k + +v);
        }
    }
    return Number.isInteger(maxF) ? acc-maxF : -1;
};