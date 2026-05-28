#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct config{
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr){
    FILE* fp = fopen("config.txt","r");
    char key[64];

    while (fscanf(fp, "%[^=]=", key) == 1) {
        
        if (strcmp(key, "InputFileName") == 0) {
            fscanf(fp, "%s\n", config_ptr->InputFileName);
        }
        else if (strcmp(key, "Options") == 0) {
            fscanf(fp, "%d\n", &(config_ptr->Options));
        }
        else if (strcmp(key, "SectionName") == 0) {
            fscanf(fp, "%s\n", config_ptr->SectionName);
        }
        else if (strcmp(key, "Address") == 0) {
            fscanf(fp, "%llx\n", &(config_ptr->Address));
        }
    }

    fclose(fp);
}

int main(int argc, const char* argv[]){
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n",
    config.InputFileName,
    config.Options, config.SectionName, config.Address);
    return 0;
}
