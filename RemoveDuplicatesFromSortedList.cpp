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

ListNode* deleteDuplicates(ListNode* head){
	if(head == NULL || head->next == NULL)
		return head;

	ListNode* temp;
	temp = head;

	while(temp->next != NULL){
		ListNode* temp1;
		temp1 = temp->next;

		if(temp->val == temp1->val){
			temp->next = temp1->next;
			delete temp1;
		}

		else
			temp = temp->next;
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

	head = deleteDuplicates(head);

	Display(head);
}
