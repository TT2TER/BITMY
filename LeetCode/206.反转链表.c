/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//迭代算法，双指针
/*
Accepted
28/28 cases passed (4 ms)
Your runtime beats 65.49 % of c submissions
Your memory usage beats 97.39 % of c submissions (6.1 MB)
*/
// struct ListNode* reverseList(struct ListNode* head){
// typedef struct ListNode node;
// node *past=NULL;//注意这里的null就是表尾，这样向后挪很好
// node *curr=head;
// while(curr)//->左侧判断，同时换到最后一个元素，操作完全相同*想好!加不加
// {
//     node *next=curr->next;
//     curr->next=past;
//     past=curr;
//     curr=next;
// }
// return past;//返回curr的时候curr已经是NULL了，past才是表头
// }

//递归算法
/*
Accepted
28/28 cases passed (0 ms)
Your runtime beats 100 % of c submissions
Your memory usage beats 9.96 % of c submissions (6.5 MB)
*/
struct ListNode *reverseList(struct ListNode *head)
{
    if (!head || !head->next)//初始就是空和最小子问题情况
    {
        return head;
    }
    struct ListNode *newhead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

//野鸡迭代，少一个指针
/*
Accepted
28/28 cases passed (4 ms)
Your runtime beats 65.49 % of c submissions
Your memory usage beats 92.5 % of c submissions (6.1 MB)
*/
// struct ListNode *reverseList(struct ListNode *head)
// {
//     typedef struct ListNode node;
//     node *curr = head;
//     while (head&&head->next) //->左侧判断，同时换到最后一个元素，操作完全相同*想好!加不加&&结束判断
//     {
//         node *next = head->next;
//         head->next=next->next;
//         next->next=curr;
//         curr=next;
//     }
//     return curr; 
// }
// @lc code=end
