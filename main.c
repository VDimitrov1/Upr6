#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
	int fd;
	struct stat FileData;
	char* D;
	int i=0;
	
	if(argc!=2)
	{
		printf("No file specified");
		exit(1);
	}
	printf("Size %s",argv[1]);
	fd=open(argv[1],O_RDWR |O_CREAT,0644);
	if(fd==-1)
	{
		printf("Error opening file");
		exit(1);
	}
	fstat(fd,&FileData);
	D=mmap(NULL,FileData.st_size,MAP_SHARED,PROT_READ,fd,0);

	printf("File Lenght is %ld\n",FileData.st_size);
	printf("File Content:\n");
	for(i=0;i<FileData.st_size;i++)
	{
		printf("%c",*D++);
	}
	close(fd);
	munmap(D,FileData.st_size);
	return 0;
}
