//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include<stdio.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode *tail = dummy;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int a = (l1 != NULL) ? l1->val : 0;
        int b = (l2 != NULL) ? l2->val : 0;
        int sum = a + b + carry;
        
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;

        tail->next = node;
        tail = node;

        carry = sum / 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;    
    }
    struct ListNode *result = dummy->next;
    free(dummy);
    return result;
}
