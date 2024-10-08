#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_file_num(const char* path);

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("%s path\n", argv[0]);
        return -1;
    }
    int num = get_file_num(argv[1]);
    printf("The number of common file is %d\n", num);
    return 0;
}

int get_file_num(const char* path)
{
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(0);
    }

    struct dirent *ptr;
    int total = 0;

    while ((ptr = readdir(dir)) != NULL) {
        char *dname = ptr->d_name;
        if (strcmp(dname, ".") == 0 || strcmp(dname, "..") == 0) {
            continue;
        }

        if (ptr->d_type == DT_DIR) {
            char new_path[256];
            sprintf(new_path, "%s/%s", path, dname);
            total += get_file_num(new_path);
        }

        if (ptr->d_type == DT_REG) {
            total++;
        }
    }

    closedir(dir);
    return total;
}


/*
struct dirent {
    ino_t d_ino;
    off_t d_off;
    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[256];
};

d_type:
    DT_BLK:块设备  DT_CHR:字符设备  DT_DIR:目录  DT_LNK:软连接
    DT_FIFO:管道   DT_REG:普通文件  DT_SOCK:套接字  DT_UNKNOWN:未知
*/
