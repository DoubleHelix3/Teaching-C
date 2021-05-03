#include <string.h>
#include <stdlib.h>

char* replace(const char* s, const char* replace, const char* replacement) {
    char* result;
    int i, count = 0;
    int replaceLength = strlen(replace);
    int replacementLength = strlen(replacement);
  
    // Counting the number of times old word
    // occur in the string
    for (i=0; s[i] != '\0'; i++) {
        if (strstr(&s[i], replace) == &s[i]) {
            count++;
  
            // Jumping to index after the old word.
            i+=replaceLength-1;
        }
    }
  
    // Making new string of enough length
    result = (char *) malloc(i+count*(replacementLength - replaceLength)+1);
  
    i = 0;
    while(*s) {
        // compare the substring with the result
        if(strstr(s, replace) == s) {
            strcpy(&result[i], replacement);
            i += replacementLength;
            s += replaceLength;
        }
        else
            result[i++] = *s++;
    }
  
    result[i] = '\0';
    return result;
}
  