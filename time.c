
/*
 *  File:  time.c
 *  Name:
 *  login: 
 *  Date:  25 Aug 07
 *  Mod:
 */

/*  Implementation of Time data type operations
 */


#include <stdio.h>
#include "time.h"
#include "common.h"

/*
#define DEBUG
*/

/* Initialization functions   */
void time_Init(Time *t, int hour, int minute)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Init\n");
	#endif

	time_SetHour(t, hour);
	time_SetMinute(t, minute);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Init\n");
	#endif
}

void time_InitSingle(Time *t, int hrmin)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_InitSingle\n");
	#endif

	time_SetHour(t, hrmin/100);
	time_SetMinute(t, hrmin%100);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_InitSingle\n");
	#endif
}

void time_Clear(Time *t)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Clear\n");
	#endif

	time_SetHour(t, 0);
	time_SetMinute(t, 0);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Clear\n");
	#endif
}

void time_Copy(Time *dest, Time *source)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Copy\n");
	#endif

        *source = *dest;

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Copy\n");
	#endif
}

/* Accessor functions  */
int time_GetHour(Time *t)
{
	#ifdef DEBUG
	fprintf(stderr, "\tExecute time_GetHour\n");
	#endif

	return t->hour;
}

int time_GetMinute(Time *t)
{
	#ifdef DEBUG
	fprintf(stderr, "\tExecute time_GetMinute\n");
	#endif

	return t->minute;
}

/* Mutator functions  */
void time_SetHour(Time *t, int hour)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_SetHour\n");
	#endif

	t->hour = hour;

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_SetHour\n");
	#endif
}

void time_SetMinute(Time *t, int min)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_SetMinute\n");
	#endif

	t->minute = min;

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_SetMinute\n");
	#endif
}

/* Display functions  */
void time_Display(Time *t)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Display\n");
	#endif

	printf("%02d:%02d", time_GetHour(t),time_GetMinute(t));

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Display\n");
	#endif
}

/* Comparison functions  */
Boolean time_Equal(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Equal\n");
	#endif

        return (a->hour == b->hour) && (a->minute && b->minute);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Equal\n");
	#endif
}

Boolean time_NotEqual(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_NotEqual\n");
	#endif

        return !time_Equal(a, b);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_NotEqual\n");
	#endif
}

Boolean time_LessThan(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_LessThan\n");
	#endif

        return (a->hour < b->hour) || (a->minute < b->minute);


	#ifdef DEBUG
	fprintf(stderr, "\tExit time_LessThan\n");
	#endif
}

Boolean time_GreaterThan(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_GreaterThan\n");
	#endif

        return !time_LessThanOrEqual(a, b);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_GreaterThan\n");
	#endif
}

Boolean time_LessThanOrEqual(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_LessThanOrEqual\n");
	#endif

        return time_Equal(a, b) || time_LessThan(a, b);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_LessThanOrEqual\n");
	#endif
}

Boolean time_GreaterThanOrEqual(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_GreaterThanOrEqual\n");
	#endif

        return !time_LessThan(a, b);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_GreaterThanOrEqual\n");
	#endif
}

/* Manipulation functions  */
Time time_Add(Time *a, int minutes)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Add\n");
	#endif

        a->minute += minutes;
        a->hour += a->minute/60;
        a->minute %= 60;

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Add\n");
	#endif
}

int time_Difference(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Difference\n");
	#endif

        /* TODO: Return negative? */

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Difference\n");
	#endif

        int minutes = a->hour*60 + a->minute;
        return minutes - b->hour*60 - b->minute;
}


