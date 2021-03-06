/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef __itkRelativeChangeCalculator_txx
#define __itkRelativeChangeCalculator_txx
#include "itkRelativeChangeCalculator.h"

#include "itkImageRegionConstIteratorWithIndex.h"
#include "itkImageRegionConstIterator.h"

namespace itk
{


template < class TInputImage>
RelativeChangeCalculator<TInputImage>
::RelativeChangeCalculator(void)
{
  m_Valid = false;
  m_Image = NULL;
  m_NewImage = NULL;
  m_Output = NumericTraits< InputPixelType >::Zero;
}


template < class TInputImage >
void
RelativeChangeCalculator<TInputImage>
::PrintSelf( std::ostream& os, Indent indent ) const
{
  Superclass::PrintSelf(os,indent);
  os << indent << "Image: " << m_Image.GetPointer() << std::endl;
  os << indent << "NewImage: " << m_NewImage.GetPointer() << std::endl;
  os << indent << "Valid: " << m_Valid << std::endl;
  os << indent << "Output: " << m_Output << std::endl;
}


template < class TInputImage >
void
RelativeChangeCalculator<TInputImage>
::Compute()
{

  typedef typename InputImageType::IndexType IndexType;

  if( !m_Image || !m_NewImage )
    {
    return;
    }

  ImageRegionConstIteratorWithIndex< InputImageType > iIt( m_Image,
                                                     m_Image->GetRequestedRegion() );
  iIt.GoToBegin();
  ImageRegionConstIteratorWithIndex< InputImageType > nIt( m_NewImage,
                                                     m_NewImage->GetRequestedRegion() );
  nIt.GoToBegin();

  // init the values
  double diff = 0;
  double sum = 0;

  while( !iIt.IsAtEnd() )
    {
    diff += vcl_abs( (double)nIt.Get() - (double)iIt.Get() );
    sum += iIt.Get();
    ++iIt;
    ++nIt;
    }

  m_Output = diff / sum;
  m_Valid = true;

}


template < class TInputImage >
const double &
RelativeChangeCalculator<TInputImage>
::GetOutput() const
{
  if (!m_Valid)
    {
    itkExceptionMacro( << "GetOutput() invoked, but the output have not been computed. Call Compute() first.");
    }
  return m_Output;
}

} // end namespace itk

#endif
