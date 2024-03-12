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
// Deletion
void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}
void deletion(node *&head, int val)
{
    node *temp = head;
    if (val == 1)
    {
        deleteAtHead(head);
        return;
    }

    while (temp->data != val)
    {
        temp = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
    delete temp;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 4);
    insertAtTail(head, 3);

    insertAtTail(head, 5);
    display(head);
    deletion(head, 1);
    display(head);
    return 0;
}