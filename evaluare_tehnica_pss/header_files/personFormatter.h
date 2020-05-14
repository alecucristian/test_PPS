#include "..\header_files\Person.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char gender_converter( enum Gender gender){
    if( gender == Male){
        return 'M';
    } else
    {
        return 'F';
    }
    
}

enum Gender gender_converter_r( char *gender){
    if( strcmp(gender, "M")){
        return Male;
    } else
    {
        return Female;
    }
    
}
// Converting person structure to string for creating input file
char *person_to_string( struct PersonTmpl person) {
    char *person_string;

    switch ( person.chRecordType ) {
        case REC_TYPE_PERSONAL:
            person_string = (char*)malloc(77);
            sprintf(person_string, "%d, %d, %s, %s, %s, %c%s", person.nPersonID, person.chRecordType, person.Details.PersonalInfo.sLastName, person.Details.PersonalInfo.sFirstName, person.Details.PersonalInfo.sBirthdate, gender_converter( person.Details.PersonalInfo.theGender), "\n");
            break;
        
        case REC_TYPE_HOME:
            person_string = (char*)malloc(147);
            sprintf(person_string, "%d, %d, %s, %s, %s, %s, %s%s", person.nPersonID, person.chRecordType, person.Details.HomeDetails.homeAddress.sStreet, person.Details.HomeDetails.homeAddress.sCity, person.Details.HomeDetails.homeAddress.sCountry, person.Details.HomeDetails.sPhone, person.Details.HomeDetails.sEmail, "\n");
            break;

        case REC_TYPE_WORK:
            person_string = (char*)malloc(188);
            sprintf(person_string, "%d, %d, %s, %s, %s, %s, %s, %s, %s%s", person.nPersonID, person.chRecordType, person.Details.WorkDetails.sCompany, person.Details.WorkDetails.workAddress.sStreet, person.Details.WorkDetails.workAddress.sCity, person.Details.WorkDetails.workAddress.sCountry, person.Details.WorkDetails.sPhone, person.Details.WorkDetails.sFax, person.Details.WorkDetails.sEmail, "\n");
            break;

        default:
            person_string = (char*)"something went wrong";

    }
    return person_string;

}

// Failed attempt at converting input to person structure

struct PersonTmpl string_to_person( char *person_string){
    struct PersonTmpl person;
    char *token = (char *)malloc(sizeof(person_string));
    char *token_tmp = (char *)malloc(sizeof(person_string));
    char *person_string_tmp;
    person_string_tmp = (char*)malloc(sizeof(person_string));
    char *person_string_tmp2;
    strcpy(person_string_tmp2, person_string);
    printf("%s\n\n", person_string_tmp2);
    person_string_tmp2 = (char*)malloc(sizeof(person_string));
    strcpy(person_string_tmp, person_string);
    printf("%s\n\n", person_string_tmp);

    // Get size of string
    int k = 1;
    int counter = 1;
    token_tmp = strtok(person_string_tmp2, ",");
    while (token_tmp = strtok(0, ",")){
        k++;}
        // printf("\n%s", token_tmp+1);


    switch(k){
        case 6:
        // printf("%s\n\n", person_string_tmp);
            token = strtok(person_string_tmp, ",");
            person.nPersonID = atoi(token);
            while ( token = strtok(0, ",") ){
                switch (counter)
                {
                case 1:
                    person.chRecordType = atoi(token+1);
                    // printf("%d", person.chRecordType);
                    break;
                    
                case 2:
                    strcpy(person.Details.PersonalInfo.sLastName, token+1);
                    // printf("%s", person.Details.PersonalInfo.sLastName);
                    break;

                case 3:
                    strcpy(person.Details.PersonalInfo.sFirstName, token+1);
                    // printf("%s", person.Details.PersonalInfo.sFirstName);
                    break;

                case 4:
                    strcpy(person.Details.PersonalInfo.sBirthdate, token+1);
                    // printf("%s", person.Details.PersonalInfo.sBirthdate);
                    break;

                case 5:
                    person.Details.PersonalInfo.theGender = gender_converter_r(token+1);
                    // printf("%d", person.Details.PersonalInfo.theGender);
                    break;
                
                default:
                    break;
                }
                
 
                counter++;

            }
            
            break;
        case 7:
            token = strtok(person_string_tmp, ",");
            person.nPersonID = atoi(token);
            // printf("%d", person.nPersonID);
            while ( token = strtok(0, ",") ){
                switch (counter)
                {
                case 1:
                    person.chRecordType = atoi(token+1);
                    // printf("%d", person.chRecordType);
                    break;
                    
                case 2:
                    strcpy(person.Details.HomeDetails.homeAddress.sStreet, token+1);
                    // printf("%s", person.Details.HomeDetails.homeAddress.sStreet);
                    break;

                case 3:
                    strcpy(person.Details.HomeDetails.homeAddress.sCity, token+1);
                    // printf("%s", person.Details.HomeDetails.homeAddress.sCity);
                    break;

                case 4:
                    strcpy(person.Details.HomeDetails.homeAddress.sCountry, token+1);
                    // printf("%s", person.Details.HomeDetails.homeAddress.sCountry);
                    break;

                case 5:
                    strcpy(person.Details.HomeDetails.sPhone, token+1);
                    // printf("%s", person.Details.HomeDetails.sPhone);
                    break;

                case 6:
                    strcpy(person.Details.HomeDetails.sEmail, token+1);
                    // printf("%s", person.Details.HomeDetails.sEmail);
                    break;

                default:
                    break;
                }
                
 
                counter++;

            }
            
            break;
        case 9:
            token = strtok(person_string_tmp, ",");
            person.nPersonID = atoi(token);
            // printf("%d", person.nPersonID);
            while ( token = strtok(0, ",") ){
                switch (counter)
                {
                case 1:
                    person.chRecordType = atoi(token+1);
                    // printf("%d", person.chRecordType);
                    break;
                    
                case 2:
                    strcpy(person.Details.WorkDetails.sCompany, token+1);
                    // printf("%s", person.Details.WorkDetails.sCompany);
                    break;

                case 3:
                    strcpy(person.Details.WorkDetails.workAddress.sStreet, token+1);
                    // printf("%s", person.Details.WorkDetails.workAddress.sStreet);
                    break;

                case 4:
                    strcpy(person.Details.WorkDetails.workAddress.sCity, token+1);
                    // printf("%s", person.Details.WorkDetails.workAddress.sCity);
                    break;

                case 5:
                    strcpy(person.Details.WorkDetails.workAddress.sCountry, token+1);
                    // printf("%s", person.Details.WorkDetails.workAddress.sCountry);
                    break;

                case 6:
                    strcpy(person.Details.WorkDetails.sPhone, token+1);
                    // printf("%s", person.Details.WorkDetails.sPhone);
                    break;

                case 7:
                    strcpy(person.Details.WorkDetails.sFax, token+1);
                    // printf("%s", person.Details.WorkDetails.sFax);
                    break;

                case 8:
                    strcpy(person.Details.WorkDetails.sEmail, token+1);
                    // printf("%s", person.Details.WorkDetails.sEmail);
                    break;
                    
                default:
                    break;
                }
                
 
                counter++;

            }
            
            break;
        default:
            exit(0);
    }


    
    free(person_string_tmp2);
    free(token_tmp);
    free(token);
    free(person_string_tmp);
    printf(person_string);
    return person;

}

// Getting number of rows from the input

int rowNumber ( char *text){
    char *token;
    char *text_tmp;
    text_tmp = (char*)malloc(strlen(text)+1);
    strcpy(text_tmp, text);

    // Get size of string
    int k = 1;
    token = strtok(text_tmp, "\n");
    while (token = strtok(0, "\n")){
        k++;
    }
    free(text_tmp);
    // printf("%d", k);
    return k;


}

// Getting a single row from the input

char *retrieveRow ( char *text, int row){
    char *token;
    char *text_tmp;
    text_tmp = (char*)malloc(strlen(text)+1);
    strcpy(text_tmp, text);

    int k = 1;
    token = strtok(text_tmp, "\n");
    // printf("%s", token);
    if ( row == 0) {
        // printf("%s", token);
        // free(text_tmp);
        return token;
    }
    while (token = strtok(0, "\n")){
        if( row == k) {
            free(text_tmp);
            return token;
        }
        k++;
    }
    free(text_tmp);
    return (char *)"Error";


}

// Failed attempt to convert binary input to person structure
// Memory error

struct PersonTmpl binary_to_person(char *binary){
    struct PersonTmpl person;
    char *binary_tmp;
    binary_tmp = (char *)malloc(strlen(binary)+1);
    strcpy(binary_tmp, binary);

    int binary_l = strlen(binary_tmp);

    if(validate(binary_tmp)){
        int symbol_count = binary_l / 8 + 1;
        char *text = (char *)malloc(symbol_count + 1);
        if(binary_l % 8 == 0){
            --symbol_count;}
            
        strcpy(text, formatBinary_t(binary_tmp));
        // strcpy(text, formatBinary_t(binary_tmp));
        // printf("%s\n\n", text);
        // text = binaryToText_t(binary_formatted, strlen(binary_formatted), symbol_count);
        // printf("\n%s in binary is the following text:\n%s\n", binary_tmp, text);
        printf("%s\n\n", text);
        // person = string_to_person(text);
        // printf("%s\n\n", person.Details.HomeDetails.sEmail);
        // printf("\n%d", persons[i].nPersonID);
        
        
        free(text);
    }


    free(binary_tmp);
    return person;
}


    



