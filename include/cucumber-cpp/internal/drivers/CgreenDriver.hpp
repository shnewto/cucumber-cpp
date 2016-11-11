/*
 * Copyright (c) 2016 Shea Newton, PolySync Technologies, Inc.
 */

#ifndef CUKE_CGREENDRIVER_HPP_
#define CUKE_CGREENDRIVER_HPP_

#include <cgreen/cgreen.h> // general unit testing

#include "../step/StepManager.hpp"

using namespace cgreen;

namespace cucumber {
namespace internal {


class CukeCgreenInterceptor;

typedef int TextPrinter(const char *format, ...);

typedef struct {
    TextPrinter *printer;
    int depth;
} TextMemo;

class CgreenStep : public BasicStep {
protected:
    const InvokeResult invokeStepBody();
    static bool initialized;

private:
    void initCgreenTest();
    void setReporterPrinter(TestReporter*, TextPrinter*);
};

#define STEP_INHERITANCE(step_name) ::cucumber::internal::CgreenStep

} // namespace internal
} // namespace cucumber

#endif // CUKE_CGREENDRIVER_HPP_

