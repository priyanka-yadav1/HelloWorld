#include<bits/stdc++.h>
using namespace std;


template <typename T>
class Container{
private:
struct Node{
	T data;
	Node *next;
};

Node *head ,*tail;
int count;

public:
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
	try{
	if(index>count)
		throw index;
		
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
    catch(int i)
    {
	cout<<"Invalid Index Value\n";
    }
}

template <typename T> 
T Container<T>::removeFirst()
{
	try
	{
	if(head == NULL)
	throw head;
	count--;
	T temp;
	temp = head->data;
	head = head->next;
	return temp;
   }
   catch(Node *p)
   {
   	cout<<"No element exist to remove"<<endl;
   	return 0;
   }
}

template <typename T>
T Container<T>::removeLast()
{
	try
	{
	if(head == NULL)
	throw head;
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
    catch(Node *p)
    {
   	cout<<"No element exist to remove"<<endl;
   	return 0;
    }
}

template <typename T>
T Container<T>::removeAt(int index)
{
	try
	{
	if(head == NULL)
	throw head;

	if(index > count)
	throw index;
	
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
    catch(Node *p)
    {
   	cout<<"No element exist to remove"<<endl;
   	return 0;
    }
    catch(int i)
    {
	cout<<"Invalid Index Value\n";
	return 0;
    }
}

template <typename T>
T Container<T>::at(int index)
{

	try
	{
	if(index > count)
	throw index;

	Node *p ;
	T temp;

	p = head;
	while(index != 1)
	{
		index--;
		p = p->next;
	}
	temp = p->data;
	return temp;
    }
    catch(int i)
    {
	cout<<"Invalid Index Value\n";
	return 0;
    }
	
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
  Container<char> obj1;

   obj1.append('a');
   cout<< "Removed Data is: "<<obj1.removeAt(7)<<endl; 
   obj1.append('f');
   obj1.append('b');
   obj1.prepend('t');
   obj1.print();
   cout<< "Removed Data is: "<<obj1.removeAt(4)<<endl;
   obj1.print();
   obj1.prepend('d');
   obj1.prepend('r');
   cout<< "Data is: "<<obj1.at(30)<<endl;
   obj1.print();
   obj1.insertAt(3,'q');
   obj1.append('w');
   obj1.print();
   cout<< "Removed Data is: "<<obj1.removeAt(7)<<endl;
   obj1.print();
   cout<<"List size is: "<<obj1.size()<<endl;
  
	return 0;
}
