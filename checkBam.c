#include <stdio.h>
#include <stdlib.h>

//Value of last 30 bytes (EOF marker) that a non truncated bam file must have
int MAGIC[30] = {0, 0, 31, -117, 8, 4, 0, 0, 0, 0,
                 0, -1, 6, 0, 66, 67, 2, 0, 27, 0,
                 3, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr,"Error: Please provide bamfile\n");
        fprintf(stderr,"./testBam <bamfile>\n");
        exit(-1);
    }
    // Open bam file
    FILE *bamfile;
    bamfile = fopen(argv[1],"rb");
    if (!bamfile) {
        fprintf(stderr,"Error: Could not open bamfile.\n");
        fprintf(stderr,"./testBam <bamfile>\n");
        exit(-1);
    }

    // Allocate memory for EOF marker
    char *file_bytestream = (char *)malloc(30*sizeof(char));
    if (!file_bytestream) {
        fprintf(stderr, "Error: Could not allocate data.\n");
        fprintf(stderr,"./testBam <bamfile>\n");
        exit(-1);
    }

    // Read last 30 bytes of bamfile
    fseek(bamfile, -30, SEEK_END);
    int read = fread(file_bytestream, sizeof(char), 30,bamfile);
    if (read != 30) {
        fprintf(stderr, "Error: Filed to read from file.\n");
        fprintf(stderr,"./testBam <bamfile>\n");
        exit(-1);
    }

    // Loop over last 30 bytes and compare with corresponfing vales
    for (int i = 0; i < 30; i++) {
        if (file_bytestream[i] != MAGIC[i]) {
            fprintf(stdout,"FAIL\n");
            fclose(bamfile);
            free(file_bytestream);
            exit(-1);
        }
    }
    fprintf(stdout,"PASS\n");
    fclose(bamfile);
    free(file_bytestream);
}
