//
// Created by lamarzhang on 2020/4/19.
//

#ifndef TEST_C___SOLUTION21_H
#define TEST_C___SOLUTION21_H

#include <MacTypes.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x, long i) : val(x), next(NULL) {}
};


class Solution21 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode(0, NULL);
        ListNode * current = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current -> next = l1;
                l1 = l1 -> next;
            } else {
                current -> next = l2;
                l2 = l2 -> next;
            }
            current = current -> next;
        }
        current -> next = l1 != NULL ? l1 : l2;
        return head -> next;
    }
};


#endif //TEST_C___SOLUTION21_H
