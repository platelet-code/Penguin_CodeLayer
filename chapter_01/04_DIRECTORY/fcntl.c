#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int fd = open("1.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    int flag = fcntl(fd, F_GETFL);
    if (flag == -1) {
        perror("fcntl");
        return -1;
    }

    flag |= O_APPEND;

    int ret = fcntl(fd, F_SETFL, flag);
    if (ret == -1) {
        perror("fcntl");
        return -1;
    }

    char *str = "nihao";
    write(fd, str, strlen(str));
    close(fd);

    return 0;
}


/*
int fcntl(int fd, int cmd, ...)
    fd: 表示需要操作的文件描述符
    cmd: 表示对文件描述符进行如何操作
        - F_DUPFD:复制文件描述符, 复制的是第一个参数fd, 得到一个新的文件描述符（返回值）
            int ret = fcntl(fd, F_DUPFD);

        - F_GETFL:获取指定的文件描述符文件状态flag
            获取的flag和我们通过open函数传递的flag是一个东西。

        - F_SETFL: 设置文件描述符文件状态 flag
            必选项: O_RDONLY, O_WRONLY, O_RDWR 不可以被修改
            可选性:
                O_APPEND 表示追加数据
                NONBLOK 设置成非阻塞
*/
