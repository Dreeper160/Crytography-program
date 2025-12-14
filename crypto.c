#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main(int argc, char const *argv[])
{   // Verification de ce que l'utilsateur entre
    if (argc != 4 )
    {
        printf("Le programme de cryptage se fait sous la forme ./cryptographie <fichier> <clé> <sortie>\n");
        return 1; 
    }
    FILE * fichier = NULL;
    fichier = fopen(argv[1], "rb");

    if (fichier == NULL)
    {   printf("Impossible de lire le fichier! Veuillez verifier le nom du fichier");
        return 1;
    }
    
    FILE * output = NULL;
    output = fopen(argv[3], "wb"); // extension de moi meme
    unsigned char buffer[BUFSIZE];
    size_t octetsLus;
    printf("====Cryptage en cours ====");
    while ((octetsLus = fread(buffer, 1, BUFSIZE, fichier)) > 0) 
    {
        for (int i = 0; i < octetsLus; i++) {
            buffer[i] = buffer[i]^ *argv[2];
        }

        fwrite(buffer, 1, octetsLus, output);

    }

    
    fclose(fichier);
    printf("Fichier d'entréee fermé avec succes\n");
    fclose(output);
    printf("Fichier de sortie fermer avec succès\n");
    printf("====Cryptage terminé ====\n");

    
    return 0;
}
