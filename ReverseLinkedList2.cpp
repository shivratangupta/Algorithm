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

ListNode* reverseBetween(ListNode* head, int m, int n){
	if(head == NULL || head->next == NULL || m == n)
		return head;

	ListNode *temp, *temp1, *temp2, *temp3;
	temp = head;
	temp1 = head;

	for(int i=0; i<m-2; i++)
		temp = temp->next;

	for(int i=0; i<n-1; i++)
		temp1 = temp1->next;

	if(m == 1)
		temp2 = head;

	else{
		temp2 = temp->next;
		temp->next = NULL;
	}

	temp3 = temp1;
	temp1 = temp1->next;
	temp3->next = NULL;

	ListNode *prev, *curr, *next;
	curr = temp2;
	prev = NULL;

	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	temp2->next = temp1;

	if(m == 1)
		head = prev;

	else
		temp->next = prev;

	return head;
}

int main(){
	ListNode* head;
	head = NULL;

	int m, n, k;
	cin>>k;

	for(int i=0; i<k; i++){
		int num;
		cin>>num;

		head = newListNode(head, num);
	}

	cin>>m;
	cin>>n;

	head = reverseBetween(head, m, n);

	Display(head);
}
