#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fichier;
    char c;
    int caracteres = 0, mots = 0, lignes = 0;
    int dans_mot = 0;

    fichier = fopen("texte.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return 1;
    }

    while ((c = fgetc(fichier)) != EOF) {
        caracteres++;

        if (c == '\n') {
            lignes++;
        }

        if (isspace(c)) {
            dans_mot = 0;
        } else if (dans_mot == 0) {
            dans_mot = 1;
            mots++;
        }
    }

    fclose(fichier);

    printf("Nombre total de caractères : %d\n", caracteres);
    printf("Nombre total de mots       : %d\n", mots);
    printf("Nombre total de lignes     : %d\n", lignes);

    return 0;
}
