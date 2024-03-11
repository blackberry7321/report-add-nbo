#include <cstdint>
#include <fstream>
#include <sstream>

uint32_t my_ntohl(uint32_t a) {
        uint32_t a1 = (a & 0xFF000000) >> 24;
        uint32_t a2 = (a & 0x00FF0000) >> 8;
        uint32_t a3 = (a & 0x0000FF00) << 8;
        uint32_t a4 = (a & 0x000000FF) << 24;
        return a1 | a2 | a3 | a4;
}
uint32_t sum(uint32_t a, uint32_t b) {
	return a + b;
}

int main(int argc, char* argv[]) {

	std::string file1Name = argv[1];
	std::string file2Name = argv[2];
	
	FILE *file1 = fopen(file1Name.c_str(), "rb");
	if (file1 == NULL) {
		printf("failed to open the file!!\n");
		return 1;
	}
	FILE *file2 = fopen(file2Name.c_str(), "rb");
	if (file2 == NULL) {
		printf("failed to open the file!!\n");
		return 1;
	}


	uint32_t a, b;
	fread(&a, sizeof(a), 1, file1);
	fread(&b, sizeof(b), 1, file2);
	a = my_ntohl(a);
	b = my_ntohl(b);
	
	uint32_t c = sum(a, b);


	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a,a, b,b, c,c);


	fclose(file1);
	fclose(file2);

	return 0;
}

