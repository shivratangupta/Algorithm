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

ListNode* partition(ListNode* head, int x){
	ListNode* small = new ListNode();
	small->val = 0;
	small->next = NULL;

	ListNode* large = new ListNode();
	large->val = 0;
	large->next = NULL;

	ListNode *small1, *large1, *temp;
	temp = head;
	small1 = small;
	large1 = large;

	while(temp != NULL){
		if(temp->val < x){
			small1->next = temp;
			small1 = small1->next;
		}

		else{
			large1->next = temp;
			large1 = large1->next;
		}

		temp = temp->next;
	}

	large1->next = NULL;
	small1->next = large->next;

	return small->next;
}

int main(){
	ListNode* head;
	head = NULL;

	int n, x;
	cin>>n;

	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		
		head = newListNode(head, num);
	}

	cin>>x;
	head = partition(head, x);

	Display(head);
}