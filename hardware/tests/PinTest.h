#pragma once

#include <cppunit/extensions/HelperMacros.h>

class PinTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(PinTest);
    CPPUNIT_TEST(test_initial_construction_value);
    CPPUNIT_TEST(test_value_persistence);
    CPPUNIT_TEST_SUITE_END();

public:
    PinTest();
    virtual ~PinTest();
    void setUp();
    void tearDown();

private:
    // @brief Verifies that logical "0" is asserted on a newly-constructed Pin
    void test_initial_construction_value();
    
    // @brief Verifies that a value that is asserted on a Pin persists until it is changed
    void test_value_persistence();
}; // PinTest class
