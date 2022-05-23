#include "vtkIntArray.h"
#include "vtkDoubleArray.h"
#include "vtkPolyData.h"
#include "vtkCellData.h"
#include "vtkCellArray.h"
#include "vtkPointData.h"
#include "vtkTetra.h"
#include "vtkGenericCell.h"
#include "vtkUnstructuredGrid.h"
#include "vtkUnstructuredGridWriter.h"
#include "vtkXMLUnstructuredGridWriter.h"
#include "vtkXMLUnstructuredGridReader.h"
#include "vtkXMLPolyDataWriter.h"
#include "vtkXMLGenericDataObjectReader.h"

void add_int_PointData( vtkPointSet * const &grid_w,
    const std::vector<int> &ptdata, const std::string &dataname );

void add_int_CellData( vtkPointSet * const &grid_w,
    const std::vector<int> &cldata, const std::string &dataname );

int main(int argc, char * argv[])
{
  const bool isXML = false;
  const std::string filename("tet-linear");

  vtkUnstructuredGrid * grid_w = vtkUnstructuredGrid::New();

  vtkPoints * ppt = vtkPoints::New();
  ppt->SetDataTypeToDouble();

  ppt -> InsertPoint(0, 0.0, 0.0, 0.0);
  ppt -> InsertPoint(1, 1.0, 0.0, 0.0);
  ppt -> InsertPoint(2, 0.0, 1.0, 0.0);
  ppt -> InsertPoint(3, 0.0, 0.0, 1.0);
  ppt -> InsertPoint(4, 1.0, 1.0, 1.0);

  grid_w -> SetPoints(ppt);
  ppt -> Delete();

  std::vector<int> IEN = {0, 1, 2, 3, 1, 2, 3, 4};

  vtkCell * cl = vtkTetra::New();
  for(int ii=0; ii<2; ++ii)
  {
    for(int jj=0; jj<4; ++jj)
      cl->GetPointIds()->SetId( jj, IEN[4*ii + jj] );

    grid_w->InsertNextCell( cl->GetCellType(), cl->GetPointIds() );
  }

  cl -> Delete();

  std::vector<int> node_id = {1,2,3,4,5};
  add_int_PointData(grid_w, node_id, "GlobalNodeID");

  std::vector<int> cell_id = {1,2};
  add_int_CellData(grid_w, cell_id, "GlobalCellID");

  if( isXML )
  {
    vtkXMLUnstructuredGridWriter * writer = vtkXMLUnstructuredGridWriter::New();
    std::string name_to_write(filename);
    name_to_write.append(".vtu");
    writer -> SetFileName( name_to_write.c_str() );

    writer->SetInputData(grid_w);
    writer->Write();
    writer->Delete();
  }
  else
  {
    vtkUnstructuredGridWriter * writer = vtkUnstructuredGridWriter::New();
    std::string name_to_write(filename);
    name_to_write.append(".vtk");
    writer -> SetFileName( name_to_write.c_str() );

    writer->SetInputData(grid_w);
    writer->Write();
    writer->Delete();
  }


  grid_w->Delete();
  return 0;
}

void add_int_PointData( vtkPointSet * const &grid_w,
    const std::vector<int> &ptdata, const std::string &dataname )
{
  vtkIntArray * data = vtkIntArray::New();
  data -> SetNumberOfComponents(1);
  data -> SetName(dataname.c_str());

  for(unsigned int ii=0; ii<ptdata.size(); ++ii)
    data -> InsertComponent(ii, 0, ptdata[ii]);

  grid_w -> GetPointData() -> AddArray( data );
  data -> Delete();
}

void add_int_CellData( vtkPointSet * const &grid_w,
    const std::vector<int> &cldata, const std::string &dataname )
{
  vtkIntArray * data = vtkIntArray::New();
  data -> SetNumberOfComponents(1);
  data -> SetName(dataname.c_str());

  for(unsigned int ii=0; ii<cldata.size(); ++ii)
    data -> InsertComponent(ii, 0, cldata[ii]);

  grid_w -> GetCellData() -> AddArray( data );
  data -> Delete();
}

// EOF
