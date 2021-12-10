#include <iostream>
#include "Student.h"
#include "hashSet.h"

hashSet::hashSet ( int _tableSize, int _setSize)
{
    tableSize = _tableSize;
    setSize = _setSize;
    students = new Student*[tableSize];
    for ( int i=0; i< tableSize; i++ ) {
        students[i] = new Student[setSize];
    }

    for ( int i=0; i< tableSize; i++ ) {
        for ( int j=0; j < setSize; j++ ) {
            students[i][j].id = EmptyID;
        }
    }
}

hashSet::~hashSet ()
{
    for ( int i=0; i < tableSize; i++ ) {
        delete[] students[i];
    }

    delete[] students;
}

int hashSet::length() const
{
    return tableSize;
}

bool hashSet::insert ( const Student &newItem )
{
    // implement this function
    int bucketIndex = newItem.id % tableSize;

    for (int j = 0; j < setSize; j++) {
        if (students[bucketIndex][j].id == EmptyID) {
            students[bucketIndex][j] = newItem;
            return true;
        }
    }
    return false;
}

Student hashSet::getStudent ( const int id )
{
    // implement this function
    int bucketIndex = id % tableSize;

    Student student;

    for (int j = 0; j < setSize; j++) {
        if (students[bucketIndex][j].id != EmptyID) {
            student = students[bucketIndex][j];
            return student;
        }
    }
    cout << "Could not find student with id " << id << " in hashSet" << endl;
    return student;
}