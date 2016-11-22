#include <cgreen/cgreen.h> // general unit testing
#include <cucumber-cpp/autodetect.hpp>
#include "../../utils/DriverTestRunner.hpp"

using namespace cucumber;
using namespace cgreen;
using namespace cucumber::internal;

THEN(SUCCEED_MATCHER) {
    ScenarioScope<SomeContext> ctx;
    assert_that(true);
}

THEN(FAIL_MATCHER) {
    ScenarioScope<SomeContext> ctx;
    assert_that(false);
}

THEN(PENDING_MATCHER_1) {
    pending();
}

THEN(PENDING_MATCHER_2) {
    pending(PENDING_DESCRIPTION);
}

class CgreenStepDouble : public CgreenStep {
public:
    bool isInitialized() {
        return CgreenStep::initialized;
    }

    const InvokeResult invokeStepBody() {
        return CgreenStep::invokeStepBody();
    };

    void body() {};
};

class CgreenDriverTest : public DriverTest {
public:
    virtual void runAllTests() {
        stepInvocationInitsBoostTest();
        DriverTest::runAllTests();
    }
private:
    void stepInvocationInitsBoostTest() {
        std::cout << "= Init =" << std::endl;
        CgreenStepDouble framework;
        expectFalse(
                "Framework is not initialized before the first test",
                framework.isInitialized());
        framework.invokeStepBody();
        expectTrue(
                "Framework is initialized after the first test",
                framework.isInitialized());
    }
};

int main(int argc, char** argv) {
    CgreenDriverTest test;
    return test.run();
}
