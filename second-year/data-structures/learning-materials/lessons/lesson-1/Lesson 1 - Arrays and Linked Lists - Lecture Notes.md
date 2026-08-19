# Lesson 1 — Arrays and Linked Lists
## Lecture Notes

**Course:** CSIT 103 · Data Structures and Algorithms  
**Module:** Module 1 · Linear Structures and Sorting Algorithms

---

## Learning Outcomes

By the end of this lesson, you will be able to:

1. Implement valid array operations.
2. Analyze time and space complexity of array operations.
3. Implement valid linked list operations.
4. Compare time and space complexity of arrays and linked lists.

---

## Section A — Abstract Data Types and Arrays

### A.1 What Is a Data Structure?

A **data structure** is an organized arrangement of data in memory that enables efficient storage, retrieval, and modification. The choice of structure determines the performance of every operation performed on that data.

Key ideas:

- Data structures store **values** and define the **relationships** between them.
- Each structure supports a fixed set of **operations** (e.g., insert, search, delete).
- No single structure is best for every problem — choosing well is a core engineering skill.
- This course covers **linear structures** (arrays, lists, stacks, queues) and **hierarchical structures** (trees).

The six structures covered this semester are: arrays, linked lists, stacks, queues, hash tables, and binary search trees.

---

### A.2 Abstract Data Type (ADT)

An **Abstract Data Type (ADT)** is a mathematical model that specifies a data type by its *behavior* — the set of operations and their semantics — without prescribing how that behavior is implemented in memory.

| ADT specifies *what* | Implementation specifies *how* |
|---|---|
| Supported operations | Memory layout (array, nodes, hash table…) |
| Preconditions and postconditions | Pointer / index management |
| Observable behavior from the caller's perspective | Time and space trade-offs |

> **Example:** The **List ADT** can be implemented with either an array or a linked list — same interface, different performance characteristics.

*Analogy:* A TV remote defines the interface (buttons); the circuit board inside is the implementation. Two brands can have identical buttons but completely different electronics.

---

### A.3 The Array

An **array** is a finite, ordered sequence of elements of the same type, stored in **contiguous memory locations** and accessed via a zero-based integer index.

Key properties:
- **Fixed size** — declared at creation; cannot grow or shrink (static array).
- **Random access** — any element reached in O(1) by index arithmetic.
- **Cache-friendly** — sequential elements sit in adjacent memory; prefetching works well.

**Index formula:**

```
address(i) = base + i × sizeof(T)
```

where `base` is the address of element 0 and `T` is the element type.

**Memory layout — `int arr[5]`:**

| Index   | 0    | 1    | 2    | 3    | 4    |
|---------|------|------|------|------|------|
| Value   | 10   | 25   | 7    | 42   | 3    |
| Address | 1000 | 1004 | 1008 | 1012 | 1016 |

Each `int` occupies 4 bytes; addresses are contiguous.

> **Example:** To access `arr[3]`, compute `1000 + 3 × 4 = 1012`. One multiply, one add, regardless of array size — that is why access is O(1).

---

### A.4 Static vs. Dynamic Arrays

| | Static Array — `int arr[N]` | Dynamic Array — `std::vector<T>` |
|---|---|---|
| Size | Fixed at **compile time** | Adjustable at **run time** |
| Allocation | **Stack** | **Heap** |
| Overhead | None — fastest allocation | Slight (capacity, size, pointer) |
| Risk | Overflow if N underestimated; waste if overestimated | — |
| Resizing | Not possible | Amortized O(1) `push_back` via doubling |

```cpp
int scores[30];          // static: exactly 30 ints
scores[0] = 95;          // O(1) access

std::vector<int> v;
v.push_back(95);         // appends; resizes if needed
v[0] = 88;               // O(1) access
```

> **Key insight:** A `std::vector` is still a contiguous array underneath. When it runs out of room, it allocates a new block **double the size** and copies everything over. That copy is O(n), but it happens rarely enough that the average cost per `push_back` is still O(1) (*amortized analysis*).

---

### A.5 Array Operation: Access

```cpp
int arr[] = {10, 25, 7, 42, 3};
int n = 5;

// Direct index access — O(1)
int val = arr[2];   // val = 7

// Bounds check (good practice)
if (idx >= 0 && idx < n) int safe = arr[idx];
```

Address computed as `base + index × sizeof(int)` — one arithmetic operation, independent of *n*.

> **Warning:** C++ does **not** check array bounds for you. Accessing outside the array is undefined behavior.

| Case | Time | Space (aux.) |
|---|---|---|
| Any index | **O(1)** | **O(1)** |

---

### A.6 Array Operation: Linear Search

```cpp
// Returns index of target, or -1 if not found
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;       // found — stop early
    }
    return -1;              // not found
}
```

| Case | Condition | Time |
|---|---|---|
| Best | Target is at index 0 | **O(1)** |
| Average | Target is somewhere in the middle | **O(n)** |
| Worst | Target is at the last index, or absent | **O(n)** |

> **When to use:** Only when the array is unsorted. If sorted, binary search gives O(log n).

---

### A.7 Array Operation: Insert at Index

```cpp
// Insert val at position pos; arr has capacity for n+1 elements
void insertAt(int arr[], int& n, int pos, int val) {
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];   // shift right: O(n) worst case
    arr[pos] = val;
    n++;
}
// Insert at tail (no shifting needed):
// arr[n++] = val;  — O(1)
```

| Position | Shifts Required | Time |
|---|---|---|
| At tail (`arr[n]`) | 0 shifts | **O(1)** |
| At middle | ~n/2 shifts | **O(n)** |
| At head (index 0) | n shifts | **O(n)** |

---

### A.8 Array Operation: Delete at Index

```cpp
// Delete element at position pos
void deleteAt(int arr[], int& n, int pos) {
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];   // shift left: O(n) worst case
    n--;
}
// Delete from tail: n--;  — O(1)
```

| Position | Shifts Required | Time |
|---|---|---|
| At tail (`arr[n-1]`) | 0 shifts | **O(1)** |
| At middle | ~n/2 shifts | **O(n)** |
| At head (index 0) | n−1 shifts | **O(n)** |

> **Note:** The old value is still physically in memory; decrementing `n` makes it logically gone. For objects with destructors, this matters.

---

### A.9 Array Complexity Summary

| Operation | Best | Average | Worst | Space (aux.) |
|---|---|---|---|---|
| Access by index | O(1) | O(1) | O(1) | O(1) |
| Linear search | O(1) | O(n) | O(n) | O(1) |
| Insert at tail | O(1) | O(1) | O(1) | O(1) |
| Insert at index *i* | O(1) | O(n) | O(n) | O(1) |
| Delete from tail | O(1) | O(1) | O(1) | O(1) |
| Delete at index *i* | O(1) | O(n) | O(n) | O(1) |

> **Arrays excel at random access** (O(1) by index) and are **cache-friendly** due to contiguous memory layout. Best suited for problems where element positions are known or the collection is rarely resized.

---

## Section B — Asymptotic Analysis

### B.1 Why Analyze Algorithms?

Two programs that produce the same correct output can differ dramatically in **speed** and **memory use** as the input grows.

| Algorithm | n = 1,000 | n = 1,000,000 | n = 1,000,000,000 |
|---|---|---|---|
| O(1) | 1 step | 1 step | 1 step |
| O(log n) | ~10 steps | ~20 steps | ~30 steps |
| O(n) | 1,000 steps | 1,000,000 steps | 1,000,000,000 steps |
| O(n²) | 1,000,000 steps | 10¹² steps | 10¹⁸ steps |

> **Warning:** An O(n²) algorithm on 10⁹ elements would take **decades** on modern hardware. Algorithm choice matters more than hardware speed for large inputs. Buying a faster CPU only helps by a constant factor; a better algorithm changes the exponent.

---

### B.2 Big-O Notation

**Big-O — O(g(n))** — An *upper bound* on the growth rate of a function. We say f(n) = O(g(n)) if there exist positive constants c and n₀ such that f(n) ≤ c · g(n) for all n ≥ n₀.

In algorithm analysis, O(g(n)) describes the **worst-case growth rate** of an algorithm's resource use (time or space) as input size *n* grows toward infinity.

Rules:
- **Drop constants:** O(3n) = O(n), O(500) = O(1)
- **Drop lower-order terms:** O(n² + n) = O(n²), O(n log n + n) = O(n log n)
- **Focus on the dominant term** — the one that grows fastest as n → ∞

> Big-O is the most commonly used notation in practice because it tells us the **guaranteed worst-case limit** — the most critical bound for system design.

---

### B.3 Big-Ω and Big-Θ Notation

| Notation | Bound | Meaning | Answers the question |
|---|---|---|---|
| **O(g(n))** | Upper | Grows *at most* as fast as g(n) | "How slow can it get?" |
| **Ω(g(n))** | Lower | Grows *at least* as fast as g(n) | "How fast can it run?" |
| **Θ(g(n))** | Tight | Grows *exactly* as fast as g(n) | "What's the exact rate?" |

**Big-Ω — Ω(g(n)):** A lower bound. Describes the **best-case floor** on resource use.  
*Example:* Linear search is Ω(1) — the target may be at index 0.

**Big-Θ — Θ(g(n)):** A tight bound; both upper and lower bounds match.  
*Example:* Linear search is Θ(n) — average and worst case both grow linearly.

*Analogy:* An elevator. Big-O is "at most this many floors up." Big-Omega is "at least this many." Big-Theta is "exactly this floor."

---

### B.4 Common Complexity Classes

| Class | Name | Example | n = 1,000 (approx.) |
|---|---|---|---|
| O(1) | Constant | Array access, hash lookup | 1 step |
| O(log n) | Logarithmic | Binary search, BST search | ~10 steps |
| O(n) | Linear | Linear search, array traversal | 1,000 steps |
| O(n log n) | Linearithmic | Merge sort, heap sort | ~10,000 steps |
| O(n²) | Quadratic | Bubble sort, insertion sort (worst) | 1,000,000 steps |
| O(2ⁿ) | Exponential | Brute-force subset enumeration | 2¹⁰⁰⁰ — infeasible |

Ordered from fastest to slowest growth:  
**O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(2ⁿ)**

> **Quick checks:** For O(log n): doubling n adds only one more step. For O(n²): doubling n quadruples the work, because (2n)² = 4n².

---

### B.5 Best, Average, and Worst Case

The same algorithm can behave very differently depending on the input:

| Scenario | Description | Bound |
|---|---|---|
| **Best Case** | Most favorable possible input | Lower bound (Ω) |
| **Average Case** | Expected performance over all inputs | Requires probability analysis |
| **Worst Case** | Most unfavorable possible input | Upper bound (O) |

*Example using linear search:*
- **Best:** Target at index 0 → 1 comparison
- **Average:** Target at random position → ~n/2 comparisons
- **Worst:** Target absent or at last index → n comparisons

> **Rule:** Unless stated otherwise, Big-O in this course refers to the **worst-case** scenario. We design for the worst case because it really does happen in practice.

---

### B.6 Introduction to Recursion

**Recursion** — A technique where a function solves a problem by calling itself on a *smaller subproblem*, until a **base case** is reached that can be solved directly.

- **Base case** — the termination condition; prevents infinite recursion.
- **Recursive case** — breaks the problem into a smaller version of itself.
- Each call is pushed onto the **call stack**; resolved in LIFO order.
- Every recursive algorithm can be rewritten iteratively (and vice versa).

```cpp
// Recursive factorial
int factorial(int n) {
    if (n == 0) return 1;       // base case
    return n * factorial(n - 1); // recursive case
}

// factorial(3) → 3 * factorial(2)
//              → 3 * 2 * factorial(1)
//              → 3 * 2 * 1 * factorial(0)
//              → 3 * 2 * 1 * 1 = 6
```

`factorial(3)` pushes 4 stack frames before unwinding.

> **Warning:** Omit the base case and you get infinite recursion — a stack overflow.

---

### B.7 Recursion vs. Iteration

```cpp
// Recursive — O(n) time, O(n) space
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// Iterative — O(n) time, O(1) space
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}
```

| | Recursive | Iterative |
|---|---|---|
| Time | O(n) | O(n) |
| Space | O(n) — one frame per call | O(1) — single accumulator |
| Risk | Stack overflow for large *n* | None |
| Clarity | Elegant; close to the math definition | Slightly more verbose |

> **Guideline:** Choose recursion when it makes the algorithm significantly clearer (e.g., tree traversal, divide-and-conquer sorting). Choose iteration when stack depth is a concern.

---

## Section C — Linked Lists

### C.1 What Is a Linked List?

A **linked list** is a linear data structure in which elements (called *nodes*) are stored at non-contiguous memory locations. Each node holds a **data value** and one or more **pointers** to adjacent nodes, forming a chain.

Unlike arrays, linked lists do not require contiguous memory — nodes may be scattered anywhere on the heap.

Key properties:
- No fixed capacity — grows and shrinks dynamically.
- Insertion and deletion at the head are **O(1)** — no shifting.
- No index-based random access — must traverse from the head.
- Each node carries a pointer overhead (4–8 bytes per node).

**Singly linked list: 10 → 25 → 7 → 42 → null**

| Node | data | next → |
|---|---|---|
| head | 10 | node₂ |
| node₂ | 25 | node₃ |
| node₃ | 7 | node₄ |
| node₄ | 42 | null |

*Analogy:* A scavenger hunt where each clue tells you only where the next clue is. You cannot jump straight to clue four — you must follow 1 → 2 → 3 → 4.

---

### C.2 Node Structure in C++

```cpp
// A singly linked list node
struct Node {
    int data;      // the stored value
    Node* next;    // pointer to the next node (nullptr if tail)
};

// Creating nodes on the heap
Node* a = new Node{10, nullptr};
Node* b = new Node{25, nullptr};

// Linking nodes: 10 → 25 → null
a->next = b;
Node* head = a;
```

Nodes are dynamically allocated; `next` is `nullptr` for the tail node.

> **Warning:** Every `new` must be paired with a `delete` when the node is removed. Failing to do so causes a **memory leak**.

---

### C.3 Singly Linked List: Insert at Head — O(1)

```cpp
void insertHead(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr};  // 1. allocate new node
    newNode->next = head;                    // 2. point new node to old head
    head = newNode;                          // 3. update head pointer
}
```

Three pointer operations, regardless of list length — **O(1)**.

**Step-by-step (inserting value 5 into list: head → [10] → [25] → null):**

1. Allocate `newNode{5}`.
2. Set `newNode->next = head` (links to [10]).  
   *Critical: do this before moving head — otherwise the old list is lost.*
3. Set `head = newNode`.

**Result:** head → [5] → [10] → [25] → null

| Case | Time | Aux. Space |
|---|---|---|
| Any | **O(1)** | **O(1)** |

---

### C.4 Singly Linked List: Insert at Tail — O(n)

```cpp
void insertTail(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (head == nullptr) {              // empty list edge case
        head = newNode; return;
    }
    Node* curr = head;
    while (curr->next != nullptr)       // traverse to the last node
        curr = curr->next;
    curr->next = newNode;               // link last node to new node
}
```

Without a `tail` pointer, inserting at the tail requires a full traversal.

| Case | Time | Aux. Space |
|---|---|---|
| Any (no tail ptr) | **O(n)** | **O(1)** |

> **Optimization:** Keeping a separate `tail` pointer alongside `head` reduces insert-at-tail to **O(1)** — the standard optimization for queue implementations.

---

### C.5 Singly Linked List: Delete a Node — O(n)

```cpp
void deleteByValue(Node*& head, int val) {
    if (head == nullptr) return;         // empty list
    if (head->data == val) {             // delete head node
        Node* temp = head;
        head = head->next;
        delete temp; return;
    }
    Node* prev = head;
    while (prev->next != nullptr && prev->next->data != val)
        prev = prev->next;              // find node before target
    if (prev->next == nullptr) return;  // value not found
    Node* target = prev->next;
    prev->next = target->next;          // bypass the target node
    delete target;                      // free memory
}
```

Re-link the predecessor's `next` to skip the target, then `delete` the node.

| Case | Time | Aux. Space |
|---|---|---|
| Best (head match) | **O(1)** | **O(1)** |
| Average / Worst | **O(n)** | **O(1)** |

> **Pattern for deleting the head:** Always save the old head in `temp`, advance `head`, then `delete temp`. Never delete before advancing.

---

### C.6 Singly Linked List: Traversal and Search

```cpp
// Print all values in the list
void traverse(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
}

// Search for a value; returns pointer or nullptr
Node* search(Node* head, int val) {
    for (Node* curr = head; curr != nullptr; curr = curr->next)
        if (curr->data == val)
            return curr;
    return nullptr;
}
```

Both operations visit every node in sequence — **O(n)**.

| Operation | Best | Average | Worst |
|---|---|---|---|
| Traverse (print all) | O(n) | O(n) | O(n) |
| Search by value | O(1) | O(n) | O(n) |

> The traversal idiom `for (Node* curr = head; curr != nullptr; curr = curr->next)` is the standard pattern used in virtually every linked list exercise.

---

### C.7 Singly Linked List: Complexity Summary

| Operation | Best | Average | Worst | Space (aux.) |
|---|---|---|---|---|
| Insert at head | O(1) | O(1) | O(1) | O(1) |
| Insert at tail (no tail ptr) | O(n) | O(n) | O(n) | O(1) |
| Insert at tail (with tail ptr) | O(1) | O(1) | O(1) | O(1) |
| Delete by value | O(1) | O(n) | O(n) | O(1) |
| Search by value | O(1) | O(n) | O(n) | O(1) |
| Traverse (all nodes) | O(n) | O(n) | O(n) | O(1) |

> **Key advantage over arrays:** O(1) head insertion and deletion — no shifting required.

---

### C.8 Doubly Linked List (DLL)

A **doubly linked list** is a linked list in which each node holds pointers to both the *next* and *previous* nodes, enabling traversal in both directions.

```cpp
struct DNode {
    int data;
    DNode* next;     // pointer to next node
    DNode* prev;     // pointer to previous node
};
// null ← [10] ⇄ [25] ⇄ [7] → null

// Delete a node (no predecessor search needed — O(1))
void deleteNode(DNode*& head, DNode* target) {
    if (target->prev) target->prev->next = target->next;
    else head = target->next;          // target was head
    if (target->next) target->next->prev = target->prev;
    delete target;
}
```

| Feature | SLL | DLL |
|---|---|---|
| Delete known node | O(n) | **O(1)** |
| Reverse traversal | Not supported | O(n) |
| Memory per node | 1 pointer | 2 pointers |
| Insert at head/tail | O(1) | O(1) |

> `std::list<T>` in the C++ STL is a doubly linked list.  
> **Real-world uses:** Browser history (back/forward), undo-redo in editors, previous/next track in a music player.

---

### C.9 Circular Linked List

A **circular linked list** is a linked list in which the tail node's `next` pointer points back to the **head**, forming a closed loop with no natural end.

| Node | data | next → |
|---|---|---|
| head | 10 | node₂ |
| node₂ | 25 | node₃ |
| node₃ | 7 | **head** ↩ |

Key properties:
- Traversal must use a stop condition other than `nullptr`.
- Can be singly or doubly linked.
- Every node has equal access to all others — no privileged "start."

> **Warning:** A naive traversal loop without a stop condition will run **infinitely** on a circular list. Stop condition: "have I arrived back at head?"

**Use cases:** Round-robin task scheduling, circular buffers, game turn rotation.

---

### C.10 Pointer Management Pitfalls

#### 1. Dangling Pointer
Accessing a node after it has been deleted.
```cpp
Node* p = head;
delete p;
p->data;  // undefined behavior!
```
**Fix:** Set `p = nullptr` immediately after `delete p`.

#### 2. Memory Leak
Losing all pointers to a node without deleting it.
```cpp
head = head->next; // old head is now orphaned — memory never freed!
```
**Fix:** Store old head in `temp`, advance, then `delete temp`.

#### 3. Null Dereference
Dereferencing a `nullptr` pointer.
```cpp
Node* curr = head;
while (curr->next != nullptr)  // crashes if head == nullptr!
    curr = curr->next;
```
**Fix:** Always check `if (head == nullptr)` before dereferencing.

#### 4. Wrong Order of Pointer Updates
Overwriting a pointer before saving the value it holds causes permanent data loss.  
**Fix:** Always save existing pointer values before overwriting them.

> **The thread through all four:** C++ has no garbage collector. Every `new` needs a `delete`, and every pointer gets checked before you use it.

---

## Section D — Arrays vs. Linked Lists

### D.1 Time Complexity Comparison

| Operation | Array | Singly Linked List | Winner |
|---|---|---|---|
| Access by index | **O(1)** | O(n) | Array |
| Search by value (unsorted) | O(n) | O(n) | Tie |
| Insert at head | O(n) | **O(1)** | Linked List |
| Insert at tail | **O(1)** | O(1)* | Tie* |
| Insert at arbitrary index *i* | O(n) | O(n) | Tie |
| Delete at head | O(n) | **O(1)** | Linked List |
| Delete at arbitrary index *i* | O(n) | O(n) | Tie |

*With a maintained `tail` pointer.

---

### D.2 Space and Cache Comparison

| Property | Array | Linked List |
|---|---|---|
| Memory layout | Contiguous — one block | Non-contiguous — nodes scattered on heap |
| Cache behavior | **Cache-friendly** — sequential access triggers prefetch | **Cache-unfriendly** — pointer chasing causes cache misses |
| Overhead per element | None | 4–8 bytes per pointer |
| Total space | O(n) | O(n) (but larger constant due to pointers) |
| Resizing | Requires full copy (static) or amortized doubling (vector) | Grow/shrink one node at a time — no copying |

---

### D.3 When to Choose Each Structure

**Choose an array when:**
- You need fast **random access** by index (O(1)).
- The size is known in advance or changes rarely.
- Cache performance matters (tight loops, numerical work).
- You need simple, predictable memory usage.

**Choose a linked list when:**
- You frequently **insert or delete at the head** (O(1) vs. O(n) for array).
- The size varies significantly and unpredictably.
- You do not need index-based access.
- You are building a stack or queue (linked list is a natural fit).

---

### D.4 Lesson Summary

| Concept | Key Takeaway |
|---|---|
| Data structure | An organized arrangement of data that enables efficient operations |
| ADT | Defines *what* operations are supported, not *how* they are implemented |
| Array | Contiguous memory; O(1) index access; O(n) insert/delete in the middle |
| Static vs. dynamic array | Stack vs. heap; `int arr[N]` vs. `std::vector<T>` |
| Big-O | Upper bound on worst-case growth rate; drop constants and lower-order terms |
| Complexity classes | O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(2ⁿ) |
| Recursion | Function calls itself on a smaller subproblem; requires a base case |
| Linked list | Non-contiguous nodes linked by pointers; O(1) head insert/delete; O(n) search |
| Doubly linked list | Adds `prev` pointer; enables O(1) deletion of a known node |
| Circular linked list | Tail points back to head; no null — stop condition must check for cycle |
| Pointer pitfalls | Dangling pointer, memory leak, null dereference, wrong update order |

---

*Lesson 1 — CSIT 103 · Data Structures and Algorithms · Visayas State University*  
*Author: Jomari Joseph A. Barrera*
