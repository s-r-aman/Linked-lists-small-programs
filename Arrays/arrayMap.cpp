#include <iostream>

typedef int (*FUNC_PTR)(int);

template <typename type, int size>
class Array
{
public:
  type array[size];

  int getSize()
  {
    return size;
  }

  type *map(FUNC_PTR func)
  {
    static type tempArray[size];
    for (int i = 0; i < size; i++)
    {
      type tempVar = func(array[i]);
      tempArray[i] = tempVar;
    };
    return tempArray;
  }
};

int doubleNumber(int var)
{
  return var * 2;
}

int main()
{
  Array<int, 5> myarray = {1, 2, 3, 4, 5};
  FUNC_PTR doubleArray = &doubleNumber;

  int *pointer = myarray.map(doubleArray);

  for (int i = 0; i < 5; i++)
  {
    std::cout << *(pointer + i) << "\t";
  }

  return 0;
}