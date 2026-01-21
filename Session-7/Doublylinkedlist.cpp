#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node* next;
    node* prev;
    node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};
node* head = NULL;
node* tail = NULL;
node* p = NULL;
void atend(int value)
{
    if(head == NULL)
    {
        head = new node(value);
        tail = head;
    }
    else
    {
        node* t = new node(value);
        tail->next = t;
        t->prev = tail;
        tail = t;
    }
}
void del(int element)
{
    if(head == NULL)
    {
        cout << "linked list underflow:\n";
        return;
    }
    if(head->data == element)
    {
        node* temp = head;
        head = head->next;

        if(head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
        return;
    }
    p = head;
    while(p != NULL)
    {
        if(p->data == element)
        {
            if(p->next != NULL)
                p->next->prev = p->prev;
            else
                tail = p->prev;

            p->prev->next = p->next;
            delete p;
            return;
        }
        p = p->next;
    }
    cout << "element not found:\n";
}
int main()
{
    int n, v;
    cout << "how many element in linked list:";
    cin >> n;
    cout << "enter the element of the linked list:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> v;
        atend(v);
    }
    cout << "enter the element who you want to insert at end:";
    cin >> v;
    atend(v);
    cout << "enter the element who you want to delete:";
    cin >> v;
    del(v);
    cout << "the element of the linked list is = ";
    p = head;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}