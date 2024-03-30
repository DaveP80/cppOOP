//Answer to coding challenge question on Turing Coding test
// Given a string like "5f93a2z" or "t10n4m8"
// return a string  where the chars are alternating from integer to normal alphabetical character. the chars must be in order, numbers get priority of letters. so the output should be:
// "2a3f5z9" and "0m1n4m8"
function alternateCharacters(str) {
    const numbers = [];
    const letters = [];
  
    // Separate numbers and letters
    for (let char of str) {
        if (!isNaN(char)) {
            numbers.push(char);
        } else {
            letters.push(char);
        }
    }

    // Sort both arrays
    numbers.sort((a, b) => a - b);
    letters.sort();
  
    // Interleave the elements of the arrays
    let result = '';
    while (numbers.length || letters.length) {
        if (numbers.length) {
            result += numbers.shift();
        }
        if (letters.length) {
            result += letters.shift();
        }
    }
  
    return result;
}

console.log(alternateCharacters("5f93a2z")); // Output: "2a3f5z9"
console.log(alternateCharacters("t10n4m8")); // Output: "0m1n4m8"

