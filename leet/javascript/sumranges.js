//LeetCode No. 228 Summary Ranges
//0(n)
var summaryRanges = function(nums) {
    nums.unshift(nums[0] - 1) 
    let stor = [];
    let temp = [];
  
    for (let i = 1; i < nums.length; i++) {
      if (nums[i] == nums[i - 1] + 1) {
        temp.push(nums[i]);
      } else {
        helper(temp);
        temp = [];
        temp.push(nums[i]);
      }
      if (i == nums.length - 1) {
        helper(temp);
      }
    }
  
    function helper(temp) {
        if (temp.length > 1) {
          stor.push(`${
            temp[0]
          }->${
            temp[temp.length - 1]
          }`);
        } else if(temp.length==1) {
          stor.push(`${
            temp
          }`);
        }
    }
  
    return stor;
  
  };