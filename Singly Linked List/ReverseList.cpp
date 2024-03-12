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
// reversed a linked list by iterative method
node *reverse(node *&head)
{
    node *prevPtr = NULL;
    node *CursrPtr = head;
    node *nextPtr;
    while (CursrPtr != NULL)
    {
        nextPtr = CursrPtr->next;
        CursrPtr->next = prevPtr;
        prevPtr = CursrPtr;
        CursrPtr = nextPtr;
    }
    return prevPtr;
}
// reversed a linked list by Recursive method
node *reverseRecursive(node *&head)
{
    // case when node is null or single element in list
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // for more then one element in List
    node *newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
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

    cout << "Reversing the list by Itreative method" << endl;
    node *newHead = reverse(head);
    display(newHead);

    // cout << "Reversing the list by Recursive Method" << endl;
    // node *newHead = reverseRecursive(head);
    // display(newHead);

    return 0;
}
