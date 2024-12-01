#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int n)
    {
        data = n;
        next = NULL;
    }
    ~node(){};
};

void InsertAtHead(node *&head, int n)
{
    node *new_node = new node(n);
    new_node->next = head;
    head = new_node;
}

void InsertAtTail(node *&head, int n)
{
    if (head == NULL)
    {
        InsertAtHead(head, n);
        return;
    }
    node *temp = head;
    node *new_node = new node(n);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void InsertAtPosition(node *&head, int n, int pos)
{
    if (pos <= 1 || head == NULL)
    {
        InsertAtHead(head, n);
        return;
    }
    node *temp = head;
    node *new_node = new node(n);
    int count = 2;
    while (count < pos)
    {
        if (temp->next == NULL)
            break;
        temp = temp->next;
        count++;
    }
    if (temp->next != NULL)
        new_node->next = temp->next;
    temp->next = new_node;
}

void DeleteAtHead(node *&head)
{
    node *temp = head;
    head = head->next;
    delete temp;
}

void DeletionAtPosition(node *&head, int pos)
{
    if (head == NULL)
        return;
    if (pos <= 1)
    {
        DeleteAtHead(head);
        return;
    }
    node *temp = head;
    int count = 2;
    while (count < pos)
    {
        if (temp->next == NULL)
            return;
        temp = temp->next;
        count = count + 1;
    }
    if (temp->next == NULL)
        return;
    if (temp->next->next == NULL)
        temp->next = NULL;
    else
    {
        node *todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
    }
}

void DeletionAtTail(node *&head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        DeleteAtHead(head);
        return;
    }
    node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    node *todelete = temp->next;
    temp->next = NULL;
    delete todelete;
}

int search(node *head, int key)
{
    int count = 1;
    while (head != NULL)
    {
        if (head->data == key)
            return count;
        head = head->next;
        count++;
    }
    return INT32_MIN;
}

void reverse_linked_list(node *&head)
{
    if (head == NULL)
        return;
    node *pre = NULL;
    node *cur = head;
    node *nex = head->next;
    while (nex != NULL)
    {
        cur->next = pre;
        pre = cur;
        cur = nex;
        nex = nex->next;
    }
    cur->next = pre;
    head = cur;
}

node *reverse_recursive(node *&head)
{
    if (head->next == NULL || head == NULL)
        return head;

    node *temp = head;
    node *newhead = reverse_recursive(temp->next);
    temp->next->next = temp;
    temp->next = NULL;
    return newhead;
}

node *reverse_k_node(node *&head, int k)
{
    node *pre = NULL;
    node *cur = head;
    node *nex = NULL;
    int count = 0;
    while (cur != NULL && count < k)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
        count++;
    }
    if (nex != NULL)
        head->next = reverse_k_node(nex, k);
    return pre;
}

void create_intersection(node *head1, node *&head2, int pos)
{
    if (head1 == NULL || head2 == NULL)
        return;
    node *temp1 = head1;
    node *temp2 = head2;
    int count = 1;
    while (temp1->next != NULL && pos > count)
    {
        temp1 = temp1->next;
        count++;
    }
    while (temp2->next != NULL)
        temp2 = temp2->next;
    temp2->next = temp1;
}

int length_of_linked_list(node *head)
{
    if (head == NULL)
        return 0;
    int count = 1;
    while (head->next != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

int detect_intersection(node *head1, node *head2)
{
    if (head1 == NULL || head2 == NULL)
        return INT32_MIN;
    int l1 = length_of_linked_list(head1);
    int l2 = length_of_linked_list(head2);
    if (l1 > l2)
    {
        int d = l1 - l2;
        while (d > 0)
        {
            head1 = head1->next;
            d--;
        }
    }
    else if (l2 > l1)
    {
        int d = l2 - l1;
        while (d > 0)
        {
            head2 = head2->next;
            d--;
        }
    }
    while (head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1->data;
}

void create_cycle(node *&head, int pos)
{
    if (head == NULL)
        return;
    node *temp = head;
    node *ptr = head;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
            ptr = temp;
        temp = temp->next;
        count++;
    }
    temp->next = ptr;
}

bool detect_cycle(node *head)
{
    if (head == NULL)
        return false;
    node *fast = head;
    node *slow = head;
    while (fast->next != NULL && fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}

void remove_cycle(node *&head)
{
    node *fast = head;
    node *slow = head;
    while (fast != slow)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}

void put_even_after_odd_node(node *&head)
{
    if (head == NULL || head->next == NULL)
        return;
    node *odd = head;
    node *even = head->next;
    node *evenstart = even;
    while (even->next != NULL && odd->next != NULL)
    {
        odd->next = even->next;
        odd = even->next;
        if (odd->next == NULL)
            break;
        even->next = odd->next;
        even = odd->next;
    }
    odd->next = evenstart;
    if (odd->next != NULL)
        even->next = NULL;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    int n, data, pos;
    node *head = NULL;
    node *head1 = NULL;
    int arr[5] = {86, 51, 71, 36, 54};
    for (int i = 0; i < 5; i++)
        InsertAtTail(head1, arr[i]);

    while (1)
    {
        cout << "\n\n\t 1. To Insert Node at End\n\t 2. To Insert Node at Particular Position \n\t 3. To Delete Node at End \n\t 4. To Delete Node at Particular Position";
        cout << "\n\t 5. To Search any Element\n\t 6. To Reverse the Linked List\n\t 7. To Reverse K Nodes\n\t 8. To Intersection node value\n\t 9. To Detect and Remove Cycle";
        cout << "\n\t10. To put Even Position Nodes after Odd\n\t11. To Display Linked List \n\t12. To Exit";
        cout << "\nEnter your choice : ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the Value : ";
            cin >> data;
            InsertAtTail(head, data);
            break;
        case 2:
            cout << "Enter the Value and Position at which you want to add : ";
            cin >> data >> pos;
            InsertAtPosition(head, data, pos);
            break;
        case 3:
            DeletionAtTail(head);
            break;
        case 4:
            cout << "Enter the Position of element which you want to delete : ";
            cin >> pos;
            DeletionAtPosition(head, pos);
            break;
        case 5:
            cout << "Enter the value of that element : ";
            cin >> data;
            pos = search(head, data);
            if (pos == INT32_MIN)
                cout << "Element was not found!";
            else
                cout << "Element was found at position " << pos << ".";
            break;
        case 6:
            reverse_linked_list(head);
            // head = reverse_recursive(head);
            cout << "The Elements in the Linked List are :\n";
            display(head);
            break;
        case 7:
            cout << "Enter the value of K : ";
            cin >> pos;
            head = reverse_k_node(head, pos);
        case 8:
            create_intersection(head1, head, 3);
            cout << "The value at the Intersection is " << detect_intersection(head, head1) << ".";
            cout << "\nThe value in both the Linked Lists are : \n";
            display(head1);
            cout << endl;
            display(head);
            break;
        case 9:
            create_cycle(head, 3);
            bool flag;
            flag = detect_cycle(head);
            if (flag == true)
            {
                cout << "The Linked List has a Cycle ";
                remove_cycle(head);
                cout << "which is Removed.";
            }
            else
            {
                cout << "The Linked List doesnot has any Cycle.";
            }
            break;
        case 10:
            put_even_after_odd_node(head);
            cout << "The Elements in the Linked List are :\n";
            display(head);
            break;
        case 11:
            cout << "The Elements in the Linked List are :\n";
            display(head);
            break;
        case 12:
            return 0;
            break;
        default:
            cout << "\nPlease enter Vaild Number.";
            break;
        }
    }
}