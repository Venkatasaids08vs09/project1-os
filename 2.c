#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

void* f1(void *fd); //declaration of f1
void* f2(void *fd); //declaration of f2
int flag[2];
int t=0; // turn is t

int main()
{   
	char bp1[20] = "dream big";  // for process 1
	char bp2[20] = "Welcome to Lpu"; //for process 2
	 
	int file1 = open("venkat.txt",O_CREAT | O_WRONLY);   //to open file

	if(file1 == -1)  //rd will be -1 if error oocurs
	{
		printf("Error Opening File\n");
	}
	
	int *fd;
	fd = &file1;
	
	
    pthread_t p1,p2;  // two processes created
    pthread_create(&p1,NULL,f1,(void *)fd);
    pthread_create(&p2,NULL,f2,(void *)fd);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL); // Joining Threads to stop other processes

}

void *f1(void *fd)  // function definition
{
    int i=0;
    while(i<2)
    {   
    
     
     // pAterson solution to synchronize two processes
       
	    flag[0]=1;
        t=1;
        while(flag[1]==1 && t==1);
        
		int sd = &fd;
	
      	write(sd,"dream big\n",20); // to write in file
      	
      	write(1,"dream big \n",20); // to write on screen (fd=1)
      	
		  //critical section
      	
        flag[0]=0;
        i++;
    }
}
void *f2(void *fd)
{
    int i=0;
    while(i<2)
    {
    	//peterson solution to syncronize two processes
    	
        flag[1]=1;
        t=0;
        while(flag[0]==1 && t==0);
       	
		      
		int sd = &fd;
       	write(sd,"Welcome to Lpu \n",20);
       	write(1,"Welcome to Lpu\n",20);
       	//critical section ends
       	
        flag[1]=0;
        i++;
    }
}
