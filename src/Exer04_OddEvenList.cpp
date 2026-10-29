//
// Created by Junio Moreira on 28/10/26.
// Problem 4: Odd Even Linked List (Adapted from LeetCode #328)
//
// Strategy:
//  Two Pointers In-Place Partitioning on LinkedList<T>:
//   1. Solution accesses `list.head` and `list.tail` directly via friend declaration.
//   2. If the list has fewer than 3 elements (0, 1, or 2), the order remains unchanged.
//   3. Separate nodes into two sub-chains based on 1-indexed positions:
//      - 'odd' pointer walks through odd positions (1st, 3rd, 5th, ...).
//      - 'even' pointer walks through even positions (2nd, 4th, 6th, ...).
//   4. Save the head of the even chain: `evenHead = list.head->next`.
//   5. In a loop, bypass adjacent nodes:
//      - `odd->next = even->next`
//      - advance `odd = odd->next`
//      - `even->next = odd->next`
//      - advance `even = even->next`
//   6. Connect the end of the odd chain to the start of the even chain: `odd->next = evenHead`.
//   7. Update `list.tail` to the last valid node (either `even` or `odd`, depending on parity).
//
// Complexity: O(N) time | O(1) auxiliary space (strict in-place pointer rearrangement).
//

#include <iostream>
#include <vector>
#include <string>
#include "../include/LinkedList.h"

using namespace std;

class Solution {
public:
    // Groups odd-positioned nodes followed by even-positioned nodes in-place
    template <typename T>
    void oddEvenList(LinkedList<T>& list) {
        using Node = typename LinkedList<T>::Node;

        // Base case: lists with fewer than 3 nodes are already partitioned
        if (list.head == nullptr || list.head->next == nullptr || list.head->next->next == nullptr) {
            return;
        }

        // TODO:
        // 1. Initialize pointers:
        //    - 'odd' pointing to list.head (1st node).
        //    - 'even' pointing to list.head->next (2nd node).
        //    - 'evenHead' pointing to even (to reconnect the sublists later).
        // 2. Loop while `even != nullptr` and `even->next != nullptr`:
        //    a. Bypass even node: odd->next = even->next.
        //    b. Advance odd pointer: odd = odd->next.
        //    c. Bypass next odd node: even->next = odd->next.
        //    d. Advance even pointer: even = even->next.
        // 3. Connect the end of the odd chain to the start of the even chain:
        //    odd->next = evenHead.
        // 4. Update `list.tail` for internal consistency:
        //    - Set `list.tail = even` if even != nullptr, otherwise `list.tail = odd`.
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

    // Test Case 1: Odd size list (LeetCode Example 1: N = 5)
    {
        cout << "--- Test Case 1: Assignment Example 1 (N = 5) ---\n";
        LinkedList<int> list = solver.buildList({1, 2, 3, 4, 5});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Rearrange nodes using solver.oddEvenList(list) and print result (Expected: [1, 3, 5, 2, 4], Size: 5)

    }

    // Test Case 2: Assignment Example 2 (N = 7)
    {
        cout << "\n--- Test Case 2: Assignment Example 2 (N = 7) ---\n";
        LinkedList<int> list = solver.buildList({2, 1, 3, 5, 6, 4, 7});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Rearrange nodes using solver.oddEvenList(list) and print result (Expected: [2, 3, 6, 7, 1, 5, 4], Size: 7)

    }

    // Test Case 3: Even size list (N = 4)
    {
        cout << "\n--- Test Case 3: Even Length List (N = 4) ---\n";
        LinkedList<int> list = solver.buildList({10, 20, 30, 40});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Rearrange nodes using solver.oddEvenList(list) and print result (Expected: [10, 30, 20, 40], Size: 4)

    }

    // Test Case 4: Two elements list (N = 2)
    {
        cout << "\n--- Test Case 4: Two Elements List (N = 2) ---\n";
        LinkedList<int> list = solver.buildList({1, 2});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Rearrange nodes using solver.oddEvenList(list) and print result (Expected: [1, 2], Size: 2)

    }

    // Test Case 5: Single element list (N = 1)
    {
        cout << "\n--- Test Case 5: Single Element List (N = 1) ---\n";
        LinkedList<int> list = solver.buildList({42});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Rearrange nodes using solver.oddEvenList(list) and print result (Expected: [42], Size: 1)

    }

    // Test Case 6: Empty list (N = 0)
    {
        cout << "\n--- Test Case 6: Empty List (N = 0) ---\n";
        LinkedList<int> list = solver.buildList({});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Rearrange nodes using solver.oddEvenList(list) and print result (Expected: [], Size: 0)

    }

    // Test Case 7: Duplicates and negative elements (N = 6)
    {
        cout << "\n--- Test Case 7: Duplicates and Negatives (N = 6) ---\n";
        LinkedList<int> list = solver.buildList({-1, 0, -3, 5, -1, 8});
        cout << "Before: " << list.toString() << "\n";

        // TODO: Rearrange nodes using solver.oddEvenList(list) and print result (Expected: [-1, -3, -1, 0, 5, 8], Size: 6)

    }

    return 0;
}