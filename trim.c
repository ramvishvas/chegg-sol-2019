#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *trim(char *line)
{
	char *end;

	// Trim leading space
	while(isspace((unsigned char)*line))
	{
		line++;
	}

	// All spaces?
	if(*line == '\0') 
	{
		printf("%s","Only Space Available");
		// return 0;
		return line;
	}

	// // Trim trailing space
	end = strlen(line) - 1;
	
	while(end >= 0)
	{
		if(isspace(*(end + line)))
		{
			
		}
		end--;
	}

	// // Write new null terminator character
	// end[1] = '\0';

	return line;
}

int main(int argc, char const *argv[])
{
	
	printf("%s\n",trim("   as  wd sd ddf   "));
	return 0;
}