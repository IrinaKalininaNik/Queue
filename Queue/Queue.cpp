#include "Queue.h"
#include <iostream>

using namespace std;
int main()
{  
	Queue<int> q(5);
   q.inqueue(2);
   q.inqueue(2);
   q.inqueue(2);
   q.inqueue(2);
   q.inqueue(2);
   q.inqueue(2);
   q.delqueue();
   q.print();
   
};