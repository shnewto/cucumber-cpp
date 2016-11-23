#include <cgreen/cgreen.h> // general unit testing
#include <cgreen/mocks.h> // mocking functionality

#include <cucumber-cpp/autodetect.hpp>
#include <cucumber-cpp/internal/CukeEngine.hpp>

using cucumber::ScenarioScope;
using namespace cgreen;

extern "C"
{
#include "FizzBuzzReporter.h"
};

struct FizzBuzzState {
    char report_buffer[REPORT_STRING_LEN];
};

// mocked version of printf
int printf(const char *__restrict __format, ...) {
    // do nothing
    return (int)mock();
}

GIVEN("^I have passed (.*) into fizzBuzzReporter") {
    REGEX_PARAM(unsigned int, input);

    ScenarioScope<FizzBuzzState> context;

    // expect mocked function to be called
    expect(printf);

    fizzBuzzReporter(input, context->report_buffer);
}

THEN("^the result should be (.*)$") {

    REGEX_PARAM(std::string, expected);

    ScenarioScope<FizzBuzzState> context;

    assert_that(context->report_buffer, is_equal_to_string(expected.c_str()));
}
