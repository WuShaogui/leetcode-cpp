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

    // �ݹ����
    ListNode* ans = ReverseList(head->next);
    //�õ�ǰ������һ������ next ָ��ָ��ǰ�ڵ�
    head->next->next = head;
    //ͬʱ�õ�ǰ���� next ָ��ָ��NULL ���Ӷ�ʵ�ִ�����β����ʼ�ľֲ���ת
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

    // ����ǰ(��ӡ�ᵼ��������ң���֤ʱ��ע�͵�)
    //while (head != NULL)
    //{
    //    std::cout << head->val << endl;
    //    head = head->next;
    //}


    ListNode* result=ReverseList(head);

    // ���ú�
    while (result!= NULL)
    {
        std::cout << result->val << endl;
        result = result->next;
    }

};