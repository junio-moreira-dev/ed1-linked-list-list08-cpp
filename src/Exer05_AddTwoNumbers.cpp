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
        Node* p1 = l1.head;
        Node* p2 = l2.head;
        int carry = 0;

        while (p1 != nullptr || p2 != nullptr || carry != 0) {
            int sum = carry;

            if (p1 != nullptr) {
                sum += p1->item;
                p1 = p1->next;
            }

            if (p2 != nullptr) {
                sum += p2->item;
                p2 = p2->next;
            }

            carry = sum / 10;
            result.addLast(static_cast<T>(sum % 10));
        }

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
             const vector<int>& in1, const vector<int>& in2, const vector<int>& expected) {
    LinkedList<int> l1 = solver.buildList(in1);
    LinkedList<int> l2 = solver.buildList(in2);
    LinkedList<int> outputList = solver.addTwoNumbers(l1, l2);

    LinkedList<int> expectedList = solver.buildList(expected);
    string outputStr = outputList.toString();
    string expectedStr = expectedList.toString();
    bool passed = (outputStr == expectedStr && outputList.size() == (int)expected.size());

    cout << "\nTest " << testNum << " Results (" << testName << "):\n";
    cout << "Input L1:  "; printVector(in1); cout << "\n";
    cout << "Input L2:  "; printVector(in2); cout << "\n";
    cout << "Expected:  " << expectedStr << " | Size = " << expected.size() << "\n";
    cout << "Output:    " << outputStr << " | Size = " << outputList.size() << "\n";
    cout << "Status:    " << (passed ? "Passed" : "Failed") << "\n";
}

int main() {
    Solution solver;

    // --- Test 1 (Assignment Example 1: 342 + 465 = 807) ---
    // [2, 4, 3] + [5, 6, 4] => [7, 0, 8]
    runTest(solver, 1, "Assignment Example 1 (Equal Lengths)", {2, 4, 3}, {5, 6, 4}, {7, 0, 8});

    // --- Test 2 (Assignment Example 2: 0 + 0 = 0) ---
    // [0] + [0] => [0]
    runTest(solver, 2, "Assignment Example 2 (Zeros)", {0}, {0}, {0});

    // --- Test 3 (Assignment Example 3: 9999999 + 9999 = 10009998) ---
    // [9, 9, 9, 9, 9, 9, 9] + [9, 9, 9, 9] => [8, 9, 9, 9, 0, 0, 0, 1]
    runTest(solver, 3, "Assignment Example 3 (Carry Cascade)",
            {9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9},
            {8, 9, 9, 9, 0, 0, 0, 1});

    // --- Test 4 (Carry creates an additional node: 5 + 5 = 10) ---
    // [5] + [5] => [0, 1]
    runTest(solver, 4, "Final Carry New Node", {5}, {5}, {0, 1});

    // --- Test 5 (Asymmetric lengths: 1 + 999 = 1000) ---
    // [1] + [9, 9, 9] => [0, 0, 0, 1]
    runTest(solver, 5, "Asymmetric Lists with Multiple Carries", {1}, {9, 9, 9}, {0, 0, 0, 1});

    return 0;
}