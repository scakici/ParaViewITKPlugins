/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkMaximumEntropyRichardsonLucyDeconvolutionImageFilter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkMaximumEntropyRichardsonLucyDeconvolutionImageFilter - peforms Gaussian blurring of an input image
// .SECTION Description
// vtkMyImageShiftFilter is a filter to generate scalar values from a
// dataset.  The scalar values lie within a user specified range, and
// are generated by computing a projection of each dataset point onto
// a line. The line can be oriented arbitrarily. A typical example is
// to generate scalars based on elevation or height above a plane.

#ifndef __vtkMaximumEntropyRichardsonLucyDeconvolutionImageFilter_h
#define __vtkMaximumEntropyRichardsonLucyDeconvolutionImageFilter_h

#include <vtkIterativeDeconvolutionImageFilter.h>

#include <itkMaximumEntropyRichardsonLucyDeconvolutionImageFilter.h>

class VTK_EXPORT vtkMaximumEntropyRichardsonLucyDeconvolutionImageFilter : public vtkIterativeDeconvolutionImageFilter
{
public:

  static vtkMaximumEntropyRichardsonLucyDeconvolutionImageFilter* New();
  vtkTypeMacro(vtkMaximumEntropyRichardsonLucyDeconvolutionImageFilter, vtkIterativeDeconvolutionImageFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  //BTX
  typedef Superclass::PixelType             PixelType;
  typedef Superclass::ITKImageType          ITKImageType;
  typedef Superclass::ITKInternalFilterType ITKInternalFilterType;
  typedef Superclass::ITKImageImportType    ITKImageImportType;
  typedef Superclass::ITKImageExportType    ITKImageExportType;
  typedef itk::MaximumEntropyRichardsonLucyDeconvolutionImageFilter< ITKImageType, ITKImageType, ITKImageType >
    ITKDeconvolutionFilterType;
  //ETX

  // Set/get regularization parameter Lambda
  vtkSetMacro(Lambda, double);
  vtkGetMacro(Lambda, double);

protected:
  vtkMaximumEntropyRichardsonLucyDeconvolutionImageFilter();
  ~vtkMaximumEntropyRichardsonLucyDeconvolutionImageFilter();

  double Lambda;

  //BTX
  ITKDeconvolutionFilterType::Pointer ITKDeconvolutionFilter;
  //ETX

protected:
  int UpdateInternalFilters();

private:
  vtkMaximumEntropyRichardsonLucyDeconvolutionImageFilter(const vtkMaximumEntropyRichardsonLucyDeconvolutionImageFilter&);  // Not implemented.
  void operator=(const vtkMaximumEntropyRichardsonLucyDeconvolutionImageFilter&);  // Not implemented.
};

#endif