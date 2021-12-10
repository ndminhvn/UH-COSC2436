#include <iostream>
#include <string>
#include "Roster.h"

using namespace std;

Roster::Roster () : allStudents(), cache()
{
}

linkedList* Roster::getAllStudents()
{
    return &allStudents;
}
hashTable* Roster::getCache()
{
    return &cache;
}

// DO NOT MODIFY ANYTHING ABOVE THIS LINE

void Roster::addStudent(const Student& newStudent )
{
   // implement this function
    allStudents.insertLast(newStudent);
    cache.insert(newStudent);
}

Student Roster::getStudent(const int id, bool& fromCache )
{
   // implement this function
    if (cache.check(id) == fromCache) {
        return cache.find(id);
    } else {
        Student student = allStudents.findStudent(id);
        cache.insert(student);
        return student;
    }
}

