#ifndef mysortguard
#define mysortguard

#include <algorithm>

template <class T>
void swap(T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

template<class T>
void MyBubbleSort(T vec){
    for(int i = 0; i < vec.size()-1; i++){
        for(int j = 0; j < vec.size()-1-i; j++){
            if(vec[j] > vec[j+1])
                swap(vec[j], vec[j+1]);
        }
    }
}

template<class T>
int partition(T arr,int lowIndex,int highIndex){
  auto pivot=arr[highIndex];
  int i=lowIndex-1;
  for(int j=lowIndex;j<=highIndex;j++){
    if(arr[j]<pivot){
        i++;
        swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[highIndex]);
  return (i+1);
}

template<class T>
void MyQuickSort_(T arr,int lowIndex,int highIndex){
  if(lowIndex>=highIndex) return;
  int part=partition(arr,lowIndex,highIndex);
  MyQuickSort_(arr,lowIndex,part-1);
  MyQuickSort_(arr,part+1,highIndex);
}

template<class T>
void MyQuickSort(T vec){
   MyQuickSort_(vec, 0, vec.size());
}

template<class T>
void heapify(T arr, int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
 
template<class T>
void heapSort(T vec){
    int n = vec.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(vec, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

template<class T>
void STDSort(T vec){
    std::sort(vec.begin(), vec.end());
}

#endif