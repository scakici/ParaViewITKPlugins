/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkGaussianBlurImageFilter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkGaussianBlurImageFilter - peforms Gaussian blurring of an input image
// .SECTION Description
// vtkMyImageShiftFilter is a filter to generate scalar values from a
// dataset.  The scalar values lie within a user specified range, and
// are generated by computing a projection of each dataset point onto
// a line. The line can be oriented arbitrarily. A typical example is
// to generate scalars based on elevation or height above a plane.

#ifndef __vtkGaussianBlurImageFilter_h
#define __vtkGaussianBlurImageFilter_h

#include <vtkITKImageFilter.h>

#include <itkDiscreteGaussianImageFilter.h>

class VTK_EXPORT vtkGaussianBlurImageFilter : public vtkITKImageFilter
{
public:

  static vtkGaussianBlurImageFilter* New();
  vtkTypeMacro(vtkGaussianBlurImageFilter, vtkITKImageFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  //BTX
  typedef Superclass::PixelType             PixelType;
  typedef Superclass::ITKImageType          ITKImageType;
  typedef Superclass::ITKInternalFilterType ITKInternalFilterType;
  typedef Superclass::ITKImageImportType    ITKImageImportType;
  typedef Superclass::ITKImageExportType    ITKImageExportType;
  typedef itk::DiscreteGaussianImageFilter< ITKImageType, ITKImageType >
    ITKGaussianFilterType;
  //ETX

  vtkSetVector3Macro(StandardDeviation, double);
  vtkGetVector3Macro(StandardDeviation, double);

protected:
  vtkGaussianBlurImageFilter();
  ~vtkGaussianBlurImageFilter();

  double StandardDeviation[3];

  //BTX
  ITKGaussianFilterType::Pointer GaussianFilter;
  //ETX

protected:
  int UpdateInternalFilters();

private:
  vtkGaussianBlurImageFilter(const vtkGaussianBlurImageFilter&);  // Not implemented.
  void operator=(const vtkGaussianBlurImageFilter&);  // Not implemented.
};

#endif
