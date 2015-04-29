#ifndef TEST_SPIN_LATTICE_TRIANGULAR_2D_HPP
#define TEST_SPIN_LATTICE_TRIANGULAR_2D_HPP

#include <cppunit/TestCaller.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>
#include <cppunit/extensions/HelperMacros.h>
#include <gespinst/spin_lattice_triangular_2d.hpp>
#include <gespinst/spins/ising_spin.hpp>

using namespace Gespinst;

class TestSpinLatticeTriangular2d : public CppUnit::TestFixture
{
public:
  typedef SpinLatticeTriangular2d<IsingSpin<SpinIsingInteractionType::Ferromagnetic> > TestLatticeTypeFerro;
  typedef SpinLatticeTriangular2d<IsingSpin<SpinIsingInteractionType::Antiferromagnetic> > TestLatticeTypeAnti;

  static CppUnit::Test* suite();

  void setUp();
  void tearDown();

  void test_delta_E_automatically();

private:
  TestLatticeTypeFerro* testlattice_ferro;
  TestLatticeTypeAnti* testlattice_anti;
};

#endif
