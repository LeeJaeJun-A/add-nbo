#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>
#include <cstdlib>

int main(int argc, char **argv){
	FILE *f1 = fopen(argv[1], "rb");
	FILE *f2 = fopen(argv[2], "rb");

	if(f1 == NULL or f2 ==NULL){
		fputs("File Error" ,stderr);
		exit(1);
	}
	
	uint32_t f1_value, f2_value, result;

	fread(&f1_value,sizeof(uint32_t),1, f1);
	fread(&f2_value,sizeof(uint32_t),1, f2);

	fclose(f1);
	fclose(f2);
	
	f1_value = ntohl(f1_value);
	f2_value = ntohl(f2_value);
	result = f1_value + f2_value;
	
	printf("%d(%#x) + %d(%#x) = %d(%#x)", f1_value, f1_value, f2_value, f2_value, result, result);
	return 0;
}
