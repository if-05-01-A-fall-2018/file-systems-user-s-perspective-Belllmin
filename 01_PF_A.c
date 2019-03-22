#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {

    struct stat fileStat;

    if(argc != 2) return 1;
    if(stat(argv[1],&fileStat) < 0) return 1;
 
    printf("Information for %s\n", argv[1]);
    printf("---------------------------\n");
    printf("File Size: \t\t%d bytes\n",fileStat.st_size);
    printf("Number of Links: \t%d\n",fileStat.st_nlink);
    printf("File inode: \t\t%d\n",fileStat.st_ino);
    printf("File Permissions: \t");

    if(S_ISDIR(fileStat.st_mode)) printf("d");
    else printf("-");

    if(fileStat.st_mode & S_IRUSR) printf("r");
    else printf("-"); 

    if(fileStat.st_mode & S_IWUSR) printf("w");    
    else printf("-"); 

    if(fileStat.st_mode & S_IXUSR) printf("x"); 
    else printf("-"); 

    if(fileStat.st_mode & S_IRGRP) printf("r"); 
    else printf("-");

    if(fileStat.st_mode & S_IWGRP) printf("w"); 
    else printf("-");

    if(fileStat.st_mode & S_IXGRP) printf("x"); 
    else printf("-");

    if(fileStat.st_mode & S_IROTH) printf("r"); 
    else printf("-");

    if(fileStat.st_mode & S_IWOTH) printf("w"); 
    else printf("-");

    if(fileStat.st_mode & S_IXOTH) printf("x"); 
    else printf("-");
    
    printf("\n\n");
    printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
    return 0;
}