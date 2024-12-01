#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    node *front = NULL, *rare = NULL;

public:
    void push(int val)
    {
        node *temp = new node(val);
        if (front == NULL)
        {
            front = temp;
            rare = temp;
        }
        else
        {
            rare->next = temp;
            rare = temp;
        }
    }

    void pop()
    {
        if (is_empty())
            cout << "Queue Underflow!";
        else if (front == rare)
        {
            node *todelete = front;
            front = NULL;
            rare = NULL;
            free(todelete);
            cout << "The element has been Poped out";
        }
        else
        {
            node *todelete = front;
            front = front->next;
            free(todelete);
            cout << "The element has been Poped out";
        }
    }

    void display()
    {
        if (!is_empty())
        {
            node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }

    int peek()
    {
        if (is_empty())
            return INT32_MIN;
        else
            return front->data;
    }

    bool is_empty()
    {
        return (front == NULL);
    }
};

int main()
{
    int n, val;
    Queue obj;
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