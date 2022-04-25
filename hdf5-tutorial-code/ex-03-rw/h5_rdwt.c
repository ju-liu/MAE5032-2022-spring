/* 
 *  This example illustrates how to write and read data in an existing
 *  dataset.  It is used in the HDF5 Tutorial.
 */

#include "stdio.h"
#include "stdlib.h"
#include "hdf5.h"
#define FILE "SDS.h5"

int main() {

  hid_t       file_id, dataset_id;  /* identifiers */
  herr_t      status;
  int         i, j, k,  dset_data[5][6][4];
  int * vec1 = (int*)malloc(5*6*4*sizeof(int));

  for (j = 0; j < 5; j++) {
    for (i = 0; i < 6; i++){
      for (k = 0; k < 4; k++)
	dset_data[j][i][k] = 200 + 100*j + 10*i + k;
    }
  }     

  file_id = H5Fopen(FILE, H5F_ACC_RDWR, H5P_DEFAULT);


  dataset_id = H5Dopen(file_id, "/IntArray", H5P_DEFAULT);

  //  printf("original dset_data[0][0][0]:%2d\n", dset_data[0][0][0]);


  status = H5Dread(dataset_id, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT, dset_data);
  printf("read from h5 dset_data[3][1][2]:%2d\n", dset_data[3][1][2]);

  status = H5Dread(dataset_id, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT, vec1);
  printf("vec1(3,1,2):%2d\n", vec1[6*4*3+4*1+2]);

  status = H5Dwrite(dataset_id, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT, dset_data);

  status = H5Dread(dataset_id, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT, dset_data);
  printf("dset_data[0][0][0]:%2d\n", dset_data[3][1][2]);

  status = H5Dclose(dataset_id);
  status = H5Fclose(file_id);
}
