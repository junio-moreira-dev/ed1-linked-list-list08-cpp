//
// Created by Junio Moreira on 28/10/26.
// Problem 5: Add Two Numbers (Adapted from LeetCode #2)
//
// Strategy:
//  Digit-by-digit addition with carry simulation on LinkedList<T>:
//   1. Solution accesses `l1.head` and `l2.head` directly via friend declaration.
//   2. Initialize pointers `p1 = l1.head`, `p2 = l2.head`, and `carry = 0`.
//   3. Loop while `p1 != nullptr`, `p2 != nullptr`, or `carry != 0`:
//      - Accumulate `sum = carry`.
//      - If `p1` is valid, add `p1->item` and advance `p1 = p1->next`.
//      - If `p2` is valid, add `p2->item` and advance `p2 = p2->next`.
//      - Compute new carry: `carry = sum / 10`.
//      - Append the single-digit result `sum % 10` using `result.addLast()`.
//   4. Return the constructed result LinkedList containing the sum in reverse order.
//
// Complexity: O(max(N, M)) time | O(max(N, M)) auxiliary space for the output list.
//

#include <iostream>
#include <vector>
#include <string>
#include "../include/LinkedList.h"

using namespace std;

class Solution {
public:
    // Adds two numbers represented by linked lists with digits stored in reverse order
    template <typename T>
    LinkedList<T> addTwoNumbers(const LinkedList<T>& l1, const LinkedList<T>& l2) {
        using Node = typename LinkedList<T>::Node;

        LinkedList<T> result;

        // TODO:
        // 1. Initialize pointers `p1 = l1.head`, `p2 = l2.head`, and integer `carry = 0`.
        // 2. Loop while `p1 != nullptr`, `p2 != nullptr`, or `carry != 0`:
        //    a. Initialize `sum = carry`.
        //    b. If `p1 != nullptr`: add `p1->item` to `sum` and advance `p1 = p1->next`.
        //    c. If `p2 != nullptr`: add `p2->item` to `sum` and advance `p2 = p2->next`.
        //    d. Update carry: `carry = sum / 10`.
        //    e. Append the calculated digit `sum % 10` to `result` using `result.addLast()`.
        // 3. Return the constructed `result` list.

        return result;
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

    // Test Case 1: Equal lengths (LeetCode Example 1: 342 + 465 = 807)
    {
        cout << "--- Test Case 1: Assignment Example 1 (Equal Lengths) ---\n";
        LinkedList<int> l1 = solver.buildList({2, 4, 3});
        LinkedList<int> l2 = solver.buildList({5, 6, 4});
        cout << "List 1: " << l1.toString() << "\n";
        cout << "List 2: " << l2.toString() << "\n";

        // TODO: Sum lists using solver.addTwoNumbers(l1, l2) and print result (Expected: [7, 0, 8], Size: 3)

    }

    // Test Case 2: Zeros (LeetCode Example 2: 0 + 0 = 0)
    {
        cout << "\n--- Test Case 2: Assignment Example 2 (Zeros) ---\n";
        LinkedList<int> l1 = solver.buildList({0});
        LinkedList<int> l2 = solver.buildList({0});
        cout << "List 1: " << l1.toString() << "\n";
        cout << "List 2: " << l2.toString() << "\n";

        // TODO: Sum lists using solver.addTwoNumbers(l1, l2) and print result (Expected: [0], Size: 1)

    }

    // Test Case 3: Carry cascade (LeetCode Example 3: 9999999 + 9999 = 10009998)
    {
        cout << "\n--- Test Case 3: Assignment Example 3 (Carry Cascade) ---\n";
        LinkedList<int> l1 = solver.buildList({9, 9, 9, 9, 9, 9, 9});
        LinkedList<int> l2 = solver.buildList({9, 9, 9, 9});
        cout << "List 1: " << l1.toString() << "\n";
        cout << "List 2: " << l2.toString() << "\n";

        // TODO: Sum lists using solver.addTwoNumbers(l1, l2) and print result (Expected: [8, 9, 9, 9, 0, 0, 0, 1], Size: 8)

    }

    // Test Case 4: Final carry creates an additional node (5 + 5 = 10)
    {
        cout << "\n--- Test Case 4: Final Carry New Node ---\n";
        LinkedList<int> l1 = solver.buildList({5});
        LinkedList<int> l2 = solver.buildList({5});
        cout << "List 1: " << l1.toString() << "\n";
        cout << "List 2: " << l2.toString() << "\n";

        // TODO: Sum lists using solver.addTwoNumbers(l1, l2) and print result (Expected: [0, 1], Size: 2)

    }

    // Test Case 5: Asymmetric lengths (1 + 999 = 1000)
    {
        cout << "\n--- Test Case 5: Asymmetric Lists with Multiple Carries ---\n";
        LinkedList<int> l1 = solver.buildList({1});
        LinkedList<int> l2 = solver.buildList({9, 9, 9});
        cout << "List 1: " << l1.toString() << "\n";
        cout << "List 2: " << l2.toString() << "\n";

        // TODO: Sum lists using solver.addTwoNumbers(l1, l2) and print result (Expected: [0, 0, 0, 1], Size: 4)

    }

    return 0;
}