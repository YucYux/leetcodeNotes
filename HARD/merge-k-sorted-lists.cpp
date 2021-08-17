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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;   
        if(lists.size()==1) return lists[0];
        vector<ListNode*> mergedLists;
        for(int i=0;i<lists.size()/2;i++)
            mergedLists.push_back(merge2Lists(lists[2*i],lists[2*i+1]));
        if(lists.size()%2!=0)
            mergedLists.push_back(lists[lists.size()-1]);
        while(mergedLists.size()>1)
        {
            for(int i=0;i<mergedLists.size()/2;i++)
                mergedLists[i]=merge2Lists(mergedLists[2*i],mergedLists[2*i+1]);
            mergedLists.erase(mergedLists.begin()+mergedLists.size()/2,mergedLists.begin()+mergedLists.size()/2*2);
        }
        return mergedLists[0];
    }
    ListNode* merge2Lists(ListNode* a,ListNode* b)
    {
        if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode* res=NULL;
        ListNode* now=NULL;
        if(a->val<b->val) 
        {
            res=a;
            a=a->next;
        }
        else
        {
            res=b;
            b=b->next;
        }
        now=res;
        while(a!=NULL||b!=NULL)
        {
            if(a==NULL||(b!=NULL&&a->val>b->val))
            {
                now->next=b;
                b=b->next;
            }
            else
            {
                now->next=a;
                a=a->next;
            }
            now=now->next;
        }
        return res;
    }
};
