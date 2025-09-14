#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute -> Using Stack => O(2N), O(N)
// Better -> Recursion => O(N), O(N) -> (Recusive Stack space)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }

        ListNode *newHead = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return newHead;
    }
};
// Time -> O(N)
// Space -> O(N)

// Brute -> Using Stack => O(2N), O(N)
// Better -> Recursion => O(N), O(N) -> (Recusive Stack space)
// Optimal -> Iterative:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr) {
            ListNode *temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
// Time -> O(N)
// Space -> O(1)