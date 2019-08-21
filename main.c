void merge(int array, int p, int q, int r){
  int i, j , k = p;
  
  int n_1 = q - p + 1; int n_2 = r - q; // This allows you to sort the two subarray's
  
  int lowHalf = [];
  int highHalf = [];
  
  //Stores the values of the first half of the array in 1 sub array
  for(i = 0; i < q+1; i++){
    lowHalf[i] = array[k];
    k++;
  }
  
  //Stores the values of the second half of the array in 1 sub array
  for(j = 0; j < r + 1; j++){
    highHalf[j] = array[k];
    k++;
  }
  
  // Reseting the values of the integers
  int k = p;
  int i = 0;
  int j = 0;
  
  // Divides and sort the values within each of the two subarrays
  while( i < n_1 && j < n_2 ){
    if(lowHalf[k] < highHalf[j]){
      lowHalf[k] = array[i++];
    }
    else{
      highHalf[k] = array[j++];
    }
  }
  
  //Any leftover values get input into the subarray
  while(i < n_1){
    lowHalf[k] = array[i++];
  }
  
  //Any leftover values get input into the subarray
  while(j < n_2){
    highHalf[k] = array[j++];
  }
  
}

void mergeSort(int array[], int p, int r){
  if(r> p){
    int q = ((r - p)/2) + p;
    mergeSort(array, p, q);
    mergeSort(array, q + 1, r);
    merge(array, p, q, r);
  }
}

void print(int array[], int size){
  int i;
  for(i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(){
  int array = [23, 3, 6, 7, 12, 34, 8];
  int size = sizeof(array)/ sizeof(array[0]);
  
  printf("Given array is : \n");
  print(array, size);
  
  //sort using merge sort
  mergeSort(array, 0, size - 1);
  
  printf("Sorted array: \n"); 
  print(array, size); 
}
