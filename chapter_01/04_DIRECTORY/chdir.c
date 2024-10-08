#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    char buf[128];
    getcwd(buf, sizeof(buf));
    printf("The current work directory is %s\n", buf);

    int ret = chdir("work_dir");
    if (ret == -1) {
        perror("chdir");
        return -1;
    }

    int fd = open("chdir.txt", O_CREAT | O_RDWR, 0664);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    close(fd);

    char buf1[128];
    getcwd(buf1, sizeof(buf1));
    printf("The current work directory is %s\n", buf1);

    return 0;
}


/*
int chdir(const char *path);
    作用:
        修改进程的工作目录
    path:
        需要修改的工作目录


char *getcwd(char *buf, size_t size);
    作用:
        获取当前工作目录
    - buf:
        存储的路径, 指向的是一个数组(传出参数)
    - size:
        数组的大小
    返回值:
        返回的指向的一块内存，这个数据就是第一个参数
*/
