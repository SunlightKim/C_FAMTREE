/* Make a family tree in C using structures */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc/clearbuffer.h"

/* INFORMATIONS IMPORTANTES */
/* En raison de la complexité du programme, j'ai décidé que chaque personne
* ne peut avoir qu'un seul enfant. Cela permet de simplifier le programme et
* de ne pas avoir à gérer des listes d'enfants.
* De plus, le programme ne permet pas de gérer les frères et sœurs.
* Enfin, le programme ne permet pas de gérer les grands-parents, les oncles, les tantes, les cousins, etc.
* Ces options seront ajoutées dans une version ultérieure, qui utilisera
* des fichiers json pour stocker les informations. Ce qui permettra de
* gérer des familles plus complexes, et de gérer les relations entre les membres de la famille,
* tout en gardant un code plus simple et plus lisible que s'il était écrit en C pur.
*/

// Structure de données pour les personnes
// La persone est définie par son nom complet, son âge, son père, sa mère, son époux(se) et son enfant
struct person {
    char name[255];
    int age;
    struct person *father;
    struct person *mother;
    struct person *spouse;
    struct person *child;
};

// Fonction pour créer une personne
struct person *newPerson(char *name, int age) {
    struct person *new = malloc(sizeof(struct person));
    strcpy(new->name, name);
    new->age = age;
    new->father = NULL;
    new->mother = NULL;
    new->spouse = NULL;
    new->child = NULL;
    return new;
}

// Fonction pour ajouter le père
void addFather(struct person *child, struct person *father) {
    child->father = father;
}

// Fonction pour ajouter la mère
void addMother(struct person *child, struct person *mother) {
    child->mother = mother;
}

// Fonction pour ajouter l'époux(se)
void addSpouse(struct person *person1, struct person *person2) {
    person1->spouse = person2;
    person2->spouse = person1;
}

// Fonction pour ajouter l'enfant
void addChild(struct person *parent, struct person *child) {
    parent->child = child;
}

/* AFFICHAGE DE LA PERSONNE */
// ('nom' a 'age' ans, 'father' est son père, 'mother' est sa mère et 'spouse' est son époux(se). 
// Il a 'child' comme enfant.)
void printPerson(struct person *person) {
    printf("%s a %d ans. ", person->name, person->age);
    if (person->father != NULL) {
        printf("%s est son père, il a %d ans. ", person->father->name, person->father->age);
    }
    if (person->mother != NULL) {
        printf("%s est sa mère, elle a %d ans. ", person->mother->name, person->mother->age);
    }
    if (person->spouse != NULL) {
        printf("%s est son époux(se). Il/elle a %d ans. ", person->spouse->name, person->spouse->age);
    }
    if (person->child != NULL) {
        printf("Il/elle a %s comme enfant, il/elle a %d ans. ", person->child->name, person->child->age);
    }
}

/* FONCTION MAIN */
int main() {
    // Créer une personne
    char name[20];
    int age;
    printf("Entrez son nom complet (sans accents): ");
    scanf_s("%s", name);
    clearBuffer();
    printf("Entrez son âge : ");
    scanf_s("%d", &age);
    clearBuffer();
    struct person *person = newPerson(name, age);

    // Créer le père de la personne
    printf("Entrez le nom du père (sans accents) : ");
    scanf_s("%s", name);
    clearBuffer();
    printf("Entrez l'âge du père : ");
    scanf_s("%d", &age);
    clearBuffer();
    struct person *father = newPerson(name, age);
    addFather(person, father);

    // Créer la mère de la personne
    printf("Entrez le nom de la mère (sans accents) : ");
    scanf_s("%s", name);
    clearBuffer();
    printf("Entrez l'âge de la mère : ");
    scanf_s("%d", &age);
    clearBuffer();
    struct person *mother = newPerson(name, age);
    addMother(person, mother);

    // Créer l'époux(se) de la personne
    printf("Entrez le nom de l'époux(se) (sans accents) : ");
    scanf_s("%s", name);
    clearBuffer();
    printf("Entrez l'âge de l'époux(se) : ");
    scanf_s("%d", &age);
    clearBuffer();
    struct person *spouse = newPerson(name, age);
    addSpouse(person, spouse);

    // Créer l'enfant de la personne
    printf("Entrez le nom de l'enfant (sans accents) : ");
    scanf_s("%s", name);
    clearBuffer();
    printf("Entrez l'âge de l'enfant : ");
    scanf_s("%d", &age);
    clearBuffer();
    struct person *child = newPerson(name, age);
    addChild(person, child);

    // Afficher la personne
    printPerson(person);

    // Attendre que l'utilisateur appuie sur une touche pour quitter
    printf("\nAppuyez sur une touche pour quitter...");
    getchar();

    return 0;
}