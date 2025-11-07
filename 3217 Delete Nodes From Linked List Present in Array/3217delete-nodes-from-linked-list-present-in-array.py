# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        dict = {}
        for x in nums:
            dict[x] = 1
        temp = head
        prev = None
        while (temp != None):
            if (dict.get(temp.val, 0) == 1): 
                # head remove
                if (temp == head):
                    temp = temp.next
                    head = temp
                # tail remove
                elif (temp.next == None):
                    prev.next = None
                    temp = temp.next
                else:
                    prev.next = temp.next
                    temp = temp.next
            else:
                prev = temp
                temp = temp.next
        return head
        