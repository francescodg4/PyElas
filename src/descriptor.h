/*
Copyright 2011. All rights reserved.
Institute of Measurement and Control Systems
Karlsruhe Institute of Technology, Germany

This file is part of libelas.
Authors: Andreas Geiger

libelas is free software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation; either version 3 of the License, or any later version.

libelas is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
libelas; if not, write to the Free Software Foundation, Inc., 51 Franklin
Street, Fifth Floor, Boston, MA 02110-1301, USA 
*/

// NOTE: This descripter is a sparse approximation to the 50-dimensional
// descriptor described in the paper. It produces similar results, but
// is faster to compute.

#ifndef __DESCRIPTOR_H__
#define __DESCRIPTOR_H__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

class Descriptor {
  
public:
  
  // constructor creates filters
  Descriptor(uint8_t* I,int32_t width,int32_t height,int32_t bpl,bool half_resolution);
  
  // deconstructor releases memory
  ~Descriptor();
  
  // descriptors accessible from outside
  uint8_t* I_desc;
  
private:

  // build descriptor I_desc from I_du and I_dv
  void createDescriptor(uint8_t* I_du,uint8_t* I_dv,int32_t width,int32_t height,int32_t bpl,bool half_resolution);

};

#endif
