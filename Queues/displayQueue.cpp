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
   //Display
   void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= back; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
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
    q.display();
    return 0;
}
