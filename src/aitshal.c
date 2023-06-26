#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "functions.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Please provide a repository name as an argument.\n");
        return 1;
    }

    char* repository = argv[1];
    executeFiglet("Thanks for using aitshal!");
    executeFiglet("------------------------------------");
    executeFiglet("This command is held by B-Consortium");
    executeFiglet("------------------------------------");
    sleep(3);
    system("clear");
    if (repositoryExists(repository)) {
        executeFiglet("Downloading Output");
        sleep(3);
        gitClone(repository);
        sleep(2);
        system("clear");
        executeFiglet("Installation Output");
    } else {
        executeFiglet("Whoops! Does not exist");
    }

    return 0;
}
