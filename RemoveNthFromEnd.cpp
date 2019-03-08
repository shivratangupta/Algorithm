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

ListNode* removeNthFromEnd(ListNode* head, int n){
	if(head == NULL)
		return head;

	int size;
	ListNode* temp;
	temp = head;
	size = 0;

	while(temp != NULL){
		size++;
		temp = temp->next;
	}

	int k;
	k = size - n;

	if(k == 0){
		ListNode* temp1;
		temp1 = head;
		head = head->next;
		delete temp1;
	}

	else{
		temp = head;
		for(int i=0; i<k-1; i++)
			temp = temp->next;

		ListNode* temp1;
		temp1 = temp->next;
		temp->next = temp1->next;
		delete temp1;
	}

	return head;
}

int main(){
	ListNode* head;
	head = NULL;
	int n, k;
	cin>>n;

	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		head = newListNode(head, num);
	}

	cin>>k;

	head = removeNthFromEnd(head, k);

	Display(head);
}