#include<iostream>
using namespace std;
class Node
{
	public:
		int val;
		Node* next;
		
		Node(int data)
		{
			val=data;
			next=NULL;
		}
};

void insertNode(Node* &head,int val)
{
	Node* newNode=new Node(val);
	if(head==NULL)
	{
		head=newNode;
		return;
	}
	Node* ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=newNode;		
}

void display(Node* head)
{
	while(head!=NULL)
	{
		cout<<head->val<<"->";
		head=head->next;
	}
	cout<<"NULL\n";
}
void insertAtHead(Node* &head,int val)
{
	Node* newHead=new Node(val);
	newHead->next=head;
	head=newHead;
}

void deleteNode(Node* &head,int key)
{
	if(head==NULL)
	{
		cout<<"List is Empty\n";
		return;
	}
	
	Node* ptr=head;
	while(ptr->next->val!=key)
	{
		ptr=ptr->next;
	}
	Node *temp=ptr->next;
	ptr->next=ptr->next->next;
	delete temp;
}
void HeadDelete(Node* &head)//delete head node
{
	Node* temp=head;
	head=head->next;
	delete temp;
}
bool searchNode(Node* head,int key)
{
	while(head!=NULL)
	{
		if(head->val==key)
			return true;
		head=head->next;
	}
	return false;
}
void reverse(Node* &head)
{
	if(head==NULL)
		return;
	Node *pre,*curr,*Next;	//this is Next pointer not our Node Next..
	pre=NULL;
	curr=head;
	
	while(curr!=NULL)
	{
		Next=curr->next;
		curr->next=pre;
		pre=curr;
		curr=Next;
	}
	head=pre;
}
int main()
{
	Node* head=NULL;
	insertNode(head,10);
	insertNode(head,20);
	insertNode(head,30);
	insertNode(head,40);
	insertNode(head,50);
	insertNode(head,60);
	insertAtHead(head,100);
	cout<<endl<<"Before Delete\n";
	display(head);
	cout<<endl;
	cout<<endl<<"After Delete\n";
	deleteNode(head,20);
	HeadDelete(head);
	display(head);
	
	cout<<"Node is Present or Not: ";
	if(searchNode(head,50)) 
		cout<<"Yes";
	else 
		cout<<"NO";
	cout<<endl;
	cout<<"Reverse Linked List\n";
	reverse(head);
	display(head);
	cout<<endl;
	return 0;
}
