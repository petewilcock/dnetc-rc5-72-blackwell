/*
 * Copyright distributed.net 2014 - All rights reserved.
 * For use in distributed.net projects only.
 * Any other distribution or use of this source violates copyright.
 *
 * $Id: cuda_core_count.h,v 1.0 2014/02/25 22:19:04 ertyu Exp $
 */
 
#ifndef CUDA_CORE_COUNT_H
#define CUDA_CORE_COUNT_H

// Number of cores per MP (varies with SM version)
// from NVIDIA CUDA SDK sample code 'deviceQuery'
// http://docs.nvidia.com/cuda/cuda-samples/index.html#device-query
typedef struct
{
  int SM; // 0xMm (hexidecimal notation)
          // M = SM Major version, m = SM minor version
  int Cores;
} sSMtoCores;
sSMtoCores CUDACoresPerSM[] =
{
  { 0x10,  8 }, // Tesla Generation (SM 1.0) G80 class
  { 0x11,  8 }, // Tesla Generation (SM 1.1) G8x class
  { 0x12,  8 }, // Tesla Generation (SM 1.2) G9x class
  { 0x13,  8 }, // Tesla Generation (SM 1.3) GT200 class
  { 0x20, 32 }, // Fermi Generation (SM 2.0) GF100 class
  { 0x21, 48 }, // Fermi Generation (SM 2.1) GF10x class
  { 0x30, 192}, // Kepler Generation (SM 3.0) GK10x class
  { 0x32, 192}, // Kepler Generation (SM 3.2)
  { 0x35, 192}, // Kepler Generation (SM 3.5) GK11x class
  { 0x37, 192}, // Kepler Generation (SM 3.7)
  { 0x50, 128}, // Maxwell Generation (SM 5.0)
  { 0x52, 128}, // Maxwell Generation (SM 5.2)
  { 0x53, 128}, // Maxwell Generation (SM 5.3)
  { 0x60,  64}, // Pascal Generation (SM 6.0)
  { 0x61, 128}, // Pascal Generation (SM 6.1)
  { 0x62, 128}, // Pascal Generation (SM 6.2)
  { 0x70,  64}, // Volta Generation (SM 7.0)
  { 0x72,  64}, // Volta Generation (SM 7.2)
  { 0x75,  64}, // Turing Generation (SM 7.5)
  { 0x80,  64}, // Ampere Generation (SM 8.0)
  { 0x86, 128}, // Ampere Generation (SM 8.6)
  { 0x87, 128}, // Ampere Generation (SM 8.7)
  { 0x89, 128}, // Ada Generation (SM 8.9)
  { 0x90, 128}, // Hopper Generation (SM 9.0)
  { 0xa0, 128}, // Blackwell Generation (SM 10.0)
  { 0xa1, 128}, // Blackwell Generation (SM 10.1)
  { 0xa3, 128}, // Blackwell Generation (SM 10.3)
  { 0xa7, 128}, // Rubin Generation (SM 10.7)
  { 0xb0, 128}, // Blackwell Generation (SM 11.0)
  { 0xc0, 128}, // Blackwell Generation (SM 12.0) RTX 50 series
  { 0xc1, 128}, // Blackwell Generation (SM 12.1)
  {   -1, -1 }
};

inline int getCUDACoresPerSM (int major, int minor)
{
  int index = 0;
  int SM = (major << 4) + minor;

  while (CUDACoresPerSM[index].SM != -1) {
    if (CUDACoresPerSM[index].SM == SM ) {
      return CUDACoresPerSM[index].Cores;
    }
    index++;
  }
  return -1;
}

#endif // CUDA_CORE_COUNT_H
