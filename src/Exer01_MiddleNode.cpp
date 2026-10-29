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
        using NodeT = typename LinkedList<T>::Node;

        NodeT* slow = list.head;
        NodeT* fast = list.head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Helper to generate a sublist starting at the middle node reusing LinkedList::toString()
    template <typename T>
    LinkedList<T> getMiddleSublist(const LinkedList<T>& list) {
        using NodeT = typename LinkedList<T>::Node;
        LinkedList<T> sublist;
        NodeT* mid = findMiddleNode(list);

        while (mid != nullptr) {
            sublist.addLast(mid->item);
            mid = mid->next;
        }

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
    LinkedList<int> expectedList = solver.buildList(expectedVals);
    LinkedList<int> outputList = solver.getMiddleSublist(list);

    string expectedStr = expectedList.toString();
    string outputStr = outputList.toString();
    bool passed = (expectedStr == outputStr);

    cout << "\nTest " << testNum << " Results (" << testName << "):\n";
    cout << "Input:    "; printVector(inputVals); cout << "\n";
    cout << "Expected: " << expectedStr << "\n";
    cout << "Output:   " << outputStr << "\n";
    cout << "Status:   " << (passed ? "Passed" : "Failed") << "\n";
}

int main() {
    Solution solver;

    // --- Test 1 (LeetCode Example 1: Odd Length) ---
    runTest(solver, 1, "Odd Length List (N = 5)", {1, 2, 3, 4, 5}, {3, 4, 5});

    // --- Test 2 (LeetCode Example 2: Even Length) ---
    runTest(solver, 2, "Even Length List (N = 6)", {1, 2, 3, 4, 5, 6}, {4, 5, 6});

    // --- Test 3 (Single Element) ---
    runTest(solver, 3, "Single Element List (N = 1)", {42}, {42});

    // --- Test 4 (Two Elements) ---
    runTest(solver, 4, "Two Elements List (N = 2)", {10, 20}, {20});

    // --- Test 5 (Negative and Duplicate Values) ---
    runTest(solver, 5, "Duplicates and Negatives (N = 7)", {-3, 0, 0, 5, 5, 8, 12}, {5, 5, 8, 12});

    return 0;
}