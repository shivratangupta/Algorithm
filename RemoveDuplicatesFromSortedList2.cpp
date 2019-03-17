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

	ListNode *temp, *temp1, *prev;
	temp = head;
	prev = NULL;

	while(temp != NULL && temp->next != NULL){
		if(temp->val == temp->next->val){
			temp1 = temp->next;

			while(temp1->next != NULL && temp1->next->val == temp1->val)
				temp1 = temp1->next;

			if(prev == NULL){
				temp = temp1->next;
				head = temp;
			}

			else{
				prev->next = temp1->next;
				temp = temp1->next;
			}
		}

		else{
			prev = temp;
			temp = temp->next;
		}
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
