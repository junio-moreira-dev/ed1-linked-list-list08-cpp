//
// Created by Junio Moreira on 28/10/26.
// Problem 1: Middle of the Linked List (Adapted from LeetCode #876)
//
// Strategy:
//  Two Pointers (Fast and Slow / Tortoise and Hare) on LinkedList<T>:
//   1. Solution accesses `list.head` directly via friend declaration.
//   2. Initialize pointers `slow` and `fast` pointing to `list.head`.
//   3. Advance `slow` by 1 step and `fast` by 2 steps while `fast != nullptr` and `fast->next != nullptr`.
//   4. When the loop finishes, `slow` points directly to the middle node (or second middle for even sizes).
//   5. Create a view sublist starting at `slow` and reuse `LinkedList<T>::toString()` for verification.
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
    // Finds and returns a pointer to the middle node of the list
    template <typename T>
    typename LinkedList<T>::Node* findMiddleNode(const LinkedList<T>& list) {
        using Node = typename LinkedList<T>::Node;

        // TODO:
        // 1. Initialize two pointers, slow and fast, both pointing to list.head.
        // 2. Loop while fast != nullptr and fast->next != nullptr.
        // 3. Move slow forward by 1 step (slow = slow->next).
        // 4. Move fast forward by 2 steps (fast = fast->next->next).
        // 5. When the loop terminates, return slow (the middle node).

        return nullptr;
    }

    // Helper to generate a sublist starting at the middle node reusing LinkedList::toString()
    template <typename T>
    LinkedList<T> getMiddleSublist(const LinkedList<T>& list) {
        using Node = typename LinkedList<T>::Node;
        LinkedList<T> sublist;

        // TODO:
        // 1. Retrieve the middle node pointer using findMiddleNode(list).
        // 2. Traverse the list from this middle node until reaching nullptr.
        // 3. In each iteration, append the current item to 'sublist' using addLast().
        // 4. Return the populated 'sublist'.

        return sublist;
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

    // Test Case 1: Odd length list (LeetCode Example 1)
    {
        cout << "--- Test Case 1: Odd Length List (N = 5) ---\n";
        LinkedList<int> list = solver.buildList({1, 2, 3, 4, 5});
        cout << "Original List: " << list.toString() << "\n";

        // TODO: Extract the middle sublist using solver.getMiddleSublist(list) and print result (Expected: [3, 4, 5])

    }

    // Test Case 2: Even length list (LeetCode Example 2)
    {
        cout << "\n--- Test Case 2: Even Length List (N = 6) ---\n";
        LinkedList<int> list = solver.buildList({1, 2, 3, 4, 5, 6});
        cout << "Original List: " << list.toString() << "\n";

        // TODO: Extract the middle sublist using solver.getMiddleSublist(list) and print result (Expected: [4, 5, 6])

    }

    // Test Case 3: Single element list
    {
        cout << "\n--- Test Case 3: Single Element List (N = 1) ---\n";
        LinkedList<int> list = solver.buildList({42});
        cout << "Original List: " << list.toString() << "\n";

        // TODO: Extract the middle sublist using solver.getMiddleSublist(list) and print result (Expected: [42])

    }

    // Test Case 4: Two elements list
    {
        cout << "\n--- Test Case 4: Two Elements List (N = 2) ---\n";
        LinkedList<int> list = solver.buildList({10, 20});
        cout << "Original List: " << list.toString() << "\n";

        // TODO: Extract the middle sublist using solver.getMiddleSublist(list) and print result (Expected: [20])

    }

    // Test Case 5: Negative and duplicate values
    {
        cout << "\n--- Test Case 5: Duplicates and Negatives (N = 7) ---\n";
        LinkedList<int> list = solver.buildList({-3, 0, 0, 5, 5, 8, 12});
        cout << "Original List: " << list.toString() << "\n";

        // TODO: Extract the middle sublist using solver.getMiddleSublist(list) and print result (Expected: [5, 5, 8, 12])

    }

    return 0;
}