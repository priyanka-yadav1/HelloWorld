#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

struct node* head;

void insert()
{
	int n;
	n=1;
	node *temp;
	cout<<"Enter node data to insert: ";
	cin>>temp->data;
	cout<<"Enter node location to insert: ";
	cin>>n;
	
	
	if(n==1)
	{
		temp->next = head->next;
		head = temp;
		return;
	}
	
	struct node *p;
	p = head;
	int count= 0;
	while(p->next== NULL)
	{
		if(count == n)
		{
			temp->next = p->next;
			p->next = temp;
			return;
			
		}
		count++;
		p=p->next;
	}
	
	
}


void print()
{
	struct node *p;
	p = head;
	
	cout<<"List is:";
	while(p->next == NULL)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}

void delete_node()
{
	int n, count;
	n =1;

	cout<<"Enter node location to delete: \n";
	cin>>n;
	count = n;
	node *p, *temp;
	p = head;
	n--;
	
	if(count == 1)
	{
		temp = head;
		head = head->next;
		delete temp;
		return;
	}
	while(p!=NULL)
	{
		if(n==1)
		{
			temp = p->next;
			p->next = temp->next;
			delete temp;
			break;
		}
		p = p->next;
		n--;
	}
}

int main()
{
	int menu;
	int loop=1;
	head = NULL;
	
	while(loop==1)
	{
		cout<<"Enter menu option:\n1. Insert\n2. Delete\n3. Reverse\n4. Print\n";
		cin>>menu;
		loop = 0;
		
		if(menu ==1 )
		{
			insert();
		}
		else if(menu == 2)
		{
			delete_node();
		}
		else if(menu == 3)
		{
			reverse();
		}
		else if(menu == 4)
		{
			print();
		}
		else{
			cout<<"Enter correct Option.\n";
			continue;
		}
		cout<<"Press 1 to continue.";
		cin>>loop;
	}
	return 0;
}
