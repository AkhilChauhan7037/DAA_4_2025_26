// reverse a linked list
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* h=NULL;
        while(head!=NULL)
        {
            if(h==NULL)
            {
                h=new ListNode(head->val);
            }
            else
            {
                ListNode* temp=new ListNode(head->val);
                temp->next=h;
                h=temp;
            }
            head=head->next;
        }
        return h;
    }
};