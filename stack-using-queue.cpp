#include <iostream>
#include <queue>
using namespace std;

class stack_using_queue
{
    queue<int> q1;

public:
    void push(int val)
    {
        queue<int> q2;
        q2.push(val);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop()
    {
        if (empty())
        {
            cout << "Stack Underflow!";
            return;
        }
        q1.pop();
    }

    void display()
    {
        if (empty())
            return;
        queue<int> q2 = q1;
        while (!q2.empty())
        {
            cout << q2.front() << " ";
            q2.pop();
        }
    }

    int peek()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }

    void swap(queue<int> &q1, queue<int> &q2)
    {
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
};

int main()
{
    int n, val;
    stack_using_queue obj;
    while (1)
    {
        cout << "\n\t1. To Push\n\t2. To Pop\n\t3. To Display\n\t4. To Exit";
        cout << "\nEnter your choice : ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the Value of that element : ";
            cin >> val;
            obj.push(val);
            break;
        case 2:
            obj.pop();
            break;
        case 3:
            cout << "The elements in the Stack are : \n";
            obj.display();
            break;
        case 4:
            return 0;
            break;

        default:
            cout << "Please Enter vaild choice.";
            break;
        }
    }
}