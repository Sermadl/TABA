// Thread_sloppy.c
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <stdint.h>

int g_count = 0; // counter (critical section)
int g_nthd = 0; // num of threads
int g_worker_loop_cnt = 0;
int sloppy = 0;
 
static void *work(void* tno); // thread routine
pthread_mutex_t Lock;

int main(int argc, char *argv[]){
    pthread_t *thd_arr; // thread array
    int thd_cnt; // thread count

    if (argc < 4){
        fprintf(stderr, "%s parameter : nthread, worker_loop_cnt, sloppy\n", argv[0]);
        exit(-1);
    }
    // continue writing main ...

    // get num of threads and worker loop count 
    g_nthd = atoi(argv[1]); 
    g_worker_loop_cnt = atoi(argv[2]);
    sloppy = atoi(argv[3]);

    pthread_mutex_init(&Lock, NULL);

    // alloc memory for thread
    thd_arr = malloc(sizeof(pthread_t) * g_nthd); 

    for(thd_cnt=0; thd_cnt < g_nthd; thd_cnt++){
        // create thread
        assert(pthread_create(&thd_arr[thd_cnt], NULL, 
               work, (void*) (intptr_t) thd_cnt) == 0);
    }

    for(thd_cnt=0; thd_cnt < g_nthd; thd_cnt++){
        // join thread
        assert(pthread_join(thd_arr[thd_cnt], NULL) == 0);
    }
    printf("Complete\n");

}

static void *work(void* cnt){
    int thd_cnt = (int)(intptr_t)cnt;
    int i, j;
    int l_count = 0;

    for(i = 0; i < g_worker_loop_cnt/sloppy; i++){
	    for(j = 0; j < sloppy; j++)
		    l_count++;
	pthread_mutex_lock(&Lock);
        g_count += l_count;
	pthread_mutex_unlock(&Lock);

	l_count = 0;
    }
    
    printf("Thread number %d: %d \n", thd_cnt, g_count);
    return NULL;
}
