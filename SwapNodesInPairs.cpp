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

void Display(ListNode* head){
	ListNode* temp;
	temp = head;

	while(temp != NULL){
		cout<<temp->val<<"\t";
		temp = temp->next;
	}
}

ListNode* swapPairs(ListNode* head){
	if(head == NULL || head->next == NULL)
		return head;

	ListNode *temp, *temp1, *temp2;
	temp = head;
	temp1 = temp->next;
	temp->next = temp1->next;
	temp1->next = temp;
	head = temp1;

	temp1 = temp1->next->next;
	while(temp1 != NULL && temp1->next != NULL){
		temp2 = temp1->next;
		temp1->next = temp2->next;
		temp2->next = temp1;
		temp->next = temp2;

		temp = temp1;
		temp1 = temp1->next;
	}

	return head;
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

	head = swapPairs(head);

	Display(head);
}
