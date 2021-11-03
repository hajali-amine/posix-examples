#include<sys/types.h>
#include<unistd.h> 
#include <sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h> 

/*  
     T
   /  \
  /    \
  T3    T1
         \
          \
           \
           T2
T (main thread): thread T waits for T1 and T3
T1 : waits for T2

Last Edit : 3/11/2021
Editor : Mohamed Fares Landoulsi
*/

void *fn2(void *arg)
{
	pthread_t tid = (pthread_t) arg ; 
	printf("I'm thread %u  waiting for %u to finish .. \n",tid,(void*)pthread_self()); 
	printf("this is the thread %u  I have finished ! \n",(void*)pthread_self());  
}


void *fn(void *arg)
{	
	pthread_t tid = (pthread_t) arg ;
	printf("I'm thread %u Waiting for %u to finish ..\n",tid,(void*)pthread_self()); 
	pthread_t thread2 ; 
	pthread_create(&thread2,NULL,fn2,(void*)pthread_self()); 
	pthread_join(thread2,NULL);
	
}


int main() 
{
	pthread_t thread1 ;
	pthread_t thread2 ; 
       	printf("this is the main thread %u\n",pthread_self()); 	
	(void) pthread_create(&thread1,NULL,fn,(void*)pthread_self()) ; 
	(void) pthread_create(&thread2,NULL,fn2,(void*)pthread_self()); 
	pthread_join(thread1,NULL); 
	pthread_join(thread2,NULL) ; 	

}
