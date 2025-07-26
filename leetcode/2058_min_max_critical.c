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
        result[0] = -1;
        result[1] = -1;
        return result;
    }
    int curr_point = 1;
    int *critical_points = (int *)malloc(100000 * sizeof(int)); // keep index of critical point
    int critical_amount = 0;
    int min_dis = 100000;
    while (head && head->next && head->next->next)
    {
        if ((head->val > head->next->val && head->next->val < head->next->next->val) || (head->val < head->next->val && head->next->val > head->next->next->val))
        {
            *(critical_points + critical_amount) = curr_point;
            critical_amount += 1;
            // re calculate min distance
            if (critical_amount > 1)
            {
                if (curr_point - *(critical_points + critical_amount - 2) < min_dis)
                {
                    min_dis = curr_point - *(critical_points + critical_amount - 2);
                }
            }
        }
        curr_point += 1;
        head = head->next;
    }
    printf("critical_points: ");
    for (int i = 0; i < critical_amount; i++)
    {
        printf("%d", *(critical_points + i));
    }
    printf("\n");

    result[0] = min_dis;
    result[1] = *(critical_points + critical_amount - 1) - *(critical_points);
    printf("result: %d %d\n",result[0],result[1]);
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
    struct ListNode node8;
    struct ListNode node9;

    node1.val = 1;
    node2.val = 3;
    node3.val = 2;
    node4.val = 2;
    node5.val = 3;
    node6.val = 2;
    node7.val = 2;
    node8.val = 2;
    node9.val = 7;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = &node8;
    node8.next = &node9;
    node9.next = NULL;

    int *returnSize;

    printf("test1: %d\n", nodesBetweenCriticalPoints(&node1, returnSize));
}