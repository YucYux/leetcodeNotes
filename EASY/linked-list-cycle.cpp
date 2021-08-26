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
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return 0;
        ListNode* p1=head;
        ListNode* p2=head;
        while(p2!=NULL)
        {
            if(p2->next) p2=p2->next->next;
            else return 0;
            p1=p1->next;
            if(p1==p2) return 1;
        }
        return 0;
    }
};
