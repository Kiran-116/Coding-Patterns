// https://leetcode.com/problems/palindrome-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Brute -> Traverse and Put it on the Stack and in the second traversal compare the element with the top of the stack

// Optimal -> Reverse the 2nd Half:
class Solution {
private:
    ListNode *reverse(ListNode *head) {
        if (!head || !head -> next) {
            return head;
        }

        ListNode *newHead = reverse(head->next);
        ListNode *front = head->next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode *newHead = reverse(slow -> next);
        ListNode *first = head;
        ListNode *second = newHead;

        while (second != NULL) {
            if (first->val != second->val) {
                
                return false;
            }
            first = first -> next;
            second = second -> next;
        }

        reverse(newHead);
        return true;
    }
};
// Time -> O(2N)
// Space -> O(1)