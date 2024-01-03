#include <iostream>
#include <vector>
using namespace std;
// Given a string containing digits from 2-9 inclusive, return all possible
// letter combinations that the number could represent. Return the answer in any
// order. A mapping of digits to letters (just like on the telephone buttons) is
// given below.
//  "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
//  Input: digits = "58"
//  Output: jt ju jv kt ku kv lt lu lv
using namespace std;
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;

    if (digits.empty()) {
      return result; // Empty input, return an empty result
    }

    // Mapping of digits to letters
    vector<string> mappings = {"",    "",    "abc",  "def", "ghi",
                               "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string current;
    generateCombinations(digits, mappings, 0, current, result);

    return result;
  }

  void generateCombinations(const string &digits,
                            const vector<string> &mappings, int index,
                            string &current, vector<string> &result) {
    if (index == digits.length()) {
      result.push_back(current); // Reached the end of digits, add the current
                                 // combination to the result
      return;
    }

    int digit = digits[index] - '0';
    const string &letters = mappings[digit];

    for (char letter : letters) {
      current.push_back(letter); // Append the current letter

      // Recursively generate combinations for the remaining digits
      generateCombinations(digits, mappings, index + 1, current, result);

      current.pop_back(); // Remove the last letter for backtracking
    }
  }
};

int main() {
  Solution sol;

  vector<string> ans = sol.letterCombinations("58");

  for (string s : ans) {
    cout << s << "\n";
  }

  return 0;
}