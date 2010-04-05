/*
 For more information, please see: http://software.sci.utah.edu

 The MIT License

 Copyright (c) 2009 Scientific Computing and Imaging Institute,
 University of Utah.


 Permission is hereby granted, free of charge, to any person obtaining a
 copy of this software and associated documentation files (the "Software"),
 to deal in the Software without restriction, including without limitation
 the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included
 in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.
 */

#ifndef UTILS_RENDERRESOURCES_RENDERCONTEXT_H
#define UTILS_RENDERRESOURCES_RENDERCONTEXT_H

// Boost includes
#include <boost/thread/mutex.hpp>
#include <boost/shared_ptr.hpp>

// Utils includes
#include <Utils/Core/Log.h>

namespace Utils
{

// Forward declarations
class RenderContext;
typedef boost::shared_ptr< RenderContext > RenderContextHandle;

// Class definition
class RenderContext
{

  // -- constructor/ destructor --
public:
  RenderContext();
  virtual ~RenderContext();

  // -- context functions --
  // IS_VALID:
  // Test whether the context is valid
  virtual bool is_valid() const = 0;

  // MAKE_CURRENT:
  // Set the rendering context current to this thread
  virtual void make_current() = 0;

  // DONE_CURRENT:
  // Indicate that rendering using this context is done for now
  virtual void done_current() = 0;

  // SWAP_BUFFERS:
  // Swap the front and back buffers
  virtual void swap_buffers() const = 0;

  virtual std::string to_string() const = 0;
};

} // end namespace Seg3D

#endif
