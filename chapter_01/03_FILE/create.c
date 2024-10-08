#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() 
{
    int fd = open("create.txt", O_RDWR | O_CREAT, 0777);
    if (fd == -1) {
        perror("open");
    }
    close(fd);
    return 0;
}


/*
int open(const char *pathname, int flags, mode_t mode)
    - pathname:
        - 要创建的文件的路径
    - flags: 对文件的操作权限和其他的设置
        - 必选项：O_RDONLY,  O_WRONLY, O_RDWR  这三个之间是互斥的
        - 可选项：O_CREAT 文件不存在，创建新文件
    - mode:
        - 八进制的数，表示创建出的新的文件的操作权限，比如：0775
*/
