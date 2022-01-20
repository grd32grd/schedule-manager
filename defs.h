#ifndef DEFS_H
#define DEFS_H


/* Constant definitions */

#define C_TRUE     1
#define C_FALSE    0

#define C_OK       0
#define C_NOK     -1

#define NUM_DAYS   5
#define NUM_SLOTS  6

#define MAX_STR   32
#define MAX_BUFF  64
#define MAX_ARR  128


/* Data type definitions */

typedef enum { C_MON_WED, C_TUE_THU, C_WED_FRI
} DeliveryDaysType;


typedef struct {
  int hour;
  int mins;
} TimeType;

typedef struct {
  int  id;
  char term[MAX_STR];
  char code[MAX_STR];
  char section;
  char instructor[MAX_STR];
  DeliveryDaysType delDays;
  TimeType         startTime;
} CourseType;

typedef struct {
  CourseType *elements[MAX_ARR];
  int        size;
} CourseArrayType;

typedef struct {
  CourseType* courses[NUM_DAYS][NUM_SLOTS];
} ScheduleType;


/* Forward references for functions */

void printMenu(char *term, int *choice);

int  initCourses(CourseArrayType *courses);
void initCourse(int id, char *term, char *code, char sect, char *instr, 
                DeliveryDaysType delDays, int hours, int mins, CourseType **newCourse);

void initCourseArray(CourseArrayType *arr);
int  addCourse(CourseArrayType *arr, CourseType *c);
int  findCourse(CourseArrayType *arr, int id, CourseType **c);

int  addToSchedule(ScheduleType *sched, CourseType *c);
void printSchedule(ScheduleType *sched, char *term);
void clearSchedule(ScheduleType *sched);
int  computeDaysFromDel(DeliveryDaysType dd, int *d1, int *d2);
int  computeTimeFromSlot(int slot, int *hrs, int *mins);
int  computeSlotFromTime(int hrs, int mins, int *slot);

void printCourses(CourseArrayType *arr, char *term);
void cleanCourses(CourseArrayType *arr);
void convertDelDays(DeliveryDaysType dd, char *ddStr);

#endif