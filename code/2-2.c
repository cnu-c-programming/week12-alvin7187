#include<stdio.h>
#include<string.h>

typedef struct student{
    char name[64];
    int score;
} Student;

int main(int argc, const char* argv[], const char* envp[]){
    FILE* fp = fopen("student.txt", "r");
    int count = 0;
    Student students[64];
    
    for(int i =0; i<64; i++){
        if(feof(fp) != 0) break;

        fscanf(fp, "%s %d",students[i].name, &students[i].score);
        count++;
    }

    int max = 0;
    float avg = 0;
    
    for(int i = 0; i<count; i++){
        if(students[i].score > max)
            max = students[i].score;

        avg += students[i].score;
    }

    avg/=count;
    

    printf("max: %d\n", max);
    printf("avg: %.2f\n", avg);
    return 0;
}
