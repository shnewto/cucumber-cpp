#include <stdio.h>

#include "fizz_buzz.h"

/*
 * Written as an example of a C program we want to test.
 */

// printf included to provide and example of how to mock with cgreen
void fizz_buzz_reporter( unsigned int input, char * const report_buffer )
{
    if((input % 15) == 0) {
        snprintf(report_buffer, REPORT_STRING_LEN, "FIZZBUZZ");
        printf("FIZZBUZZ");
    } else if((input % 3) == 0) {
        snprintf(report_buffer, REPORT_STRING_LEN, "FIZZ");
        printf("FIZZ");
    } else if((input % 5) == 0 ) {
        snprintf( report_buffer, REPORT_STRING_LEN, "BUZZ");
        printf("BUZZ");
    } else {
        snprintf(report_buffer, REPORT_STRING_LEN, "%u", input);
        printf("%d", input);
    }

    printf("\n");
}