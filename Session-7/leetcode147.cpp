// insertaion sort linked list
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* h=NULL;
        ListNode* t=NULL;
        multiset<int>m;
        while(head!=NULL)
        {
            m.insert(head->val);
            head=head->next;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(h==NULL)
            {
                h=new ListNode(*it);
                t=h;
            }
            else
            {
                ListNode* temp=new ListNode(*it);
                t->next=temp;
                t=temp;
            }
        }
        return h;
    }
};