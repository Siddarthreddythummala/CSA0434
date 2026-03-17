#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd=open("test.txt",O_CREAT|O_WRONLY,0644);
    write(fd,"Hello OS",8);
    close(fd);
    printf("File created and written\n");
    return 0;
}
