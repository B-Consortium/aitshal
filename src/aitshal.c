#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#include "functions.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Please provide a repository name as an argument. There might be typo in the name.\n");
        return 1;
    }

    if (strcmp(argv[1], "--about") == 0) {
        printf("Tool: aitshal");
        printf("\n \n");
        printf("An invention of Research, Provisions, Successors, and the Member of the Broke Consortium.\n");
        printf("This tool is to be identified as the provision under Broke Consortium's chartered OpenRights.\n");
        printf("[-] aitshal is the standard package installer for C-Styled projects \n");
        printf("[-] aitshal is the first tool developed by the consortium and its development plans were classified till the consortium built online presence\n");
        return 0;
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
        system("sudo make install");
    } else {
        executeFiglet("Whoops! Does not exist");
        printf("Please ensure the existence of this repository in the B-Consortium directory.");
    }   
    return 0;
}
