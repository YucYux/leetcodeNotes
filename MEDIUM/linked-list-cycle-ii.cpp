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
    ListNode *detectCycle(ListNode *head) {
        int ans=0;
        if(head==NULL||head->next==NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* find=head;
        while(1)
        {
            if(!fast)
                return NULL;
            if(fast->next)
                fast=fast->next->next;
            else
                return NULL;
            slow=slow->next;
            if(fast==slow)
                break;
        }
        while(slow!=find)
        {
            find=find->next;
            slow=slow->next;
        }
        return find;
    }
};
