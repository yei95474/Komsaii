# Lab Exercise 1 — Arrays and Linked Lists
## CSIT 103 — Data Structures and Algorithms

> **Visayas State University · Department of Computer Science and Technology · Faculty of Computing**

---

| Field | Value |
|-------|-------|
| **Course Outcome** | CO1 — Implement linear data structures with foundational sorting algorithms |
| **Learning Outcomes** | LO 1.1 — Implement valid array operations<br>LO 1.2 — Analyze time and space complexity of array operations<br>LO 1.3 — Implement valid linked list operations<br>LO 1.4 — Compare time and space complexity of arrays and linked lists |
| **Weight** | 2.5% of the final grade |
| **Format** | Individual, asynchronous |
| **Assigned** | Week 2 |
| **Due** | Week 3 — 5:00 PM |
| **Submission** | Push all `.cpp` files to `LabExercise01/` in your GitHub repository, then submit the repository URL on the VSU E-Learning Portal |

---

## Overview

In this lab exercise you will implement the array and linked list operations covered in Lesson 1. You will write four C++ source files:

| File | Contents | Points |
|------|----------|:------:|
| `ArrayOperations.cpp` | Four fundamental array operations | 25 |
| `SinglyLinkedList.cpp` | Five singly linked list operations | 20 |
| `DoublyLinkedList.cpp` | Five doubly linked list operations | 20 |
| `CircularLinkedList.cpp` | Four circular linked list operations | 20 |
| Complexity comment block in all four files | Part C — time complexity fill-in | 15 |
| **Total** | | **100** |

Each file must include a `main()` function that demonstrates all implemented operations using the test cases specified below. Your `main()` output must match the **Expected Output** shown for each part exactly.

Each file must also include a completed `/* COMPLEXITY ANALYSIS */` comment block at the top (Part C).

---

## Prerequisites

Before starting, ensure you have:

- Reviewed the **Lesson 1 — Arrays and Linked Lists** slides.
- Completed (or reviewed) **TLA 1 — Structure Trace** — the Part A code fragments (`getElement`, `linearSearch`, `insertAt`, `deleteAt`) and the Part C comparison table map directly to this exercise.
- A working C++ development environment (VS Code + GCC/MinGW). See [Setup/Laboratory Initial Set-up.md](../../../Setup/Laboratory%20Initial%20Set-up.md).
- Your GitHub lab repository set up with the `LabExercise01/` folder. See §8.3 of the setup guide.

---

## Files to Submit

Place all four `.cpp` files directly inside `LabExercise01/` in your GitHub repository:

```
LabExercise01/
├── README.md
├── ArrayOperations.cpp
├── SinglyLinkedList.cpp
├── DoublyLinkedList.cpp
└── CircularLinkedList.cpp
```

Download the starter files from the **Lab Exercise 1** activity on the VSU E-Learning Portal. Each starter file contains:

- The required `Node` struct definition (do **not** modify it).
- All function prototypes with detailed comments.
- A `/* COMPLEXITY ANALYSIS */` comment block template at the top (fill in all blanks).
- A `main()` skeleton with labelled sections (implement each section in order).

Replace every `// TODO: implement` comment with a working implementation.

---

## Part A — Array Operations

**File:** `ArrayOperations.cpp` &nbsp;|&nbsp; **Points:** 25

### Background

An array stores elements in contiguous memory. Index-based access is O(1), but insertions and deletions at arbitrary positions require shifting elements — O(n) in the worst case. You analyzed these same operations in TLA 1 Part A; this exercise asks you to implement them.

The array in this exercise uses a statically allocated array of capacity `MAX_SIZE = 100` and an integer `size` that tracks how many elements are currently stored.

### Function Specifications

Implement the following four functions exactly as specified. Do **not** change the function signatures.

```cpp
const int MAX_SIZE = 100;

// Returns the element stored at arr[index].
// Returns -1 if index < 0 or index >= size.
int getElement(int arr[], int size, int index);

// Returns the first index i such that arr[i] == target.
// Returns -1 if target is not found in arr[0..size-1].
int linearSearch(int arr[], int size, int target);

// Inserts value at position arr[index], shifting elements at positions
// index..size-1 one position to the right to make room.
// Increments size by 1 on success.
// Returns true on success.
// Returns false if index < 0, index > size, or size >= MAX_SIZE (array full).
bool insertAt(int arr[], int& size, int index, int value);

// Deletes the element at arr[index] by shifting elements at positions
// index+1..size-1 one position to the left to fill the gap.
// Decrements size by 1 on success.
// Returns true on success.
// Returns false if index < 0 or index >= size.
bool deleteAt(int arr[], int& size, int index);
```

### Helper Function

The following `printArray` helper is provided in the starter file. Do **not** modify it — use it to print the array in your `main()`.

```cpp
void printArray(int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "]  size = " << size;
}
```

### Test Sequence (implement in `main()`)

Your `main()` must execute the following operations **in this exact order** using the starting array `{10, 20, 30, 40, 50}` with `size = 5`.

1. Print the section header and initial array.
2. Call `getElement(arr, size, 2)` — print the result.
3. Call `getElement(arr, size, 10)` — print the result.
4. Call `linearSearch(arr, size, 40)` — print the result.
5. Call `linearSearch(arr, size, 99)` — print the result.
6. Call `insertAt(arr, size, 2, 25)` — print the array after insertion.
7. Call `insertAt(arr, size, 0, 5)` — print the array after insertion.
8. Call `deleteAt(arr, size, 3)` — print the array after deletion.
9. Call `deleteAt(arr, size, 0)` — print the array after deletion.

### Expected Output

```
=== PART A: ARRAY OPERATIONS ===
Initial array: [ 10 20 30 40 50 ]  size = 5

-- Access --
getElement at index 2:  30
getElement at index 10: -1

-- Search --
linearSearch for 40: found at index 3
linearSearch for 99: not found

-- Insert --
After insertAt(index 2, value 25): [ 10 20 25 30 40 50 ]  size = 6
After insertAt(index 0, value 5):  [ 5 10 20 25 30 40 50 ]  size = 7

-- Delete --
After deleteAt(index 3): [ 5 10 20 30 40 50 ]  size = 6
After deleteAt(index 0): [ 10 20 30 40 50 ]  size = 5
```

---

## Part B — Linked List Operations

### Task B.1 — Singly Linked List

**File:** `SinglyLinkedList.cpp` &nbsp;|&nbsp; **Points:** 20

#### Node Structure

The following `SLLNode` struct is provided in the starter file. Do **not** modify it.

```cpp
struct SLLNode {
    int data;
    SLLNode* next;
    SLLNode(int val) : data(val), next(nullptr) {}
};
```

#### Function Specifications

```cpp
// Creates a new node with value and inserts it before the current head.
// Updates head to point to the new node.
void insertAtHead(SLLNode*& head, int value);

// Creates a new node with value and appends it after the last node.
// If the list is empty, the new node becomes head.
void insertAtTail(SLLNode*& head, int value);

// Removes the first node whose data equals value.
// Does nothing if value is not found.
// Returns true if a node was deleted, false otherwise.
bool deleteByValue(SLLNode*& head, int value);

// Returns true if any node's data equals target; false otherwise.
bool search(SLLNode* head, int target);

// Prints all node values from head to tail in the format:
//   v1 -> v2 -> ... -> vN -> NULL
// Prints "NULL" if the list is empty.
void display(SLLNode* head);
```

#### Test Sequence (implement in `main()`)

Starting with an empty list (`head = nullptr`):

1. `insertAtHead(head, 10)` — display the list.
2. `insertAtHead(head, 5)` — display the list.
3. `insertAtTail(head, 20)` — display the list.
4. `insertAtTail(head, 30)` — display the list.
5. `search(head, 20)` — print result.
6. `search(head, 99)` — print result.
7. `deleteByValue(head, 10)` — display the list.
8. `deleteByValue(head, 99)` — print result.

#### Expected Output

```
=== PART B.1: SINGLY LINKED LIST ===

insertAtHead(10): 10 -> NULL
insertAtHead(5):  5 -> 10 -> NULL
insertAtTail(20): 5 -> 10 -> 20 -> NULL
insertAtTail(30): 5 -> 10 -> 20 -> 30 -> NULL

search(20): found
search(99): not found

deleteByValue(10): 5 -> 20 -> 30 -> NULL
deleteByValue(99): not found
```

---

### Task B.2 — Doubly Linked List

**File:** `DoublyLinkedList.cpp` &nbsp;|&nbsp; **Points:** 20

#### Node Structure

The following `DLLNode` struct is provided in the starter file. Do **not** modify it.

```cpp
struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};
```

#### Function Specifications

```cpp
// Creates a new node with value and inserts it before the current head.
// The new node's next points to the old head.
// The old head's prev (if it exists) is updated to point to the new node.
// Updates head to the new node.
void insertAtHead(DLLNode*& head, int value);

// Creates a new node with value and appends it after the last node.
// The new node's prev points to the former last node.
// If the list is empty, the new node becomes head.
void insertAtTail(DLLNode*& head, int value);

// Removes the first node whose data equals value.
// Correctly re-links the prev and next pointers of neighboring nodes.
// Returns true if a node was deleted, false otherwise.
bool deleteByValue(DLLNode*& head, int value);

// Prints all node values from head to tail in the format:
//   NULL <- v1 <-> v2 <-> ... <-> vN -> NULL
// Prints "NULL <- -> NULL" if the list is empty.
void displayForward(DLLNode* head);

// Traverses forward to reach the tail, then walks backward via prev pointers.
// Prints all values from tail to head in the format:
//   NULL <- vN <-> ... <-> v2 <-> v1 -> NULL
void displayBackward(DLLNode* head);
```

#### Test Sequence (implement in `main()`)

Starting with an empty list (`head = nullptr`):

1. `insertAtHead(head, 10)` — `displayForward`.
2. `insertAtHead(head, 5)` — `displayForward`.
3. `insertAtTail(head, 20)` — `displayForward`.
4. `insertAtTail(head, 30)` — `displayForward`.
5. `displayBackward(head)`.
6. `deleteByValue(head, 10)` — `displayForward`.
7. `deleteByValue(head, 99)` — print result.

#### Expected Output

```
=== PART B.2: DOUBLY LINKED LIST ===

insertAtHead(10): NULL <- 10 -> NULL
insertAtHead(5):  NULL <- 5 <-> 10 -> NULL
insertAtTail(20): NULL <- 5 <-> 10 <-> 20 -> NULL
insertAtTail(30): NULL <- 5 <-> 10 <-> 20 <-> 30 -> NULL

displayBackward: NULL <- 30 <-> 20 <-> 10 <-> 5 -> NULL

deleteByValue(10): NULL <- 5 <-> 20 <-> 30 -> NULL
deleteByValue(99): not found
```

---

### Task B.3 — Circular Linked List

**File:** `CircularLinkedList.cpp` &nbsp;|&nbsp; **Points:** 20

#### Node Structure

The following `CLLNode` struct is provided in the starter file. Do **not** modify it.

```cpp
struct CLLNode {
    int data;
    CLLNode* next;
    CLLNode(int val) : data(val), next(nullptr) {}
};
```

#### Function Specifications

```cpp
// Creates a new node with value and inserts it before the current head.
// The new node's next must point to the old head.
// The last node's next must be updated to point to the new node (new head).
// If the list is empty, the new node's next points to itself and becomes head.
void insertAtHead(CLLNode*& head, int value);

// Creates a new node with value and appends it after the last node.
// The new node's next must point to head (maintaining the circular link).
// The former last node's next must be updated to the new node.
// If the list is empty, the new node's next points to itself and becomes head.
void insertAtTail(CLLNode*& head, int value);

// Removes the first node whose data equals value.
// Maintains the circular link — the predecessor's next must point to the successor.
// If head is deleted and the list had only one node, head becomes nullptr.
// Returns true if a node was deleted, false otherwise.
bool deleteByValue(CLLNode*& head, int value);

// Prints all node values starting at head, stopping before returning to head.
// Format: v1 -> v2 -> ... -> vN -> (back to head)
// Prints "(empty)" if head is nullptr.
void display(CLLNode* head);
```

#### Test Sequence (implement in `main()`)

Starting with an empty list (`head = nullptr`):

1. `insertAtHead(head, 10)` — display the list.
2. `insertAtHead(head, 5)` — display the list.
3. `insertAtTail(head, 20)` — display the list.
4. `insertAtTail(head, 30)` — display the list.
5. `deleteByValue(head, 10)` — display the list.
6. `deleteByValue(head, 99)` — print result.

#### Expected Output

```
=== PART B.3: CIRCULAR LINKED LIST ===

insertAtHead(10): 10 -> (back to head)
insertAtHead(5):  5 -> 10 -> (back to head)
insertAtTail(20): 5 -> 10 -> 20 -> (back to head)
insertAtTail(30): 5 -> 10 -> 20 -> 30 -> (back to head)

deleteByValue(10): 5 -> 20 -> 30 -> (back to head)
deleteByValue(99): not found
```

---

## Part C — Complexity Writeup

**All four files** &nbsp;|&nbsp; **Points:** 15

### Instructions

At the **top of each** `.cpp` file you submit, include the following comment block filled in with the correct Big-O **time** complexity. Use the notation from Lesson 1: O(1), O(log n), O(n), O(n²), etc.

```cpp
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
```

The same completed table must appear at the top of **all four** `.cpp` files.

> **Grading note:** Each column (Array or SLL) is graded as a whole — all 7 entries must be correct to earn the column's points. There is no partial credit within a column.

---

## Submission Instructions

### Step 1 — Compile and test locally

Before pushing to GitHub, compile and run each file from the terminal:

```bash
g++ ArrayOperations.cpp    -o ao  && ./ao
g++ SinglyLinkedList.cpp   -o sll && ./sll
g++ DoublyLinkedList.cpp   -o dll && ./dll
g++ CircularLinkedList.cpp -o cll && ./cll
```

Verify that each program's output matches the **Expected Output** shown in this document exactly.

### Step 2 — Commit and push to GitHub

```bash
cd csit103-<sem>-sem-<year>-<lastname>-<firstname>
git add LabExercise01/
git commit -m "Lab Exercise 1 - array and linked list operations"
git push origin main
```

### Step 3 — Submit on the Portal

1. Copy your repository URL from the browser address bar.
2. Open the **CSIT 103** course on the VSU E-Learning Portal.
3. Navigate to **Lab Exercise 1** and paste the repository URL as your submission text.

> **Deadline policy:** The timestamp of your **last commit to `LabExercise01/`** is your official submission time — not the Portal submission time. Commits pushed after 5:00 PM at the end of Week 3 will be treated as late.

---

## Grading Rubric

### Part A — Array Operations (25 pts)

| Item | Points |
|------|:------:|
| `getElement` — returns correct value for valid index; returns -1 for out-of-bounds | 5 |
| `linearSearch` — returns correct index when found; returns -1 when not found | 5 |
| `insertAt` — correctly shifts right, inserts value, increments size; validates boundaries and capacity | 8 |
| `deleteAt` — correctly shifts left, decrements size; validates boundaries | 7 |
| **Part A Total** | **25** |

### Part B — Linked List Operations (60 pts)

#### B.1 — Singly Linked List (20 pts)

| Item | Points |
|------|:------:|
| `insertAtHead` — new node created; head updated correctly | 4 |
| `insertAtTail` — traverses to last node; new node appended | 4 |
| `deleteByValue` — target node removed; pointers re-linked; returns correct bool | 4 |
| `search` — traverses list; returns correct bool | 4 |
| `display` — correct format (`v -> ... -> NULL`); prints `NULL` for empty list | 4 |
| **SLL Total** | **20** |

#### B.2 — Doubly Linked List (20 pts)

| Item | Points |
|------|:------:|
| `insertAtHead` — `prev`/`next` pointers of new node and former head updated | 4 |
| `insertAtTail` — traverses to tail; `prev`/`next` of new node and former tail updated | 4 |
| `deleteByValue` — `prev` and `next` of both neighbors correctly re-linked; returns correct bool | 4 |
| `displayForward` — correct format (`NULL <- v <-> ... -> NULL`) | 4 |
| `displayBackward` — traverses to tail first; walks back via `prev`; correct format | 4 |
| **DLL Total** | **20** |

#### B.3 — Circular Linked List (20 pts)

| Item | Points |
|------|:------:|
| `insertAtHead` — last node's `next` updated to new head; circular link intact | 5 |
| `insertAtTail` — new tail's `next` points to head; circular link intact | 5 |
| `deleteByValue` — circular link maintained after deletion; single-node edge case handled | 5 |
| `display` — traversal stops before revisiting head; no infinite loop; correct format | 5 |
| **CLL Total** | **20** |

### Part C — Complexity Writeup (15 pts)

| Item | Points |
|------|:------:|
| Array column — all 7 time complexities correct | 7 |
| SLL column — all 7 time complexities correct | 7 |
| Comment block present and fully completed (no blanks) in all four `.cpp` files | 1 |
| **Part C Total** | **15** |

---

**Grand Total: 100 points**

---

*Lab Exercise 1 · CSIT 103 — Data Structures and Algorithms*
*Prepared by: Jomari Joseph A. Barrera, Assistant Professor 1, DCST, VSU*
