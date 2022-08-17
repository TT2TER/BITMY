/*
 * @lc app=leetcode.cn id=876 lang=c
 *
 * [876] 链表的中间结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
Accepted
36/36 cases passed (0 ms)
Your runtime beats 100 % of c submissions
Your memory usage beats 97.15 % of c submissions (5.6 MB)
*/
struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *rabbit = head;
    struct ListNode *turtle = head;
    while (rabbit)
    {
        
        if (rabbit->next)
        {
            turtle = turtle->next;
            rabbit = rabbit->next->next;
        }
        else break;
    }
    return turtle;
}
// @lc code=end
