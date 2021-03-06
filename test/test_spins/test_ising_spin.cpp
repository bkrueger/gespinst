#include "test_ising_spin.hpp"

CppUnit::Test* TestIsingSpin::suite()
{
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestIsingSpin");
    
    suiteOfTests->addTest( new CppUnit::TestCaller<TestIsingSpin>("TestIsingSpin: test_constructor", &TestIsingSpin::test_constructor ) );

    suiteOfTests->addTest( new CppUnit::TestCaller<TestIsingSpin>("TestIsingSpin: test_get_set_value", &TestIsingSpin::test_get_set_value ) );

    suiteOfTests->addTest( new CppUnit::TestCaller<TestIsingSpin>("TestIsingSpin: test_operator_equal", &TestIsingSpin::test_operator_equal ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<TestIsingSpin>("TestIsingSpin: test_operator_multiply", &TestIsingSpin::test_operator_multiply ) );

    suiteOfTests->addTest( new CppUnit::TestCaller<TestIsingSpin>("TestIsingSpin: test_all_possible_values", &TestIsingSpin::test_all_possible_values ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<TestIsingSpin>("TestIsingSpin: test_random", &TestIsingSpin::test_random ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<TestIsingSpin>("TestIsingSpin: test_random_differ", &TestIsingSpin::test_random_differ ) );

    return suiteOfTests;
}

void TestIsingSpin::setUp()
{
  spin_up_ferro.set_value(1);
  spin_down_ferro.set_value(-1);
  spin_up_anti.set_value(1);
  spin_down_anti.set_value(-1);
}

void TestIsingSpin::tearDown()
{
}

void TestIsingSpin::test_constructor()
{
  IsingSpin<> spin_test_1(2);
  CPPUNIT_ASSERT_EQUAL(1, spin_test_1.get_value());
  
  IsingSpin<> spin_test_2(0);
  CPPUNIT_ASSERT_EQUAL(1, spin_test_2.get_value());

  IsingSpin<> spin_test_3(-5);
  CPPUNIT_ASSERT_EQUAL(-1, spin_test_3.get_value());
}

void TestIsingSpin::test_get_set_value()
{
  CPPUNIT_ASSERT_EQUAL(1, spin_up_ferro.get_value());
  CPPUNIT_ASSERT_EQUAL(-1, spin_down_ferro.get_value());

  IsingSpin<> spin_test;
  spin_test.set_value(13);
  CPPUNIT_ASSERT_EQUAL(1, spin_test.get_value());
  spin_test.set_value(9);
  CPPUNIT_ASSERT_EQUAL(1, spin_test.get_value());
  spin_test.set_value(0);
  CPPUNIT_ASSERT_EQUAL(1, spin_test.get_value());
  spin_test.set_value(-2);
  CPPUNIT_ASSERT_EQUAL(-1, spin_test.get_value());
  spin_test.set_value(-18);
  CPPUNIT_ASSERT_EQUAL(-1, spin_test.get_value());
}

void TestIsingSpin::test_operator_equal()
{
  CPPUNIT_ASSERT(spin_up_ferro == spin_up_ferro);
  CPPUNIT_ASSERT(!(spin_up_ferro != spin_up_ferro));

  CPPUNIT_ASSERT(spin_up_ferro != spin_down_ferro);
  CPPUNIT_ASSERT(!(spin_up_ferro == spin_down_ferro));

  CPPUNIT_ASSERT(spin_down_ferro != spin_up_ferro);
  CPPUNIT_ASSERT(!(spin_down_ferro == spin_up_ferro));

  CPPUNIT_ASSERT(spin_down_ferro == spin_down_ferro);
  CPPUNIT_ASSERT(!(spin_down_ferro != spin_down_ferro));
}
void TestIsingSpin::test_operator_multiply()
{
  CPPUNIT_ASSERT_EQUAL(static_cast<double>(-1), spin_up_ferro * spin_up_ferro);
  CPPUNIT_ASSERT_EQUAL(static_cast<double>(-1), spin_down_ferro * spin_down_ferro);
  CPPUNIT_ASSERT_EQUAL(static_cast<double>(1), spin_up_ferro * spin_down_ferro);
  CPPUNIT_ASSERT_EQUAL(static_cast<double>(1), spin_down_ferro * spin_up_ferro);

  CPPUNIT_ASSERT_EQUAL(static_cast<double>(1), spin_up_anti * spin_up_anti);
  CPPUNIT_ASSERT_EQUAL(static_cast<double>(1), spin_down_anti * spin_down_anti);
  CPPUNIT_ASSERT_EQUAL(static_cast<double>(-1), spin_up_anti * spin_down_anti);
  CPPUNIT_ASSERT_EQUAL(static_cast<double>(-1), spin_down_anti * spin_up_anti);
}

void TestIsingSpin::test_all_possible_values()
{
  CPPUNIT_ASSERT(spin_up_ferro.all_possible_values()[0] == spin_up_ferro);
  CPPUNIT_ASSERT(spin_up_ferro.all_possible_values()[1] == spin_down_ferro);
  CPPUNIT_ASSERT(spin_down_ferro.all_possible_values()[0] == spin_up_ferro);
  CPPUNIT_ASSERT(spin_down_ferro.all_possible_values()[1] == spin_down_ferro);
}
void TestIsingSpin::test_random()
{
}

void TestIsingSpin::test_random_differ()
{
  CPPUNIT_ASSERT(spin_up_ferro.random_differ(0.3) == spin_down_ferro);
  CPPUNIT_ASSERT(spin_up_ferro.random_differ(0.15) == spin_down_ferro);
  CPPUNIT_ASSERT(spin_down_ferro.random_differ(0.3) == spin_up_ferro);
  CPPUNIT_ASSERT(spin_down_ferro.random_differ(0.15) == spin_up_ferro);
}
