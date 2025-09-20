#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp = head;
        int count = 1;
        ListNode *l, *r, *prev = NULL, *next = NULL;
        while (count < left) {
            count++;
            prev = temp;
            temp = temp -> next;
        }

        l = temp;
        while (count < right) {
            temp = temp -> next;
            count++;
        }

        r = temp;
        if (temp -> next) {
            next = temp -> next;
        }
        if (prev != NULL) {
            prev -> next = r;
        }
        else {
            head = r;
        }

        temp = l;
        while (temp != next) {
            ListNode *curr = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = curr;
        }

        l -> next = next;
        return head;
    }
};
// Time -> O(N)
// Space -> O(N)