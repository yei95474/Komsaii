// ============================================================
// Lab Exercise 1 — Arrays and Linked Lists
// CSIT 103 — Data Structures and Algorithms
// Visayas State University · AY 2026-2027 · 1st Semester
// ------------------------------------------------------------
// Part A: Array Operations
// File: ArrayOperations.cpp
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

const int MAX_SIZE = 100;

// ── Function Prototypes ──────────────────────────────────────
int  getElement(int arr[], int size, int index);
int  linearSearch(int arr[], int size, int target);
bool insertAt(int arr[], int& size, int index, int value);
bool deleteAt(int arr[], int& size, int index);
void printArray(int arr[], int size);

// ── printArray ───────────────────────────────────────────────
// Prints the array contents and current size.
// Do not modify this function.
void printArray(int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "]  size = " << size;
}

// ── getElement ───────────────────────────────────────────────
// Returns the element stored at arr[index].
// Returns -1 if index < 0 or index >= size.
int getElement(int arr[], int size, int index) {
    // TODO: implement
    return -1;
}

// ── linearSearch ────────────────────────────────────────────
// Returns the first index i such that arr[i] == target.
// Returns -1 if target is not found in arr[0..size-1].
int linearSearch(int arr[], int size, int target) {
    // TODO: implement
    return -1;
}

// ── insertAt ────────────────────────────────────────────────
// Inserts value at arr[index] by shifting arr[index..size-1]
// one position to the right. Increments size by 1 on success.
// Returns false if index < 0, index > size, or size >= MAX_SIZE.
bool insertAt(int arr[], int& size, int index, int value) {
    // TODO: implement
    return false;
}

// ── deleteAt ────────────────────────────────────────────────
// Deletes arr[index] by shifting arr[index+1..size-1] one
// position to the left. Decrements size by 1 on success.
// Returns false if index < 0 or index >= size.
bool deleteAt(int arr[], int& size, int index) {
    // TODO: implement
    return false;
}

// ── main ─────────────────────────────────────────────────────
int main() {
    int arr[MAX_SIZE] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "=== PART A: ARRAY OPERATIONS ===" << endl;
    cout << "Initial array: "; printArray(arr, size); cout << endl;

    // ── Access ───────────────────────────────────────────────
    cout << endl << "-- Access --" << endl;
    // TODO: call getElement(arr, size, 2) and print the result.
    //   Expected format: "getElement at index 2:  " << result << endl

    // TODO: call getElement(arr, size, 10) and print the result.
    //   Expected format: "getElement at index 10: " << result << endl

    // ── Search ───────────────────────────────────────────────
    cout << endl << "-- Search --" << endl;
    // TODO: call linearSearch(arr, size, 40) and print the result.
    //   When found:     "linearSearch for 40: found at index " << idx << endl
    //   When not found: "linearSearch for 40: not found" << endl

    // TODO: call linearSearch(arr, size, 99) and print the result.
    //   Same format as above.

    // ── Insert ───────────────────────────────────────────────
    cout << endl << "-- Insert --" << endl;
    // TODO: call insertAt(arr, size, 2, 25), then print:
    //   "After insertAt(index 2, value 25): "; printArray(arr, size); cout << endl;

    // TODO: call insertAt(arr, size, 0, 5), then print:
    //   "After insertAt(index 0, value 5):  "; printArray(arr, size); cout << endl;

    // ── Delete ───────────────────────────────────────────────
    cout << endl << "-- Delete --" << endl;
    // TODO: call deleteAt(arr, size, 3), then print:
    //   "After deleteAt(index 3): "; printArray(arr, size); cout << endl;

    // TODO: call deleteAt(arr, size, 0), then print:
    //   "After deleteAt(index 0): "; printArray(arr, size); cout << endl;

    return 0;
}
