#include <sys/stat.h>
#include <stdio.h>

int main() 
{
    int ret = chmod("a.txt", 0777);
    if (ret == -1) {
        perror("chmod");
        return -1;
    }
    return 0;
}


/*
int chmod(const char *pathname, mode_t mode)
    参数:
        - pathname: 
            需要修改的文件的路径
        - mode:
            需要修改的权限值，八进制的数
    返回值:
        成功返回0，失败返回-1
*/

// 1. chmod 改变已有目录或文件的权限
// 2. umask 设置用户创建目录或文件时的默认权限
