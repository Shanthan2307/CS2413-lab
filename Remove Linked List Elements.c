struct ListNode* removeElements(struct ListNode* head, int val) {
    // Handle cases where head itself needs to be removed
    while (head && head->val == val) {
        head = head->next;
    }

    // Initialize pointers
    struct ListNode* temp = head;
    struct ListNode* prev = NULL;

    while (temp) {
        if (temp->val == val) {
            prev->next = temp->next; // Skip the node with val
        } else {
            prev = temp; // Move prev only when we don’t delete
        }
        temp = temp->next;
    }

    return head;
}
