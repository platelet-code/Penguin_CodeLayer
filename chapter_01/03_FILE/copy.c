#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() 
{
    int srcfd = open("english.txt", O_RDONLY);
    if (srcfd == -1) {
        perror("open");
        return -1;
    }

    int destfd = open("cpy.txt", O_WRONLY | O_CREAT, 0664);
    if (destfd == -1) {
        perror("open");
        return -1;
    }

    char buf[1024] = {0};
    int len = 0;
    while ((len = read(srcfd, buf, sizeof(buf))) > 0) {
        write(destfd, buf, len);
    }
    
    close(destfd);
    close(srcfd);
    return 0;
}


/*  
ssize_t read(int fd, void *buf, size_t count)
    - fd:
        文件描述符，open得到的，通过这个文件描述符操作某个文件
    - buf:
        需要读取数据存放的地方，数组的地址（传出参数）
    - count:
        指定的数组的大小


ssize_t write(int fd, const void *buf, size_t count)
    - fd:
        文件描述符，open得到的，通过这个文件描述符操作某个文件
    - buf:
        要往磁盘写入的数据，数据
    - count:
        要写的数据的实际的大小
*/
