
/*
 *  File:  time.h
 *  Name:
 *  login: 
 *  Date:  25 Aug 07
 *  Mod:
 */

/*  Defines the "Time" data time and the functions that manipulate it 
 *
 *  A "Time" object records the hours and minutes of a time of day
 */

#ifndef TIME_H
#define TIME_H

#include "common.h"


/*  Time data type declaration  */
typedef struct Time {
	int hour;
	int minute;
} Time;

/* Initialization functions   */
void time_Init(Time *t, int hour, int minute);
void time_InitSingle(Time *t, int hrmin);
void time_Clear(Time *t);
void time_Copy(Time *dest, Time *source);

/* Accessor functions  */
int time_GetHour(Time *t);
int time_GetMinute(Time *t);

/* Mutator functions  */
void time_SetHour(Time *t, int hour);
void time_SetMinute(Time *t, int min);

/* Display functions  */
void time_Display(Time *d);

/* Comparison functions  */
Boolean time_Equal(Time *a, Time *b);
Boolean time_NotEqual(Time *a, Time *b);
Boolean time_LessThan(Time *a, Time *b);
Boolean time_GreaterThan(Time *a, Time *b);
Boolean time_LessThanOrEqual(Time *a, Time *b);
Boolean time_GreaterThanOrEqual(Time *a, Time *b);

/* Manipulation functions  */
Time time_Add(Time *a, int minutes);
int time_Difference(Time *a, Time *b);


#endif
