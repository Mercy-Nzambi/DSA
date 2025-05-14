#include <stdio.h>
#include <stdlib.h>

struct reverseNode {
    int val;
    struct reverseNode* next;
};


struct reverseNode* reverseList(struct reverseNode* head) {
    struct reverseNode* prev = NULL;
    struct reverseNode* current = head;
    struct reverseNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


void printList(struct reverseNode* head) {
    struct reverseNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    struct reverseNode* head = (struct reverseNode*)malloc(sizeof(struct reverseNode));
    struct reverseNode* node2 = (struct reverseNode*)malloc(sizeof(struct reverseNode));
    struct reverseNode* node3 = (struct reverseNode*)malloc(sizeof(struct reverseNode));
    struct reverseNode* node4 = (struct reverseNode*)malloc(sizeof(struct reverseNode));

    head->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 4;

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    printf("Original list: ");
    printList(head);

    struct reverseNode* reversedHead = reverseList(head);

    printf("Reversed list: ");
    printList(reversedHead);


    free(head);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}
