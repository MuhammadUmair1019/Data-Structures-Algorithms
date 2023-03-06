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
  // find single missing element in an sorted array
  // method 1
  int findSingleMissingEl1();
  // method 2
  int findSingleMissingEl2();

  // Find multiple missing element
  // method 1
  int findMultiMissingEl1();
  // method 2
  int findMultiMissingEl2();
};

void Array::setElements(int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << "Enter element: ";
    cin >> A[i];
  }
}

// Method -1
int Array::findSingleMissingEl1()
{
  int sum, s;
  sum = 0;

  for (int i = 0; i < length; i++)
  {
    sum += A[i];
  }

  s = (A[length - 1] * (A[length - 1] + 1)) / 2;

  cout << "Missing Element: " << s - sum;
}

// Method -2
int Array::findSingleMissingEl2()
{
  int l, diff;
  l = A[0];
  diff = l - 0;

  for (int i = 0; i < length; i++)
  {
    if (A[i] - i != diff)
    {
      cout << "Missing element: " << i + diff;
      break;
    }
  }
}

// Finding multiple missing elements
int Array::findMultiMissingEl1()
{
  int l, diff;
  l = A[0];
  diff = l - 0;

  for (int i = 0; i < length; i++)
    if (A[i] - i != diff)
      while (diff < A[i] - i)
      {
        cout << "Missing element: " << i + diff << endl;
        diff++;
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

// method -3 -- hash/bitset
int Array::findMultiMissingEl2()
{
  int max = Max();
  int *arr = new int[max];

  for (int i = 0; i < length; i++)
    arr[A[i]]++;

  for (int i = 1; i < max; i++)
    if (arr[i] == 0)
      cout << "Missing Element: " << i << endl;
}

int main()
{
  Array *arr = new Array(10, 5);

  // arr->findSingleMissingEl1();
  // arr->findSingleMissingEl2();
  // arr->findMultiMissingEl1();
  arr->findMultiMissingEl2();
}