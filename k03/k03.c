#include <stdio.h>
#include <string.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    int start;
    int text_len = strlen(StrOriginal);
    int pos;
    int key_len = strlen(StrKey);
    int i=0;

    for(start=0;start<text_len - key_len;start++){
        for(pos=0;pos<key_len;pos++){

            if(text[start+pos] == key[pos]){   
            i++;
            } else{
                break;
            }
            
            if(i == key_len){
            return &text[start];        
            }


        }
    }
    return NULL;
    //  ここを実装する

}

char* BMSearch(char text[], char key[])
{
    int text_len = strlen(StrOriginal);
    int key_len = strlen(StrKey);
    int key_index = key_len -1;
    int i,n=0;
    int count=0;
    int table[256];
    int m=key_len;

    for(i=0;i<256;i++){
        table[i]=key_len;
    }

    for(n=0 ; n<key_len ; n++){
        table[StrKey[n]]=m-1;
        m--;
    }

    int index = key_len - 1;
    int start_index = key_len - 1;

    while(index < text_len){

        for(key_index=key_len-1;key_index>=0;key_index--){
            printf("%s\n", text);
            for (int k=0; k < index - key_len + 1; k++) {
            printf(" ");
            }
            printf("%s\n", key);
            printf("count= %d\n", count);
            if (text[index] == key[key_index]) {
                index--;
                count++;
                if (count == key_len) {
                    return &text[index];
                }
            } else  {
                count = 0;
                break ;
            }
        }

    index = index + table[text[index]];
        if(index <= start_index){
            index = start_index + 1;
        }
    start_index = index;

    }
    return NULL;

    }

    //  ここを実装する


int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}