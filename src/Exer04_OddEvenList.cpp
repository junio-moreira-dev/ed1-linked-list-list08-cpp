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

        if (list.head == nullptr || list.head->next == nullptr || list.head->next->next == nullptr) {
            return;
        }

        Node* odd = list.head;
        Node* even = list.head->next;
        Node* evenHead = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        // Link the end of odd list to the head of even list
        odd->next = evenHead;

        // Update list.tail to maintain consistency with LinkedList class
        if (even != nullptr) {
            list.tail = even;
        } else {
            list.tail = odd;
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
    solver.oddEvenList(list);

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

    // --- Test 1 (Assignment Example 1: N = 5, Odd Size) ---
    // Positions: [1st, 2nd, 3rd, 4th, 5th] -> [1, 2, 3, 4, 5] => [1, 3, 5, 2, 4]
    runTest(solver, 1, "Assignment Example 1 (N = 5)", {1, 2, 3, 4, 5}, {1, 3, 5, 2, 4});

    // --- Test 2 (Assignment Example 2: N = 7) ---
    // [2, 1, 3, 5, 6, 4, 7] => Odds: [2, 3, 6, 7], Evens: [1, 5, 4] => [2, 3, 6, 7, 1, 5, 4]
    runTest(solver, 2, "Assignment Example 2 (N = 7)", {2, 1, 3, 5, 6, 4, 7}, {2, 3, 6, 7, 1, 5, 4});

    // --- Test 3 (Even size list: N = 4) ---
    // [10, 20, 30, 40] => [10, 30, 20, 40]
    runTest(solver, 3, "Even Length List (N = 4)", {10, 20, 30, 40}, {10, 30, 20, 40});

    // --- Test 4 (Small list: N = 2) ---
    runTest(solver, 4, "Two Elements List (N = 2)", {1, 2}, {1, 2});

    // --- Test 5 (Single element list: N = 1) ---
    runTest(solver, 5, "Single Element List (N = 1)", {42}, {42});

    // --- Test 6 (Empty list: N = 0) ---
    runTest(solver, 6, "Empty List (N = 0)", {}, {});

    // --- Test 7 (Negative and duplicate elements) ---
    runTest(solver, 7, "Duplicates and Negatives (N = 6)", {-1, 0, -3, 5, -1, 8}, {-1, -3, -1, 0, 5, 8});

    return 0;
}