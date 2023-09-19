// https://leetcode.cn/problems/add-two-numbers/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
  {
    ListNode* ans = new ListNode();
    ListNode* p=ans;
    int carry=0;
    while(l1||l2||carry)
    {
      int sum = 0;
      if(l1)
        sum+=l1->val;
      if(l2)
        sum+=l2->val;
      sum+=carry;

      if(sum>=10)
      {
        carry=1;
        sum%=10;
      }
      else
        carry=0;

      ListNode* tmp = new ListNode(sum);
      p->next = tmp;
      p=p->next;

      if(l1)
        l1=l1->next;
      if(l2)
        l2=l2->next;
    }
    return ans->next;
  }
};