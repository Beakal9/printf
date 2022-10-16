include "main.h"
/**
 * print_unsigned - unsign int
 * @types: list of args
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: num of chars
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_args(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - octal notation
 * @types: types
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number of chars
 */
int print_octal(va_list types, char buffer[], 
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_args(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));

}
/**
 * print_hexadecimal - hexa nums
 * @types: list of args
 * @buffer: buffer
 * @flags: flags
 * @width: get widtg
 * @precision: precision
 * @size: size
 * Return: number of chars
 */
int print_hexadecimal(va_list types, char buffer[], 
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "012345789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - prints unsigned int
 * @types: list of args
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * @Return: number of chars
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "012345789ABCDEF", buffer,
				flags, 'x', width, precision, size));
}
/**
 * print_hexa - hexa nums
 * @types: types
 * @map_to: it maps
 * @buffer: buffer
 * @flags: flags
 * @flag_ch: flags calc
 * @width: width
 * @precision: precision
 * @size: size
 * Return: num of chars
 */
int print_hexada(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_args(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
