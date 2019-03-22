#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

    if(argc != 3) {
        printf("Arguments error!");
        return 0;
    }

    int source_file = open(argv[1], O_RDONLY);
    if(source_file < 0) {
        printf("File not found!");
        return 0;
    }

    int cnt = lseek(source_file, 0, SEEK_END);
    char toNew[cnt];

    cnt = lseek(source_file, 0, 0);
    read(source_file, &toNew, sizeof(toNew));
    source_file = open(argv[2], O_TRUNC);
    source_file = open(argv[2], O_WRONLY);

    int cnt_write = write(source_file, toNew, sizeof(toNew));
    if(cnt_write < 0) {
        printf("Write error!");
        return 0;
    }
    printf("Done.\n");
    return 0;
}


