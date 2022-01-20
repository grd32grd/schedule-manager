#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"

int main(){

  char str[MAX_STR];  //Variables
  int choice = -1;
  char currTerm[MAX_STR] = "NONE SELECTED";
  int courseId = 0;

  CourseArrayType courseCollec;
  ScheduleType currentSch;
  CourseType c;
  CourseType *cc = &c;

  
  initCourses(&courseCollec); //Initalizing both the schedule and course collection
  clearSchedule(&currentSch);
  
  while (choice != 0) { //Prints out options for user to choose from.
    printMenu(currTerm, &choice);

    if (choice == 0) {  //Deallocates the allocated memory & exits the program.
        cleanCourses(&courseCollec);
        break;
    }
    
    switch(choice) {
      case 1:   // Reset current term
        
        printf("Following this format (Fall 2021 = F21), enter a term: ");  //Takes in new term.
        fgets(str, sizeof(str), stdin);
        sscanf(str, "%s", currTerm);

        clearSchedule(&currentSch);   //Clears the schedule.
        
        break;

      case 2:   // Print courses for current term
      
        printCourses(&courseCollec,&currTerm);
        
        break;

      case 3:   // Add course to schedule
      
        printf("Enter a course ID: ");  //Takes in course ID.
        fgets(str, sizeof(str), stdin);
        sscanf(str, "%d", &courseId);
        
        if (findCourse(&courseCollec,courseId,&cc) == C_OK){  //Only adds course to schedule if it can be found in the course.
            addToSchedule(&currentSch,cc);
            printf("\nCourse ID %d has been found. Course added to schedule.\n",courseId);
        } else {
            printf("\nCourse not offered in the %s term.\n",currTerm);
        }
        
        break;

      case 4:   // Print schedule
      
        printSchedule(&currentSch,currTerm);
        
        break;

      case 5:   // Clear schedule
      
        clearSchedule(&currentSch);
        
        break;

      default:
        
        break;

    }
  }


  return 0;
}

/*
  Function:  printMenu
  Purpose:   displays the menu, reads the user's selection, 
             and returns the selection
       in:   the current term
      out:   the user's selection from the menu
   return:   nothing
*/
void printMenu(char *term, int *choice)
{
  int c = -1;
  int numOptions = 5;
  char str[MAX_STR];

  printf("\nMAIN MENU -- CURRENT TERM: %s\n", term);
  printf("  (1) Reset current term\n");
  printf("  (2) Print courses\n");
  printf("  (3) Add to schedule\n");
  printf("  (4) Print schedule\n");
  printf("  (5) Clear schedule\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  fgets(str, sizeof(str), stdin);
  sscanf(str, "%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d", &c);
  }

  *choice = c;
}