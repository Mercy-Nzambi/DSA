#include <stdio.h>
#include <stdlib.h>

struct CycleStartNode {
    int value;
    struct CycleStartNode* next;
};

struct CycleStartNode* detectCycle(struct CycleStartNode* head) {
    struct CycleStartNode* once = head;
    struct CycleStartNode* twice = head;


    while (twice != NULL && twice->next != NULL) {
        once = once->next;
        twice = twice->next->next;


        if (once == twice) {

            once = head;
            while (once != twice) {
                once = once->next;
                twice = twice->next;
            }
            return once;
        }
    }


    return NULL;
}

int main() {

    struct CycleStartNode* head = (struct CycleStartNode*)malloc(sizeof(struct CycleStartNode));
    struct CycleStartNode* node2 = (struct CycleStartNode*)malloc(sizeof(struct CycleStartNode));
    struct CycleStartNode* node3 = (struct CycleStartNode*)malloc(sizeof(struct CycleStartNode));
    struct CycleStartNode* node4 = (struct CycleStartNode*)malloc(sizeof(struct CycleStartNode));

    head->value = 1;
    node2->value = 2;
    node3->value = 3;
    node4->value = 4;

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = head; //can also replace with node2, 3 or 4 and it will still be a cyclic list

    struct CycleStartNode* cycleStart = detectCycle(head);
    if (cycleStart) {
        printf("Cycle starts at node whose value is: %d\n", cycleStart->value);
    } else {
        printf("No cycle in the linked list.\n");
    }


    free(head);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}
