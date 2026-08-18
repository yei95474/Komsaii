#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

void createList(Node *dummy);
int nodeCounter(Node *dummy);
void displayList(Node *dummy);
bool searchVal(Node *dummy);
Node *getNodeAt(Node *dummy, int index);
void insertNodeHead(Node &dummy, int value);
void insertTail(Node &dummy, int value);
void insertTailp(Node &dummy, Node& tail, int value);
Node *getTail(Node &dummy);


int main()
{
    Node dummy = Node();
    Node *dummyptr = &dummy;

    createList(&dummy);
    displayList(&dummy);
    Node *tail = getTail(dummy);

    cout << tail->val << endl;
    // insertNodeHead(dummy, 10);
    insertTail(dummy, 7);

    displayList(&dummy);

    cout << "Number of nodes in the list: " << nodeCounter(dummy.next) << endl;
    cout << ((searchVal(&dummy)) ? "Value found" : "Value not found") << endl;
    // Node* getNode = getNodeAt(&dummy, 2);
    // cout<<"Node at index 2: "<<getNode->val<<endl;
}

void createList(Node *dummy)
{
    Node *current = dummy;
    for (int i = 0; i < 3; i++)
    {
        int value;
        cin >> value;

        current->next = new Node();
        current = current->next;
        current->val = value;
        current->next = nullptr;
    }
    // return dummy->next;
}

int nodeCounter(Node *dummy)
{
    Node *runner = dummy;
    int count = 0;
    while (runner != nullptr)
    {
        ++count;
        runner = runner->next;
    }
    return count;
}

void displayList(Node *dummy)
{
    const Node *runner = dummy->next;
    while (runner != nullptr)
    {
        cout << runner->val << " ";
        runner = runner->next;
    }
    cout << endl
         << endl;
}

bool searchVal(Node *dummy)
{
    cout << "Enter value to search: ";
    int x;
    cin >> x;
    Node *runner = dummy;
    while (runner != nullptr)
    {
        if (runner->val == x)
        {
            return true; // Value found
        }
        runner = runner->next;
    }
    return false; // Value not found
}

Node *getNodeAt(Node *dummy, int index)
{
    Node *runner = dummy;
    int current = 0;
    if (index < 0)
    {
        return nullptr;
    }

    while (runner != nullptr && current <= index)
    {
        runner = runner->next;
        ++current;
    }
    return runner;
}

void insertNodeHead(Node &dummy, int value)
{
    Node *newNode = new Node();
    newNode->val = value;
    newNode->next = dummy.next;
    dummy.next = newNode;
}

void insertTail(Node &dummy, int value)
{
    Node *newNode = new Node();
    Node *dummyptr = &dummy;
    newNode->val = value;
    newNode->next = nullptr;

    if (dummyptr == nullptr)
    {
        dummyptr = newNode;
    }

    Node *tail = &dummy;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = newNode;
}

Node *getTail(Node &dummy)
{
    Node *runner = &dummy;
    while (runner->next != nullptr)
    {
        runner = runner->next;
    }
    return runner;
}

void insertTailp(Node &dummy, Node& tail, int value){
    //Node head = dummy;
    Node* newNode = new Node();
    newNode->val = value;

    if (dummy.next == nullptr) {
        dummy.next = newNode;
        tail = dummy;
        return;
    }

    tail.next = newNode;
    tail = newNode;
}