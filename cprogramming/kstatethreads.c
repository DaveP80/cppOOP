#include <stdio.h>       /* standard I/O routines                 */
#include <pthread.h>     /* pthread functions and data structures */
#include <unistd.h>
/* function to be executed by the new thread 
https://www.cs.kent.edu/~ruttan/sysprog/lectures/multi-thread/multi-thread.html
To Run: gcc kstatethreads.c -o pthread_create -lpthread
*/
void*
do_loop(void* data)
{
    int i;			/* counter, to print numbers */
    int j;			/* counter, for delay        */
    int me = *((int*)data);     /* thread identifying number */
    printf("I am %d, mypid is %d\n", me, getpid());
    for (i=0; i<10; i++) {
	for (j=0; j<500000; j++) /* delay loop */
	    ;
        printf("'%d' - Got '%d'\n", me, i);
    }

    /* exit the thread */
    pthread_exit(NULL);
}

/* like any C program, program's execution begins in main */
int
main(int argc, char* argv[])
{
    int        thr_id;         /* thread ID for the newly created thread */
    pthread_t  p_thread;       /* thread's structure                     */
    int        a         = 1;  /* thread 1 identifying number            */
    int        b         = 2;  /* thread 2 identifying number            */
    int        c         = 3;  /* thread 2 identifying number            */

    /* create a new thread that will execute 'do_loop()' */
    thr_id = pthread_create(&p_thread, NULL, do_loop, (void*)&a);
    thr_id = pthread_create(&p_thread, NULL, do_loop, (void*)&b);
    /* run 'do_loop()' in the main thread as well */
    do_loop((void*)&c);
    
    /* NOT REACHED */
    return 0;
}