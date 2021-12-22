//Include definitions for C Runtime Library functions used in this program
#include <stdio.h>				//The standard I/O functions

//-------------------------------------------------------------------------------
//This is the main function, invoked by the C Runtime (CRT) to start the program
//-------------------------------------------------------------------------------
int main(void) {

    //Insert your source statements here
	
	int ch;
	int upperCase;
	int lowerCase;
	int vowels;
	int consonants;
	int digits;
	int total;
	
	upperCase = lowerCase = vowels = consonants = digits = total = 0;

	while((ch = getchar()) != EOF){

		if (isupper(ch)){
			++upperCase;
		}
		else if (islower(ch)){
			++lowerCase;
		}
		else if (isdigit(ch)){
			++digits;
		}
		
		if (isalpha(ch) && ch == 'a' || ch == 'e' || ch == 'i' ||
				ch == 'o' || ch == 'u' || ch == 'A' ||
				ch == 'E' || ch == 'I' || ch == 'O' ||
				ch == 'U' || ch == 'y' || ch == 'Y'){
			++vowels;
		}
		else if (isalpha(ch)){
			++consonants;
		}

		++total;

	}
	printf("\n");
	printf("upper-case: %d\n", upperCase);
  printf("lower-case: %d\n", lowerCase);
	printf("vowels: %d\n", vowels);
	printf("consonants: %d\n", consonants);
	printf("digits: %d\n", digits);
	printf("total: %d\n", total);
	printf("\n");
	
	
	return 0;

}
	
