// $Id$

// The libMesh Finite Element Library.
// Copyright (C) 2002-2008 Benjamin S. Kirk, John W. Peterson, Roy H. Stogner
  
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
  
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
  
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA



#ifndef __libmesh_base_h__
#define __libmesh_base_h__



namespace libMesh {
  
  /**
   * @returns the number of processors used in the current simulation.
   */
  unsigned int n_processors();

  /**
   * @returns the index of the local processor.
   */
  unsigned int processor_id();

  /**
   * @returns the maximum number of threads used in the simulation.
   */
  unsigned int n_threads();

  /**
   * Namespaces don't provide private data,
   * so let's take the data we would like
   * private and put it in an obnoxious
   * namespace.  At least that way it is a
   * pain to use, thus discouraging errors.
   */
  namespace libMeshPrivateData {
#ifdef LIBMESH_HAVE_MPI
    /**
     * Total number of processors used.
     */
    extern int _n_processors;
    
    /**
     * The local processor id.
     */
    extern int _processor_id;
#endif
    
    /**
     * Total number of threads possible.
     */
    extern int _n_threads;
  }
}



// ------------------------------------------------------------
// libMesh inline member functions
inline
unsigned int libMesh::n_processors()
{
#ifdef LIBMESH_HAVE_MPI
  return static_cast<unsigned int>(libMeshPrivateData::_n_processors);
#else
  return 1;
#endif
}



inline
unsigned int libMesh::processor_id()
{
#ifdef LIBMESH_HAVE_MPI
  return static_cast<unsigned int>(libMeshPrivateData::_processor_id);
#else
  return 0;
#endif
}




inline
unsigned int libMesh::n_threads()
{
  return static_cast<unsigned int>(libMeshPrivateData::_n_threads);
}



#endif // #define __libmesh_base_h__