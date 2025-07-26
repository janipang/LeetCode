#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int *nodesBetweenCriticalPoints(struct ListNode *head, int *returnSize)
{
    *returnSize = 2;
    int *result = (int *)malloc(*returnSize * sizeof(int));
    if (!head || !head->next || !head->next->next)
    {
        printf("break");
        result[0] = -1;
        result[1] = -1;
        return result;
    }
    int curr_point = 1;
    int *critical_points = (int *)malloc(100000 * sizeof(int)); // keep index of critical point
    int critical_amount = 0;
    while (head && head->next && head->next->next)
    {
        printf("round -> %d %d %d", head->val, head->next->val, head->next->next->val);
        if ((head->val > head->next->val && head->next->val < head->next->next->val) || (head->val < head->next->val && head->next->val > head->next->next->val))
        {
            printf(" ---> found %d", head -> next -> val);
            *(critical_points + critical_amount) = curr_point;
            critical_amount += 1;
        }
        curr_point += 1;
        head = head->next;
        printf("\n");
    }
    printf("critical_points: ");
    for (int i = 0; i < critical_amount; i++)
    {
        printf("%d", *(critical_points + i));
    }
    return result;
}

int main()
{
    struct ListNode node1;
    struct ListNode node2;
    struct ListNode node3;
    struct ListNode node4;
    struct ListNode node5;
    struct ListNode node6;
    struct ListNode node7;
    
    node1.val = 5;
    node2.val = 3;
    node3.val = 1;
    node4.val = 2;
    node5.val = 5;
    node6.val = 1;
    node7.val = 2;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = NULL;

    int *returnSize;

    printf("test1: %d\n", nodesBetweenCriticalPoints(&node1, returnSize));
}