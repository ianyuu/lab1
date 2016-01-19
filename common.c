
/* File: commmon.c
 * Date: 5 Sep 05
 * Rev:  
 *
 *  contains common utility functions
 */

#include "common.h"


void Error(char *s)
/* Reports program error
   Pre:  s pionts to message to be printed
   Post: message printed and program terminated.
*/
{
	fprintf(stderr, "Error: %s\n", s);
	exit(1);
}

void Warning(char *s)
/* Reports unusual program condition
   Pre:  s pionts to message to be printed
   Post: message printed and program resumed.
*/
{
	fprintf(stderr, "Warning: %s\n", s);
}
