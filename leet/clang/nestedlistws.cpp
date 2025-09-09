//LeetCode No. 339 Nested List Weight Sum
class Solution {
    public:
     int dfs(vector<NestedInteger>& nestedList, int depth) {
       int n = nestedList.size(), sum = 0;
       for (int i = 0; i < n; i++) {
         if (nestedList[i].isInteger())
           sum += nestedList[i].getInteger() * depth;
         else
           sum += dfs(nestedList[i].getList(), depth + 1);
       }
       return sum;
     };
   
     int depthSum(vector<NestedInteger>& nestedList) {
       return dfs(nestedList, 1);
     };
   };