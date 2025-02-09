/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    dummy->next = NULL;
    int carry = 0;

     struct ListNode *tail = dummy;

    while (l1 || l2 || carry)
    {
        int sum = carry;

        if (l1 != NULL)
        {
            sum += l1 -> val;
            l1 = l1 -> next;
        }

        if (l2 != NULL)
        {
            sum += l2 -> val;
            l2 = l2 -> next;
        }
        carry = sum/10;
        sum = sum % 10;
        tail -> next = (struct ListNode*)malloc(sizeof(struct ListNode));
        tail = tail -> next;
        tail -> val = sum;
        tail -> next = NULL;
    }


    struct ListNode *result = dummy -> next;
    free(dummy);
    return result;
}
