#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>
#include <cstdlib>

int main(int argc, char **argv){
	if(argc !=3){
		printf("Input only two files");
		exit(1);
	}
	
	FILE *f1 = fopen(argv[1], "rb");
	FILE *f2 = fopen(argv[2], "rb");
	
	if(f1 == NULL){
		perror("File 1 occurs error: ");
		exit(1);
	}

	if(f2 ==NULL){
		perror("File 2 occurs error: ");
		exit(1);
	}
	
	uint32_t f1_value, f2_value, result;

	// fread(&f1_value,sizeof(uint32_t),1, f1);라고하면 sizeof(uint32_t,1,f1) 만큼 1 번 읽는다는 것
	// 총 바이트 수를 반환하기 위해서  fread(&f1_value,1, sizeof(uint32_t), f1);라고 하자.
	// fread() 함수는 읽기에 성공한 전체 항목의 수를 리턴하며, 오류가 발생하거나 count에 도달하기 전에 파일 끝이면 count보다 적을 수 있습니다.
	int size_1 = fread(&f1_value,1, sizeof(uint32_t), f1);
	int size_2 = fread(&f1_value,1, sizeof(uint32_t), f1);

	if(size_1 < 4){
		printf("File1 is too short");
		exit(1);
	}

	if(size_2 < 4){
		printf("File2 is too short");
		exit(1);
	}
	
	fclose(f1);
	fclose(f2);
	
	f1_value = ntohl(f1_value);
	f2_value = ntohl(f2_value);
	result = f1_value + f2_value;
	
	printf("%d(%#x) + %d(%#x) = %d(%#x)", f1_value, f1_value, f2_value, f2_value, result, result);
	return 0;
}
