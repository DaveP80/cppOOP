//LeetCode No. 66 Easy

var plusOne = function(digits) {

    let c = BigInt(digits.join("")) + BigInt(1);
    return Array.from(c.toString())
    
};