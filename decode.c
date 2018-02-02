/****************************************************************************
* decode.c
*
* Decodes cipher text encoded with a vigenere cipher using provided key
*
* Dylan Doblar and Noah Zamzow-Schmidt
* 6.179 Final Project
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

  // Key used to perform vigenere cipher
  char key[1000];

  do {
    printf("Enter key:\n");
    fgets(key, sizeof(key), stdin);
    if (strlen(key) <= 1) {
      printf("Please enter a key.\n");
    } else if (strstr(key, " ") != NULL) {
      key[0] = '\0';
      printf("Please enter a single word.\n");
    } else {
      for (int a = 0; a < strlen(key) - 1; a++) {
        if (!isalpha(key[a])) {
          printf("Please enter an alphabetical word.\n");
          key[0] = '\0';
          break;
        }
      }
    }

    // Remove trailing newline character
    char* pos;
    if ((pos = strchr(key, '\n')) != NULL) {
     *pos = '\0';
    }
  } while(strlen(key) <= 1);

  int i = 0, j = 0, l = 0;

  // Read message
	printf("Enter message:\n");
	char s[10000];
	fgets(s, sizeof(s), stdin);

  // // Remove trailing newline character of message
  // char*pos;
  // if ((pos=strchr(s, '\n')) != NULL) {
  //  *pos = '\0';
  // }

	char* k = key;
	int len = strlen(k);

	// Convert key to lowercase
	while (k[l] != '\0') {
	    if(isupper(k[l]))
	        k[l] = tolower(k[l]);
	    l++;
	}

	// // Perform reverse cipher letter by letter
  while (s[i] != '\0') {
    if ((int)s[i] >= 65 && (int)s[i] <= 90) {
      if (((s[i] - 65) - (k[j] - 97)) > 0) {
			  s[i] = 'A' + (((s[i] - 65) - (k[j] - 97)) % 26);
			  j++;
      }
      else {
        s[i] = 'A' + ((((s[i] - 65) - (k[j] - 97)) + 130) % 26);
			  j++;
      }
		}
		else if ((int)s[i] >= 97 && (int)s[i] <= 122) {
      if (((s[i] - 97) - (k[j] - 97)) > 0) {
			  s[i] = 'a' + (((s[i] - 97) - (k[j] - 97)) % 26);
			  j++;
      }
      else {
        s[i] = 'a' + ((((s[i] - 97) - (k[j] - 97)) + 130) % 26);
			  j++;
      }
		}
		if (j==len) {
			j=0;
    }
		i++;
	}

	// Print result
  printf("Decoded Message:\n%s\n",s);

  return 0;
}
