#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insert(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
// Revers K nodes in Linked List
node *reverseK(node *&head, int k)
{
    node *prevPtr = NULL;
    node *curPtr = head;
    node *nextPtr;
    int count = 0;
    while (curPtr != NULL && count < k)
    {
        nextPtr = curPtr->next;
        curPtr->next = prevPtr;
        prevPtr = curPtr;
        curPtr = nextPtr;
        count++;
    }
    if (nextPtr != NULL)
    {
        head->next = reverseK(nextPtr, k);
    }
    return prevPtr;
}

int main()
{
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    display(head);
    int k = 2;
    node *newHead = reverseK(head, k);
    display(newHead);
    return 0;
}
