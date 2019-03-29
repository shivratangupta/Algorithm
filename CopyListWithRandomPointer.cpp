#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode* random;
};

Node* copyRandomList(ListNode* head){
	if(head == NULL)
		return head;

	ListNode* temp;
	temp = head;

	while(temp != NULL){
		ListNode* temp1 = new ListNode();
		temp1->val = temp->val;
		temp1->next = temp->next;
		temp1->random = NULL;
		temp->next = temp1;
		temp = temp->next->next;
	}

	temp = head;

	while(temp != NULL){
		temp->next->random = temp->random->next;
		temp = temp->next->next;
	}

	ListNode* copy = new ListNode();
	copy->val = 0;
	copy->next = NULL;
	copy->random = NULL;

	ListNode* temp1;
	temp = head;
	temp1 = copy;

	while(temp != NULL){
		temp1->next = temp->next;
		temp->next = temp->next->next;
		temp = temp->next;
		temp1 = temp1->next;
	}

	return copy->next;
}