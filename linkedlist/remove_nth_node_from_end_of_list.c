/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp = head;
    int length = 0;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    if (length == n) {
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }

    temp = head;
    for (int i = 1; i < length - n; i++) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        struct ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete);
    }

    return head;
}