#pragma once
#include <iostream>

using  namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* ReverseList(ListNode* head) {
    // write code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // 递归调用
    ListNode* ans = ReverseList(head->next);
    //让当前结点的下一个结点的 next 指针指向当前节点
    head->next->next = head;
    //同时让当前结点的 next 指针指向NULL ，从而实现从链表尾部开始的局部反转
    head->next = NULL;

    return ans;
};


void Run_ReverseList()
{
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    head->next = second;
    second->next = third;

    // 调用前(打印会导致链表错乱，验证时需注释掉)
    //while (head != NULL)
    //{
    //    std::cout << head->val << endl;
    //    head = head->next;
    //}


    ListNode* result=ReverseList(head);

    // 调用后
    while (result!= NULL)
    {
        std::cout << result->val << endl;
        result = result->next;
    }

};