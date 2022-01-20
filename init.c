#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"

/*
  Function:  initCourses
  Purpose:   initializes the primary course collection
   in-out:   the primary course collection
   return:   C_OK for success, C_NOK for failure
*/
int initCourses(CourseArrayType *courses)
{
  initCourseArray(courses);

  CourseType *c;

  initCourse(6017, "F21", "COMP 2401", 'A', "Nussbaum", C_MON_WED, 13, 0, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(6022, "F21", "COMP 2401", 'B', "Laurendeau", C_MON_WED, 11, 30, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(6008, "F21", "COMP 2401", 'C', "Laurendeau", C_MON_WED, 11, 30, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(6011, "F21", "COMP 2401", 'D', "Maqsood", C_MON_WED, 18, 0, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(6014, "F21", "COMP 2402", 'A', "Shaikhet", C_TUE_THU, 16, 0, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(6003, "F21", "COMP 2402", 'B', "Shaikhet", C_MON_WED, 13, 0, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  } 
  initCourse(6031, "F21", "COMP 2404", 'B', "Hill", C_TUE_THU, 11, 30, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(6028, "F21", "COMP 2406", 'A', "Shaikhet", C_MON_WED, 16, 0, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(6012, "F21", "COMP 2406", 'B', "Shaikhet", C_TUE_THU, 13, 0, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(6043, "F21", "COMP 2804", 'A', "Hill", C_MON_WED, 8, 30, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  } 
  initCourse(6036, "F21", "COMP 2804", 'B', "Hill", C_TUE_THU, 8, 30, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }

  initCourse(7096, "W22", "COMP 2401", 'B', "Lanthier", C_WED_FRI, 8, 30, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(7065, "W22", "COMP 2402", 'A', "Sharp", C_MON_WED, 16, 0, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(7082, "W22", "COMP 2402", 'B', "Sharp", C_WED_FRI, 14, 30, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  } 
  initCourse(7061, "W22", "COMP 2404", 'A', "Hill", C_TUE_THU, 10, 0, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(7077, "W22", "COMP 2404", 'B', "Laurendeau", C_MON_WED, 11, 30, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(7053, "W22", "COMP 2404", 'C', "Laurendeau", C_WED_FRI, 8, 30, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(7089, "W22", "COMP 2406", 'A', "Maqsood", C_WED_FRI, 13, 0, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(7041, "W22", "COMP 2406", 'B', "Maqsood", C_MON_WED, 10, 0, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(7058, "W22", "COMP 2804", 'A', "Morin", C_TUE_THU, 16, 0, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  }
  initCourse(7063, "W22", "COMP 2804", 'B', "Smid", C_TUE_THU, 8, 30, &c);
  if (addCourse(courses, c) == C_NOK){
      return C_NOK;
  } 

  return C_OK;
}

/*
    Function:               initCourse
    Purpose:                initializes the course given
    param newCourse:        the course given, out
    return:                 nothing
*/
void initCourse(int id, char *term, char *code, char sect, char *instr,
                DeliveryDaysType delDays, int hours, int mins, CourseType **newCourse)
{
	CourseType* ptr;
	ptr = malloc(sizeof(CourseType));
	ptr->id = id;
	strcpy(ptr->term,term);
	strcpy(ptr->code,code);
	ptr->section =sect;
	strcpy(ptr->instructor,instr);
	ptr->delDays = delDays;
	ptr->startTime.hour = hours;
	ptr->startTime.mins = mins;
	
	*newCourse = ptr;
}