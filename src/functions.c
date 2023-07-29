#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <string.h>
#include <unistd.h>

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

int repositoryExists(const char* repository) {
    CURL* curl = curl_easy_init();
    if (curl) {
        // Construct the URL
        size_t urlLength = strlen("https://github.com/B-Consortium/") + strlen(repository) + 1;
        char* url = (char*)malloc(urlLength);
        snprintf(url, urlLength, "https://github.com/B-Consortium/%s", repository);

        // Set the request URL
        curl_easy_setopt(curl, CURLOPT_URL, url);
        // Follow redirects
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        // Disable output to stdout
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        // Perform the request
        CURLcode res = curl_easy_perform(curl);

        // Clean up the CURL handle
        curl_easy_cleanup(curl);

        // Check for errors and the existence of the repository
        if (res == CURLE_OK) {
            long httpCode;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

            if (httpCode == 200) {
                return 1;
            }
        }

        // Free allocated memory
        free(url);
    }
    return 0;
}

void executeFiglet(const char* inputString) {
    // Construct the command string
    const char* figletCmd = "figlet";
    size_t cmdLength = strlen(figletCmd) + strlen(inputString) + 4;
    char* command = (char*)malloc(cmdLength);
    snprintf(command, cmdLength, "%s \"%s\"", figletCmd, inputString);

    // Execute the command using system()
    int status = system(command);

    // Check the return value of system() for any errors
    if (status == 0) {
        
    } else {
        printf("figlet command failed with error code %d\n", status);
    }

    // Free the allocated memory
    free(command);
}

void buildAndInstall(const char* repository) {
    char repositoryPath[256];
    snprintf(repositoryPath, sizeof(repositoryPath), "./%s", repository);
    // Change directory to the repository
    if (chdir(repositoryPath) != 0) {
        fprintf(stderr, "Failed to change directory to '%s'\n", repositoryPath);
        return;
    }

    // Check if Makefile or makefile exists
    if (access("Makefile", F_OK) != 0 && access("makefile", F_OK) != 0) {
        fprintf(stderr, "Makefile not found in '%s', check if this project is aitshal supported C-Styled \n", repositoryPath);
        return;
    }

    // Run 'make repository'
    char makeCommand[256];
    snprintf(makeCommand, sizeof(makeCommand), "make %s", repository);
    if (system(makeCommand) != 0) {
        fprintf(stderr, "Failed to run 'make %s'. Is make installed?\n", repository);
        return;
    }

    // Run 'sudo make install'
    if (system("sudo make install") != 0) {
        fprintf(stderr, "Failed to run 'sudo make install'\n");
        return;
    }

    printf("Build and installation completed successfully!\n");
}
