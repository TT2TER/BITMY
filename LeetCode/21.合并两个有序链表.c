/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start

// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     struct ListNode *next;
// };

//AC未优化
// struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
// {
//     // Node *list1 = l1->head;
//     // Node *list2 = l2->head;
//     // Node temp = {'\0', NULL};

//     struct _List
// {
//     struct ListNode *head;
//     struct ListNode *tail;
// } ;
//     struct _List *ans = (struct _List *)malloc(sizeof(struct _List));
//     ans->head=NULL;
//     ans->tail=NULL;
//     while (!list1 && list2)
//     {
//         ans->head=list2;
//         goto exit;
//     }
//     while (list1 && !list2)
//     {
//         ans->head=list1;
//         goto exit;
//     }
//     while (list1 || list2)
//     {
//         if (!ans->head)
//         {
//             struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
//             p->next=NULL;
//             if (list1->val < list2->val ? 1 : 0)
//             {
//                 // temp = *list1;
//                 *p = *list1;
//                 ans->head = p;
//                 ans->tail = p;
//                 list1 = list1->next;
//             }
//             else
//             {
//                 // temp = *list2;
//                 *p = *list2;
//                 ans->head = p;
//                 ans->tail = p;
//                 list2 = list2->next;
//             }
//         }
//         else
//         {
//             while (list1 || list2)
//             {
//                 struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
//                 p->next=NULL;
//                 if (!list1 && list2)
//                 {
//                     // temp=*list2;
//                     *p = *list2;
//                     ans->tail->next = p;
//                     ans->tail = p;
//                     list2 = list2->next;
//                 }
//                 else if (!list2 && list1)
//                 {
//                     // temp=*list1;
//                     *p = *list1;
//                     ans->tail->next = p;
//                     ans->tail = p;
//                     list1 = list1->next;
//                 }
//                 else
//                 {
//                     if (list1->val < list2->val ? 1 : 0)
//                     {
//                         // temp = *list1;
//                         *p = *list1;
//                         ans->tail->next = p;
//                         ans->tail = p;
//                         list1 = list1->next;
//                     }
//                     else
//                     {
//                         // temp = *list2;
//                         *p = *list2;
//                         ans->tail->next = p;
//                         ans->tail = p;
//                         list2 = list2->next;
//                     }
//                 }
//             }
//         }
//     }
//     exit:
//     return list1= ans->head;
// }
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode dummyhead=NULL;
    struct ListNode pre=NULL;
    while(list1&&list2)
    {
        
    }
}
// @lc code=end
