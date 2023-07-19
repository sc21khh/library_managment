/**
 * @file library.c
 * @author YOUR NAME
 * @brief Contains functions which set up and run the main library interface.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libraryStructures.h"
#include "library.h"
#include "user.h"
#include "librarian.h"
#include "utility.h"

/**
 * @brief Function to initialise the Library object, reading in the books from file
 * and setting up the User object.
 *
 * @param bookFile The filename of where the books file will be found
 * @param theLibrary The library object which encapsulate the bookList and users.
 */
void initLibrary(char *bookFile, Library *theLibrary)
{

  theLibrary->maxBooks = 100;
  theLibrary->maxBorrowed = 4;

  // TO DO :

  // dynamically allocate the bookList array for storing books
  theLibrary->bookList = malloc(sizeof(Book) * theLibrary->maxBooks);
    if(theLibrary->bookList == NULL) {
        printf("Unable to allocate memory for book list.\n");
        exit(EXIT_FAILURE);
    }
    theLibrary->numBooks = 0;

  
  // open the book file
    FILE* books = fopen(bookFile, "r");
    if (books == NULL) {
        printf("Cannot open book file: %s\n", bookFile);
        free(theLibrary->bookList);
        theLibrary->bookList = NULL;
        exit(EXIT_FAILURE);
    }
  // use the readBooks function to read in the file and add the book records into the bookList array
    theLibrary->numBooks = readBooks(books, theLibrary->bookList);

  // remember to close the file
    fclose(books);

  // Initialise the User data
    theLibrary->theUser.numBorrowed = 0;

  return;
}

/**
 * @brief reads in the books from the provided file to a given bookList.
 * Books are stored in file in a set format:
 * Book author
 * Book title
 * blank line
 * And returns the number of books read.
 *
 * @param books The file pointer where the data will be read from.
 * @param bookList The bookList where the books will be stored.
 * @return int The number of books read from the file.
 */
int readBooks(FILE *books, Book *bookList)
{

  // TO DO:
  int i = 0;
  while (!feof(books) && i < 100) 
  {
    char *pos;

    if (fgets(bookList[i].author, 40, books) != NULL)
    {
      if ((pos=strchr(bookList[i].author, '\n')) != NULL)
        *pos = '\0';
    }

    if (fgets(bookList[i].title, 40, books) != NULL)
    {
      if ((pos=strchr(bookList[i].title, '\n')) != NULL)
        *pos = '\0';
    }
    
    bookList[i].available = 1;

    // Increment book count
    i++;

    char skip[2];
    fgets(skip, 2, books);
  }
  return i;  

  return 0;
}

/**
 * @brief Free any allocated data before exit.
 *
 * @param theLibrary The library object where any allocated memory will be found.
 */
void exitLibrary(Library *theLibrary)
{

  // TO DO:

  // free the allocated lists
  free(theLibrary->bookList);
  
  return;
}

// DO NOT ALTER THIS FUNCTION
/**
 * @brief Sets up and runs the library interface - you should not edit any of this code.
 *
 * @param bookFile The filename of the book
 */
void libraryCLI(char *bookFile)
{
  int libraryOpen = 1;
  int option;

  // create the library structure
  Library *theLibrary = (Library *)malloc(sizeof(Library));

  initLibrary(bookFile, theLibrary);

  while (libraryOpen)
  {
    printf("\n Main menu options\n 1 User login\n 2 Librarian login\n 3 Exit system\n Choice:");
    option = optionChoice();

    if (option == 1)
    {
      printf("\nUser login\n");
      userCLI(theLibrary);
    }
    else if (option == 2)
    {
      printf("\nLibrarian login\n");
      librarianCLI(theLibrary);
    }
    else if (option == 3)
    {
      libraryOpen = 0;
      printf("\nClosing\n");
    }
    else
      printf("\nUnknown option\n");
  }

  exitLibrary(theLibrary);

  // free the library structure
  free(theLibrary);

  return;
}
