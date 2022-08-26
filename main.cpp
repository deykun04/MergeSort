#include <iostream>
#include <ctime>

void generate (int arr[], int size) // generate number for array and print them
{
    for (size_t i=0; i < size; i++)
    {
        arr[i] = rand()%+99+1;
        std::cout << " " << arr[i]; 
    }
}
void Merge(int* arr,const int left,const int middle,const int right)
{
    int leftIndex = left;  // start index for left subarray
    int rightIndex = middle+1; // start index for right subarray
    int indexForNewArray = left;
    int sizeOfMassive =right;
    int resultArray[sizeOfMassive];
    while(leftIndex <= middle && rightIndex <= right)
    {
        if (arr[leftIndex] <= arr[rightIndex])
        {
            resultArray[indexForNewArray] = arr[leftIndex];
            leftIndex++;
            indexForNewArray++;
        }
        else
        {
            resultArray[indexForNewArray] = arr[rightIndex];
            rightIndex++;
            indexForNewArray++;
        }
    }
    while ( leftIndex <= middle)   // copying all elements from left subarray to temp as it is
    {
        resultArray[indexForNewArray] = arr[leftIndex];
            leftIndex++;
            indexForNewArray++;
    }
    while ( rightIndex <= right)   // copying all elements from right subarray to temp as it is
    {
        resultArray[indexForNewArray] = arr[rightIndex];
            rightIndex++;
            indexForNewArray++;
    }
    for (int i=left; i <= right; i++)
    {
        arr[i] = resultArray[i];
    }

}
void MergSort(int* arr, int left, int right)
{
    if ( left < right)
    {
        int middle;
        middle = (left+ right) / 2;
        MergSort(arr,left,middle);
        MergSort(arr,middle+1,right);
        Merge(arr,left,middle,right);
    }
    return;
}
int main ()
{ 
    srand(time(NULL));
    int size;
    std::cout << "Please, enter the size of your array:__ \b\b\b";
    std::cin>> size;
    int* arr = new int[size];
    std::cout << "Unsorted look of array: " << std:: endl;
    generate(arr,size);
    std::cout<<std::endl;
    int left = 0;
    int right = size-1;
    MergSort(arr,left,right);
    std::cout << "After sort: " <<std::endl;
    for (size_t i=0; i < size; i++)
    {
       std::cout << " " << arr[i]; 
    }
    delete[] arr;
}
