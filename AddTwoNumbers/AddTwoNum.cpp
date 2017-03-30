#include <stdlib.h>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	int opt = 0;
	ListNode* head = l2;
	while(l1 != NULL && l2 != NULL) {
		l2->val += opt;
		opt = (l1->val + l2->val) / 10;
		l2->val = (l1->val + l2->val) % 10;
		l1 = l1->next;
		l2 = l2->next;
	}
	if ( l2 == NULL )
		l2 = l1;
	while( true ) {
		if ( opt == 1 && l2 == NULL){
			l2 = new ListNode(opt);
			return head;
		}
		if ( opt == 0 || l2 == NULL)
			return head;
		l2->val += opt;
		opt = l2->val / 10;
		l2->val = l2->val % 10;
		l2 = l2->next;
	}

}
	
