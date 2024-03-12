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

void insertAtTail(node *&head, int val)
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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
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
// find the length of list
int lenght(node *head)
{
    int L = 0;
    node *temp = head;
    while (temp != NULL)
    {
        L++;
        temp = temp->next;
    }
    return L;
}
// append k
void appendK(node *&head, int k)
{
    node *newHead;
    node *newTail;
    node *tail = head;
    int L = lenght(head);
    k = k % L;
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == L - k)
        {
            newTail = tail;
        }
        if (count == L - k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
    head=newHead;
}
int main()
{
    node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        insertAtTail(head, arr[i]);
    }
    display(head);

    appendK(head, 3);
    display(head);
    return 0;
}
