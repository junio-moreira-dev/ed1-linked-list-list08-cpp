//
// Created by Junio Moreira on 28/10/26.
// Problem 3: Remove Duplicates from Sorted List (Adapted from LeetCode #83)
//
// Strategy:
//  Single-pass traversal on LinkedList<T>:
//   1. Solution accesses `list.head`, `list.tail`, and `list.count` directly via friend declaration.
//   2. If the list has 0 or 1 element, no duplicates exist.
//   3. Traverse the list with pointer `current` starting at `list.head`.
//   4. If `current->item == current->next->item`:
//      - Save `current->next` to a temporary pointer `nodeToDelete`.
//      - Bypass the duplicate: `current->next = current->next->next`.
//      - If the deleted node was `list.tail`, update `list.tail = current`.
//      - Deallocate `nodeToDelete` with `delete` and decrement `list.count`.
//   5. Otherwise, advance `current = current->next`.
//
// Complexity: O(N) time | O(1) auxiliary space.
//

#include <iostream>
#include <vector>
#include <string>
#include "../include/LinkedList.h"

using namespace std;

class Solution {
public:
    // Removes all duplicate values from an already sorted linked list in-place
    template <typename T>
    void deleteDuplicates(LinkedList<T>& list) {
        using Node = typename LinkedList<T>::Node;

        if (list.head == nullptr || list.head->next == nullptr) {
            return;
        }

        Node* current = list.head;

        while (current != nullptr && current->next != nullptr) {
            if (current->item == current->next->item) {
                Node* nodeToDelete = current->next;
                current->next = current->next->next;

                // Update tail if the removed element was the last one
                if (nodeToDelete == list.tail) {
                    list.tail = current;
                }

                delete nodeToDelete;
                list.count--;
            } else {
                current = current->next;
            }
        }
    }

    // Helper to populate a LinkedList from a std::vector
    template <typename T>
    LinkedList<T> buildList(const vector<T>& items) {
        LinkedList<T> list;
        for (const T& item : items) {
            list.addLast(item);
        }
        return list;
    }
};

// Helper function to print numeric vectors
void printVector(const vector<int>& nums) {
    size_t n = nums.size();
    cout << "[";
    for (size_t i = 0; i < n; i++) {
        cout << nums[i] << (i + 1 < n ? ", " : "");
    }
    cout << "]";
}

// Test runner function matching the standard testing format
void runTest(Solution& solver, int testNum, const string& testName,
             const vector<int>& inputVals, const vector<int>& expectedVals) {
    LinkedList<int> list = solver.buildList(inputVals);
    solver.deleteDuplicates(list);

    LinkedList<int> expectedList = solver.buildList(expectedVals);
    string outputStr = list.toString();
    string expectedStr = expectedList.toString();
    bool passed = (outputStr == expectedStr && list.size() == (int)expectedVals.size());

    cout << "\nTest " << testNum << " Results (" << testName << "):\n";
    cout << "Input:    "; printVector(inputVals); cout << "\n";
    cout << "Expected: " << expectedStr << " | Size = " << expectedVals.size() << "\n";
    cout << "Output:   " << outputStr << " | Size = " << list.size() << "\n";
    cout << "Status:   " << (passed ? "Passed" : "Failed") << "\n";
}

int main() {
    Solution solver;

    // --- Test 1 (LeetCode Example 1) ---
    runTest(solver, 1, "Assignment Example 1 (N = 3)", {1, 1, 2}, {1, 2});

    // --- Test 2 (LeetCode Example 2) ---
    runTest(solver, 2, "Assignment Example 2 (N = 5)", {1, 1, 2, 3, 3}, {1, 2, 3});

    // --- Test 3 (All elements identical) ---
    runTest(solver, 3, "All Elements Identical (N = 5)", {7, 7, 7, 7, 7}, {7});

    // --- Test 4 (Already without duplicates) ---
    runTest(solver, 4, "No Duplicates (N = 4)", {10, 20, 30, 40}, {10, 20, 30, 40});

    // --- Test 5 (Single element list) ---
    runTest(solver, 5, "Single Element List (N = 1)", {42}, {42});

    // --- Test 6 (Empty list) ---
    runTest(solver, 6, "Empty List (N = 0)", {}, {});

    // --- Test 7 (Negative values and duplicates at the tail) ---
    runTest(solver, 7, "Negatives and Tail Duplicates (N = 6)", {-5, -5, -2, 0, 4, 4}, {-5, -2, 0, 4});

    return 0;
}