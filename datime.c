
/*
 *  File:  datime.c
 *  Name:
 *  login: 
 *  Date:  25 Aug 07
 *  Mod:
 */

/*  Implementation of DaTime data type operations
 */


#include <stdio.h>
#include <assert.h>
#include "datime.h"
#include "time.h"
#include "common.h"

/*
#define DEBUG
*/

/* Initialization functions   */
void dt_Init(DaTime *d, Day day, Time start, Time end)
{	
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Init\n");
	#endif

	dt_SetDay(d, day);
	dt_SetStart(d, start);
	dt_SetEnd(d, end);

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Init\n");
	#endif
}

void dt_Clear(DaTime *d)
{	
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Clear\n");
	#endif

	dt_SetDay(d, '\0');
	time_Clear(&(d->start));
	time_Clear(&(d->end));

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Clear\n");
	#endif
}

void dt_Copy(DaTime *dest, DaTime *source)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Copy\n");
	#endif

	dt_Init(dest,
		dt_GetDay(source),
		dt_GetStart(source),
		dt_GetEnd(source));

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Copy\n");
	#endif
}


/* Accessor functions  */
Day dt_GetDay(DaTime *d)
{
	#ifdef DEBUG
	fprintf(stderr,"\tExecute dt_GetDay\n");
	#endif

	return d->day;
}

Time dt_GetStart(DaTime *d)
{
	#ifdef DEBUG
	fprintf(stderr,"\tExecute dt_GetStart\n");
	#endif

	return d->start;
}

Time dt_GetEnd(DaTime *d)
{
	#ifdef DEBUG
	fprintf(stderr,"\tExecute dt_GetEnd\n");
	#endif

	return d->end;
}

int dt_GetDuration(DaTime *d)
{
	#ifdef DEBUG
	fprintf(stderr,"\tExecute dt_GetDuration\n");
	#endif

        return time_Difference(&d->end, &d->start);
}


/* Mutator functions  */
void dt_SetDay(DaTime *d, Day day)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_SetDay\n");
	#endif

	d->day = day;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_SetDay\n");
	#endif
}

void dt_SetStart(DaTime *d, Time start)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_SetStart\n");
	#endif

	d->start = start;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_SetStart\n");
	#endif
}

void dt_SetEnd(DaTime *d, Time end)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_SetEnd\n");
	#endif

	d->end = end;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_SetEnd\n");
	#endif
}

void dt_SetDuration(DaTime *d, int mins)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_SetDuration\n");
	#endif

        d->end = time_Add(&d->start, mins);

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_SetDuration\n");
	#endif
}



/* Display functions  */
void dt_Display(DaTime *d)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Display\n");
	#endif

	switch(dt_GetDay(d))
	{
	   case 'u':	printf("Sunday ");
			break;
	   case 'm':	printf("Monday ");
			break;
	   case 't':	printf("Tuesday ");
			break;
	   case 'w':	printf("Wednesday ");
			break;
	   case 'r':	printf("Thursday ");
			break;
	   case 'f':	printf("Friday ");
			break;
	   case 's':	printf("Saturday ");
			break;
	   default:	printf("Unknown day ");
	};
	time_Display(&d->start);
	putchar('-');
	time_Display(&d->end);
	putchar('\n');

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Display\n");
	#endif
}

int charToDay(Day c) {
   switch(c) {
        case 'u': return 0;
        case 'm':  return 1;
        case 't':  return 2;
        case 'w':  return 3;
        case 'r':  return 4;
        case 'f':  return 5;
        case 's':  return 6;
        default: assert(0);
    }
}

/* Comparison functions  */
Boolean dt_Equal(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Equal\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Equal\n");
	#endif

        return charToDay(a->day) == charToDay(b->day) &&
               time_Equal( &a->start, &b->start );

}

Boolean dt_NotEqual(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_NotEqual\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_NotEqual\n");
	#endif

        return !dt_Equal(a, b);
}

Boolean dt_LessThan(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_LessThan\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_LessThan\n");
	#endif

        return !dt_Equal(a, b) && dt_LessThanOrEqual(a, b);
}

Boolean dt_GreaterThan(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_GreaterThan\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_GreaterThan\n");
	#endif

        return !dt_LessThanOrEqual(a, b);
}

Boolean dt_LessThanOrEqual(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_LessThanOrEqual\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_LessThanOrEqual\n");
	#endif

        if (charToDay(b->day) < charToDay(a->day)) return 0;
        if (time_LessThan(&b->start, &a->end)) return 0;
        return 1;
}

Boolean dt_GreaterThanOrEqual(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_GreaterThanOrEqual\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_GreaterThanOrEqual\n");
	#endif

        return !dt_LessThan(a, b);
}

Boolean dt_Overlap(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Overlap\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Overlap\n");
	#endif

        Boolean less_than = dt_LessThan(a, b);

        DaTime* first = less_than ? a : b;
        DaTime* last = less_than ? b : a;

        return time_GreaterThan(&first->end, &last->start);
}

Boolean dt_NonOverlap(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_NonOverlap\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_NonOverlap\n");
	#endif
        
        return !dt_Overlap(a, b);
}


/* Manipulation functions  */
void dt_ChangeDay(DaTime *d, Day day)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_ChangeDay\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_ChangeDay\n");
	#endif

        d->day = day;
}

void dt_ChangeDuration(DaTime *d, int dur)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_ChangeDuration\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_ChangeDuration\n");
	#endif

        d->end = d->start;
        time_Add(&d->start, dur);
}

void dt_ChangeStart(DaTime *d, Time newstart)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_ChangeStart\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_ChangeStart\n");
	#endif

        d->start = newstart;
}


DaTime dt_Merge(DaTime *a, DaTime *b)
{  DaTime temp;
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Merge\n");
	#endif

	if(dt_GetDay(a) != dt_GetDay(b))
	{	Warning("Cannot merge across days; result cleared");
		dt_Clear(&temp);
		return temp;
	}

	dt_SetDay(&temp, dt_GetDay(a));
	dt_SetStart(&temp, dt_GetStart(a));
	dt_SetEnd(&temp, dt_GetEnd(b));

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Merge\n");
	#endif

	return temp;
}

int dt_Difference(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Difference\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Difference\n");
	#endif

        int ret = charToDay(b->day)*60 - charToDay(a->day)*60
               + time_Difference(&a->start, &b->start);

        return ret >= 0 ? ret : -ret;
}
