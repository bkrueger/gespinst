// CppUnit-Tutorial

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TestResult.h>
#include "test_spins/test_ising_spin.hpp"
#include "test_spins/test_potts_spin.hpp"
#include "test_spins/test_real_spin.hpp"
#include "test_spin_lattice.hpp"
#include "test_spin_lattice_step.hpp"
#include "test_spin_network.hpp"
#include "test_spin_network_step.hpp"

int main()
{
  CppUnit::TextUi::TestRunner runner;
  
  runner.addTest(TestIsingSpin::suite());
  runner.addTest(TestPottsSpin::suite());
  runner.addTest(TestRealSpin::suite());
  runner.addTest(TestSpinLattice::suite());
  runner.addTest(TestSpinLatticeStep::suite());
  runner.addTest(TestSpinNetwork::suite());
  runner.addTest(TestSpinNetworkStep::suite());

  CppUnit::BriefTestProgressListener listener; 
  runner.eventManager().addListener(&listener);

  runner.run();
  
  return 0;
}
