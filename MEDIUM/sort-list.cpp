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
    ListNode* sortList(ListNode* head) {
        return sortByNum(head, getListNum(head));
    }
    ListNode* sortByNum(ListNode* head, int num)
    {
        if(num <= 1)
            return head;
        if(num == 2)
        {
            if(head->val <= head->next->val)
                return head;
            int headOldVal = head->val;
            head->val = head->next->val;
            head->next->val = headOldVal;
            return head;
        }
        ListNode* second = nextNnode(head, num/2);
        second = sortByNum(second, num - (num / 2));
        ListNode* first = head;
        first = sortByNum(first, num / 2);
        ListNode* tempHeadRaw = new ListNode();
        ListNode* tempHead = tempHeadRaw;
        int n1 = 0;
        int n2 = 0;
        while(n1 < num / 2 || n2 < (num - (num / 2)))
        {
            if(n1 < num / 2 && n2 < (num - (num / 2)))
            {
                if(first->val < second->val)
                {
                    tempHead->next = first;
                    first = first->next;
                    tempHead = tempHead->next;
                    n1++;
                }
                else
                {
                    tempHead->next = second;
                    second = second->next;
                    tempHead = tempHead->next;
                    n2++;
                }
            }
            else if(n1 < num / 2)
            {
                tempHead->next = first;
                first = first->next;
                tempHead = tempHead->next;
                n1++;
            }
            else
            {
                tempHead->next = second;
                second = second->next;
                tempHead = tempHead->next;
                n2++;
            }
        }
        tempHead->next = NULL;
        ListNode* ans = tempHeadRaw->next;
        delete(tempHeadRaw);
        return ans;
    }
    int getListNum(ListNode* head)
    {
        if(!head) return 0;
        int ans = 1;
        ListNode* p = head->next;
        while(p)
        {
            ans++;
            p = p->next;
        }
        return ans;
    }
    ListNode* nextNnode(ListNode* head, int n)
    {
        for(int i = 0; i < n; i++)
        {
            head = head->next;
            if(!head)
                return NULL;
        }
        return head;
    }
};
