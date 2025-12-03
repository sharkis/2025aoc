#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long checkRepeats(long start, long end){
	long count=0;
	// loop through range
	for(long i=start; i<=end; i++){
		// convert to a string and see if it's made of repeats
		char numstring[20];
		sprintf(numstring, "%ld", i);
		int numlength = strlen(numstring);
		// if length is even, see if the first half matches the back half
		if(numlength%2==0){
			int match = 1;
			for(int k=0; k<numlength/2; k++){
				if(numstring[k] != numstring[k+numlength/2]){
					match=0;
				}
			}
			// if yes, add to counter
			if(match){
				count+=i;
			}
		}

	}
	return count;
}

long splitRange(char range[]){
	char *token = NULL;
	long count=0;
	token = strtok(range,"-");
	if(token !=NULL){
		char *endptr;
		long num1 = strtol(token,&endptr,10);
		token = strtok(NULL,"-");
		if(token !=NULL){
			char *endptrtwo;
			long num2 = strtol(token,&endptrtwo,10);
			count = checkRepeats(num1, num2);
		}
	}
	return count;
}

int main(){
	FILE *fp;
	char buffer[1000];
	fp = fopen("input.txt","r");

	if(fp == NULL){
		return -1;
	}
	if(fgets(buffer, sizeof(buffer), fp) !=NULL){
		long count=0;
		char *range = NULL;
		char *range_token;
		range = strtok_r(buffer,",",&range_token);
		while(range != NULL){
			count += splitRange(range);
			range = strtok_r(NULL,",",&range_token);
		}
		printf("%ld\n", count);

	}
	return 0;
}
