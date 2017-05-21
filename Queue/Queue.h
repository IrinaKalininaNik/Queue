#ifndef QUEUE_H
#define QUEUE_H
#include "stdio.h"

template <class T>
class Queue
{
private:
	T* que; //указатель на очередь
	int size; //количество элементов в очереди
	int begin; //начало очереди
	int end; //конец очереди
	int element; //элементы
public:
	Queue(int a=1);
	Queue(const Queue&a);
	~Queue();
	void inqueue(const T &a); //добавить элемент в очередь
	T delqueue(); //удалить элемент из очереди
	void print(); //вывод на экран
};

template <class T>
Queue<T>::Queue(int a)
{ 
	size=a;
	begin=0;
	end=0;
	element=0;
	que= new T[size];
	for(int i=0; i<size; i++)
	{ que[i]=0;}
}

template <class T>
Queue<T>::Queue(const Queue&a)
{ 
	size=a.size;
	begin=a.begin;
	end=a.end;
	elemet=a.element;
	que= new T[size];
	for(int i=0; i<size; i++)
	{que[i]-a.que[i];}
}

template <class T>
Queue<T>::~Queue()
{ 
	delete[] que;
}

template <class T>
void Queue<T>::inqueue(const T &a) 
{
	if(element<size)
	{
		que[end]=a;
		end = ++end%size;
	    }
	else
	{ 

		T* que2=new T[size+1];
		for(int i=begin, count=0;count<element;i++,count++)
		{
			que2[i]=que[i];
		}
		begin=0;
		end = element;
		que2[end]=a;
		end = ++end%size;

		delete []que;
		que=que2;
		size++;
	}
	element++;
}

template <class T>
T Queue<T>::delqueue()
{ 
	int a;
	if(element<=0)
	{ 
		return 0;
	}
	else
	{
		a=que[begin];
		begin = ++begin%size;
		element--;
		return a;
	}
}

template <class T>
void Queue<T>::print()
{ printf("'Size': %d \n", size);
  printf("'Begin': %d \n", begin);
  printf("'End': %d \n", end);
  printf("'Element': %d \n", element);
  for(int i=begin, count=0;count<element;i++,count++)
  { printf("'Que': %d \n", que[i]);}
}

#endif
