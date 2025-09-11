//LeetCode No. 702. Search in a Sorted Array of Unknown Size    
class Solution {
    public:
     int search(const ArrayReader& reader, int target) {
       int mid = (10 * 10 * 10 * 10) / 2;
       int l = 0;
       int r = (10 * 10 * 10 * 10) - 1;
       int ans = -1;

       while (l <= r) {
         if (reader.get(mid) == target) {
           ans = mid;
           break;
         };
   
         if (reader.get(mid) < target) {
           l += 1;
         } else if (reader.get(mid) > target) {
           r -= 1;
         };
         mid = r - l / 2;
       };
   
       return ans;
     }
   };