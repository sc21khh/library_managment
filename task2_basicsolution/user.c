/**
 * @file user.c
 * @author your name
 * @brief User.c provides a number of utilities for the user of the library, such as being
 * able to view all the books, and being able to borrow or return books.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "libraryStructures.h"
#include "user.h"
#include "utility.h"

/**
 * @brief Lists all books in the bookList which are available to borrow.
 *
 * @param bookList The library bookList.
 * @param numBooks The number of books in bookList
 */
void listAvailableBooks(Book *bookList, int numBooks)
{

  // TO DO :

  // print out available books with format "list number - author - title" on each line
  int i;
  for (i = 0; i < numBooks; i++)
  {
    if (bookList[i].available == 1)
    {
      printf("%d - %s - %s\n", i + 1, bookList[i].author, bookList[i].title);
    }
  }
  return;
}

/**
 * @brief Clears the input buffer by reading and discarding any remaining characters in the buffer.
 *
 * This function is useful for clearing the input buffer after reading input from the user with functions like `scanf`.
 * If there are any remaining characters in the input buffer, they will be read and discarded until a newline character
 * or end-of-file (EOF) is encountered.
 */
void clearInputBuffer()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

/**
 * @brief Allows the user to borrow a book from the library
 *
 * @param theUser The current user object
 * @param bookList The library book list
 * @param numBooks The number of books in bookList
 * @param maxBorrowed The maximum number of books a user can borrow.
 */
void borrowBook(User *theUser, Book *bookList, int numBooks, int maxBorrowed)
{

  // TO DO :
  // request the choice of book
  // borrow the book, update the data structures
  if (theUser->numBorrowed >= maxBorrowed)
  {
    printf("You have reached your limit of borrowed books.\n");
    return;
  }

  int bookIndex;
  printf("Enter the list number of the book you want to borrow: ");
  scanf("%d", &bookIndex);
  clearInputBuffer();
  bookIndex--; // To adjust for zero-based index

  if (bookIndex < 0 || bookIndex >= numBooks || bookList[bookIndex].available != 1)
  {
    printf("Invalid book selection.\n");
    return;
  }

  bookList[bookIndex].available = 0;
  theUser->borrowed[theUser->numBorrowed++] = &bookList[bookIndex];
  printf("You've borrowed the book: %s by %s\n", bookList[bookIndex].title, bookList[bookIndex].author);
  return;
}

/**
 * @brief Lists all the books which the user has borrowed.
 *
 * @param theUser The current user
 * @param bookList The book list
 * @param maxBorrowed The maximum number of books which a user can borrow
 */
void listMyBooks(User *theUser, Book *bookList, int maxBorrowed)
{

  // TO DO :

  // list books in format "number - author - title"
  int i;
  for (i = 0; i < theUser->numBorrowed; i++)
  {
    printf("%d - %s - %s\n", i + 1, theUser->borrowed[i]->author, theUser->borrowed[i]->title);
  }
  return;
}

/**
 * @brief Return a book to the library, making it available for others to borrow.
 *
 * @param theUser The current user
 * @param bookList The list of all books
 * @param numBooks The number of books in bookList
 * @param maxBorrowed The maximum number of books which a user can borrow.
 */
void returnBook(User *theUser, Book *bookList, int numBooks, int maxBorrowed)
{

  // TO DO :
  

  // check that there are borrowed books
  if (theUser->numBorrowed == 0)
  {
    printf("You haven't borrowed any books.\n");
    return;
  }

  // request the choice of book
  int bookIndex;
  printf("Enter the list number of the book you want to return: ");
  scanf("%d", &bookIndex);
  clearInputBuffer();
  bookIndex--; // To adjust for zero-based index

  if (bookIndex < 0 || bookIndex >= theUser->numBorrowed)
  {
    printf("Invalid selection.\n");
    return;
  }

  // return the book and update data structures
  theUser->borrowed[bookIndex]->available = 1;
  printf("You've returned the book: %s by %s\n", theUser->borrowed[bookIndex]->title, theUser->borrowed[bookIndex]->author);
  theUser->borrowed[bookIndex] = theUser->borrowed[theUser->numBorrowed - 1];
  theUser->numBorrowed--;
  return;
}

// DO NOT ALTER THIS FUNCTION
/**
 * @brief This controls the basic UI for the user section of the library. You should not edit it.
 *
 * @param theLibrary The library object.
 */
void userCLI(Library *theLibrary)
{
  int userLoggedIn = 1;
  int option;

  while (userLoggedIn)
  {
    printf("\n User options\n 1 List available books\n 2 Borrow book\n 3 Return book\n 4 Log out\n Choice:");
    option = optionChoice();

    if (option == 1)
    {
      printf("\nList available books:\n");
      listAvailableBooks(theLibrary->bookList, theLibrary->numBooks);
    }
    else if (option == 2)
    {
      printf("\nBorrow book from library:\n");
      listAvailableBooks(theLibrary->bookList, theLibrary->numBooks);
      borrowBook(&(theLibrary->theUser), theLibrary->bookList, theLibrary->numBooks, theLibrary->maxBorrowed);
    }
    else if (option == 3)
    {
      printf("\nReturn book from my list:\n");
      listMyBooks(&(theLibrary->theUser), theLibrary->bookList, theLibrary->maxBorrowed);
      returnBook(&(theLibrary->theUser), theLibrary->bookList, theLibrary->numBooks, theLibrary->maxBorrowed);
    }
    else if (option == 4)
    {
      userLoggedIn = 0;
      printf("\nLogging out\n");
    }
    else
      printf("\nUnknown option\n");
  }
  return;
}
