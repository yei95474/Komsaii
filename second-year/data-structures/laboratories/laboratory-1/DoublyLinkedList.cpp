// ============================================================
// Lab Exercise 1 — Arrays and Linked Lists
// CSIT 103 — Data Structures and Algorithms
// Visayas State University · AY 2026-2027 · 1st Semester
// ------------------------------------------------------------
// Part B.2: Doubly Linked List Operations
// File: DoublyLinkedList.cpp
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
struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// ── Function Prototypes ──────────────────────────────────────
void insertAtHead(DLLNode*& head, int value);
void insertAtTail(DLLNode*& head, int value);
bool deleteByValue(DLLNode*& head, int value);
void displayForward(DLLNode* head);
void displayBackward(DLLNode* head);

// ── insertAtHead ─────────────────────────────────────────────
// Creates a new node with value and inserts it before head.
// The new node's next must point to the old head.
// The old head's prev (if it exists) must be updated to the new node.
// Updates head to the new node.
void insertAtHead(DLLNode*& head, int value) {
    // TODO: implement
}

// ── insertAtTail ─────────────────────────────────────────────
// Creates a new node with value and appends it after the last node.
// The new node's prev must point to the former last node.
// If the list is empty, the new node becomes head.
void insertAtTail(DLLNode*& head, int value) {
    // TODO: implement
}

// ── deleteByValue ────────────────────────────────────────────
// Removes the first node whose data equals value.
// Correctly re-links the prev and next pointers of neighboring nodes.
// Returns true if a node was deleted, false otherwise.
bool deleteByValue(DLLNode*& head, int value) {
    // TODO: implement
    return false;
}

// ── displayForward ───────────────────────────────────────────
// Prints all node values from head to tail in the format:
//   NULL <- v1 <-> v2 <-> ... <-> vN -> NULL
// Prints "NULL <- -> NULL" if the list is empty.
void displayForward(DLLNode* head) {
    // TODO: implement
}

// ── displayBackward ──────────────────────────────────────────
// Traverses forward to reach the tail, then walks backward
// via prev pointers. Prints values from tail to head in the format:
//   NULL <- vN <-> ... <-> v2 <-> v1 -> NULL
void displayBackward(DLLNode* head) {
    // TODO: implement
}

// ── main ─────────────────────────────────────────────────────
int main() {
    DLLNode* head = nullptr;

    cout << "=== PART B.2: DOUBLY LINKED LIST ===" << endl;

    // TODO: call insertAtHead(head, 10), then print:
    //   "insertAtHead(10): "; displayForward(head); cout << endl;

    // TODO: call insertAtHead(head, 5), then print:
    //   "insertAtHead(5):  "; displayForward(head); cout << endl;

    // TODO: call insertAtTail(head, 20), then print:
    //   "insertAtTail(20): "; displayForward(head); cout << endl;

    // TODO: call insertAtTail(head, 30), then print:
    //   "insertAtTail(30): "; displayForward(head); cout << endl;

    cout << endl;

    // TODO: call displayBackward(head) and print:
    //   "displayBackward: "; displayBackward(head); cout << endl;

    cout << endl;

    // TODO: call deleteByValue(head, 10), then print:
    //   "deleteByValue(10): "; displayForward(head); cout << endl;

    // TODO: call deleteByValue(head, 99) and print the result.
    //   When not found: "deleteByValue(99): not found" << endl

    return 0;
}
