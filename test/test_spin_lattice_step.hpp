#ifndef TEST_SPIN_LATTICE_STEP_HPP
#define TEST_SPIN_LATTICE_STEP_HPP

#include <cppunit/TestCaller.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>
#include <cppunit/extensions/HelperMacros.h>
#include <gespinst/spin_lattice_step.hpp>
#include <gespinst/spin_lattice.hpp>
#include <gespinst/spins/ising_spin.hpp>

using namespace Gespinst;

typedef boost::multi_array<IsingSpin, 1> lattice_array_type_1d;
typedef boost::array<lattice_array_type_1d::index, 1> index_type_1d;
typedef boost::multi_array<IsingSpin, 2> lattice_array_type_2d;
typedef boost::array<lattice_array_type_2d::index, 2> index_type_2d;

class TestSpinLatticeStep : public CppUnit::TestFixture
{
private:
  SpinLattice<1, IsingSpin>* testlattice_1d;
  SpinLattice<2, IsingSpin>* testlattice_2d;

  index_type_1d index_0, index_1, index_2, index_3, index_4;
  index_type_2d index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22;

  SpinLatticeStep<1, IsingSpin>* teststep_1d_0;
  SpinLatticeStep<1, IsingSpin>* teststep_1d_1;
  SpinLatticeStep<1, IsingSpin>* teststep_1d_2;
  SpinLatticeStep<1, IsingSpin>* teststep_1d_3;
  SpinLatticeStep<1, IsingSpin>* teststep_1d_4;
  SpinLatticeStep<2, IsingSpin>* teststep_2d_00;
  SpinLatticeStep<2, IsingSpin>* teststep_2d_01;
  SpinLatticeStep<2, IsingSpin>* teststep_2d_02;
  SpinLatticeStep<2, IsingSpin>* teststep_2d_10;
  SpinLatticeStep<2, IsingSpin>* teststep_2d_11;
  SpinLatticeStep<2, IsingSpin>* teststep_2d_12;
  SpinLatticeStep<2, IsingSpin>* teststep_2d_20;
  SpinLatticeStep<2, IsingSpin>* teststep_2d_21;
  SpinLatticeStep<2, IsingSpin>* teststep_2d_22;

  IsingSpin spin_up;
  IsingSpin spin_down;

public:
  static CppUnit::Test* suite();

  void setUp();
  void tearDown();

  void test_constructor();

  void test_get_flip_index();
  void test_get_old_spin();
  void test_get_new_spin();
  void test_get_creation_simulation_time();

  void test_delta_E();
  void test_execute();
  void test_undo();
};

#endif
