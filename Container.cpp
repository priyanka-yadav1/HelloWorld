#include<bits/stdc++.h>
using namespace std;


template <typename T>
class Container{
public:
struct Node{
	T data;
	Node *next;
};

Node *head ,*tail;
int count;

Container();


void append(T data);
void prepend(T data);
void insertAt(int index, T data); 
T removeFirst(); 
T removeLast();
T removeAt(int index); 
T at(int index); 
int size(); 
bool isEmpty(); 
void print();
};

template <typename T>
Container<T>::Container()
{
	head= NULL;
	tail= NULL;
	count = 0;
}

template <typename T>
void Container<T>::append(T data)
{
	count++;
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(count == 1)
	{
		head = temp;
		tail = temp;
		
		return;
	}
	tail->next = temp;
	tail = temp;
}

template <typename T>
void Container<T>::prepend(T data)
{
		count++;
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(count == 1)
	{
		head = temp;
		tail = temp;
		return;
	}
	
	temp->next = head;
	head = temp;

}

template <typename T>
void Container<T>::insertAt(int index, T data)
{
	count++;
	if(index>count)
	{
		cout<<"Invalid location\n";
		return;
	}
	 Node *temp = new Node();
     temp->data= data;
     temp->next = NULL;
     if(count == 1)
     {
     	head = temp;
     	tail = temp;
     	return;
	 }
	if(index == count)
	{
		tail->next = temp;
		tail = temp;
		return;
	}
 Node *p;
 p = head;
 index--;
 while(index != 1 && p != NULL)
 {
 	index--;
 	p = p->next;
 }
 

 temp->next = p->next;
 p->next = temp;
}

template <typename T> 
T Container<T>::removeFirst()
{
	if(head == NULL)
	return NULL;
	count--;
	T temp;
	temp = head->data;
	head = head->next;
	return temp;
}

template <typename T>
T Container<T>::removeLast()
{
	if(head == NULL)
	return NULL;
	count--;
	T temp;
	Node *p;
	p = head;
	while(p->next != tail)
	{
		p = p->next;
	}
	
	p->next = NULL;
	temp  = tail->data;
	tail = p;
	if(count == 0)
	head = NULL;
	return temp;
}

template <typename T>
T Container<T>::removeAt(int index)
{
	if(head == NULL)
	return NULL;

	if(index > count)
	{
		cout<<"Invalid Data\n";
		return NULL;
	}
	count--;
	
	T temp;
	Node *p;
	p = head;
	
	
	if(index == 1)
	{
		temp = head->data;
		head = head->next;
		return temp;
	}
	index--;
	while(p->next != NULL && index != 1)
	{
		index--;
		p = p->next;
	}
	if(p->next == tail)
	{
	temp  = tail->data;
	p->next = NULL;
	tail = p;	
	}
    else 
    {
     temp = p->data;
     p->next = p->next->next;
	}
	if(count == 0)
	head = NULL;
	return temp;
}

template <typename T>
T Container<T>::at(int index)
{
	Node *p ;
	T temp;
	if(index > count)
	{
		cout<<"Invalid Location\n";
		return NULL;
	}
	p = head;
	while(index != 1)
	{
		index--;
		p = p->next;
	}
	temp = p->data;
	return temp;
}

template <typename T>
int Container<T>:: size()
{
	return count;
}
template <typename T>
bool Container<T>::isEmpty()
{
	if(count <= 0)
	return true;
	return false;
}


template <typename T>
void Container<T>::print()
{ 
	
	Node *p;
	p = head;
	cout<<"List is: ";
	while(p!= NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}
int main()
{
  Container<int> obj1;
 
   obj1.append(6);
   obj1.append(45);
   obj1.append(12);
   obj1.prepend(33);
   obj1.print();
   cout<< "Removed Data is: "<<obj1.removeAt(4)<<endl;
   obj1.print();
   obj1.prepend(78);
   obj1.prepend(8);
   cout<< "Data is: "<<obj1.at(3)<<endl;
   obj1.print();
   obj1.insertAt(3,56);
   obj1.append(23);
   obj1.print();
   cout<< "Removed Data is: "<<obj1.removeAt(7)<<endl;
   obj1.print();
   cout<<"List size is: "obj1.size()<<endl;
  
	return 0;
}
