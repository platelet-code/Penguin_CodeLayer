#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int fd = open("a.txt", O_RDWR | O_CREAT, 0777);
    if (fd == -1) {
        perror("open");
        return -1;
    }
    // 复制一个新的文件描述符, 从空闲的文件描述符表中找一个最小的, 作为新的拷贝的文件描述符
    int fd1 = dup(fd);

    if (fd1 == -1) {
        perror("dup");
        return -1;
    }

    printf("fd: %d, fd1: %d\n", fd, fd1);
    close(fd);

    char *str = "hello, world";
    int ret = write(fd1, str, strlen(str));
    if (ret == -1) {
        perror("write");
        return -1;
    }
    close(fd1);
    return 0;
}
