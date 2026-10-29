//
// Created by Junio Moreira on 28/10/26.
// Problem 2: Palindrome Linked List (Adapted from LeetCode #234)
//
// Strategy:
//  Two Pointers & In-Place Reversal on LinkedList<T>:
//   1. Solution accesses `list.head` directly via friend declaration.
//   2. Find the end of the first half using fast and slow pointers.
//   3. Reverse the second half of the list in-place (O(1) auxiliary space).
//   4. Compare the node values of the first half and the reversed second half.
//   5. Restore the list to its original configuration by re-reversing the second half.
//
// Complexity: O(N) time | O(1) auxiliary space.
//

#include <iostream>
#include <vector>
#include <string>
#include "../include/LinkedList.h"

using namespace std;

class Solution {
private:
    // Reverses a singly-linked list in-place and returns the new head
    template <typename T>
    typename LinkedList<T>::Node* reverseList(typename LinkedList<T>::Node* head) {
        using Node = typename LinkedList<T>::Node;
        Node* prev = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }

        return prev;
    }

public:
    // Determines if the linked list is a palindrome
    template <typename T>
    bool isPalindrome(LinkedList<T>& list) {
        using Node = typename LinkedList<T>::Node;

        if (list.head == nullptr || list.head->next == nullptr) {
            return true;
        }

        // Step 1: Find the end of the first half (slow pointer)
        Node* slow = list.head;
        Node* fast = list.head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        Node* secondHalfStart = reverseList<T>(slow->next);

        // Step 3: Check whether it is a palindrome
        Node* p1 = list.head;
        Node* p2 = secondHalfStart;
        bool palindrome = true;
        while (palindrome && p2 != nullptr) {
            if (p1->item != p2->item) {
                palindrome = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // Step 4: Restore list structure to original state
        slow->next = reverseList<T>(secondHalfStart);

        return palindrome;
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
             const vector<int>& inputVals, bool expected) {
    LinkedList<int> list = solver.buildList(inputVals);
    bool output = solver.isPalindrome(list);
    bool passed = (output == expected);

    cout << "\nTest " << testNum << " Results (" << testName << "):\n";
    cout << "Input:    "; printVector(inputVals); cout << " (as " << list.toString() << ")\n";
    cout << "Expected: " << (expected ? "true" : "false") << "\n";
    cout << "Output:   " << (output ? "true" : "false") << "\n";
    cout << "Status:   " << (passed ? "Passed" : "Failed") << "\n";
}

int main() {
    Solution solver;

    // --- Test 1 (LeetCode Example 1: Even Length Palindrome) ---
    runTest(solver, 1, "Even Length Palindrome (N = 4)", {1, 2, 2, 1}, true);

    // --- Test 2 (LeetCode Example 2: Not a Palindrome) ---
    runTest(solver, 2, "Not a Palindrome (N = 2)", {1, 2}, false);

    // --- Test 3 (Odd Length Palindrome) ---
    runTest(solver, 3, "Odd Length Palindrome (N = 5)", {1, 2, 3, 2, 1}, true);

    // --- Test 4 (Single Element) ---
    runTest(solver, 4, "Single Element List (N = 1)", {99}, true);

    // --- Test 5 (Negative and Duplicate Values Palindrome) ---
    runTest(solver, 5, "Palindromic with Negatives (N = 6)", {-5, 10, 0, 0, 10, -5}, true);

    // --- Test 6 (Almost Palindrome - Mismatch at Extremes) ---
    runTest(solver, 6, "Mismatch at Extremes (N = 4)", {1, 2, 2, 3}, false);

    return 0;
}