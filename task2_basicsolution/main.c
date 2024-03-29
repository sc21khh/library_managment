/**
 * @file main.c
 * @author your name
 * @brief The main runs the rest of the program.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libraryStructures.h"
#include "library.h"

/**
 * @brief The main() will accept a command line argument of the filename where the books
 * file should be found, and then run the library program until it is exited by a user.
 *
 * @param argc The number of arguments
 * @param argv The argument array
 * @return int Always returns 0.
 */
int main(int argc, char **argv)
{
    char bookFile[40];

    // TO DO :
    if (argc < 2)
    {
        printf("Please provide a book file name.\n");
        return 1;
    }

    // assign command line value to filename string
    strncpy(bookFile, argv[1], sizeof(bookFile) - 1);

    // DO NOT ALTER
    // start the system
    printf("\nIntialising library system!\n");
    libraryCLI(bookFile);
    printf("\nClosing library system!\n\n");

    return 0;
}
