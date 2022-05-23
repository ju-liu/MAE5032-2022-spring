PROJECT(vtk-demo)

CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

SET(VTK_DIR /Users/juliu/lib/VTK-8.2.0/lib/cmake/vtk-8.2)

FIND_PACKAGE(VTK COMPONENTS vtkCommonCore vtkCommonSystem
  vtkCommonMisc vtkCommonMath vtkIOCore vtkIOLegacy vtkIOXML REQUIRED)

INCLUDE_DIRECTORIES(${VTK_INCLUDE_DIRS})
ADD_EXECUTABLE( vtkdemo main.cpp )
TARGET_LINK_LIBRARIES( vtkdemo ${VTK_LIBRARIES} )

# EOF
