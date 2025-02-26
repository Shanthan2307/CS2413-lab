struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* pervious = NULL;

    while (head) {
        struct ListNode* temp = head->next;
        head->next = pervious;
        pervious = head;
        head = temp;
    }

    return pervious;
}
