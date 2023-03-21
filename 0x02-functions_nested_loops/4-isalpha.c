#include "main.h"
/**
* _isalpha - Checks for alphabetic character .
* @c: The character to be checked.
*
* Return: 1 if character is lowercase, 0 otherwise.
*/
int _isalpha(int c)
{
	if (c >= 65 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	return (0);
}
