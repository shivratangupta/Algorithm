#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

ListNode* newListNode(ListNode* head, int num){
	ListNode* temp = new ListNode();
	temp->val = num;
	temp->next = NULL;

	if(head == NULL)
		head = temp;

	else{
		ListNode* temp1;
		temp1 = head;

		while(temp1->next != NULL)
			temp1 = temp1->next;

		temp1->next = temp;
	}

	return head;
}

ListNode* detectCycle(ListNode* head){
	if(head == NULL)
		return head;

	ListNode *temp, *temp1;
	temp = head;
	temp1 = head;

	while(temp1 != NULL && temp1->next != NULL){
		temp = temp->next;
		temp1 = temp1->next->next;

		if(temp == temp1)
			break;
	}

	if(temp1 == NULL || temp1->next == NULL)
		return NULL;

	temp = head;
	while(temp != temp1){
		temp = temp->next;
		temp1 = temp1->next;
	}

	return temp;
}

int main(){
	ListNode* head;
	head = NULL;

	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		int num;
		cin>>num;

		head = newListNode(head, num);
	}

	head = detectCycle(head);
}