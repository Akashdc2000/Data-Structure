#include<iostream>
#define n 100
using namespace std;

class Stack
{
	public:
		int *arr;
		int top;
		Stack()
		{
			arr=new int[n];
			top=-1;
		}
		void push(int val)
		{
			if(top==n-1)
			{
				cout<<"Stack is Full...\n";
				return;
			}
			top++;
			arr[top]=val;
		}
		void display()
		{
			if(isEmpty())
				return;
			for(int i=0;i<=top;i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}
		void pop()
		{
			if(isEmpty())
			{
				cout<<"Stack is Empty...\n";
				cout<<"You can pop elements from stack...\n";
				return;
			}
			top--;
		}
		bool isEmpty()
		{
			return top==-1;
		}
};


int main()
{
	cout<<"Stack Implemention\n";
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	s.push(70);
	cout<<"Stack Elements: ";
	s.display();
	s.pop();
	cout<<"Stack Elements: ";
	s.display();
	s.pop();
	cout<<"Stack Elements: ";
	s.display();
	s.pop();
	s.push(98);
	s.push(58);
	cout<<"Stack Elements: ";
	s.display();
	return 0;
}
