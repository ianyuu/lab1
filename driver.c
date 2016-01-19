
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
#include <assert.h>

main()
{
   Time t1, t2, t3, t4, t5;
   DaTime a, b, c, d, e;


    /* time_Equal */
    time_Init(&t1, 3, 30);
    time_Init(&t2, 3, 30);
    time_Init(&t3, 4, 30);

    assert( time_Equal(&t1, &t2) );
    assert( !time_Equal(&t1, &t3) );
 

    /* time_NotEqual */
    time_Init(&t1, 3, 30);
    time_Init(&t2, 3, 30);
    time_Init(&t3, 4, 30);

    assert( time_NotEqual(&t1, &t3) );
    assert( !time_NotEqual(&t1, &t2) );

    /* time_Difference */
    time_Init(&t1, 8, 30);
    time_Init(&t2, 3, 45);

    assert( 285 == time_Difference( &t1, &t2 ) );


    /* time_Add */
    time_Init(&t1, 3, 45);
    time_Init(&t2, 8, 30);

    Time t = time_Add(&t1, 285);

    assert( time_Equal( &t, &t2 ) );


    /* dt_Overlap */
    time_Init(&t1, 1, 30);
    time_Init(&t2, 2, 45);
    dt_Init(&a, 'm', t1, t2);

    time_Init(&t3, 2, 30);
    time_Init(&t4, 3, 45);
    dt_Init(&b, 'm', t3, t4);

    assert( dt_Overlap(&a, &b) );

    time_Init(&t1, 1, 30);
    time_Init(&t2, 2, 10);
    dt_Init(&a, 'm', t1, t2);

    assert( !dt_Overlap(&a, &b) );

    printf("Tests passed\n");

/*
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
*/
}
