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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
	if(l1 == NULL && l2 == NULL)
		return l1;

	else if(l1 == NULL)
		return l2;

	else if(l2 == NULL)
		return l1;

	else if(l1->val <= l2->val)
		l1->next = mergeTwoLists(l1->next, l2);

	else{
		ListNode* temp;
		temp = l2;
		l2 = l2->next;
		temp->next = l1;
		l1 = temp;
		l1->next = mergeTwoLists(l1->next, l2);
	}

	return l1;
}

int main(){
	ListNode* l1;
	ListNode* l2;
	l1 = NULL;
	l2 = NULL;

	int m, n;

	cin>>m;
	for(int i=0; i<m; i++){
		int num;
		cin>>num;
		l1 = newListNode(l1, num);
	}

	cin>>n;
	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		l2 = newListNode(l2, num);
	}

	ListNode* head;
	head = mergeTwoLists(l1, l2);

	Display(head);
}
