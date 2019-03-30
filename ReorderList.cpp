#include<iostream>
#include<stack>
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

ListNode* reorderList(ListNode* head){
	if(head == NULL)
		return head;

	ListNode *temp, *temp1;
	int n;
	temp = head;
	n = 0;

	while(temp != NULL){
		n++;
		temp = temp->next;
	}

	n = (n / 2) + 1;
	temp = head;

	for(int i=0; i<n-1; i++)
		temp = temp->next;

	temp1 = temp->next;
	temp->next = NULL;


	ListNode *curr, *prev, *next;
	curr = temp1;
	prev = NULL;

	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	temp1 = prev;
	temp = head;

	while(temp1 != NULL){
		next = temp1->next;
		temp1->next = temp->next;
		temp->next = temp1;

		temp = temp->next->next;
		temp1 = next;
	}

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

	head = reorderList(head);

	display(head);
}