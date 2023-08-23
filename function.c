#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    char c;

    while (*format) {
        if (*format == '%') {
            format++;  // Move past the '%'

            switch (*format) {
                case 'c':
                    c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                
                case 's':
                    char *str = va_arg(args, char*);
                    while (*str) {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;

                case '%':
                    putchar('%');
                    count++;
                    break;
                
                default:
                    // Ignore unsupported format specifiers
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}

int main() {
    _printf("Hello, %s! This is a test: %c and %%\n", "John", 'A');
    return 0;
}
