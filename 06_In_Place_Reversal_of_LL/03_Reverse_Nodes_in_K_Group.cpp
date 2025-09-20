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
private:
    int lengthK(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }
    ListNode* reverseGroup(ListNode* head, int k, int length) {
        if (length < k) {
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int cnt = 0;
        while (curr != NULL && cnt < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        if (next != NULL) {
            head->next = reverseGroup(next, k, length - k);
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = lengthK(head);
        return reverseGroup(head, k, length);
    }
};
// Time -> O(N)
// Space -> O(N)