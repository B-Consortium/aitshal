#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#include "functions.h"

int main(int argc, char* argv[]){
   char* repository = argv[1];
   executeFiglet("Thanks for using aitshal!");
   executeFiglet("This command is held by B-Consortium");
    if (repositoryExists(repository)) {
       // Perform git clone function
       executeFiglet("Downloading Output");
       gitClone(repository);
       executeFiglet("Installation Output");
    } else {
      // Handle the case when the repository does not exist
       executeFiglet("Whoops! Does not exist");
    }
   return 0;
}
