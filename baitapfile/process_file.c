#include "process_file.h"

int file_size_count(char* file_cnt)
{
	fseek(file_cnt, 0, SEEK_END);
	long size_sc = ftell(file_cnt);
	fseek(file_cnt, 0, SEEK_SET);
	return size_sc;
}

void reading_file(char *pt_buf, long size, char * f_rd)
{
	fread(pt_buf, sizeof(char), size, f_rd);

}

void writting_file(char* pt_buf, long size, char* f_wr)
{
	fwrite(pt_buf, sizeof(char), size, f_wr);
}