#include "test_spin_lattice_triangular_2d.hpp"

#include <mocasinns/random/boost_random.hpp> 

CppUnit::Test* TestSpinLatticeTriangular2d::suite()
{
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestSpinLatticeTriangular2d");
    
    suiteOfTests->addTest( new CppUnit::TestCaller<TestSpinLatticeTriangular2d>("TestSpinLatticeTriangular2d: test_delta_E_automatically", &TestSpinLatticeTriangular2d::test_delta_E_automatically ) );

    return suiteOfTests;
}

void TestSpinLatticeTriangular2d::setUp()
{
  testlattice_ferro = new TestLatticeTypeFerro(4,4);
  testlattice_anti = new TestLatticeTypeAnti(4,4);}

void TestSpinLatticeTriangular2d::tearDown()
{
  // Delete the lattices
  delete testlattice_ferro;
  delete testlattice_anti;
}

void TestSpinLatticeTriangular2d::test_delta_E_automatically()
{
  // Define the random number generator
  Mocasinns::Random::Boost_MT19937 rng;

  // Test for ferromagnetic interaction
  for (unsigned int i = 0; i < 1000; ++i)
  {
    // Store the energy before the step
    double energy_before = testlattice_ferro->energy();

    // Create, execute the step and calculate the energy difference
    typename TestLatticeTypeFerro::StepType step = testlattice_ferro->propose_step(&rng);
    double delta_E = step.delta_E();
    step.execute();
    double energy_after = testlattice_ferro->energy();

    // Compare the calculated energy difference with the actual energy difference
    CPPUNIT_ASSERT_DOUBLES_EQUAL(energy_after - energy_before, delta_E, 1e-5);
  }

  // Test for antiferromagnetic interaction
  for (unsigned int i = 0; i < 1000; ++i)
  {
    // Store the energy before the step
    double energy_before = testlattice_anti->energy();

    // Create, execute the step and calculate the energy difference
    typename TestLatticeTypeAnti::StepType step = testlattice_anti->propose_step(&rng);
    double delta_E = step.delta_E();
    step.execute();
    double energy_after = testlattice_anti->energy();

    // Compare the calculated energy difference with the actual energy difference
    CPPUNIT_ASSERT_DOUBLES_EQUAL(energy_after - energy_before, delta_E, 1e-5);
  }
}
