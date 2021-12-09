/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// struct ListNode {
//       int val;
//       struct ListNode *next;
//   };
//AC 未优化
// bool hasCycle(struct ListNode *head) {
//     typedef struct ListNode node;
//     bool ans=false;
//     if(!head||!head->next)
//     {
//         goto exit;
//     }
//     node *slow=head;
//     node *fast=head;
//     while (1)
//     {
//         if(fast&&fast->next)fast=fast->next->next;
//         else break;
//         slow=slow->next;
//         if(fast==slow)
//         {
//             ans=true;
//             break;
//         }
//     }
//     exit:
//     return ans;
// }
//以上是没有优化过的，主要优化在判断上，fast=head->next,不用再来for循环
bool hasCycle(struct ListNode *head) {
    typedef struct ListNode node;
    if(!head||!head->next)
    {
        return false;
    }
    node *slow=head;
    node *fast=head->next;
    while(fast!=slow)
    {
        if(!fast||!fast->next)
        {
            return false;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
    return true;
}
// @lc code=end

