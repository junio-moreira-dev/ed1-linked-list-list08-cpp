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

        // TODO:
        // 1. Initialize two pointers: prev = nullptr and current = head.
        // 2. Loop while current != nullptr.
        // 3. Store current->next in a temporary pointer nextTemp.
        // 4. Reverse current node's link: current->next = prev.
        // 5. Shift prev to current, and current to nextTemp.
        // 6. Return prev (the new head of the reversed sublist).

        return nullptr;
    }

public:
    // Determines if the linked list is a palindrome
    template <typename T>
    bool isPalindrome(LinkedList<T>& list) {
        using Node = typename LinkedList<T>::Node;

        // Base cases: an empty list or a single node list is trivially a palindrome
        if (list.head == nullptr || list.head->next == nullptr) {
            return true;
        }

        // TODO:
        // Step 1: Locate the end of the first half using fast and slow pointers.
        //         - Initialize slow and fast pointers to list.head.
        //         - Advance while fast->next != nullptr && fast->next->next != nullptr.
        // Step 2: Reverse the second half starting at slow->next using reverseList<T>().
        // Step 3: Compare node items between the first half (list.head) and the reversed second half.
        // Step 4: Restore the original list structure by reversing the second half back.
        // Step 5: Return true if all paired items matched, or false otherwise.

        return false;
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

    // Test Case 1: Even length palindrome (LeetCode Example 1)
    {
        cout << "--- Test Case 1: Even Length Palindrome (N = 4) ---\n";
        LinkedList<int> list = solver.buildList({1, 2, 2, 1});
        cout << "Original List: " << list.toString() << "\n";

        // TODO: Check if 'list' is a palindrome using solver.isPalindrome(list) and print result (Expected: true)

    }

    // Test Case 2: Not a palindrome (LeetCode Example 2)
    {
        cout << "\n--- Test Case 2: Not a Palindrome (N = 2) ---\n";
        LinkedList<int> list = solver.buildList({1, 2});
        cout << "Original List: " << list.toString() << "\n";

        // TODO: Check if 'list' is a palindrome using solver.isPalindrome(list) and print result (Expected: false)

    }

    // Test Case 3: Odd length palindrome
    {
        cout << "\n--- Test Case 3: Odd Length Palindrome (N = 5) ---\n";
        LinkedList<int> list = solver.buildList({1, 2, 3, 2, 1});
        cout << "Original List: " << list.toString() << "\n";

        // TODO: Check if 'list' is a palindrome using solver.isPalindrome(list) and print result (Expected: true)

    }

    // Test Case 4: Single element list
    {
        cout << "\n--- Test Case 4: Single Element List (N = 1) ---\n";
        LinkedList<int> list = solver.buildList({99});
        cout << "Original List: " << list.toString() << "\n";

        // TODO: Check if 'list' is a palindrome using solver.isPalindrome(list) and print result (Expected: true)

    }

    // Test Case 5: Palindromic list with negative and duplicate values
    {
        cout << "\n--- Test Case 5: Palindromic with Negatives (N = 6) ---\n";
        LinkedList<int> list = solver.buildList({-5, 10, 0, 0, 10, -5});
        cout << "Original List: " << list.toString() << "\n";

        // TODO: Check if 'list' is a palindrome using solver.isPalindrome(list) and print result (Expected: true)

    }

    // Test Case 6: Almost a palindrome (mismatch at extremes)
    {
        cout << "\n--- Test Case 6: Mismatch at Extremes (N = 4) ---\n";
        LinkedList<int> list = solver.buildList({1, 2, 2, 3});
        cout << "Original List: " << list.toString() << "\n";

        // TODO: Check if 'list' is a palindrome using solver.isPalindrome(list) and print result (Expected: false)

    }

    return 0;
}