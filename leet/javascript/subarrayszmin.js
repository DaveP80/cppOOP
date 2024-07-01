//LeetCode No. 209
//Minimum Size Subarray Sum
//Sliding window Approach
var minSubArrayLen = function(target, nums) {
    let l = 0;
    let sub = 0;
    let ans = Number.MAX_SAFE_INTEGER;

    for (let i = 0; i < nums.length; i++) {
        sub += nums[i];
        
        while (sub >= target) {
            ans = Math.min(ans, i - l + 1);
            sub -= nums[l];
            l++;
        }
    }
    
    return ans === Number.MAX_SAFE_INTEGER ? 0 : ans;
};