#include <unistd.h>
#include <fcntl.h>

int main(int argc,char **argv)
{
	if(argc<3)
		return 1;
	int fdSrcFile = open( argv[1], O_RDONLY);
	if(fdSrcFile == -1)
	{
		return 2;
	}
	
	int fdDstFile = open( argv[2], O_CREAT | O_WRONLY, S_IWUSR | S_IWUSR);
	if(fdDstFile == -1)
	{
		return 3;
	}
	
	char buffer[2];
	ssize_t charcount;
	
	while((charcount = read(fdSrcFile, buffer, sizeof(buffer))))
	{
		write(fdDstFile, buffer, charcount);
	}
	
	return 0;
	
	
}
