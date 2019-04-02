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

ListNode* mergeList(ListNode* head1, ListNode* head2){
	if(head1 == NULL)
		return head2;

	if(head2 == NULL)
		return head1;

	if(head1->val <= head2->val)
		head1->next = mergeList(head1->next, head2);

	else{
		ListNode* temp;
		temp = head2;
		head2 = head2->next;
		temp->next = head1;
		head1 = temp;
		head1->next = mergeList(head1->next, head2);
	}

	return head1;
}

ListNode* sortList(ListNode* head){
	if(head == NULL || head->next == NULL);
		return head;

	ListNode *slow, *fast;
	slow = head;
	fast = head->next;

	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode* next;
	next = slow->next;
	slow->next = NULL;

	return mergeList(sortList(head), sortList(next));
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

	head = sortList(head);

	display(head);
}
