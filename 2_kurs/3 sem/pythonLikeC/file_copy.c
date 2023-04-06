#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 4096

int main (int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <file_in> <file_out>\n", argv[0]);
        exit(1);
    }
    FILE* fin = NULL, *fout = NULL;
    fin = fopen(argv[1], "rb");
    if (fin == NULL) {
        perror("input file");
        exit(2);
    }
    fout = fopen(argv[2], "wbx");
    if (fout == NULL) {
        perror("output file");
        fclose(fin);
        exit(3);
    }
    char* buf = (char*)calloc(sizeof(char), BUFSIZE);
    if (buf == NULL) { perror("calloc"); fclose(fin); fclose(fout); exit(4); }
    size_t read_bytes = 0;
    while ((read_bytes = fread(buf, sizeof(char), BUFSIZE, fin)) > 0)
        fwrite(buf, sizeof(char), read_bytes, fout);
    fclose(fin); fclose(fout);
    return 0;
}
