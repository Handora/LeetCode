#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      auto itr1 = l1;
      auto itr2 = l2;
      int leading = 0;

      while (itr1->next && itr2->next) {
	int newval = itr1->val + itr2->val + leading;
	if (newval >= 10) {
	  newval -= 10;
	  leading = 1;
	} else {
	  leading = 0;
	}

	itr1->val = newval;
	itr1 = itr1->next;
	itr2 = itr2->next;
      }

      if (itr1->next == NULL) {
	std::swap(itr1->next, itr2->next);
      }
      
      while (itr1->next) {
	itr1->val += leading;
	if (itr2) {
	  itr1->val += itr2->val;
	  itr2 = itr2->next;
	}

	if (itr1->val > 10) {
	  itr1->val -= 10;
	  leading = 1;
	} else {
	  leading = 0;
	}

	itr1 = itr1->next;
      }

      itr1->val += leading;
      if (itr2) {
	itr1->val += itr2->val;
	itr2 = itr2->next;
      }
      
      if (itr1->val >= 10) {
	itr1->val -= 10;
	leading = 1;
      } else {
	leading = 0;
      }

      if (leading) {
	auto node = new ListNode(1);
	itr1 -> next = node;
      }

      return itr1;
    }
};
