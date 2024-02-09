#LeetCode No. 481 Magical String. Solution by david paquette
class Solution(object):
    def magicalString(self, n):
        if n <= 3:
            return 1
        
        ans = 1
        key = "122"
        next_char = "1"

        for i in range(2, n + 1):
            r = int(key[i])
            if next_char == "1":
                key += next_char * r
                next_char = "2"
                ans += r
            elif next_char == "2":
                key += next_char * r
                next_char = "1"
            
            if len(key) >= n:
                if len(key) > n and key[-1] == "1":
                    ans -= 1
                break

        return ans