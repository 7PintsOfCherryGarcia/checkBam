#include <stdio.h>
#include <stdlib.h>
int MAGIC[30] = {0, 0, 31, -117, 8, 4, 0, 0, 0, 0,
                 0, -1, 6, 0, 66, 67, 2, 0, 27, 0,
                 3, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr,"Error: Please provide bamfile\n");
        fprintf(stderr,"./testBam <bamfile>\n");
        exit(-1);
    }
    FILE *bamfile;
    bamfile = fopen(argv[1],"rb");
    if (!bamfile) {
        fprintf(stderr,"Error: Could not open bamfile.\n");
        exit(-1);
    }

    char *file_bytestream = (char *)malloc(30*sizeof(char));
    if (!file_bytestream) {
        fprintf(stderr, "Error: Could not allocate data.\n");
        exit(-1);
    }
    fseek(bamfile, -30, SEEK_END);
    fread(file_bytestream, sizeof(char), 30,bamfile);
    for (int i = 0; i < 30; i++) {
        if (file_bytestream[i] != MAGIC[i]) {
            fprintf(stderr,"FAIL\n");
            fclose(bamfile);
            free(file_bytestream);
            exit(-1);
        }
    }
    fprintf(stdout,"PASS\n");
    fclose(bamfile);
    free(file_bytestream);
}
