#include "pin.h"
#include "PinTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(PinTest);

PinTest::PinTest() {
    // Nothing to do
}

PinTest::~PinTest() {
    // Nothing to do
}

void PinTest::setUp() {
    // Nothing to do
}

void PinTest::tearDown() {
    // Nothing to do
}

void PinTest::test_initial_construction_value() {
    hw::Pin<hw::PinType::DIGITAL> digital_pin;
    CPPUNIT_ASSERT(digital_pin.get_value() == false);

    hw::Pin<hw::PinType::ANALOG> analog_pin;
    CPPUNIT_ASSERT(analog_pin.get_value() == 0.0);
}

void PinTest::test_value_persistence() {
    hw::Pin<hw::PinType::DIGITAL> digital_pin;
    CPPUNIT_ASSERT(digital_pin.get_value() == false);
    CPPUNIT_ASSERT(digital_pin.get_value() == false);
    CPPUNIT_ASSERT(digital_pin.get_value() == false);

    digital_pin.set_value(true);
    CPPUNIT_ASSERT(digital_pin.get_value() == true);
    CPPUNIT_ASSERT(digital_pin.get_value() == true);
    CPPUNIT_ASSERT(digital_pin.get_value() == true);

    digital_pin.set_value(false);
    CPPUNIT_ASSERT(digital_pin.get_value() == false);
    CPPUNIT_ASSERT(digital_pin.get_value() == false);
    CPPUNIT_ASSERT(digital_pin.get_value() == false);
}

