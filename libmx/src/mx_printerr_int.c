#include "../inc/libmx.h"

void mx_printerr_int(int n) {
	int num[30];
	int lenght = 0;
	char c;
	if (n < 0) mx_printerr("-");
	else if (n == 0) mx_printerr("0");
	while (n != 0)
	{
		if (n % 10 < 0) 
			num[lenght] = -(n % 10);
		else 
			num[lenght] = n % 10;
		lenght++;
		n /= 10;
	}
    for(int i = lenght - 1; i >= 0;i--) {
		c = 48 + num[i];
        mx_printerr(&c);
	}
}

