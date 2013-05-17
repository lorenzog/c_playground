#include <stdio.h>
#include <stdarg.h>

void myFun(char* format, ...) {
		va_list ap;
		int d;
//		double e;
		char c, *s;

		va_start(ap, format);
		while (*format)
				switch(*format++) {
						case 's':	// string
								s = va_arg(ap, char*);
								printf("stringa: %s\n", s);
								break;
						case 'd': 	// dec
								d = va_arg(ap, int);
								printf("intero: %d\n", d);
								break;
								/*
						case 'e':	// float promoted to double
								e = (double)va_arg(ap, double);
								printf("(float)double: %f\n", e);
								break;
								*/
						case 'c':	// char promoted to int
								c = (char)va_arg(ap, int);
								printf("(char)int: %c\n", c);
								break;
						default:
								perror("not implemented\n");
				}
		va_end(ap);
}
		 

int main (int argc, char* argv[]) {
		myFun("stringa");
		int i = 1;
		myFun(i);
		//double j = 0.5;
		//myFun(j);
}
