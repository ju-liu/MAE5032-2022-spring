PROJECT(vtk-demo)

CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

set(VTK_DIR /Users/juliu/lib/VTK-8.2.0/lib/cmake/vtk-8.2)
find_package(VTK COMPONENTS vtkCommonCore vtkCommonSystem
  vtkCommonMisc vtkCommonMath vtkIOCore vtkIOLegacy vtkIOXML REQUIRED)

include_directories(${VTK_INCLUDE_DIRS})
ADD_EXECUTABLE( vtkdemo main.cpp )
TARGET_LINK_LIBRARIES( vtkdemo ${VTK_LIBRARIES} )
