//Write your code in this file
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define Num_elever 5
#define Num_prov 13

typedef struct {                //Struktur en för att lagra information om elever
    char namn[11];              // Max 10 tecken + 1 för null-terminator
    int poang[Num_prov];        // 13 prov
    float medel;                // Medelvärde
} Elev;
// Funktion för att formatera namnet
void formatNamn(char *namn){
    namn[0] = toupper(namn[0]);
    for (int i = 1; namn[i] != '\0'; i++) {
        namn[i] = tolower(namn[i]);
    }
}
int main(){
    Elev elever[Num_elever];
    float totalMedel = 0.0;
    int i, j;
    // Läser in elevernas namn och poäng
    for (i = 0; i < Num_elever; i++) {
        scanf("%s", elever[i].namn);
        for (j = 0; j < Num_prov; j++) {
            scanf("%d", &elever[i].poang[j]);
        }
        // Beräknar medelvärdet för varje elev
        int sum = 0;
        for (j = 0; j < Num_prov; j++) {
            sum += elever[i].poang[j];
        }
        elever[i].medel = sum / (float)Num_prov;
        totalMedel += elever[i].medel;
    }
// hittar eleven med högst medelvärde
int maxIndex = 0;
for (i = 1; i < Num_elever; i++) {
    if (elever[i].medel > elever[maxIndex].medel) {
        maxIndex = i;
    }
}
formatNamn(elever[maxIndex].namn);
printf("%s\n", elever[maxIndex].namn);
    totalMedel /= Num_elever;                    //Beräknar klassens totala medel värde

    for (i = 0; i < Num_elever; i++){

        if (elever[i].medel < totalMedel) {
            formatNamn(elever[i].namn);
            printf("%s\n", elever[i].namn);
        }

    }
       return 0;
    }