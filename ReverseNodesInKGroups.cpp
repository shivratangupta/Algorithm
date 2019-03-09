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

ListNode* reverseKGroups(ListNode* head, int k){
	if(head == NULL)
		return head;

	int n;
	ListNode* temp;
	temp = head;
	n = 0;

	while(temp != 0){
		n++;
		temp = temp->next;
	}

	if(k > n)
		return head;

	int m;
	m = n / k;
	ListNode *curr, *prev, *next, *prev2;
	prev = NULL;
	curr = head;
	temp = head;

	for(int i=0; i<m; i++){
		int j;
		j = 0;

		while(j < k){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			j++;
		}

		if(head == temp)
			head = prev;

		else
			prev2->next = prev;

		prev2 = temp;
		temp = curr;
	}

	prev2->next = curr;

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
	head = reverseKGroups(head, k);	

	Display(head);
}
