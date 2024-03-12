#include <iostream>
using namespace std;
#define n 100

class queue
{
    int *arr;
    int front;
    int back;

public:
    // constructor
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    // pushing
    void enqueue(int x)
    {
        if (back == n - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        back++;
        arr[back] = x; 
        if (front == -1)
        {
            front++;
        }
    }

    // pop
    void dequeue()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        front++;
    }

    // checking top
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "No element in queue" << endl;
            return -1;
        }
        return arr[front];
    }

    // check if the queue is empty
    bool empty()
    {
        return (front == -1 || front > back);
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.empty() << endl;
    return 0;
}
