#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include <WinBase.h>
#include "..\header_files\personFormatter.h"


// Getting filepath from the .ini file
LPCSTR filename( LPCSTR filetype ) {
    // LPCTSTR path = _T("D:\evaluare_tehnica_pss\resource_files\testc.ini");
    LPCTSTR path = _T("..\\resource_files\\testc.ini");
    TCHAR filename[100];
    printf("%s\n", filetype);
    if ( filetype == "in") {
        int a = GetPrivateProfileString(_T("testc"), _T("in"), _T("Failure while retrieving file name"), filename, 100, path);
    } else
    {
        int a = GetPrivateProfileString(_T("testc"), _T("out"), _T("Failure while retrieving file name"), filename, 100, path);
    }
    
    LPCTSTR filename_s = filename;
    return filename_s;


}

// Making input file

void f_create( char *filename ) {
    // Make file
    FILE *f;
    f=fopen(filename, "wb");
    if(f == NULL)
    {
        printf("\nError!");
        exit (1);              
    }



    // Make persoana1
    struct PersonTmpl persoana1;
    persoana1.nPersonID = 1;
    persoana1.chRecordType = REC_TYPE_PERSONAL;
    strcpy(persoana1.Details.PersonalInfo.sLastName, "Cristian");
    strcpy(persoana1.Details.PersonalInfo.sFirstName, "Alecu");
    strcpy(persoana1.Details.PersonalInfo.sBirthdate, "28-07-1998");
    persoana1.Details.PersonalInfo.theGender = Male;
    // Convert to string
    char *persoana1_s = person_to_string(persoana1);

    // Convert to binary
    char *persoana1_b;
	int persoana1_tl, persoana1_bl;

    persoana1_tl = strlen(persoana1_s);
    persoana1_bl = persoana1_tl * 9;      // 8 binary digits + 1 space separator
    persoana1_b = (char*)malloc(persoana1_bl + 1);  // + 1 null terminator
    if(persoana1_b == NULL)
        exit(1);
    
    textToBinary(persoana1_s, persoana1_tl, persoana1_b, persoana1_bl);

    // printf("\nYour binary encoding is:\n%s\n", persoana1_b);

    // printf("%s", persoana1_s);

    // Make persoana2
    struct PersonTmpl persoana2;
    persoana2.nPersonID = 2;
    persoana2.chRecordType = REC_TYPE_HOME;
    strcpy(persoana2.Details.HomeDetails.homeAddress.sStreet, "Ramnicu Sarat");
    strcpy(persoana2.Details.HomeDetails.homeAddress.sCity, "Bucuresti");
    strcpy(persoana2.Details.HomeDetails.homeAddress.sCountry, "Romania");
    strcpy(persoana2.Details.HomeDetails.sEmail, "alecucristianionut@gmail.com");
    strcpy(persoana2.Details.HomeDetails.sPhone, "0720047657");
    // Convert to string
    char *persoana2_s = person_to_string(persoana2);

    // Convert to binary
    char *persoana2_b;
	int persoana2_tl, persoana2_bl;

    persoana2_tl = strlen(persoana2_s);
    persoana2_bl = persoana2_tl * 9;      // 8 binary digits + 1 space separator
    persoana2_b = (char*)malloc(persoana2_bl + 1);  // + 1 null terminator
    if(persoana2_b == NULL)
        exit(1);
    
    textToBinary(persoana2_s, persoana2_tl, persoana2_b, persoana2_bl);

    // printf("%s", persoana2_s);

    // Make persoana 3
    struct PersonTmpl persoana3;
    persoana3.nPersonID = 3;
    persoana3.chRecordType = REC_TYPE_WORK;
    strcpy(persoana3.Details.WorkDetails.sCompany, "Prosoft Solutions");
    strcpy(persoana3.Details.WorkDetails.workAddress.sStreet, "Iuliu Maniu");
    strcpy(persoana3.Details.WorkDetails.workAddress.sCity, "Bucuresti");
    strcpy(persoana3.Details.WorkDetails.workAddress.sCountry, "Romania");
    strcpy(persoana3.Details.WorkDetails.sPhone, "+40 213 133847");
    strcpy(persoana3.Details.WorkDetails.sFax, "+40 372 873189");
    strcpy(persoana3.Details.WorkDetails.sEmail, "office@pss.ro");
    // Convert to string
    char *persoana3_s = person_to_string(persoana3);

    // Convert to binary
    char *persoana3_b;
	int persoana3_tl, persoana3_bl;

    persoana3_tl = strlen(persoana3_s);
    persoana3_bl = persoana3_tl * 9;      // 8 binary digits + 1 space separator
    persoana3_b = (char*)malloc(persoana3_bl + 1);  // + 1 null terminator
    if(persoana3_b == NULL)
        exit(1);
    
    textToBinary(persoana3_s, persoana3_tl, persoana3_b, persoana3_bl);


    // printf("%s", persoana3_s);

    // Writing to input file the person structures


    fwrite(persoana1_b, 1, strlen(persoana1_b), f);
    fwrite("\n", 1, strlen("\n"), f);
    fwrite(persoana1_b, 1, strlen(persoana1_b), f);
    fwrite("\n", 1, strlen("\n"), f);
    fwrite(persoana2_b, 1, strlen(persoana2_b), f);
    fwrite("\n", 1, strlen("\n"), f);
    fwrite(persoana3_b, 1, strlen(persoana3_b), f);
    fwrite("\n", 1, strlen("\n"), f);
    fwrite(persoana2_b, 1, strlen(persoana2_b), f);
    fwrite("\n", 1, strlen("\n"), f);
    fwrite(persoana3_b, 1, strlen(persoana3_b), f);
    fclose(f);

}

// Getting number of characters of the input file

long f_textsize( char *filename ) {
     // Read file
    FILE *f;
    f=fopen(filename, "rb");
    if(f == NULL)
    {
        printf("\nError!"); 
        exit (1);             
    }

    // obtain file size:
    long f_size;
    fseek (f , 0 , SEEK_END);
    f_size = ftell (f);
    rewind (f);

    fclose(f);

    return f_size;

}

// Reading file and putting it in a string

char *f_read( char *filename ) {
    // Read file
    FILE *f;
    f=fopen(filename, "rb");
    if(f == NULL)
    {
        printf("\nError!"); 
        exit (1);             
    }

    // obtain file size:
    long f_size = f_textsize( filename );

    // allocate memory to contain the whole file:
    char *buffer;
    buffer = (char*) malloc (sizeof(char)*f_size);
    if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

    // copy the file into the buffer:
    size_t result;
    result = fread (buffer, 1, f_size, f);
    if (result != f_size) {fputs ("Reading error",stderr); exit (3);}
    // printf("\n%s", buffer);
    return buffer;


    fclose(f);
    free (buffer);
    

}

// Making the output file row by row

void f_out( char *input, char *filename, int create ) {
    // Make file
    FILE *f;
    if(create){
        f=fopen(filename, "wb");

    } else
    {
        f=fopen(filename, "ab");
    }
    
    if(f == NULL)
    {
        printf("\nError!");
        exit (1);              
    }
    
    // Declaring variables
    char *token;
    int k = 1;
    int RecordType;
    // Writing index and strating tokening
    token = strtok(input, ",");
    fwrite(token, 1, strlen(token), f);
    for(int i=0; i<(3-strlen(token)); i++){
    fwrite(" ", 1, 1, f);
    }
    // Writing the rest on the file based on record type

    while (token = strtok(0, ",")) {
        switch (k)
        {
        case 1:
            fwrite(token, 1, strlen(token), f);
            if(strcmp(token+1, "1") == 0){
                RecordType = REC_TYPE_PERSONAL;
            }
            if(strcmp(token+1, "2") == 0){
            // printf("%s", token+1);
                RecordType = REC_TYPE_HOME;
            }
            if(strcmp(token+1, "3") == 0){
                RecordType = REC_TYPE_WORK;
            }
            break;
        case 2:
            switch(RecordType){
                case REC_TYPE_PERSONAL:
                // printf("personal");
                    fwrite(token+1, 1, strlen(token+1), f);
                    for(int i=0; i<(31-strlen(token)); i++){
                    fwrite(" ", 1, 1, f);
                    }
                    break;

                case REC_TYPE_HOME:
                // printf("home");
                    fwrite(token+1, 1, strlen(token+1), f);
                    for(int i=0; i<(31-strlen(token)); i++){
                    fwrite(" ", 1, 1, f);
                    }
                    break;

                case REC_TYPE_WORK:
                // printf("work");
                    fwrite(token+1, 1, strlen(token+1), f);
                    for(int i=0; i<(31-strlen(token)); i++){
                    fwrite(" ", 1, 1, f);
                    }
                    break;
                default:
                    printf("ERROR");
                    break;

            }
            break;
        case 3:
            switch(RecordType){
                case REC_TYPE_PERSONAL:
                    fwrite(token+1, 1, strlen(token+1), f);
                    for(int i=0; i<(31-strlen(token)); i++){
                    fwrite(" ", 1, 1, f);
                    }
                    break;

                case REC_TYPE_HOME:
                    fwrite(token+1, 1, strlen(token+1), f);
                    for(int i=0; i<(31-strlen(token)); i++){
                    fwrite(" ", 1, 1, f);
                    }
                    break;

                case REC_TYPE_WORK:
                    fwrite(token+1, 1, strlen(token+1), f);
                    for(int i=0; i<(31-strlen(token)); i++){
                    fwrite(" ", 1, 1, f);
                    }
                    break;
                default:
                    printf("ERROR");
                    break;

            }
            break;
        case 4:
            switch(RecordType){
                case REC_TYPE_PERSONAL:
                    fwrite(token+1, 1, strlen(token+1), f);
                    for(int i=0; i<(11-strlen(token)); i++){
                    fwrite(" ", 1, 1, f);
                    }
                    break;

                case REC_TYPE_HOME:
                    fwrite(token+1, 1, strlen(token+1), f);
                    for(int i=0; i<(31-strlen(token)); i++){
                    fwrite(" ", 1, 1, f);
                    }
                    break;

                case REC_TYPE_WORK:
                    fwrite(token+1, 1, strlen(token+1), f);
                    for(int i=0; i<(31-strlen(token)); i++){
                    fwrite(" ", 1, 1, f);
                    }
                    break;
                default:
                    printf("ERROR");
                    break;

            }
            break;
        case 5:
            switch(RecordType){
                case REC_TYPE_PERSONAL:
                    fwrite(token+1, 1, strlen(token+1), f);
                    break;

                case REC_TYPE_HOME:
                    fwrite(token+1, 1, strlen(token+1), f);
                    for(int i=0; i<(16-strlen(token)); i++){
                    fwrite(" ", 1, 1, f);
                    }
                    break;

                case REC_TYPE_WORK:
                    fwrite(token+1, 1, strlen(token+1), f);
                    for(int i=0; i<(31-strlen(token)); i++){
                    fwrite(" ", 1, 1, f);
                    }
                    break;
                default:
                    printf("ERROR");
                    break;

            }
            break;
        
        
        case 6:
            switch(RecordType){
                case REC_TYPE_PERSONAL:
                    break;

                case REC_TYPE_HOME:
                    fwrite(token+1, 1, strlen(token+1), f);
                    break;

                case REC_TYPE_WORK:
                    fwrite(token+1, 1, strlen(token+1), f);
                    for(int i=0; i<(16-strlen(token)); i++){
                    fwrite(" ", 1, 1, f);
                    }
                    break;
                default:
                    printf("ERROR");
                    break;

            }
            break;

        
        case 7:
            switch(RecordType){
                case REC_TYPE_PERSONAL:
                    break;

                case REC_TYPE_HOME:
                    break;

                case REC_TYPE_WORK:
                    fwrite(token+1, 1, strlen(token+1), f);
                    for(int i=0; i<(16-strlen(token)); i++){
                    fwrite(" ", 1, 1, f);
                    }
                    break;
                default:
                    printf("ERROR");
                    break;

            }
            break;
        
        case 8:
            switch(RecordType){
                case REC_TYPE_PERSONAL:
                    break;

                case REC_TYPE_HOME:
                    break;

                case REC_TYPE_WORK:
                    fwrite(token+1, 1, strlen(token+1), f);
                    break;
                default:
                    printf("ERROR");
                    break;

            }
            break;
        
        

        default:
            break;
        
        
        }

        
        k++;
    }
        





    fclose(f);

}




