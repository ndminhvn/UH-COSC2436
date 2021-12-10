#include "Library.h"
#include <iostream> 

Library::Library()
{
   numBooks = 0;
   firstBook = nullptr;
   lastBook = nullptr;
}

//Copy constructor
Library::Library( Library& other)
{
   //  implement this function
   firstBook = new LibraryBook;
   *firstBook = *(other.firstBook);
   lastBook = new LibraryBook;
   *lastBook = *(other.lastBook);
   numBooks = other.numBooks;
}

int Library::getnumBooks() const
{
   return numBooks;
}

LibraryBook* Library::getFirstBook()
{
   return firstBook;
}
LibraryBook* Library::getLastBook()
{
   return lastBook;
}

// return a pointer to the n'th book in the linked list
LibraryBook* Library::getBook( const int pos )
{
   // implement this function
   LibraryBook* currentBook = firstBook;
   int count = 0;

   while (currentBook != nullptr) {
      if (count == pos) {
         return currentBook;
      }
      count++;
      currentBook = currentBook->next;
   }
   cout << "Book at position " << pos << " is not available." << endl;
   return nullptr;
}

// add a Book to the end of the linked list
void Library::addBook(Book book)
{
   // implement this function
   LibraryBook *newBook = new LibraryBook;
   newBook->book = book;

   if (firstBook == nullptr) {
      firstBook = newBook;
   } else {
      lastBook->next = newBook;
      newBook->prev = lastBook;
   }
   lastBook = newBook;

   numBooks++; // increment
}


// Move a book to the front of the linked list
void Library::moveToFront (LibraryBook *entry)
{
   // implement this function
   entry->prev->next = entry->next;
   entry->next->prev = entry->prev;
   entry->prev = firstBook->prev;
   entry->next = firstBook;
   firstBook = entry;
}

// print all Books
void Library::printAllBooks() const
{
   // implement this function
   LibraryBook *currentBook = firstBook;

   while (currentBook != nullptr) {
      currentBook->book.printBook();
      currentBook = currentBook->next;
   }
}

// print all Books of a single Genre
void Library::printBooksOfOneGenre(string genre)
{
   // implement this function
   LibraryBook *currentBook = firstBook;

   while (currentBook != nullptr) {
      if (currentBook->book.getGenre() == genre) {
         currentBook->book.printBook();
      }
      currentBook = currentBook->next;
   }
}
