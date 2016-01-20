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

/* Initialization functions   */
void time_Init(Time *t, int hour, int minute) {
    time_SetHour(t, hour);
    time_SetMinute(t, minute);
}

void time_InitSingle(Time *t, int hrmin) {
    time_SetHour(t, hrmin/100);
    time_SetMinute(t, hrmin%100);
}

void time_Clear(Time *t) {
    time_SetHour(t, 0);
    time_SetMinute(t, 0);
}

void time_Copy(Time *dest, Time *source) {
    *source = *dest;
}

/* Accessor functions  */
int time_GetHour(Time *t) {
    return t->hour;
}

int time_GetMinute(Time *t) {
    return t->minute;
}

/* Mutator functions  */
void time_SetHour(Time *t, int hour) {
    t->hour = hour;
}

void time_SetMinute(Time *t, int min) {
    t->minute = min;
}

/* Display functions  */
void time_Display(Time *t) {
    printf("%02d:%02d", time_GetHour(t),time_GetMinute(t));
}

/* Comparison functions  */
Boolean time_Equal(Time *a, Time *b) {
    return (a->hour == b->hour) && (a->minute == b->minute);
}

Boolean time_LessThanOrEqual(Time *a, Time *b) {
    if (a->hour > b->hour) return 0;
    if (a->minute > b->minute) return 0;
    return 1;
}

Boolean time_NotEqual(Time *a, Time *b) {
    return !time_Equal(a, b);
}

Boolean time_LessThan(Time *a, Time *b) {
    return time_LessThanOrEqual(a, b) && !time_Equal(a, b);
}

Boolean time_GreaterThan(Time *a, Time *b) {
    return !time_LessThanOrEqual(a, b);
}

Boolean time_GreaterThanOrEqual(Time *a, Time *b) {
    return time_Equal(a, b) || time_GreaterThan(a, b);
}

/* Manipulation functions  */
Time time_Add(Time *a, int minutes) {
    Time t = *a;
    t.minute += minutes;
    t.hour += t.minute/60;
    t.minute %= 60;

    return t;
}

int time_Difference(Time *a, Time *b) {
    int minutes = a->hour*60 + a->minute;
    int ret = minutes - b->hour*60 - b->minute;

    return ret >= 0 ? ret : -ret;
}
