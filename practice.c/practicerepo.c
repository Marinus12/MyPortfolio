#include <stdio.h>
#include <stdarg.h>

int _printf(const char* format, ...)
{
    int len = 0, i = 0, j = 0;
    char *str;
    va_list list;
    va_start(list, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 's')
            {
                str = va_arg(list, char *);
                for (j = 0; str[j] != '\0'; j++)
                {
                    putchar(str[j]);
                    len++;
    
                }
            }
        }
        else
        {
            putchar(format[i]);
            len++;
        }
    }
    va_end(list);

    return len;
}