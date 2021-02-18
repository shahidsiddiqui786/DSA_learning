#include<stdio.h>

unsigned long hash(unsigned char *str)
    {
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }

static unsigned long sdbm(str)
    unsigned char *str;
    {
        unsigned long hash = 0;
        int c;

        while (c = *str++)
            hash = c + (hash << 6) + (hash << 16) - hash;

        return hash;
    }

 unsigned long
    hash2(unsigned char *str)
    {
	unsigned int hash = 0;
	int c;

	while (c = *str++)
	    hash += c;

	return hash;
    }

int main() {

    char str[40];
    scanf("%s",str);
    printf("%ld\n",hash(str));
    printf("%ld",hash2(str));

}