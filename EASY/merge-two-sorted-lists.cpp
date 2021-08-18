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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        else if(l2==NULL) return l1;
        ListNode* p1=l1;
        ListNode* p2=l2;
        ListNode* ans;
        ListNode* now;
        if(l1->val<l2->val)
        {
            ans=l1;
            l1=l1->next;
        }
        else
        {
            ans=l2;
            l2=l2->next;
        }
        now=ans;
        while(l1!=NULL||l2!=NULL)
        {
            if(l1==NULL||(l2!=NULL&&l2->val<l1->val))
            {
                now->next=l2;
                now=l2;
                l2=l2->next;
            }
            else
            {
                now->next=l1;
                now=l1;
                l1=l1->next;
            }
        }
        return ans;
    }
};
