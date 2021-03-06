/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkRegularizedLeastSquaresDeconvolutionImageFilter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkRegularizedLeastSquaresDeconvolutionImageFilter - peforms Gaussian blurring of an input image
// .SECTION Description
// vtkMyImageShiftFilter is a filter to generate scalar values from a
// dataset.  The scalar values lie within a user specified range, and
// are generated by computing a projection of each dataset point onto
// a line. The line can be oriented arbitrarily. A typical example is
// to generate scalars based on elevation or height above a plane.

#ifndef __vtkRegularizedLeastSquaresDeconvolutionImageFilter_h
#define __vtkRegularizedLeastSquaresDeconvolutionImageFilter_h

#include <vtkDeconvolutionImageFilter.h>

#include <itkRegularizedLeastSquaresDeconvolutionImageFilter.h>

class VTK_EXPORT vtkRegularizedLeastSquaresDeconvolutionImageFilter : public vtkDeconvolutionImageFilter
{
public:

  static vtkRegularizedLeastSquaresDeconvolutionImageFilter* New();
  vtkTypeMacro(vtkRegularizedLeastSquaresDeconvolutionImageFilter, vtkDeconvolutionImageFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  //BTX
  typedef Superclass::PixelType             PixelType;
  typedef Superclass::ITKImageType          ITKImageType;
  typedef Superclass::ITKInternalFilterType ITKInternalFilterType;
  typedef Superclass::ITKImageImportType    ITKImageImportType;
  typedef Superclass::ITKImageExportType    ITKImageExportType;
  typedef itk::RegularizedLeastSquaresDeconvolutionImageFilter< ITKImageType, ITKImageType, ITKImageType >
    ITKDeconvolutionFilterType;
  //ETX

  // Set/get regularizing parameter Alpha
  vtkSetMacro(Alpha, double);
  vtkGetMacro(Alpha, double);

protected:
  vtkRegularizedLeastSquaresDeconvolutionImageFilter();
  ~vtkRegularizedLeastSquaresDeconvolutionImageFilter();

  double Alpha;

  //BTX
  ITKDeconvolutionFilterType::Pointer ITKDeconvolutionFilter;
  //ETX

protected:
  int UpdateInternalFilters();

private:
  vtkRegularizedLeastSquaresDeconvolutionImageFilter(const vtkRegularizedLeastSquaresDeconvolutionImageFilter&);  // Not implemented.
  void operator=(const vtkRegularizedLeastSquaresDeconvolutionImageFilter&);  // Not implemented.
};

#endif
