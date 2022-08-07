
#include<iostream>
using namespace std;

class DNode
{
	public:
		int val;
		DNode* next;
		DNode* pre;
	
	DNode(int data)
	{
		val=data;
		next=NULL;
		pre=NULL;	
	}
};
void insertAtHead(DNode* &head,int val)
{
	DNode *newhead=new DNode(val);
	newhead->next=head;
	if(head!=NULL)
		head->pre=newhead;
	head=newhead;
}
void insertNode(DNode* &head,int val)
{
	if(head==NULL)
	{
		insertAtHead(head,val);
		//head=newNode;
		return;
	}
	DNode* newNode=new DNode(val);
	DNode *ptr=head;
	
	while(ptr->next!=NULL)
		ptr=ptr->next;
		
	ptr->next=newNode;
	newNode->pre=ptr;
		
	
}
void display(DNode* head)
{
	if(head==NULL)
	{
		cout<<"List is Empty..\n";
		return;
	}
	while(head!=NULL)
	{
		cout<<head->val<<"->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}
void deleteAtHead(DNode* &head)
{
	DNode* temp=head;
	head=head->next;
	head->pre=NULL;
	
}
void deleteNode(DNode* &head,int pos)
{
	if(pos==1)
	{
		deleteAtHead(head);
		return;
	}
	if(pos<=0)
	{
		cout<<"Please Enter Valid Position of List Node..\n";
		return;
	}
	DNode* temp=head;
	int count=1;
	while(temp!=NULL && count!=pos)
	{
		temp=temp->next;
		count++;
	}
	if(temp==NULL) return;
	temp->pre->next=temp->next;
	if(temp->next!=NULL)
		temp->next->pre=temp->pre;
	
	delete temp;
}
int main()
{
	cout<<"\nDoubly Linked List...\n";
	DNode *head=NULL;
	insertNode(head,10);
	insertNode(head,20);
	insertNode(head,30);
	insertNode(head,40);
	insertNode(head,50);
	insertAtHead(head,99);
	display(head);
	cout<<"\n\nAfter Deletion on DLink List...\n";
	deleteNode(head,4);
	display(head);
	deleteNode(head,9);
	display(head);
	deleteNode(head,0);
	deleteNode(head,1);
	display(head);
	return 0;
}

/*

//updated Logic  DL
#include<iostream>
using namespace std;
class DNode
{
    public :
        int data;
        DNode *next;
        DNode *pre;
        
        DNode(int val)
        {
            data=val;
            next=NULL;
            pre=NULL;
        }
};


void insertNodeAtHead(DNode* &head,int val)
{
    DNode* newNode=new DNode(val);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    newNode->next=head;
    head->pre=newNode;
    head=newNode;
}


void insertNode(DNode* &head,int val)
{
    if(head==NULL)
    {
        insertNodeAtHead(head,val);
        return;
    }
    DNode* newNode=new DNode(val);
    DNode* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->pre=temp;
}


void insertNodeAt(DNode* &head,int val,int pos)
{
    if(head==NULL || (head!=NULL) && pos==1)
    {
        insertNodeAtHead(head,val);
        return;
    }
    DNode* temp=head;
    int cnt=1;
    while(cnt!=pos-1)
    {
        cnt++;
        if(temp==NULL)
        {
            insertNode(head,val);
            return;
        }
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        insertNode(head,val);
        return;
    }
    DNode* newNode=new DNode(val);
    newNode->next=temp->next;
    temp->next->pre=newNode;
    newNode->pre=temp;
    temp->next=newNode;
}

void deleteAtHead(DNode* &head)
{
    if(head==NULL)
        return;
    head=head->next;
    head->pre=NULL;
    
}
void deleteNode(DNode* &head,int pos)
{
   if(head==NULL)
   {
       cout<<"You can Delete Node. List is Empty\n";
       return;
   }
   if(pos==1)
   {
       deleteAtHead(head);
       return;
   }
   int cnt=1;
   DNode* temp=head;
   while(cnt!=pos)
   {
       if(temp==NULL)
       {
           cout<<"\nPosition Doesn't Exist..\n";
           return;
       }
       temp=temp->next;
       cnt++;
   }
   if(temp==NULL)
   {
       cout<<"\nPosition Doesn't Exist..\n";
       return;
   }
   temp->pre->next=temp->next;
   if(temp->next!=NULL)
        temp->next->pre=temp->pre;
}

void display(DNode* head)
{
    if(head==NULL)
    {
        cout<<"List is Empty\n";
        return;
    }
    cout<<"\nList Elements : NULL->";
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
}
int main()
{
    cout<<"Doubly Link List\n";
    
    DNode* head=NULL;
    deleteNode(head,2);
    insertNodeAt(head,99,8);
    insertNodeAtHead(head,143);
    insertNode(head,10);
    insertNode(head,20);
    insertNode(head,30);
    insertNode(head,40);
    insertNodeAtHead(head,100);
    display(head);
    insertNodeAtHead(head,90);
    insertNodeAtHead(head,80);
    insertNodeAt(head,98,1);
    insertNodeAt(head,97,2);
    insertNodeAt(head,96,4);
    insertNodeAt(head,11,13);
    insertNodeAt(head,1000,1000);
    cout<<"\nBefore Delete: ";
    display(head);
    deleteNode(head,2);
    deleteNode(head,5);
    deleteNode(head,12);
    deleteNode(head,1);
    deleteNode(head,5);
    deleteNode(head,10);
    deleteNode(head,9);
    deleteNode(head,118);
    cout<<"\nAfter Delete: ";
    display(head);
    
    
}
*/
