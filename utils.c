#include "main.h"
/**
 * is_printable - char is printable
 * @c: char to be evaluated
 *
 * Return: 1 or 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * append_hexa_code - append ASCI
 * @buffer: array of chars
 * @i: index
 * @ascii_code: ASCI code
 * Return: always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'X';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i++] = map_to[ascii_code % 16];
	return (3);
}
/**
 * is_digit - char is digit
 * @c: char evaluated
 *
 * Return: 1 or 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
 * convert_size_number -num to be specified
 * @num: number
 * @size: num to be casted
 *
 * Return: casted value
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}
/**
 * convert_size_unsgnd - cast spec
 * @num: number
 * @size: casted num
 *
 * Return: value num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
