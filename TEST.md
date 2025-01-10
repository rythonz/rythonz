; Assemble and run the assembly code
nasm -f elf32 one.asm -o one.o
ld -m elf_i386 one.o -o one
./one

echo "B804000000BB01000000B900000000BA0E0000CD80B80100000031DBCD80" | xxd -r -p > two.bin
chmod +x two.bin
# ./two.bin will not work directly due to Exec format error

# Compile and run the C program to execute the machine code
gcc run_two.c -o run_two
./run_two

# Compile and Run the Rust Programs
rustc hello.rs -o hello
./hello

rustc info.rs -o info
./info
