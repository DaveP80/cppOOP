# #LeetCode No. 1347
# You are given two strings of the same length s and t. In one step you can choose any character of 
# t and replace it with another character.
# Return the minimum number of steps to make t an anagram of s.
# An Anagram of a string is a string that contains the same characters with a different (or the same) 
# ordering. David Paquette solution.
class Solution(object):
    def minSteps(self, s, t):
        cnt = defaultdict(int)
        N = 0
        for x,y in enumerate(s):
            cnt[s[x]] += 1
            cnt[t[x]] -= 1
        
        for k,v in cnt.items():
            if v > 0:
                N += v
        
        return N