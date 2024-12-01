#include <iostream>
using namespace std;

#define n 100

class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int val)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow!";
            return;
        }
        top++;
        arr[top] = val;
    }

    int pop()
    {
        if (is_empty())
        {
            cout << "Stack Underflow!";
            return top;
        }
        top--;
        return arr[top + 1];
    }

    void insert_at_bottom(int data)
    {
        if (is_empty())
        {
            push(data);
            return;
        }
        int temp = Top();
        pop();
        insert_at_bottom(data);
        push(temp);
    }

    void reverse_stack()
    {
        if (is_empty())
            return;
        int data = Top();
        pop();
        reverse_stack();
        insert_at_bottom(data);
    }

    void display()
    {
        if (top == -1)
            return;
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
    }

    bool is_empty()
    {
        return (top == -1);
    }

    int Top()
    {
        return arr[top];
    }
};

int main()
{
    int x, data;
    stack obj;
    while (1)
    {
        cout << "\n\t1. To Push an Element\n\t2. To Pop an Element\n\t3. To Reverse Stack\n\t4. To Display all Elements\n\t5. To Exit";
        cout << "\nEnter your choice : ";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "Enter that Element value : ";
            cin >> data;
            obj.push(data);
            break;
        case 2:
            data = obj.pop();
            if (data != -1)
                cout << data << " has been Poped out.";
            break;
        case 3:
            obj.reverse_stack();
            cout << "The Elements in the Stack are : \n";
            obj.display();
            break;
        case 4:
            cout << "The Elements in the Stack are : \n";
            obj.display();
            break;
        case 5:
            return 0;
            break;
        default:
            cout << "Please Enter a Vaild Number.";
            break;
        }
    }
}