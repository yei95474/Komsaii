// ============================================================
// Lab Exercise 1 — Arrays and Linked Lists
// CSIT 103 — Data Structures and Algorithms
// Visayas State University · AY 2026-2027 · 1st Semester
// ------------------------------------------------------------
// Part B.3: Circular Linked List Operations
// File: CircularLinkedList.cpp
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
struct CLLNode {
    int data;
    CLLNode* next;
    CLLNode(int val) : data(val), next(nullptr) {}
};

// ── Function Prototypes ──────────────────────────────────────
void insertAtHead(CLLNode*& head, int value);
void insertAtTail(CLLNode*& head, int value);
bool deleteByValue(CLLNode*& head, int value);
void display(CLLNode* head);

// ── insertAtHead ─────────────────────────────────────────────
// Creates a new node with value and inserts it before head.
// The new node's next must point to the old head.
// The last node's next must be updated to the new node (new head).
// If the list is empty, the new node's next points to itself.
void insertAtHead(CLLNode*& head, int value) {
    // TODO: implement
}

// ── insertAtTail ─────────────────────────────────────────────
// Creates a new node with value and appends it after the last node.
// The new node's next must point to head (circular link).
// The former last node's next must be updated to the new node.
// If the list is empty, the new node's next points to itself.
void insertAtTail(CLLNode*& head, int value) {
    // TODO: implement
}

// ── deleteByValue ────────────────────────────────────────────
// Removes the first node whose data equals value.
// Maintains the circular link after deletion.
// If head is deleted and the list had only one node, head = nullptr.
// Returns true if a node was deleted, false otherwise.
bool deleteByValue(CLLNode*& head, int value) {
    // TODO: implement
    return false;
}

// ── display ──────────────────────────────────────────────────
// Prints all node values starting at head, stopping before
// returning to head. Format:
//   v1 -> v2 -> ... -> vN -> (back to head)
// Prints "(empty)" if head is nullptr.
void display(CLLNode* head) {
    // TODO: implement
}

// ── main ─────────────────────────────────────────────────────
int main() {
    CLLNode* head = nullptr;

    cout << "=== PART B.3: CIRCULAR LINKED LIST ===" << endl;

    // TODO: call insertAtHead(head, 10), then print:
    //   "insertAtHead(10): "; display(head); cout << endl;

    // TODO: call insertAtHead(head, 5), then print:
    //   "insertAtHead(5):  "; display(head); cout << endl;

    // TODO: call insertAtTail(head, 20), then print:
    //   "insertAtTail(20): "; display(head); cout << endl;

    // TODO: call insertAtTail(head, 30), then print:
    //   "insertAtTail(30): "; display(head); cout << endl;

    cout << endl;

    // TODO: call deleteByValue(head, 10), then print:
    //   "deleteByValue(10): "; display(head); cout << endl;

    // TODO: call deleteByValue(head, 99) and print the result.
    //   When not found: "deleteByValue(99): not found" << endl

    return 0;
}
