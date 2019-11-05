# checkBam
Check for truncated bam files

# get
git clone https://github.com/7PintsOfCherryGarcia/checkBam.git

cd checkBam

# INSTALL
gcc -Wall -O3 -o checkBam checkBam.c

# RUN
./checkBam <bamfile>

This will print FAIL if bam file is truncated (EOF 30 byte marker is not present).
Otherwise, it will print PASS

