// ============================================================
// Lab Exercise 1 — Arrays and Linked Lists
// CSIT 103 — Data Structures and Algorithms
// Visayas State University · AY 2026-2027 · 1st Semester
// ------------------------------------------------------------
// Part B.1: Singly Linked List Operations
// File: SinglyLinkedList.cpp
// ------------------------------------------------------------
// Name       : ________________________________________
// Student ID : ________________________________________
// Section    : ________________________________________
// Date       : ________________________________________
// ============================================================

/* ============================================================
   COMPLEXITY ANALYSIS — Lab Exercise 1
   Name: ____________________  Student ID: ________________
   ============================================================
   Fill in the Big-O time complexity for each operation.
   Use your Lesson 1 notes and TLA 1 Part C as a reference.

   Operation                   | Array    | SLL
   ----------------------------|----------|----------
   Access by index             | ________ | ________
   Linear search (by value)    | ________ | ________
   Insert at head              | ________ | ________
   Insert at tail              | ________ | ________
   Insert at arbitrary index   | ________ | ________
   Delete by value             | ________ | ________
   Delete by index             | ________ | ________
   ============================================================ */

#include <iostream>
using namespace std;

// ── Node Structure ───────────────────────────────────────────
// Do not modify this struct.
struct SLLNode {
    int data;
    SLLNode* next;
    SLLNode(int val) : data(val), next(nullptr) {}
};

// ── Function Prototypes ──────────────────────────────────────
void insertAtHead(SLLNode*& head, int value);
void insertAtTail(SLLNode*& head, int value);
bool deleteByValue(SLLNode*& head, int value);
bool search(SLLNode* head, int target);
void display(SLLNode* head);

// ── insertAtHead ─────────────────────────────────────────────
// Creates a new node with value and inserts it before head.
// Updates head to point to the new node.
void insertAtHead(SLLNode*& head, int value) {
    SLLNode* temp = new SLLNode(value);
    temp->next = head;
    head = temp;
    // TODO: implement
}

// ── insertAtTail ─────────────────────────────────────────────
// Creates a new node with value and appends it after the last node.
// If the list is empty, the new node becomes head.
void insertAtTail(SLLNode*& head, int value) {
    SLLNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    SLLNode* temp = new SLLNode(value);
    tail->next = temp;
    // TODO: implement
}

// ── deleteByValue ────────────────────────────────────────────
// Removes the first node whose data equals value.
// Does nothing if value is not found.
// Returns true if a node was deleted, false otherwise.
bool deleteByValue(SLLNode*& head, int value) {
    if (head == nullptr) {
        return false;
    }
    SLLNode* prev = head;
    SLLNode* curr = head->next;
    while (curr != nullptr) {
        if (curr->data == value) {
            prev->next = curr->next;
            delete curr;
            return true;
        }
        prev=curr;
        curr=curr->next;
    }
    // TODO: implement
    return false;
}

// ── search ───────────────────────────────────────────────────
// Returns true if any node's data equals target; false otherwise.
bool search(SLLNode* head, int target) {
    while (head != nullptr) {
        if(head->data == target) {
            return true;
        }
        head = head->next;
    }
    // TODO: implement
    return false;
}

// ── display ──────────────────────────────────────────────────
// Prints all node values from head to tail in the format:
//   v1 -> v2 -> ... -> vN -> NULL
// Prints "NULL" if the list is empty.
void display(SLLNode* head) {
    while (head != nullptr) {
        cout<< head->data<< " ";
    }
    cout<<endl;
    // TODO: implement
}

// ── main ─────────────────────────────────────────────────────
int main() {
    SLLNode* head = nullptr;

    cout << "=== PART B.1: SINGLY LINKED LIST ===" << endl;

    // TODO: call insertAtHead(head, 10), then print:
    //   "insertAtHead(10): "; display(head); cout << endl;

    // TODO: call insertAtHead(head, 5), then print:
    //   "insertAtHead(5):  "; display(head); cout << endl;

    // TODO: call insertAtTail(head, 20), then print:
    //   "insertAtTail(20): "; display(head); cout << endl;

    // TODO: call insertAtTail(head, 30), then print:
    //   "insertAtTail(30): "; display(head); cout << endl;

    cout << endl;

    // TODO: call search(head, 20) and print the result.
    //   When found:     "search(20): found" << endl
    //   When not found: "search(20): not found" << endl

    // TODO: call search(head, 99) and print the result.
    //   Same format as above.

    cout << endl;

    // TODO: call deleteByValue(head, 10), then print:
    //   "deleteByValue(10): "; display(head); cout << endl;

    // TODO: call deleteByValue(head, 99) and print the result.
    //   When not found: "deleteByValue(99): not found" << endl

    return 0;
}
