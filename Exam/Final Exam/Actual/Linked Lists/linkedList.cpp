#include <iostream>
#include "linkedList.h"

using namespace std;

linkedList::linkedList()
{
    first = NULL;
    last = NULL;
    count = 0;
}

void linkedList::insertLast(const Student& newItem)
{
  nodeType *newNode;       //pointer to create the new node
  newNode = new nodeType;  //create the new node
  newNode->info = newItem; //store the new item in the node
  newNode->prev = NULL;    //set the link field of newNode to NULL
  newNode->next = NULL;    //set the link to prev. node to NULL

  if (first == NULL)       //if the list is empty, newNode is both the first and last node
    {
      first = newNode;
      last = newNode;
    }
  else //the list is not empty, insert newNode after last
    {
      last->next = newNode;
      newNode->prev = last;
      last = newNode;
    }

  count++; //increment count
}

int linkedList::getLength() const
{
    return count;
}

void linkedList::printList() const
{
    nodeType *current=first;
    while (current != nullptr ) {
        cout << "Student " << current->info.name << " ID " << current->info.id << endl;
        current = current->next;
    }
}


void linkedList::deleteStudent (nodeType* student)
{
    nodeType *current = first;
    if (current == nullptr) {
        return;
    }
    while (current != nullptr) {
        if (current->info.id == student->info.id && current->info.name == student->info.name) {
            // nodeType *temp = current;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            // delete temp;
            count--;
        }
        current = current->next;
    }
}

void linkedList::removeDuplicates()
{
    nodeType *node1 = first;
    nodeType *node2;
    while (node1 != nullptr && node1->next != nullptr) {
        node2 = node1;
        while (node2->next != nullptr) {
            if (node1->info.id == node2->next->info.id && node1->info.name == node2->next->info.name) {
                node2->next = node2->next->next;
                count--;
            }
            else {
                node2 = node2->next;
            }
        }
        node1 = node1->next;
    }
}