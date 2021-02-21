#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


//makes a copy of the a file replacing all of the white spaces with commas
void file_to_csv(char* file_name){
    FILE* file_to_convert = fopen(file_name, "r");
    char* header_csv = "_header.csv";
    char* new_file_name = malloc(strlen(file_name)+strlen(header_csv));
    strcpy(new_file_name, file_name);
    strcat(new_file_name, header_csv);
    FILE* csv_file = fopen(new_file_name, "w");
    FILE* csv_tmp =  fopen("columns.csv", "w");
    char c;
    unsigned long column_count = 0;
    
    fprintf(csv_file, "%c", '\"');
    fprintf(csv_file, "%lu", column_count);
    column_count++;
    fprintf(csv_file, "%c", '\"');

    fprintf(csv_tmp, "%c", '\"');

    while(!feof(file_to_convert)){
        c = fgetc(file_to_convert);
        if(isspace(c)){                      //convert whitespace to comma
            fprintf(csv_tmp, "%c", '\"');
            fprintf(csv_tmp, "%c", ',');
            c = fgetc(file_to_convert);
            while(isspace(c))
                c = fgetc(file_to_convert);
            ungetc(c, file_to_convert);
            fprintf(csv_tmp, "%c", '\"');
            //add column nbr
            fprintf(csv_file, "%c", ',');
            fprintf(csv_file, "%c", '\"');
            fprintf(csv_file, "%lu", column_count);
            fprintf(csv_file, "%c", '\"');
            column_count++; 
        }
        else if(c == ','){                  //surronds already exiisting comma with quotes
            fprintf(csv_tmp, "%c", '\"');
            fprintf(csv_tmp, "%c", ',');
            fprintf(csv_tmp, "%c", '\"');
            fprintf(csv_tmp, "%c", ',');
            //add column nbr
            fprintf(csv_file, "%c", ',');
            fprintf(csv_file, "%c", '\"');
            fprintf(csv_file, "%lu", column_count);
            fprintf(csv_file, "%c", '\"');
            column_count++; 
        }
        else if(c == '\"'){
            fprintf(csv_tmp, "%c", '\\');
            fprintf(csv_tmp, "%c", '\"');
        }
        else
            fprintf(csv_tmp, "%c", c);
    }

    //end line foe collumns
    fprintf(csv_file, "%c", '\n');
    
    //final quote
    fprintf(csv_tmp, "%c", '\"');
    //append csv_tmp to csv_file(not working now, fix later)
    // fclose(csv_tmp);
    // csv_tmp =  fopen("tmp.csv", "r");
    // c = getc(csv_tmp);
    // while(!feof(csv_tmp)){
    //     fprintf(csv_file, "%c", c);
    //     c = getc(csv_tmp);
    // }

    //clean up
    fclose(csv_tmp);
    //remove("tmp.csv");
    fclose(file_to_convert);
    fclose(csv_file);
}

int main(){
    char* file_name = "concepts_of_programming_languages.txt";

    file_to_csv(file_name);
}
