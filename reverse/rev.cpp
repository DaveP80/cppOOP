#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isEven(int val) { return val % 2 == 0; }

class Number {
public:
  int n;

  Number(int n) : n(n) {}

  bool operator==(const Number &num) { return (this->n == num.n); }
};

int main() {
  // two ways to reverse a string
  string text1 = "There is no hand to catch time";

  reverse(text1.begin(), text1.end());
  cout << text1 << "\n";

  char text2[] = "All that glitters is not gold";

  reverse(text2, text2 + strlen(text2));

  cout << text2 << "\n";

  // find if element is even, and return the first truthy, dereferenced

  vector<int> data;
  data.push_back(3);
  data.push_back(55);
  data.push_back(53);
  data.push_back(86);
  data.push_back(18);
  data.push_back(53);
  data.push_back(8);

  auto res = find_if(data.begin(), data.end(), isEven);

  if (res == data.end()) {
    cout << "No even values found in vector."
         << "\n";
  } else
    cout << "First even value in vector: " << *res << "\n";

  // new find function
  // find index that satifies value in itfound
  vector<int> newdata = {9, 8, 7, 6, 5, 4, 3, 2};

  auto itfound = find(newdata.begin(), newdata.end(), 77);

  if (itfound == newdata.end())
    cout << "number not found in range"
         << "\n";
  else {
    cout << *itfound << endl;
    cout << "Index: " << itfound - newdata.begin() << endl;
  }

  // same but use Number Object defined at top
  vector<Number> moredata = {Number(5), Number(2), Number(1)};

  auto nitfound = find(moredata.begin(), moredata.end(), Number(2));

  if (nitfound != moredata.end()) {
    cout << "Number two found: " << (*nitfound).n << "\n";
  }
  return 0;
}