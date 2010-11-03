/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkWienerDeconvolutionImageFilter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkWienerDeconvolutionImageFilter - peforms Gaussian blurring of an input image
// .SECTION Description
// vtkMyImageShiftFilter is a filter to generate scalar values from a
// dataset.  The scalar values lie within a user specified range, and
// are generated by computing a projection of each dataset point onto
// a line. The line can be oriented arbitrarily. A typical example is
// to generate scalars based on elevation or height above a plane.

#ifndef __vtkWienerDeconvolutionImageFilter_h
#define __vtkWienerDeconvolutionImageFilter_h

#include <vtkITKImageFilter.h>

#include <itkWienerDeconvolutionImageFilter.h>

class VTK_EXPORT vtkWienerDeconvolutionImageFilter : public vtkITKImageFilter
{
public:

  static vtkWienerDeconvolutionImageFilter* New();
  vtkTypeMacro(vtkWienerDeconvolutionImageFilter, vtkITKImageFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  //BTX
  typedef Superclass::PixelType             PixelType;
  typedef Superclass::ITKImageType          ITKImageType;
  typedef Superclass::ITKInternalFilterType ITKInternalFilterType;
  typedef Superclass::ITKImageImportType    ITKImageImportType;
  typedef Superclass::ITKImageExportType    ITKImageExportType;
  typedef itk::WienerDeconvolutionImageFilter< ITKImageType, ITKImageType, ITKImageType >
    ITKDeconvolutionFilterType;
  //ETX

  // Set the convolution kernel image
  void SetKernelImage(vtkAlgorithmOutput* image);

  // Set/get the image padding type
  vtkSetMacro(PaddingMethod, int);
  vtkGetMacro(PaddingMethod, int);

protected:
  vtkWienerDeconvolutionImageFilter();
  ~vtkWienerDeconvolutionImageFilter();

  int PaddingMethod;

  //BTX
  ITKDeconvolutionFilterType::Pointer ITKDeconvolutionFilter;
  //ETX

protected:
  virtual int RequestUpdateExtent (vtkInformation *, vtkInformationVector **, vtkInformationVector *);

  virtual int FillInputPortInformation(int port, vtkInformation *info);

  int UpdateInternalFilters();

private:
  vtkWienerDeconvolutionImageFilter(const vtkWienerDeconvolutionImageFilter&);  // Not implemented.
  void operator=(const vtkWienerDeconvolutionImageFilter&);  // Not implemented.
};

#endif
