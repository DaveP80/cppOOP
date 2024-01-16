# LeetCode No. 1207
# Given an array of integers arr, return true if the number of occurrences of each value in 
# the array is unique or false otherwise.
class Solution(object):
    def uniqueOccurrences(self, arr):
        stor = {}
        c = []
        for n,m in enumerate(arr):
            if m not in c:
                temp = str(arr.count(m))
                if temp in stor:
                    return False
                stor[temp] = m
                c.append(m)
                l = []
        return True