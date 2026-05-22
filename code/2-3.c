#include<stdio.h>
#include<string.h>

void logger(char* message){
    FILE* fp = fopen("log.txt", "a");
    fprintf(fp, "%s\n", message);
}

int job(){
    return 1;
}

int main(int argc, const char* argv[], const char* envp[]){
    if(job() == 1)
        logger("success");
    else
        logger("fail");
    return 0;
}
