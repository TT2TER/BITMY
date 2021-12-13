/*
 * @lc app=leetcode.cn id=143 lang=c
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//找中，拆分，倒转，合并
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
        else
            break;
    }
    return turtle;
}
struct ListNode *Listreverse(struct ListNode *head)
{
    if (head || head->next)
    {
        return head;
    }
    struct ListNode newhead = Listreverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
void reorderList(struct ListNode *head)
{
    struct ListNode *beforelist2 = middleNode(head);
    struct ListNode *list1 = head;
    struct ListNode *list2=beforelist2->next;
    list2=Listreverse(list2);
    struct ListNode *ans=(struct ListNode *)malloc(struct ListNode);
    ans=list1;
    while (list1!=beforelist2)
    {
        
    }
}
// @lc code=end
