#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//new comment in different branch for testing

int hexStringToDecimalString (char *hexString);
char *readInput (void);
void mExit (int status);

int main (void)
{
	char *hex;
	printf("Enter a hexadecimal number to be converted to decimal, or 'q' to quit.\n");
	while (1)
	{
		hex = readInput();
		if ( (hex[0] == 'q') || (hex[0] == 'Q') )
		{
			break;
		}
		else
		{
			//printf("you entered: %s, which is %d characters long\n", hex, strlen(hex));
			int resultant = hexStringToDecimalString(hex);
			if (resultant == -1)
			{
				printf("Invalid input! Only characters 0-9, A-F, and a-f are valid.\n");
			}
			else
			{
				printf("Decimal: %d\n", resultant);
			}
		}
		free(hex);
	}
	free(hex);
	return 0;
}

int hexStringToDecimalString (char *hexString)
{
	int i = 0, k = 0;
	int resultant = 0;
	//essentially a boolean which represents that we made a successful conversion
	//we assume the conversion will be successful, unless we later flag otherwise
	unsigned short success = 1;
	//start at the end of the hex string and work toward the beginning
	for (i = (strlen(hexString) - 1); i >= 0; i--)
	{
		//printf("in for loop\n");
		//if the character has encoding values between (inclusive) that of '0' and '9'
		if ( ((int) hexString[i] >= 48) && ((int) hexString[i] <= 57) )
		{
			//normalize the value to the actual digit, then multiply it by 16^k, and add it to our resultant number
			resultant += ((int) hexString[i] - 48) * (pow((double) 16, (double) k));
			//printf("number found\n");
		}
		//if the character has encoding values between (inclusive) that of 'A' and 'F'
		else if ( ((int) hexString[i] >= 65) && ((int) hexString[i] <= 70) )
		{
			//normalize the (letter)digit to its value, then multiply it by 16^k, and add it to our resultant
			resultant += ((int) hexString[i] - 55) * (pow((double) 16, (double) k));
			//printf("letter found\n");
		}
		//if the character has encoding values between (inclusive) that of 'a' and 'f'
		else if ( ((int) hexString[i] >= 97) && ((int) hexString[i] <= 102) )
		{
			//normalize the (letter)digit to its value, then multiply it by 16^k, and add it to our resultant
			resultant += ((int) hexString[i] - 87) * (pow((double) 16, (double) k));
			//printf("letter found\n");
		}
		//if the current character is the null terminator
		else if (hexString[i] == '\0')
		{
			//do nothing
		}
		//if the input contains something other than
		else
		{
			//we dont accept this kind of input: tell the user and stop converting
			success = 0;
			//printf("invalid character found\n");
			break;
		}
		k++;
	}
	if (success)
	{
		return resultant;
	}
	else
	{
		return -1;
	}
}

char *readInput (void)
{
	int max = 20;
    char* name = (char*) malloc(max); // allocate buffer
    if (name == 0) 
	{
		mExit(0);
	}

    printf("Enter: ");

    while (1) 
	{ 
		// skip leading whitespace
        int c = getchar();
        if (c == EOF) break; // end of file
        if (!isspace(c)) 
		{
             ungetc(c, stdin);
             break;
        }
    }

    int i = 0;
    while (1) 
	{
        int c = getchar();
        if (c == '\n' || c == EOF) 
		{
			// at end, add terminating zero
            name[i] = 0;
            break;
        }
        name[i] = c;
        if (i==max-1) 
		{ 
			// buffer full
            max = max + max;
            name = (char*) realloc(name,max); // get a new and larger buffer
            if (name == 0) 
			{
				mExit(0);
			}
        }
        i++;
    }

    return name;
}

void mExit (int status)
{
	printf("Some kind of error occurred!\n");
	exit(status);
}
