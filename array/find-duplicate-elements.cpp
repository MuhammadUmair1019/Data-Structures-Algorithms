#include <iostream>
using namespace std;

class Array
{
private:
  int *A;
  int size;
  int length;
  void setElements(int n);

public:
  Array(int sz = 0, int n = 0)
  {
    size = sz;
    length = n;
    A = new int[sz];
    setElements(n);
  }

  int Max();

  // find duplicates
  void findDuplicateEl1();

  // find duplicates + count
  void findDuplicateEl2();

  // find duplicates + count (hashing method)
  void findDuplicateEl3();
  // find duplicates + count in unsorted array
  void findDuplicateEl4();
};

void Array::setElements(int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << "Enter element: ";
    cin >> A[i];
  }
}

int Array::Max()
{
  int max = A[0];
  for (int i = 0; i < length; i++)
    if (A[i] > max)
      max = A[i];
  return max;
}

// method -1
void Array::findDuplicateEl1()
{
  int lastDuplicate;

  for (int i = 0; i < length; i++)
  {
    if (A[i] == A[i + 1] && A[i] != lastDuplicate)
    {
      cout << "Duplicate element: " << A[i];
      lastDuplicate = A[i];
    }
  }
}

// method -2 (Duplicates + count)
void Array::findDuplicateEl2()
{
  int i, j;
  for (int i = 0; i < length; i++)
  {
    if (A[i] == A[i + 1])
    {
      j = i + 1;
      while (A[j] == A[i])
        j++;
      cout << "Duplicate element: " << A[i] << "count: " << j - 1;
      i = j - 1;
    }
  }
}

// method -3 (hashing)
// sorted array

void Array::findDuplicateEl3()
{
  int max = Max();
  int *arr = new int[max];

  for (int i = 0; i < length; i++)
    arr[A[i]]++;

  for (int i = 0; i < max; i++)
    if (arr[i] > 1)
      cout << "Duplicate element: " << i << "=" << arr[i];
}

// find element in unsorted array
void Array::findDuplicateEl4()
{
  int count;

  for (int i = 0; i < length - 1; i++)
  {
    count = 0;
    if (A[i] != -1)
    {
      for (int j = i + 1; j < length; j++)
      {
        if (A[i] == A[j])
        {
          count++;
          A[i] = -1;
        }
      }
      if (count > 1)
        cout << A[i] << count;
    }
  }
}

int main()
{
  Array *arr = new Array(10, 5);

  arr->findDuplicateEl1();
  // arr->findDuplicateEl2();
  // arr->findDuplicateEl3();
  // arr->findDuplicateEl4();
}