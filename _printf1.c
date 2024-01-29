#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format) {
        if (*format == '%') {
            format++;

            switch (*format) {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str) {
                        count += putchar(*str);
                        str++;
                    }
                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    count += printf("%d", num);
                    break;
                }
                case '%':
                    count += putchar('%');
                    break;
                default:
                    // Ignore unsupported format specifiers
                    break;
            }
        } else {
            count += putchar(*format);
        }

        format++;
    }

    va_end(args);

    return count;
}

int main() {
    int number = 42;
    _printf("The answer is %d. Character: %c\n", number, 'A');
    return 0;
}

