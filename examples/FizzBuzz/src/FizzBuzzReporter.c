#include <stdio.h>

#include "FizzBuzzReporter.h"

/*
 * Written as an example of a C program we want to test.
 */

// printf included to provide and example of how to mock with cgreen
void fizzBuzzReporter( unsigned int input, char* const reportBuffer )
{
    if((input % 15) == 0) {
        snprintf(reportBuffer, REPORT_STRING_LEN, "FIZZBUZZ");
        printf("FIZZBUZZ");
    } else if((input % 3) == 0) {
        snprintf(reportBuffer, REPORT_STRING_LEN, "FIZZ");
        printf("FIZZ");
    } else if((input % 5) == 0 ) {
        snprintf( reportBuffer, REPORT_STRING_LEN, "BUZZ");
        printf("BUZZ");
    } else {
        snprintf(reportBuffer, REPORT_STRING_LEN, "%u", input);
        printf("%d", input);
    }

    printf("\n");
}
