#include <iostream>

using namespace std;

void Print(const int* const pArray, size_t arraySize)
{
    cout << "[";
    for(size_t i = 0; i < arraySize; ++i)
        cout << pArray[i] << " ";
    cout << "]" << endl;
}

int* ApplyAll(const int* const pArray0, size_t arraySize0, const int* const pArray1, size_t arraySize1)
{
    //alloc mem
    int* pResultArray {nullptr};
    size_t resultArraySize = arraySize0 * arraySize1;
    pResultArray = new int[resultArraySize];
    //int resultArrayNdx = 0;
    
    for(size_t i = 0, resultArrayNdx = 0; i < arraySize0; ++i)
        for (size_t j = 0; j < arraySize1; ++j, ++resultArrayNdx)
        {
            *pResultArray++ = pArray0[i] * pArray1[j];
            //pResultArray[resultArrayNdx] = pArray0[i] * pArray1[j];
            //resultArrayNdx++;
        }
            
    return pResultArray-resultArraySize;
}

int main()
{
    
    
    int array1[] {1, 2, 3};
    int array1Quantity = (sizeof array1)/(sizeof array1[0]);
    int array2[] {10, 20, 30, 40};
    int array2Quantity = (sizeof array2)/(sizeof array2[0]);
    
    int* resultArray {nullptr};    
    
    cout << "sizeof array1: " << sizeof array1 << endl;
    
	cout << "array 1:" << endl;
    Print(array1, array1Quantity);
    cout << "array 2:" << endl;
    Print(array2, array2Quantity);
    
    resultArray = ApplyAll(array1, array1Quantity, array2, array2Quantity);
    cout << "print result:" << endl;
    
    cout << "sizeof resultArray: " << sizeof resultArray << endl;
    
    Print(resultArray, array1Quantity * array2Quantity);
    
    //delete memory
    delete [] resultArray;
	return 0;
}
