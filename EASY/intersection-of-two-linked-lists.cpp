/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * a = headA;
        ListNode * b = headB;
        ListNode * tempheadA = headA;
        ListNode * tempheadB = headB;
        if(a == b) return a;
        while(1)
        {
            if(a->next != NULL)
                a = a->next;
            else
            {
                a = tempheadB;
                if(tempheadB == headB)
                    tempheadB = headA;
                else 
                    tempheadB = headB;
            }
                
            if(b->next != NULL)
                b = b->next;
            else
            {
                b = tempheadA;
                if(tempheadA == headA)
                    tempheadA = headB;
                else
                    tempheadA = headA;
            }
            if(a == b)
                return a;
            if(a == headA && b == headB)
                return NULL;
        }
    }
};
