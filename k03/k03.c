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
    int index;
    int key_index;
    int key_len = strlen(StrKey);
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
    index = key_len - 1;

    while(index < text_len){
        for(key_index=key_len-1;key_index>=0;key_index--){
            if (text[index] == key[key_index]) {
                count++;
                if (count == key_len) {
                    return &text[index-count];
                }
            } else {
                break ;
            }
        }


        index = index + table[text[index]];
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