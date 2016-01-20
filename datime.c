
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

/* Initialization functions   */
void dt_Init(DaTime *d, Day day, Time start, Time end) {	
    dt_SetDay(d, day);
    dt_SetStart(d, start);
    dt_SetEnd(d, end);
}

void dt_Clear(DaTime *d) {	
    dt_SetDay(d, '\0');
    time_Clear(&(d->start));
    time_Clear(&(d->end));
}

void dt_Copy(DaTime *dest, DaTime *source) {
    dt_Init(dest,
            dt_GetDay(source),
            dt_GetStart(source),
            dt_GetEnd(source));
}

/* Accessor functions  */
Day dt_GetDay(DaTime *d) {
    return d->day;
}

Time dt_GetStart(DaTime *d) {
    return d->start;
}

Time dt_GetEnd(DaTime *d) {
    return d->end;
}

int dt_GetDuration(DaTime *d) {
    return time_Difference(&d->end, &d->start);
}

/* Mutator functions  */
void dt_SetDay(DaTime *d, Day day) {
    d->day = day;
}

void dt_SetStart(DaTime *d, Time start) {
    d->start = start;
}

void dt_SetEnd(DaTime *d, Time end) {
    d->end = end;
}

void dt_SetDuration(DaTime *d, int mins) {
    d->end = time_Add(&d->start, mins);
}

/* Display functions  */
void dt_Display(DaTime *d) {
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
Boolean dt_Equal(DaTime *a, DaTime *b) {
    return charToDay(a->day) == charToDay(b->day) 
           && time_Equal( &a->start, &b->start );

}

Boolean dt_NotEqual(DaTime *a, DaTime *b) {
    return !dt_Equal(a, b);
}

Boolean dt_LessThan(DaTime *a, DaTime *b) {
    return !dt_Equal(a, b) && dt_LessThanOrEqual(a, b);
}

Boolean dt_GreaterThan(DaTime *a, DaTime *b) {
    return !dt_LessThanOrEqual(a, b);
}

Boolean dt_LessThanOrEqual(DaTime *a, DaTime *b) {
    return  charToDay(b->day) >= charToDay(a->day)
            || time_GreaterThanOrEqual(&b->start, &a->end);
}

Boolean dt_GreaterThanOrEqual(DaTime *a, DaTime *b) {
    return !dt_LessThan(a, b);
}

Boolean dt_Overlap(DaTime *a, DaTime *b) {
    Boolean less_than = dt_LessThan(a, b);

    DaTime* first = less_than ? a : b;
    DaTime* last = less_than ? b : a;

    return time_GreaterThan(&first->end, &last->start);
}

Boolean dt_NonOverlap(DaTime *a, DaTime *b) {
    return !dt_Overlap(a, b);
}

/* Manipulation functions  */
void dt_ChangeDay(DaTime *d, Day day) {
    d->day = day; }

void dt_ChangeDuration(DaTime *d, int dur) {
    d->end = d->start;
    time_Add(&d->start, dur);
}

void dt_ChangeStart(DaTime *d, Time newstart) {
    d->start = newstart;
}

DaTime dt_Merge(DaTime *a, DaTime *b) {  
    DaTime temp;

    if(dt_GetDay(a) != dt_GetDay(b)) {	
        Warning("Cannot merge across days; result cleared");
        dt_Clear(&temp);
        return temp;
    }

    dt_SetDay(&temp, dt_GetDay(a));
    dt_SetStart(&temp, dt_GetStart(a));
    dt_SetEnd(&temp, dt_GetEnd(b));

    return temp;
}

int dt_Difference(DaTime *a, DaTime *b) {
    int ret = charToDay(b->day)*60 - charToDay(a->day)*60
              + time_Difference(&a->start, &b->start);

    return ret >= 0 ? ret : -ret;
}
