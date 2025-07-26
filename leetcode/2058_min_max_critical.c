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
    result[0] = -1;
    result[1] = -1;
    if (!head || !head->next || !head->next->next) return result;
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

    if (critical_amount < 2) return result;
    result[0] = min_dis;
    result[1] = *(critical_points + critical_amount - 1) - *(critical_points);
    return result;
}

int main()
{
    struct ListNode node1;
    struct ListNode node2;
    struct ListNode node3;

    node1.val = 3;
    node2.val = 1;
    node3.val = 2;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    int *returnSize;

    nodesBetweenCriticalPoints(&node1, returnSize);
}