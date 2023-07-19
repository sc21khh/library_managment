# Test Plan

You should add your own test cases in here, explaining what you are testing, what data your are going to use, and what you would expect the working system to do. The only things which should cause the program to end are issues with the start-up process (i.e. argument errors, input file errors). In other cases, you should be providing an error message and giving users another chance - your program **should not crash or exit** unless a user selects the 'exit' option.

main() has been started to show you the level of granularity you should be using, but isn't a full list of possible errors- you should add to this, thinking about all potential user or system errors which could happen.

Make sure you run these tests regularly and mark off whether they are passing - it is recommended that you copy this file and date these attempts so you have evidence of doing these regularly.

## main() Tests

| Test Case      | Data To Use | Expected Outcome | Passing? |
| ----------- | ----------- | ----------- | ------------ |
| Valid books file  | ./bin/library books.txt  | Program proceeds with no issues | [ ] |
| Books file does not exist  |  ./bin/library fake.txt  |  Program should exit and alert user | [ ] |
| Books file has no read permissions | chmod -r books.txt <br> ./bin/library books.txt <br> chmod +r books.txt | Program should exit and alert user | [ ] |
| No books file provided | ./bin/library  | Program should give usage message and exit | [ ] |

*There are lots more tests you could include here - try and think of more!*

## Librarian

 | Test Case | Data To Use | Expected Outcome | Passing? |
 | -- | -- | -- | -- |
 |  |  |  | [ ] |

## Library

| Test Case | Data To Use | Expected Outcome | Passing? |
| -- | -- | -- | -- |
| Empty book file | An empty text file | Program should handle gracefully and not crash | [] |
| File contains more books than maximum | A text file containing more than 100 books | Program should only load the first 100 books and ignore the rest | [] |
| User tries to borrow more books than allowed | User attempts to borrow 5 books | The 5th book should not be borrowed, and an error message should be displayed | [] |
| User tries to borrow a book that is not available | User attempts to borrow a book that has already been borrowed | The book should not be borrowed, and an error message should be displayed | [] |
| User tries to return a book they have not borrowed | User attempts to return a book that they have not borrowed | The book should not be returned, and an error message should be displayed | [] |
| User tries to return a book they have borrowed | User attempts to return a book they have borrowed | The book should be returned successfully, and an appropriate message should be displayed | [] |

## User

 | Test Case | Data To Use | Expected Outcome | Passing? |
 | -- | -- | -- | -- |
 |  |  |  | [ ] |

## Anything Else

*If you have more than two or three tests in here related to one part of your system, consider adding another heading for that part.*

 | Test Case | Data To Use | Expected Outcome | Passing? |
 | -- | -- | -- | -- |
 |  |  |  | [ ] |
