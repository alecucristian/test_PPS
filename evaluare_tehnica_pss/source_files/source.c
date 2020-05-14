#include "..\header_files\binaryConverter.h"
#include "..\header_files\fileHandler.h"


// To do:
// Read .in and write .out
// Remove \n from creater
// Add defaults to ini
// Add comments

int main(void)
{
    
    // Getting file path for input
    LPCSTR filetype_in = "in";
    LPCSTR filename_in_t = filename( filetype_in );
    char filename_in_s[100];
    strcpy(filename_in_s, filename_in_t);
    // Making input file
    f_create(filename_in_s);

    // Reading input file
    char *input = (char*)malloc(f_textsize(filename_in_s));
    input = f_read(filename_in_s);

    
    // Getting file path for output
    LPCSTR filetype_out = "out";
    LPCSTR filename_out_t = filename( filetype_out );
    char filename_out_s[100];
    strcpy(filename_out_s, filename_out_t);

    // Initializer for first row of writing
    int create_out = 1;

    // Formatting first row and converting it to text from binary
    const int row_number = rowNumber(input);
    char *row = (char *)malloc(strlen(input)+1);
    strcpy(row, retrieveRow(input, 0));
    char *row_s = (char *)malloc(strlen(row)+1);
    strcpy(row_s, formatBinary_t(row));
    printf("%s\n\n", row_s);

    // Writing first row
    f_out(row_s, filename_out_s, create_out);
    create_out = 0;
    
    // Writing the rest
    for (int i = 1; i < row_number; i++)
    {
        free(row);
        free(row_s);
        
        char *row = (char *)malloc(strlen(input)+1);
        strcpy(row, retrieveRow(input, i));
        char *row_s = (char *)malloc(strlen(row)+1);
        strcpy(row_s, formatBinary_t(row));
        printf("%s\n\n", row_s);
        f_out(row_s, filename_out_s, create_out);
      
        
    }
    
    

    





    

    
    

    

    




    system("pause");
	
	return 0;
}
