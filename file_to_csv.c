#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


//makes a copy of the a file replacing all of the white spaces with commas
void file_to_csv(char* file_name){
    FILE* file_to_convert = fopen(file_name, "r");
    char* new_file_name = malloc(strlen(file_name)+4);
    strcpy(new_file_name, file_name);
    strcat(new_file_name, ".csv");
    FILE* csv_file = fopen(new_file_name, "w");
    char c;

    while(!feof(file_to_convert)){
        c = fgetc(file_to_convert);
        if(isspace(c))                      //convert whitespace to comma 
            fprintf(csv_file, "%c", ',');
        else if(c == ','){                  //surronds already exiisting comma with quotes
            fprintf(csv_file, "%c", '\"');
            fprintf(csv_file, "%c", ',');
            fprintf(csv_file, "%c", '\"');
        }
        else
            fprintf(csv_file, "%c", c);
    }

    fclose(file_to_convert);
    fclose(csv_file);
}
