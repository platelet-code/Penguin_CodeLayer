#include <stdio.h>

int main()
{
    // int rename(const char *oldpath, const char *newpath)
    int ret = rename("dir_a", "dir_b");
    if (ret == -1) {
        perror("rename");
        return -1;
    }
    return 0;
}
