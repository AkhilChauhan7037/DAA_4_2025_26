// flatten-a-multilevel-doubly-linked-list
class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL)
            return head;
        Node* p = head;
        while (p != NULL) {
            if (p->child != NULL) {
                Node* childHead = p->child;
                Node* childTail = childHead;

                while (childTail->next != NULL)
                    childTail = childTail->next;

                childTail->next = p->next;
                if (p->next != NULL)
                    p->next->prev = childTail;

                p->next = childHead;
                childHead->prev = p;

                p->child = NULL;
            }
            p = p->next;
        }
        return head;
    }
};