#include "function_pointers.h"

/**
  * int_index - ...
  * @array: ...
  * @size: ...
  * @cmp: ...
  *
  * Return: ...
  */
int int_index(int *array, int size, int (*cmp)(int))
{
int i;

for (i = 0; i < size; i++)
{
if (cmp(array[i]))
{
return (i);
}
}
return (-1);
}

