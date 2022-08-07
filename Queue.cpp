#include<iostream>
#define n 10
using namespace std;
class Queue
{
	public:
		int *arr;
		int front;	 // Delete Elements from Queue...
		int back;	// call it rear also which is used to insert element in Queue
		Queue()
		{
			arr=new int[n];
			front=-1;
			back=-1;
		}
		
		void enqueue(int val)
		{
			if(back==n-1)
			{
				cout<<"Queue is Full...\n";
				return;
			}
			back++;
			arr[back]=val;
			
			if(front==-1)
				front++;			
		}
		
		void display()
		{
			cout<<"Queue Elements: ";
			for(int i=front;i<=back;i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}
		void dequeue()
		{
			if(isEmpty())
				return;
			front++;
		}
		
		bool isEmpty()
		{
			if(front==-1 || front>back)
				return true;
			return false;
		}	
};

int main()
{
	cout<<"Queue Implementation...\n\n";
	Queue e;
	e.enqueue(10);
	e.enqueue(20);
	e.enqueue(30);
	e.enqueue(40);	
	e.enqueue(50);
	e.display();
	e.enqueue(60);
	e.enqueue(70);
	e.enqueue(80);
	e.display();
	cout<<"\nAfter Dequeue operation: \n";
	e.dequeue();
	e.dequeue();
	e.display();
	return 0;
}
