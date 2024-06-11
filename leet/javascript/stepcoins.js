//LeetCode No. 441
//Arranging Coins
var arrangeCoins = function(n) {
    let l = 0;
    let h = n;

    while (l <= h) {
        let m = Math.floor((l + h) / 2);
        let g = (m * (m + 1)) / 2;
        if (g === n) {
            return m;
        }
        if (g < n) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return h;
};