#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "process_file.h"

int main()
{
	errno_t err1, err2;
	FILE* fsc, * fdn;
	char* buf = NULL;
	err1 = fopen_s(&fsc, "1.jpg", "rb");
	if (err1 != 0)
	{
		printf_s("Error! openning file!");
		exit(0);
	}
	err2 = fopen_s(&fdn, "2.jpg", "wb");
	if (err2 != 0)
	{
		printf_s("Error! openning file!");
		exit(0);
	}

	long size_sc = file_size_count(fsc);
	buf = (char*)calloc(size_sc, sizeof(char));
	
	reading_file(buf, size_sc, fsc);
	writting_file(buf, size_sc, fdn);
	
	fclose(fsc);
	fclose(fdn);

	printf_s("2 bytes dau: %x, %x\r\n", *buf,*(buf +1));
	printf_s("2 bytes cuoi: %x, %x\r\n", *(buf +size_sc -1), *(buf + size_sc));
	free(buf);

	return 0;
}