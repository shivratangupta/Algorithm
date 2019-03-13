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

ListNode* rotateRight(ListNode* head, int k){
	if(head == NULL)
		return head;

	int n;
	n = 0;

	ListNode* temp;
	temp = head;
	while(temp != NULL){
		n++;
		temp = temp->next;
	}

	if(k == n)
		return head;

	if(k > n)
		k %= n;

	temp = head;

	for(int i=0; i<n-k-1; i++)
		temp = temp->next;

	ListNode* temp1;
	temp1 = temp->next;
	temp->next = NULL;

	temp = temp1;

	while(temp1->next != NULL)
		temp1 = temp1->next;

	temp1->next = head;
	head = temp;

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

	head = rotateRight(head, k);

	Display(head);
}
