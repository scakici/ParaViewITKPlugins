/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkFFTConvolutionImageFilter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkFFTConvolutionImageFilter - peforms Gaussian blurring of an input image
// .SECTION Description
// vtkMyImageShiftFilter is a filter to generate scalar values from a
// dataset.  The scalar values lie within a user specified range, and
// are generated by computing a projection of each dataset point onto
// a line. The line can be oriented arbitrarily. A typical example is
// to generate scalars based on elevation or height above a plane.

#ifndef __vtkFFTConvolutionImageFilter_h
#define __vtkFFTConvolutionImageFilter_h

#include <vtkImageAlgorithm.h>

#include <itkVTKImageImport.h>
#include <itkVTKImageExport.h>
#include <itkFFTConvolutionImageFilter.h>

class vtkImageExport;
class vtkImageImport;

class VTK_EXPORT vtkFFTConvolutionImageFilter : public vtkImageAlgorithm
{
public:

  //BTX
  typedef float
    PixelType;
  typedef itk::Image< PixelType, 3 >
    ITKImageType;
  typedef itk::VTKImageImport< ITKImageType >
    ITKImageImportType;
  typedef itk::VTKImageExport< ITKImageType >
    ITKImageExportType;
  typedef itk::FFTConvolutionImageFilter< ITKImageType, ITKImageType, ITKImageType >
    ITKFFTConvolutionFilterType;
  //ETX

  static vtkFFTConvolutionImageFilter* New();
  vtkTypeMacro(vtkFFTConvolutionImageFilter, vtkImageAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Set the convolution kernel image
  void SetKernelImage(vtkAlgorithmOutput* image);

  // Set/get the image padding type
  vtkSetMacro(PaddingMethod, int);
  vtkGetMacro(PaddingMethod, int);

protected:
  vtkFFTConvolutionImageFilter();
  ~vtkFFTConvolutionImageFilter();

  int PaddingMethod;

  vtkImageExport*                VTKExporter;
  vtkImageExport*                VTKKernelExporter;
  //BTX
  ITKImageImportType::Pointer          ITKImporter;
  ITKImageImportType::Pointer          ITKKernelImporter;
  ITKFFTConvolutionFilterType::Pointer ITKConvolutionFilter;
  ITKImageExportType::Pointer          ITKExporter;
  //ETX
  vtkImageImport*                VTKImporter;

protected:
  void InitializeITKImporters();
  void InitializeITKExporter();

  int RequestData(vtkInformation *request, vtkInformationVector **inputVector, vtkInformationVector *outputVector);

  int FillInputPortInformation(int port, vtkInformation *info);

  //BTX
  template <class T>
  void RunITKPipeline(const T *input);
  //ETX

private:
  vtkFFTConvolutionImageFilter(const vtkFFTConvolutionImageFilter&);  // Not implemented.
  void operator=(const vtkFFTConvolutionImageFilter&);  // Not implemented.
};

#endif
