#include <iostream>
#include <stack>
using namespace std;

class queue_uisng_stack
{
    stack<int> s1;

public:
    void push(int val)
    {
        s1.push(val);
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue is Empty!";
            return;
        }
        stack<int> s2;
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void display()
    {
        if (empty())
            return;
        int data = s1.top();
        s1.pop();
        display();
        s1.push(data);
        cout << data << " ";
    }

    int peek()
    {
        if (empty())
            return INT32_MIN;
        int data = s1.top();
        s1.pop();
        if (s1.empty())
        {
            s1.push(data);
            return data;
        }
        int ans = peek();
        s1.push(data);
    }

    bool empty()
    {
        return (s1.empty());
    }
};

int main()
{
    int n, val;
    queue_uisng_stack obj;
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
            cout << "The elements in the Queue are : \n";
            obj.display();
            cout << endl;
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