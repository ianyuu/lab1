
/*
 *  File:  driver.c
 *  Name:
 *  login: 
 *  Date:  25 Aug 07
 *  Mod:
 */

/*  Test driver for DaTime data type
 */


#include <stdio.h>
#include "datime.h"
#include "time.h"

main()
{
   Time t1, t2, t3, t4, t5;
   DaTime a, b, c, d, e;

	time_Init(&t1, 11, 30);
	time_Init(&t2, 12, 20);
	time_InitSingle(&t3, 300);
	time_InitSingle(&t4, 415);
	time_InitSingle(&t5, 1030);

	dt_Init(&a, 'm', t1, t2);
	dt_Display(&a);
	dt_Init(&b, 't', t3, t4);
	dt_Display(&b);
	dt_Init(&c, 'm', t5, t1);
	dt_Display(&c);
	d = dt_Merge(&c, &a);
	dt_Display(&d);
	e = dt_Merge(&d, &b);
	dt_Display(&e);

}
