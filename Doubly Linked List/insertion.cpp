#include <iostream>
using namespace std;
struct node
{
    node *prev;
    node *next;
    int data;
    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void display(node *&head)
{
    node *temp = head;
    cout << "NULL";
    while (temp != NULL)
    {
        cout << "<=>" << temp->data;
        temp = temp->next;
    }
    cout << "<=>NULL" << endl;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    display(head);
    return 0;
}