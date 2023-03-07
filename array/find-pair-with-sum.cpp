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

  // method -1
  // o(n2)
  void findSum1(int k);

  void findSum2(int k);

  void findSum3(int k);
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
void Array::findSum1(int k)
{
  for (int i = 0; i < length - 1; i++)
    for (int j = i + 1; j < length; j++)
      if (A[i] + A[j] == k)
      {
        cout << "{" << A[i] << "," << A[j] << "}";
      }
}

// method -3
// o(n)

void Array::findSum2(int k)
{
  int max = Max();
  int *arr = new int[max];

  for (int i = 0; i < length; i++)
  {
    if (arr[k - A[i]] != 0)
    {
      cout << "{" << A[i] << "," << k - A[i] << "}";
    }
    arr[A[i]]++;
  }
}

void Array::findSum3(int k)
{
  int i = 0, j = length - 1;
  while (i < j)
  {
    if (A[i] + A[j] == k)
    {
      cout << "{" << A[i] << "," << A[j] << "}";
      j--;
      i++;
    }
    else if (A[i] + A[j] < k)
      i++;
    else
      j--;
  }
}

int main()
{
  Array *arr = new Array(10, 5);

  arr->findSum1(10);
  // arr->findSum2(10);
  // arr->findSum3(10);
}