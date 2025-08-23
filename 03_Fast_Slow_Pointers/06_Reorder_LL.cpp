// https://leetcode.com/problems/reorder-list/description/.  ===> IMP

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode *reverse(ListNode *head) {
        if (!head || !head -> next) {
            return head;
        }
        ListNode *newHead = reverse(head -> next);
        ListNode *front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }
public:
    void reorderList(ListNode* head) {
        if (!head || !head -> next) {
            return;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        // Find Middle Node
        while (fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // Reverse 2nd Half
        ListNode *second = reverse(slow -> next);
        slow -> next = NULL;
        ListNode *first = head;

        while(second) {
            ListNode *nextNode1 = first -> next;
            ListNode *nextNode2 = second -> next;

            first -> next = second;
            second -> next = nextNode1;
            
            first = nextNode1;
            second = nextNode2;
        }
    }
};
// Time -> O(N)
// Space -> O(1)