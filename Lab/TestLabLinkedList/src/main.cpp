#include <iostream>
#include "linkedList.h"

int main()
{
	linkedList<int> list;
	list.insertLast(20);
	list.insertFirst(10);
	list.print();

	return 0;
}