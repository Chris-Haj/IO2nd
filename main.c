#include <stdio.h>
#include <stdbool.h>

struct Hash{
    char letter;
    int count;
}Stats[26];

void intialize();
void countletters(FILE *f);
void printStats(FILE *f);

int main(){
    intialize();


    FILE *f=NULL;
    char *location = "\\Users\\chris\\Desktop\\random.txt";
    f = fopen(location,"a+");
    if(f!=NULL){
        intialize();
        countletters(f);
        printStats(f);
    }
    else{
        printf("Rip");
    }
    fclose(f);
    f=NULL;

    return 0;
}

void intialize(){
    int a =97;
    for(int i=0;i<26;i++){
        struct Hash *pHash = &Stats[i];
        pHash->letter= (char) a;
        a++;
    }
}

void countletters(FILE *f){
    int read;
    if(f!=NULL){
        while( (read = fgetc(f)) != EOF){
            if(97<=read&&read<=122){
                Stats[read-97].count++;
            }
        }
    }
}

void printStats(FILE *f){
    if(f!=NULL){
        bool space = false;
        fprintf(f,"\n");
        for(int i=0;i<26;i++){
            fprintf(f,"Count of letter %c is %d\n",Stats[i].letter,Stats[i].count);
            if(space == false)
                fprintf(f,"\t");
            else
                fprintf(f,"\n");
            space = !space;
        }
    }
}
