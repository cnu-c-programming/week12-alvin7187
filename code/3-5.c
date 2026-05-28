#include<stdio.h>

int main(int argc, const char* argv[]){
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        return 0;
    }
    int sum = 0;
    int num;
    int check;
    char error_str[256];

    while(1){
        check = fscanf(fp, "%d", &num);

        if(check == 1)
            sum+=num;
        else if(check == EOF){
            break;
        }
        else{
            if(fscanf(fp, "%255s", error_str) != EOF){
                fprintf(stderr, "invalid input %s\n", error_str);
            }else 
                break;
        }
    }
    

    fclose(fp);
    printf("sum: %d\n",sum);
    return 0;
}
