# LeetCode No 443
class Solution(object):
    def compress(self, chars):
        dint = len(chars)
        flag = False
        count = 0
        last = ""
        ans = ""
        for a,b in enumerate(chars[:]):
            if b != last:
                diff = dint - a
                innerc = 0
                l = len(ans)
                for z,y in enumerate(chars[a:]):
                    if y != b:
                        break
                    innerc += 1
                    if z == diff-1:
                        flag = True
                subcount = str(innerc)
                if int(subcount) < 2:
                    subcount = ""
                temp = b + subcount
                ans += temp
                last = b
                for n in range(l, len(ans)):
                    chars[n] = ans[n]
                if flag:
                    break
        chars = chars[:len(ans)]
        return len(chars)