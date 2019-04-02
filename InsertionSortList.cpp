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

ListNode* insertionSortList(ListNode* head){
	if(head == NULL)
		return head;

	ListNode *temp, *next, *sorted;
	temp = head;
	sorted = NULL;

	while(temp != NULL){
		next = temp->next;

		if(sorted == NULL || sorted->val >= temp->val){
			temp->next = sorted;
			sorted = temp;
		}

		else{
			ListNode* temp1;
			temp1 = sorted;

			while(temp1->next != NULL && temp1->next->val < temp->val)
				temp1 = temp1->next;

			temp->next = temp1->next;
			temp1->next = temp;
		}

		temp = next;
	}

	head = sorted;

	return head;
}

void display(ListNode* head){
	if(head == NULL)
		return;

	ListNode* temp;
	temp = head;

	while(temp != NULL){
		cout<<temp->val<<"\t";
		temp = temp->next;
	}
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

	head = insertionSortList(head);

	display(head);
}
