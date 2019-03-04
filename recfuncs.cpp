#include "recfuncs.h"
#include <stdlib.h>

int calc_array_size(int n){
  if(n == 0) { return 1; }
  return 2*calc_array_size(n-1);
}
int convert_to_binary(int n){
  if(n == 0) { return 0; }
  return (n%2)+10*convert_to_binary(n/2);
}

int* create_array(int size){
  if(size > 0)
  {
    int* start = (int*)malloc(sizeof(int));
    start[0] = -1;
    help_create(size, 1, start);
    return start;
  }
  return 0;
}

void help_create(int size, int i, int* start) {
  if(i < size) {
    int* new_address = start + i;
    new_address = (int*)malloc(sizeof(int));
    start[i] = -1;
    help_create(size, i+1, start);

    // Useless code to remove warning
    int* start_p = new_address;
    new_address = start_p;
  }
}

int calc_factorial(int n){
  if(n == 0) { return 1; }
  return n*calc_factorial(n-1);
}

void calc_sums(int* nums,int size, int* out_arr, int* out_arr_bin)
{
  thx(nums, size-1, out_arr,out_arr_bin,0,0,0);
}

int thx(int* nums,int size, int* out_arr, int* out_arr_bin, int i, int index, int sum)
{
  if(i>size)
  {
    out_arr[index]=sum;
    out_arr_bin[index]=convert_to_binary(sum);
    return ++index;
  }

  int index1=thx(nums,size,out_arr,out_arr_bin,i+1,index,sum+nums[i]);
  return thx(nums,size,out_arr,out_arr_bin,i+1,index1,sum);
}

struct CalculationResults perform_calculations(int* arr, int n){
  struct CalculationResults res;
  res.no_of_nums = n;
  res.no_of_sums = calc_array_size(n);
  res.num_factorials = create_array(n);
  for (int i = 0; i < n; i++)
  {
      res.num_factorials[i] = calc_factorial(arr[i]);
  }
  res.sums = create_array(res.no_of_sums);
  res.binary_sums = create_array(res.no_of_sums);
  calc_sums(arr, n, res.sums, res.binary_sums);
  return res;
}
