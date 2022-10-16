#include "main.h"
/**
 * handle_write_char - prints string
 * @c: char type
 * @buffer: buffer
 * @flags: flags
 * @width: get width
 * @precision: precision
 * @size: size
 *
 * Return: size spec
 */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1] width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) + 
				write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1);
}
/**
 * write_number - print string
 * @is_negative: list of arg
 * @ind: char types
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 *
 * Return: size spec
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
				length, padd, extra_ch));
}
/**
 * write_num - number
 * @ind: index
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @prec: precision
 * @length: len
 * @padd: padd
 * @extra_c: char
 *
 * Return: char
 */
int write_num(int ind, char buffer[],
		int flags, int width, int prec
		int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length;
	if (extra_c != 0)
		length++;
	if (width > length)
	{

	}
}
