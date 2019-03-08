#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
	int c = 0;
	ListNode* head;
	head = NULL;
	ListNode* temp;

	while(l1 != NULL || l2 != NULL || c != 0){
		int a, b, d, e;

		if(l1 == NULL)
			a = 0;

		else{
			a = l1->val;
			l1 = l1->next;
		}

		if(l2 == NULL){
			b = 0;
		}

		else{
			b = l2->val;
			l2 = l2->next;
		}

		d = a + b + c;
		e = d % 10;
		c = d / 10;

		ListNode* temp1 = new ListNode();
		temp1->val = e;
		temp1->next = NULL;

		if(head == NULL){
			head = temp1;
			temp = head;
		}

		else{
			temp->next = temp1;
			temp = temp->next;
		}
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

ListNode* NewListNode(ListNode* head, int n){
	ListNode* temp = new ListNode();
	temp->val = n;
	temp->next = NULL;

	if(head == NULL)
		head = temp;

	else{
		ListNode* temp1;
		temp1 = head;
		while(temp1->next != NULL){
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}

	return head;
}

int main(){
	ListNode* l1;
	ListNode* l2;
	l1 = NULL;
	l2 = NULL;

	int n1, n2;
	cin>>n1;

	for(int i=0; i<n1; i++){
		int a;
		cin>>a;
		l1 = NewListNode(l1, a);
	}

	cin>>n2;

	for(int i=0; i<n2; i++){
		int a;
		cin>>a;
		l2 = NewListNode(l2, a);
	}

	ListNode* head;

	head = addTwoNumbers(l1, l2);
	Display(head);
}
