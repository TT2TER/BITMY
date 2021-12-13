/*
 * @lc app=leetcode.cn id=142 lang=c
 *
 * [142] 环形链表 II
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
16/16 cases passed (0 ms)
Your runtime beats 100 % of c submissions
Your memory usage beats 40.21 % of c submissions (7 MB)
*/
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *rabbit=head;
    struct ListNode *turtle=head;
    while(rabbit)
    {
        if(rabbit->next)
        {
            turtle=turtle->next;
            rabbit=rabbit->next->next;
        }
        else return NULL;
        if(rabbit==turtle)
        {
            rabbit=head;
            while(rabbit!=turtle)//括号内不能用!rabbit==turtle,!优先级高
            {
                rabbit=rabbit->next;
                turtle=turtle->next;
            }
            return rabbit;
        }
    }
    return NULL;
}
// @lc code=end

