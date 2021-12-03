/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *p1=head;
        ListNode *p2=head->next;
        p1->next=NULL;
        while(1)
        {
            if(p2->next)
            {
                ListNode *temp=p2->next;
                p2->next=p1;
                p1=p2;
                p2=temp;
            }
            else
            {
                p2->next=p1;
                return p2;
            }
        }
        return 0;
    }
};
