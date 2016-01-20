#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    struct flock lock, savelock;
    fd = open("./test.log", O_RDWR);
    lock.l_type     = F_WRLCK;
    lock.l_start    = 0;
    lock.l_whence   = SEEK_SET;
    lock.l_len      = 0;
    savelock = lock;
    fcntl(fd, F_GETLK, &lock);
    if (lock.l_type == F_WRLCK)
    {
        printf("process %ld has a write lock already\n", (long int)(lock.l_pid));
        exit(1);
    }
    else if (lock.l_type == F_RDLCK)
    {
        printf("process %ld has a read lock already\n", (long int)(lock.l_pid));
        exit(1);
    }
    else
        fcntl(fd, F_SETLK, &savelock);
    pause();
}
