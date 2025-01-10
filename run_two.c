
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

int main() {
    // Machine code from 'two'
    unsigned char code[] = {
        0xB8, 0x04, 0x00, 0x00, 0x00,
        0xBB, 0x01, 0x00, 0x00, 0x00,
        0xB9, 0x00, 0x00, 0x00, 0x00, // Replace with actual address if needed
        0xBA, 0x0E, 0x00, 0x00, 0x00,
        0xCD, 0x80,
        0xB8, 0x01, 0x00, 0x00, 0x00,
        0x31, 0xDB,
        0xCD, 0x80
    };
    
    // Allocate executable memory
    void *exec = mmap(NULL, sizeof(code), PROT_READ | PROT_WRITE | PROT_EXEC,
                      MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (exec == MAP_FAILED) {
        perror("mmap");
        return EXIT_FAILURE;
    }
    
    // Copy machine code to executable memory
    memcpy(exec, code, sizeof(code));
    
    // Execute the machine code
    ((void (*)())exec)();
    
    // Cleanup
    munmap(exec, sizeof(code));
    
    return 0;
}