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
    if (index < 0 || index >= size) {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        if (i == index) {
            return arr[index];
        }
    }
    return -1;
}

// ── linearSearch ────────────────────────────────────────────
// Returns the first index i such that arr[i] == target.
// Returns -1 if target is not found in arr[0..size-1].
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// ── insertAt ────────────────────────────────────────────────
// Inserts value at arr[index] by shifting arr[index..size-1]
// one position to the right. Increments size by 1 on success.
// Returns false if index < 0, index > size, or size >= MAX_SIZE.
bool insertAt(int arr[], int& size, int index, int value) {
    if (index < 0 || index > size || size >= MAX_SIZE) {
        return false;
    }
    for (int i = size; i > index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    ++size;
    return true;
}

// ── deleteAt ────────────────────────────────────────────────
// Deletes arr[index] by shifting arr[index+1..size-1] one
// position to the left. Decrements size by 1 on success.
// Returns false if index < 0 or index >= size.
bool deleteAt(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        return false;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    --size;
    return true;
}

// ── main ─────────────────────────────────────────────────────
int main() {
    int arr[MAX_SIZE] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "=== PART A: ARRAY OPERATIONS ===" << endl;
    cout << "Initial array: "; printArray(arr, size); cout << endl;

    // ── Access ───────────────────────────────────────────────
    cout << endl << "-- Access --" << endl;
    cout << "getElement at index 2: " << getElement(arr, size, 2) << endl;
    cout << "getElement at index 10: " << getElement(arr, size, 10) << endl;

    // ── Search ───────────────────────────────────────────────
    cout << endl << "-- Search --" << endl;
    int idx = linearSearch(arr, size, 40);
    if (idx != -1) cout << "linearSearch for 40: found at index " << idx << endl;
    else cout << "linearSearch for 40: not found" << endl;

    idx = linearSearch(arr, size, 99);
    if (idx != -1) cout << "linearSearch for 99: found at index " << idx << endl;
    else cout << "linearSearch for 99: not found" << endl;

    // ── Insert ───────────────────────────────────────────────
    cout << endl << "-- Insert --" << endl;
    insertAt(arr, size, 2, 25);
    cout << "After insertAt(index 2, value 25): ";
    printArray(arr, size); cout << endl;

    insertAt(arr, size, 0, 5);
    cout << "After insertAt(index 0, value 5):  ";
    printArray(arr, size); cout << endl;

    // ── Delete ───────────────────────────────────────────────
    cout << endl << "-- Delete --" << endl;
    deleteAt(arr, size, 3);
    cout << "After deleteAt(index 3): ";
    printArray(arr, size); cout << endl;

    deleteAt(arr, size, 0);
    cout << "After deleteAt(index 0): ";
    printArray(arr, size); cout << endl;

    return 0;
}
