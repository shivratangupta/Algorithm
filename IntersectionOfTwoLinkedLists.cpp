#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

ListNode* getIntersectionNode(ListNode* head1, ListNode* head2){
	if(head1 == NULL || head2 == NULL)
		return NULL;

	if(head1 == head2)
		return head1;

	int n1, n2;
	ListNode* temp;

	n1 = 0;
	temp = head1;
	while(temp != NULL){
		n1++;
		temp = temp->next;
	}

	n2 = 0;
	temp = head2;
	while(temp != NULL){
		n2++;
		temp = temp->next;
	}

	ListNode* temp1;
	temp = head1;
	temp1 = head2;

	if(n1 > n2){
		for(int i=0; i<n1-n2; i++)
			temp = temp->next;
	}

	else{
		for(int i=0; i<n2-n1; i++)
			temp1 = temp1->next;
	}

	while(temp != NULL){
		if(temp == temp1)
			return temp;

		temp = temp->next;
		temp1 = temp1->next;
	}

	return NULL;
}