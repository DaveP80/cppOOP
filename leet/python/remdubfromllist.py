#LeetCode No. 83
class Solution(object):
    def deleteDuplicates(self, head):
        it = head
        if head is None or head.next is None:
            return head
        
        while it and it.next:
            if it.val == it.next.val:
                it.next = it.next.next
            else:
                it = it.next
        return head