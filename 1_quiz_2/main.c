#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a linked list node
struct CycleNode {
    int val;
    struct CycleNode* next;
};

// Function to detect a cycle in the linked list
bool hasCycle(struct CycleNode* head) {
    if (head == NULL || head->next == NULL) {
        return false; // If the list is empty or has only one node, no cycle.
    }

    struct CycleNode* once = head;
    struct CycleNode* twice = head;

    while (twice != NULL && twice->next != NULL) {
        once = once->next;        // Move slow pointer by one step
        twice = twice->next->next;  // Move fast pointer by two steps

        if (once == twice) {
            return true; // A cycle is detected
        }
    }

    return false; // No cycle in the list
}

int main() {
    // Create nodes
    struct CycleNode* node1 = (struct CycleNode*)malloc(sizeof(struct CycleNode));
    struct CycleNode* node2 = (struct CycleNode*)malloc(sizeof(struct CycleNode));
    struct CycleNode* node3 = (struct CycleNode*)malloc(sizeof(struct CycleNode));

    // Initialize nodes
    node1->val = 1; node1->next = node2;
    node2->val = 2; node2->next = node3;
    node3->val = 3; node3->next = node1; // Creates a cycle

    // Check for a cycle
    if (hasCycle(node1)) {
        printf("Cycle detected in the linked list.\n");
    } else {
        printf("No cycle in the linked list.\n");
    }

    // Free memory (to avoid memory leaks in non-cyclic cases)
    free(node1);
    free(node2);
    free(node3);

    return 0;
}



