#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *callback(void *arg)
{
    printf("child thread id: %ld\n", pthread_self());
    return NULL;
}

int main()
{
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, callback, NULL);

    if (ret != 0) {
        char *errstr = strerror(ret);
        printf("error: %s\n", errstr);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d\n", i);
    }
    
    printf("tid: %ld, main thread id: %ld\n", tid, pthread_self());

    pthread_exit(NULL);

    printf("main thread exit\n");

    return 0;
}


// void pthread_exit(void *retval);
//     功能：终止一个线程，在哪个线程中调用，就表示终止哪个线程
//     参数：
//         retval:需要传递一个指针，作为一个返回值，可以在 pthread_join() 中获取到。

// pthread_t pthread_self(void);
//     功能：获取当前的线程的线程 ID

// int pthread_equal(pthread_t t1, pthread_t t2);
//     功能：比较两个线程ID是否相等
