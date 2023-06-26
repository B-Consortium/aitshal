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
    executeFiglet("This command is held by B-Consortium");

    if (repositoryExists(repository)) {
        executeFiglet("Downloading Output");
        gitClone(repository);
        executeFiglet("Installation Output");
    } else {
        executeFiglet("Whoops! Does not exist");
    }

    return 0;
}
