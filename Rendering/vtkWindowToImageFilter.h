/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkWindowToImageFilter.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

Copyright (c) 1993-2001 Ken Martin, Will Schroeder, Bill Lorensen 
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * Neither name of Ken Martin, Will Schroeder, or Bill Lorensen nor the names
   of any contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

 * Modified source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
// .NAME vtkWindowToImageFilter - Use a vtkWindow as input to image pipeline
// .SECTION Description
// vtkWindowToImageFilter provides methods needed to read the data in a 
// vtkWindow and use it as input to the imaging pipeline. This is
// useful for saving an image to a file for example. Use this filter to
// convert RenderWindows or ImageWindows to an image format.

#ifndef __vtkWindowToImageFilter_h
#define __vtkWindowToImageFilter_h

#include "vtkImageSource.h"

class vtkRenderWindow;

class VTK_RENDERING_EXPORT vtkWindowToImageFilter : public vtkImageSource
{
public:
  static vtkWindowToImageFilter *New();

  vtkTypeMacro(vtkWindowToImageFilter,vtkImageSource);
  void PrintSelf(ostream& os, vtkIndent indent);   

  // Description:
  // Indicates what renderer to get the pixel data from.
  void SetInput(vtkRenderWindow *input);

  // Description:
  // Returns which renderer is being used as the source for the pixel data.
  vtkGetObjectMacro(Input,vtkRenderWindow);

  // Description:
  // The magnification of the current render window
  vtkSetClampMacro(Magnification,int,1,2048);
  vtkGetMacro(Magnification,int);

protected:
  vtkWindowToImageFilter();
  ~vtkWindowToImageFilter();

  // vtkWindow is not a vtkDataObject, so we need our own ivar.
  vtkRenderWindow *Input;
  int Magnification;
  void ExecuteInformation();
  void ExecuteData(vtkDataObject *data);
private:
  vtkWindowToImageFilter(const vtkWindowToImageFilter&);  // Not implemented.
  void operator=(const vtkWindowToImageFilter&);  // Not implemented.
};

#endif
