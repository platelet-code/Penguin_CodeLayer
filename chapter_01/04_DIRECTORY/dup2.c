#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int fd1 = open("1.txt", O_RDWR | O_CREAT, 0777);
    if (fd1 == -1) {
        perror("open");
        return -1;
    }

    int fd2 = open("2.txt", O_RDWR | O_CREAT, 0777);
    if (fd2 == -1) {
        perror("open");
        return -1;
    }

    printf("fd1 : %d, fd2: %d\n", fd1, fd2);

    // 将 fd1 的文件描述符复制到 fd2, 这会使 fd2 指向 fd1 指向的文件, 如果 fd2 已打开，则先关闭
    int fd3 = dup2(fd1, fd2);
    if (fd3 == -1) {
        perror("dup2");
        return -1;
    }

    char *str = "hello, dup2";
    // 将字符串写入 fd2 指向的文件（现在 fd1 和 fd2 指向同一个文件）
    int len = write(fd2, str, strlen(str));

    if (len == -1) {
        perror("write");  // 如果写入失败，则输出错误信息
        return -1;
    }

    // 打印操作后的文件描述符编号
    printf("fd1 : %d, fd2: %d, fd3: %d\n", fd1, fd2, fd3);

    // 关闭打开的文件描述符
    close(fd1);
    close(fd3);

    return 0;
}
