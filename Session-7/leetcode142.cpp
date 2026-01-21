// linked list cycle 2
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* p=head;
        vector<ListNode*>v;
        int c=0;
        while(p!=NULL&&c<=1&&p->next!=head)
        {
            v.push_back(p->next);
            p=p->next;
            c=count(v.begin(),v.end(),p);
        }
        if(p==NULL)
        {
            return NULL;
        }
        else if(p->next==head)
        {
            return head;
        }
        else
        {
            return p;
        }
    }
};