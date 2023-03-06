// All array operation
// Display
// Append
// Insert
// Delete
// LinearSearch
// BinarySearch
// Get
// Set
// Max
// Min
// Sum
// Avg
// Reverse --> method 1
// Reverse2 --> method 2
// insert element in sorted position
// Arrange negative elements on left and +ve right side of an array
// Merge two array
// Union
// Diff
// Inter

#include <iostream>
using namespace std;

class Array
{
private:
  int *A;
  int size;
  int length;
  void setElements(int n);
  void swap(int *x, int *y);

public:
  Array(int sz = 0, int n = 0)
  {
    size = sz;
    length = n;
    A = new int[sz];
    setElements(n);
  }

  void Display();
  void Append(int x);
  void Insert(int index, int x);
  int Delete(int index);
  int Get(int index);
  void Set(int index, int x);
  int Min();
  int Max();
  int Sum();
  float Avg();
  void Reverse();
  void Reverse2();
  void LeftShift();
  void RightShift();
  int LinearSerachV1(int key);
  int LinearSerachV2(int key);
  int LinearSerachV3(int key);
  int BinarySearch(int key);
  void InsertSortedEl(int x);
  int isSorted();
  void Rearrange();
  Array *Merge(Array arr2);
  Array *Union(Array arr2);
  Array *Inter(Array arr2);
  Array *Diff(Array arr2);
};

void Array::swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void Array::setElements(int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << "Enter element: ";
    cin >> A[i];
  }
}

void Array::Display()
{
  for (int i = 0; i < length; i++)
  {
    cout << A[i] << endl;
  }
}

// Append element in last index
void Array::Append(int x)
{
  if (length < size)
  {
    A[length++] = x;
  }
}

// Insert element in a specific index
void Array::Insert(int index, int x)
{
  if (index >= 0 && index <= length)
  {
    for (int i = length; i > index; i--)
    {
      A[i] = A[i - 1];
    }
    A[index] = x;
    length++;
  }
}

// Delete element from specfic index
int Array::Delete(int index)
{
  int x = -1;
  if (index >= 0 && index <= length)
  {
    x = A[index];
    for (int i = index; i < length; i++)
    {
      A[i] = A[i + 1];
    }
    length--;
    return x;
  }
  return x;
}

// Get element
int Array::Get(int index)
{
  if (index >= 0 && index <= length)
  {
    return A[index];
  }
  return -1;
}

// Set element
void Array::Set(int index, int x)
{
  if (index >= 0 && index <= length)
  {
    A[index] = x;
  }
}

// Get min elemnt from an array
int Array::Min()
{
  int min = A[0];
  for (int i = 0; i < length; i++)
  {
    if (A[i] < min)
    {
      min = A[i];
    }
  }
  return min;
}

// Get max elemnt from an array
int Array::Max()
{
  int max = A[0];
  for (int i = 0; i < length; i++)
  {
    if (A[i] > max)
    {
      max = A[i];
    }
  }
  return max;
}

// Sum of all the elements of an array

int Array::Sum()
{
  int sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum += A[i];
  }
  return sum;
}

// Find average of an array of element
float Array::Avg()
{
  return (float)Sum() / length;
}

// Reverse an array
void Array::Reverse()
{
  int *B = new int[length];
  for (int i = length - 1, j = 0; i >= 0; i--, j++)
  {
    B[j] = A[i];
  }

  for (int i = 0; i < length; i++)
  {
    A[i] = B[i];
  }
}

// Reverse method 2
void Array::Reverse2()
{
  for (int i = 0, j = length - 1; i < j; i++, j--)
  {
    swap(&A[i], &A[j]);
  }
}

void Array::LeftShift()
{
  int firstEl = A[0];
  for (int i = 0; i < length; i++)
  {
    A[i] = A[i + 1];
  }
  A[length - 1] = firstEl;
}

void Array::RightShift()
{
  int lastEl = A[length - 1];
  for (int i = length - 1; i > 0; i--)
  {
    A[i] = A[i - 1];
  }
}

// Linear serach version - 1
// O(n)
int Array::LinearSerachV1(int key)
{
  for (int i = 0; i < length; i++)
  {
    if (A[i] == key)
    {
      return i;
    }
  }
  return -1;
}

// Transposition technique
// O(n)
int Array::LinearSerachV2(int key)
{
  for (int i = 0; i < length; i++)
  {
    if (A[i] == key)
    {
      // move find index near to starting position
      // reduce the number of itration in next query if key is same
      swap(&A[i], &A[i - 1]);
      return i;
    }
  }
  return -1;
}

// Move to front/head technique
// O(1)
int Array::LinearSerachV3(int key)
{
  for (int i = 0; i < length; i++)
  {
    if (A[i] == key)
    {
      // move find index to starting position
      // in next if key is same then it will take only O(1) time
      swap(&A[i], &A[0]);
      return i;
    }
  }
  return -1;
}

// Binary serach
int Array::BinarySearch(int key)
{
  int l, h, mid;
  l = 0;
  h = length - 1;
  while (l <= h)
  {
    mid = (l + h) / 2;
    if (A[mid] == key)
      return mid;
    else if (key < A[mid])
      h = mid - 1;
    else
      l = mid + 1;
  }

  return -1;
}

// Insert element in sorted position
void Array::InsertSortedEl(int x)
{
  int i = length - 1;
  while (A[i] > x)
  {
    A[i + 1] = A[i];
    i--;
  }
  A[i + 1] = x;
  length++;
}

// Check is sorted array
int Array::isSorted()
{
  for (int i = 0; i < length; i++)
    if (A[i] < A[i + 1])
      return 0;
  return -1;
}

// Move all -ve number on left hand side and +ve right hand side
void Array::Rearrange()
{
  int i = 0;
  int j = length - 1;
  while (i < j)
  {
    while (A[i] < 0)
      i++;
    while (A[i] >= 0)
      j--;
    if (i < j)
      swap(&A[i], &A[j]);
  }
}

// Merge two arrays
Array *Array::Merge(Array arr2)
{
  int i, j, k;
  i = j = k = 0;

  int *arr3 = new int[arr2.length + length];

  while (i < length && j < arr2.length)
  {
    if (A[i] < arr2.A[j])
      arr3[k++] = A[i++];
    else
      arr3[k++] = arr2.A[j++];
  }
  for (; i < length; i++)
    arr3[k++] = A[i];
  for (; j < arr2.length; j++)
    arr3[k++] = arr2.A[j];

  for (int i = 0; i < arr2.length + length; i++)
  {
    cout << arr3[i];
  }
}

Array *Array::Union(Array arr2)
{
  int i, j, k;
  i = j = k = 0;
  int *arr3 = new int[length + arr2.length];

  while (i < length && j < arr2.length)
  {
    if (A[i] < arr2.A[j])
      arr3[k++] = A[i++];
    else if (arr2.A[j] < A[i])
      arr3[k++] = arr2.A[j++];
    else
    {
      arr3[k++] = A[i++];
      j++;
    }
  }

  for (; i < length; i++)
  {
    arr3[k++] = A[i];
  }

  for (; j < arr2.length; j++)
  {
    arr3[k++] = arr2.A[j];
  }

  for (int i = 0; i < k; i++)
  {
    cout << arr3[i] << endl;
  }
}

Array *Array::Inter(Array arr2)
{
  int i, j, k;
  i = j = k = 0;

  int *arr3 = new int[length + arr2.length];

  while (i < length && j < arr2.length)
  {
    if (A[i] < arr2.A[j])
      i++;
    else if (arr2.A[j] < A[i])
      j++;
    else
    {
      arr3[k++] = A[i++];
      j++;
    }
  }

  for (int x = 0; x < k; x++)
  {
    cout << arr3[x] << endl;
  }
}

Array *Array::Diff(Array arr2)
{
  int i, j, k;
  i = j = k = 0;

  int *arr3 = new int[length + arr2.length];

  while (i < length && j < arr2.length)
  {
    if (A[i] < arr2.A[j])
      arr3[k++] = A[i++];
    else if (arr2.A[j] < A[i])
      j++;
    else
    {
      i++;
      j++;
    }
  }

  for (; i < length; i++)
    arr3[k++] = A[i];

  for (int x = 0; x < k; x++)
  {
    cout << arr3[x] << endl;
  }
}

int main()
{
  Array *arr;
  Array *arr3;
  int sz, num;

  cout << "Enter size of an array: ";
  cin >> sz;

  cout << "Enter elements of an array: ";
  cin >> num;

  // arr = new Array(sz, num);

  // cout << "Enter size of second array: ";
  // cin >> sz;

  // cout << "Enter elements of second array: ";
  // cin >> num;

  // Array arr2 = Array(sz, num);
  // arr->Inter(arr2);
  // arr->Diff(arr2);
  // arr->Union(arr2);
  // arr->Merge(arr2);

  // arr->Append(20);
  // arr->Insert(2, 20);
  // arr->Delete(2);
  // arr->LeftShift();
  // arr->Reverse2();
  // cout << arr->BinarySearch(30) << endl;
  // arr->InsertSortedEl(30);
  arr->Display();
}
