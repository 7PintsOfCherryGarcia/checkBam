# checkBam
Check for truncated bam files

# GET
git clone https://github.com/7PintsOfCherryGarcia/checkBam.git

cd checkBam

# INSTALL
gcc -Wall -O3 -o checkBam checkBam.c

# RUN
./checkBam \<bamfile\>

This will print FAIL if bam file is truncated (EOF 28 byte marker is not present).
Otherwise, it will print PASS

checkBam loads the LAST 30 bytes of a given file and compares them to the following EOF signature:

{31, -117, 8, 4, 0, 0, 0, 0, 0, -1, 6, 0, 66, 67, 2, 0, 27, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0}

If any of the bytes do not match, the file is considered to be truncated.

# WARNING

A bam file may be corrupted and still have a correct EOF marker. checkBam does not detect any other types of corruption. 
