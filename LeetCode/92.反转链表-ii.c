/*
 * @lc app=leetcode.cn id=92 lang=c
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//我的半成品，函数有返回值，而且和原来的链表似离非离
// struct ListNode *reverseList(struct ListNode *head, struct ListNode *endnext)
// {
//     if (!head || head->next == endnext) //初始就是空和最小子问题情况
//     {
//         return head;
//     }
//     struct ListNode *newhead = reverseList(head->next, endnext);
//     head->next->next = head;
//     head->next = endnext;
//     return newhead;
// }
// struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
// {
//     typedef struct ListNode node;
//     node *newhead = head;
//     int len = right - left;
//     int i;
//     for (i = 2; i < left; i++)
//     {
//         newhead = newhead->next;
//     }
//     node *newheadlast = newhead;
//     newhead = newhead->next;
//     node *newend = NULL;
//     if (newhead)
//     {
//         newend = newhead;
//         for (i = 1; i <= len; i++)
//         {
//             newend = newend->next;
//         }
//         newend = reverseList(newhead, newend->next);
//     }
//     else
//     {
//         newend = NULL;
//         newend = reverseList(newhead, NULL);
//     }
//     newheadlast->next = newend;
//     return head;
// }

struct ListNode *reverseList(struct ListNode *head, struct ListNode *endnext)
//这个函数返回值是链表的新的头指针，参数第一个是头指针，第二个是表尾指向的东西，是空就指向空
{
    if (!head || head->next == endnext) //初始就是空和最小子问题情况
    {
        return head;
    }
    struct ListNode *newhead = reverseList(head->next, endnext);
    head->next->next = head;
    head->next = endnext;
    return newhead;
}
/*
Accepted
44/44 cases passed (0 ms)
Your runtime beats 100 % of c submissions
Your memory usage beats 67.07 % of c submissions (5.7 MB)
*/
struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
    struct ListNode * dummyNode=(struct ListNode *)malloc(sizeof(struct ListNode));
    dummyNode->val=-1;
    dummyNode->next=head;
    struct ListNode * pre=dummyNode;
    for(int i=0;i<left-1;i++)
    {
        pre=pre->next;//到待返转的前一个
    }    
    struct ListNode *rightnode=pre;
    for(int i=0;i<right-left+1;i++)
    {
        rightnode=rightnode->next;
    }
    pre->next=reverseList(pre->next,rightnode->next);
    //return head;错的，万一head也参与到翻转之中，就错了
    return dummyNode->next;
}
// @lc code=end
