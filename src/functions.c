#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gitClone(const char* inputString) {
    // Construction of the command string
    const char* gitCloneCmd = "git clone https://github.com/B-Consortium/";
    size_t cmdLength = strlen(gitCloneCmd) + strlen(inputString) + 1;
    char* command = (char*)malloc(cmdLength);
    snprintf(command, cmdLength, "%s%s", gitCloneCmd, inputString);

    // Execute the command using system()
    int status = system(command);

    // Check the return value of system() for any errors
    if (status == 0) {
        printf("Git clone successful!\n");
    } else {
        printf("Git clone failed with error code %d\n", status);
    }

    // Free the allocated memory
    free(command);
}
