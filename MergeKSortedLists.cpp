#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

struct cmp{
	bool operator()(ListNode* x, ListNode* y){
		return x->val > y->val;
	}
};

ListNode* newListNode(ListNode* head, int num){
	ListNode* temp = new ListNode();
	temp->val = num;
	temp->next = NULL;

	if(head == NULL)
		head = temp;

	else{
		ListNode* temp1;
		temp1= head;

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

ListNode* mergeKLists(vector<ListNode*> &lists){
	priority_queue<ListNode*, vector<ListNode*> , cmp> h;

	ListNode* head;
	ListNode* prev;
	head = NULL;

	for(int i=0; i<lists.size(); i++){
		if(lists[i] != NULL)
			h.push(lists[i]);
	}

	while(!h.empty()){
		ListNode* temp;
		temp = h.top();
		h.pop();

		if(head == NULL){
			head = temp;
			prev = temp;
		}

		else{
			prev->next = temp;
			prev = temp;
		}

		if(temp->next != NULL)
			h.push(temp->next);
	}

	prev->next = NULL;

	return head;
}

int main(){
	int n;
	cin>>n;

	vector<ListNode*> arr;
	for(int i=0; i<n; i++){
		ListNode* l;
		l = NULL;
		int m;
		cin>>m;

		for(int i=0; i<m; i++){
			int num;
			cin>>num;
			l = newListNode(l, num);
		}

		arr.push_back(l);
	}

	ListNode* head;
	head = mergeKLists(arr);

	Display(head);
}
