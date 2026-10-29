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

        // Base cases: if the list has 0 or 1 element, no duplicates can exist
        if (list.head == nullptr || list.head->next == nullptr) {
            return;
        }

        // TODO:
        // 1. Initialize a pointer `current` pointing to `list.head`.
        // 2. Loop while `current != nullptr` and `current->next != nullptr`.
        // 3. If `current->item == current->next->item`:
        //    a. Store `current->next` in a temporary pointer `nodeToDelete`.
        //    b. Bypass the duplicate: set `current->next = current->next->next`.
        //    c. If `nodeToDelete == list.tail`, update `list.tail = current`.
        //    d. Free memory explicitly using `delete nodeToDelete`.
        //    e. Decrement `list.count--`.
        // 4. Otherwise (values are different):
        //    a. Advance `current = current->next`.
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

int main() {
    Solution solver;

    // Test Case 1: Simple duplicate removal (LeetCode Example 1)
    {
        cout << "--- Test Case 1: Assignment Example 1 (N = 3) ---\n";
        LinkedList<int> list = solver.buildList({1, 1, 2});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Remove duplicates using solver.deleteDuplicates(list) and print result (Expected: [1, 2], Size: 2)

    }

    // Test Case 2: Multiple duplicates throughout the list (LeetCode Example 2)
    {
        cout << "\n--- Test Case 2: Assignment Example 2 (N = 5) ---\n";
        LinkedList<int> list = solver.buildList({1, 1, 2, 3, 3});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Remove duplicates using solver.deleteDuplicates(list) and print result (Expected: [1, 2, 3], Size: 3)

    }

    // Test Case 3: All elements identical
    {
        cout << "\n--- Test Case 3: All Elements Identical (N = 5) ---\n";
        LinkedList<int> list = solver.buildList({7, 7, 7, 7, 7});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Remove duplicates using solver.deleteDuplicates(list) and print result (Expected: [7], Size: 1)

    }

    // Test Case 4: Already without duplicates
    {
        cout << "\n--- Test Case 4: No Duplicates (N = 4) ---\n";
        LinkedList<int> list = solver.buildList({10, 20, 30, 40});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Remove duplicates using solver.deleteDuplicates(list) and print result (Expected: [10, 20, 30, 40], Size: 4)

    }

    // Test Case 5: Single element list
    {
        cout << "\n--- Test Case 5: Single Element List (N = 1) ---\n";
        LinkedList<int> list = solver.buildList({42});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Remove duplicates using solver.deleteDuplicates(list) and print result (Expected: [42], Size: 1)

    }

    // Test Case 6: Empty list
    {
        cout << "\n--- Test Case 6: Empty List (N = 0) ---\n";
        LinkedList<int> list = solver.buildList({});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Remove duplicates using solver.deleteDuplicates(list) and print result (Expected: [], Size: 0)

    }

    // Test Case 7: Negative values and duplicates at the tail
    {
        cout << "\n--- Test Case 7: Negatives and Tail Duplicates (N = 6) ---\n";
        LinkedList<int> list = solver.buildList({-5, -5, -2, 0, 4, 4});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Remove duplicates using solver.deleteDuplicates(list) and print result (Expected: [-5, -2, 0, 4], Size: 4)

    }

    return 0;
}