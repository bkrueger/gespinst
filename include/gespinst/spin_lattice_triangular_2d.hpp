#ifndef GESPINST_SPIN_LATTICE_TRIANGULAR_2D_HPP
#define GESPINST_SPIN_LATTICE_TRIANGULAR_2D_HPP

#include "spin_network.hpp"
#include "spin_network_step.hpp"

namespace Gespinst
{
  /*!
   * \brief Class for a two-dimensional triangular lattice.
   * \author Benedikt Krüger
   * \tparam SpinType Spin to use in the triangular lattice.
   */
  template<class SpinType>
  class SpinLatticeTriangular2d : public SpinNetworkStatic<SpinType, 6>
  {
  public:
    typedef SpinNetworkStatic<SpinType, 6> Base;
    typedef int size_t;

    //! Default constructor
    SpinLatticeTriangular2d()
      : Base(0, SpinType()), size_x(0), size_y(0) {}
    //! Constructor giving the size in each direction and an optional default spin
    SpinLatticeTriangular2d(size_t lattice_size_x, size_t lattice_size_y, SpinType default_spin = SpinType())
      : Base(lattice_size_x*lattice_size_y, default_spin), size_x(lattice_size_x), size_y(lattice_size_y)
    {
      // Create the neighbours for each spin
      for (size_t x = 0; x < size_x; ++x)
      {
	for (size_t y = 0; y < size_y; ++y)
	{
	  size_t linear_index = x*size_y + y;
	  typename Base::NeighbourContainerType neighbours;

	  // Set the 6 nearest neighbours
	  // Linear in y +- 1
	  neighbours[0] = &(this->spins[x*size_y + to_index(y + 1, size_y)]);
	  neighbours[1] = &(this->spins[x*size_y + to_index(y - 1, size_y)]);
	  // Linear in x +- 1
	  neighbours[2] = &(this->spins[to_index(x + 1, size_x)*size_y + y]);
	  neighbours[3] = &(this->spins[to_index(x - 1, size_x)*size_y + y]);
	  // Diagonal in (x,y) +- (1,1)
	  neighbours[4] = &(this->spins[to_index(x + 1, size_x)*size_y + to_index(y + 1, size_y)]);
	  neighbours[5] = &(this->spins[to_index(x - 1, size_x)*size_y + to_index(y - 1, size_y)]);

	  // Assign the neighbours
	  this->set_neighbours(x*size_y + y, neighbours);
	}
      }
    }

    //! Get-accessor for the x-size
    size_t get_size_x() const { return size_x; }
    //! Get-accessor for the y-size
    size_t get_size_y() const { return size_y; }

    //! Operator for read-access with two indices
    const SpinType& operator()(size_t index_x, size_t index_y) const { return this->spins[index_x*size_y + index_y]; }
    //! Operator for write-access with two indices
    SpinType& operator()(size_t index_x, size_t index_y) { return this->spins[index_x*size_y + index_y]; }

  private:
    //! Number of spins in x-direction
    size_t size_x;
    //! Number of spins in y-direction
    size_t size_y;

    //! Function to use periodic boundary conditions
    size_t to_index(size_t index, size_t size)
    {
      while (index < 0) index += size;
      while (index > size - 1) index -= size;
      return index;
    }
  };
}

#endif
