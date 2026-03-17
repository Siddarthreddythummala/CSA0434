#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd=open("test.txt",O_RDONLY);
    lseek(fd,0,SEEK_SET);

    struct stat s;
    stat("test.txt",&s);

    printf("File size: %ld\n",s.st_size);
    close(fd);
    return 0;
}
