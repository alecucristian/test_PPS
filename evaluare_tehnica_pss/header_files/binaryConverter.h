#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned long binaryToDecimal(char *binary, int length)
{
	int i;
	unsigned long decimal = 0;
	unsigned long weight = 1;
	binary += length - 1;
	weight = 1;
	for(i = 0; i < length; ++i, --binary)
	{
		if(*binary == '1')
			decimal += weight;
		weight *= 2;
	}
	
	return decimal;
}
// Failed attempt
// Memory error
void binaryToText(char *binary, int binaryLength, char *text, int symbolCount)
{
    int i;
    for(i = 0; i < binaryLength; i+=8, binary += 8)
    {
        char *byte = binary;
        byte[8] = '\0';
        *text++ = binaryToDecimal(byte, 8);
    }
    text -= symbolCount;
}
// Failed attempt
// Memory error
void formatBinary(char *input, int length, char *output)
{
    while(*input)
    {
        if(*input == '0' || *input == '1')
        {
            *output++ = *input++;
        }
        else
        {
            ++input;
            --length;
        }
    }
    output -= length;
}
// Converting a binary input to a string
char *formatBinary_t(char *input)
{
    char *input_tmp = (char *)malloc(strlen(input));
    // char *output;
    char *output = (char *)malloc(strlen(input));
    strcpy(input_tmp, input);

    char *token;
    char c[2];
    token = strtok(input_tmp, " ");
    c[0] = strtol(token, 0, 2);
    strcpy(output, c);
    while (token = strtok(0, " ")){
        c[0] = strtol(token, 0, 2);
        strcat(output, c);
    }
    // printf("%s", output);
    free(input_tmp);
    return output;
}

// Validate if the input is binary
int validate(char *binary)
{
	while(*binary)
	{
		if((*binary != '0') && (*binary != '1') && (*binary != ' '))
			return 0;
        ++binary;
	}
	return 1;
}

// Convert from int to string of binary
void decimalToBinary(int decimal, char *octet)
{
	octet += 8;
	*octet = '\0';
	if(decimal == 0)
	{
		octet -= 8;
		octet = (char*)"00000000";
	}
	else
	{
		while(decimal > 0)
		{
			--octet;
			*octet = decimal % 2 + '0';
			decimal = decimal / 2;
		}
	}
    while(strlen(octet) < 8)
    {
        --octet;
        *octet = '0';
    }
}
// Convert from a string of text to a binary string
void textToBinary(char *text, int textLength, char *binary, int binaryLength)
{
    char *octet = (char*)malloc(9);
    if(octet == NULL)
        exit(1);
    while(*text)
    {
        decimalToBinary(*text, octet);
        while(*octet)
            *binary++ = *octet++;
        *binary++ = ' ';
        ++text;
        octet -= 8;
    }
    *binary = '\0';
    binary -= binaryLength;
    free(octet);
}

// Test for the text conversion
void test_text_to_binary(void)
{
	char text[101];
    char *binary;
	int textLength, binaryLength;
	
    scanf("%100[^\n]s", text);
	textLength = strlen(text);
    binaryLength = textLength * 9;      // 8 binary digits + 1 space separator
    binary = (char*)malloc(binaryLength + 1);  // + 1 null terminator
    if(binary == NULL)
        exit(1);
    
    textToBinary(text, textLength, binary, binaryLength);
    printf("Your binary encoding is:\n%s\n", binary);
    
    free(binary);
	
}
// Test for the failed attempt at the binary conversion
// Does not work for multiple accesses
void test_binary_to_text(void)
{
	char binary[559];
	int binaryLength;
	
    scanf("%558[^\n]s", binary);
	binaryLength = strlen(binary);
	if(validate(binary))
	{
        int symbolCount = binaryLength / 8 + 1;
        char *text = (char*)malloc(symbolCount + 1);
        char *formattedBinary = (char*)malloc(binaryLength + 1);
        if(text == NULL || formattedBinary == NULL)
            exit(1);
        if(binaryLength % 8 == 0)
            --symbolCount;
            
        formatBinary(binary, binaryLength, formattedBinary);
        binaryToText(formattedBinary, strlen(formattedBinary), text, symbolCount);
		printf("%s in binary is the following text:\n%s\n", binary, text);
        
        free(text);
        free(formattedBinary);
	}
	else
	{
		printf("The input should be a binary number, containing only zeros(0) and ones(1).\n");
	}
}





