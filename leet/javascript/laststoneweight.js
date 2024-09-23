// Leetcode No. 1046
/**
 * @param {number[]} stones
 * @return {number}
 */
var lastStoneWeight = function(stones) {

    while(stones.length) {
        stones.sort((a,b) => a-b);
        let y = stones[stones.length-1];
        let x = stones[stones.length - 2];

        if (x == y) {
            stones.pop();
            stones.pop();
        }
        if (y > x) {
            stones.pop();
            stones[stones.length-1] = y - x;
        }
        if (stones.length <= 1) {
            break;
        }
    }

    return stones[0] || 0
    
};