// LeetCode No. 2187
// Medium
var minimumTime = function(time, totalTrips) {

    let left = 1;
    let right = Math.min(...time) * totalTrips;
    while(left<=right) {
        let mid = Math.floor((right+left)/2);
        if (go(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;

    function go(v) {
        let sum = time.reduce((a,b) => {return a + Math.floor(v/b)}, 0);
        return sum >= totalTrips;
    }
    
};