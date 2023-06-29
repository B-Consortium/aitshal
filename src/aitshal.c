#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "functions.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Please provide a repository name as an argument. There might be typo in the name.\n");
        return 1;
    }

    char* repository = argv[1];
    printf("Thanks for using aitshal!");
    printf("------------------------------------\n");
    printf("This command is held by B-Consortium\n");
    printf("------------------------------------\n");
    sleep(3);
    system("clear");
    if (repositoryExists(repository)) {
        executeFiglet("Downloading Output");
        sleep(3);
        gitClone(repository);
        sleep(2);
        system("clear");
        executeFiglet("Installation Output");
        buildAndInstall(repository);
    } else {
        executeFiglet("Whoops! Does not exist");
        printf("Please ensure the existence of this repository in the B-Consortium directory.");
    }   
    return 0;
}
