//#include <stdio.h>
//#include <malloc.h>
//
//
//typedef struct Biblioteca Biblioteca;
//typedef struct Nod Nod;
//
//struct Biblioteca {
//    char* nume;
//    int nrCarti;
//    int nrCititori;
//
//
//};
//
//struct Nod {
//    Biblioteca info;
//    Nod* next;
//};
//
//Biblioteca initializare(char* nume, int nrCarti, int nrCititori) {
//
//    Biblioteca b;
//    b.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
//    strcpy(b.nume, nume);
//    b.nrCarti = nrCarti;
//    b.nrCititori = nrCititori;
//
//    return b;
//}
//
//Nod* inserareInceput(Nod* cap, Biblioteca b) {
//    Nod* nou = (Nod*)malloc(sizeof(Nod));
//    nou->info = initializare(b.nume, b.nrCarti, b.nrCititori);  // deep-copy
//    nou->next = cap;
//
//    return nou;
//}
//
//void afisareLista(Nod* cap) {
//    while (cap != NULL) {
//        printf("Biblioteca %s are %d carti si %d cititori\n", cap->info.nume, cap->info.nrCarti, cap->info.nrCititori);
//        cap = cap->next;
//    }
//
//}
//
//char* getBibliotecaNrCartiPerCititor(Nod* cap) { // media
//    float max = 0;
//    char* nume_aux = NULL;
//
//
//    while (cap) {
//        if (cap->info.nrCarti / cap->info.nrCititori > max) {
//            max = cap->info.nrCarti / cap->info.nrCititori;
//            nume_aux = cap->info.nume;
//        }
//        cap = cap->next;
//    }
//
//    char* nume = (char*)malloc(sizeof(char) * (strlen(nume_aux) + 1)); //deep copy
//    strcpy(nume, nume_aux);
//
//
//    return nume;
//
//}
//
//void stergeLista(Nod** cap) { // modificam cap, transmitem doublu **
//
//    while ((*cap) != NULL) {
//        free((*cap)->info.nume);
//        Nod* copie = *cap;
//        *cap = (*cap)->next;
//        free(copie);
//    }
//
//}
//
//
//void inserareLaSfarsit(Nod** cap, Biblioteca b) {
//    Nod* sfarsit = (Nod*)malloc(sizeof(Nod));
//
//    sfarsit->info = initializare(b.nume, b.nrCarti, b.nrCititori);
//    sfarsit->next = NULL;
//
//
//    if ((*cap) != NULL) {
//        Nod* aux = (Nod*)malloc(sizeof(Nod)); //temp
//        aux = (*cap);
//
//        while (aux->next != NULL) {
//            aux = aux->next;
//        }
//
//        aux->next = sfarsit;
//    }
//    else {
//        *cap = sfarsit;
//    }
//}
//
//
//
//void main() {
//    Nod* cap = NULL;
//    Biblioteca b1 = initializare("Mihai Eminescu", 150, 20);
//    cap = inserareInceput(cap, b1);
//    Biblioteca b2 = initializare("Ioan Slavici", 200, 30);
//    cap = inserareInceput(cap, b2);
//    Biblioteca b3 = initializare("Tudor Arghezi", 150, 15);
//    cap = inserareInceput(cap, b3);
//
//
//    afisareLista(cap);
//
//    char* numeDeAfisat = getBibliotecaNrCartiPerCititor(cap);
//    printf("Biblioteca cu media cea mai mare: %s\n", numeDeAfisat);
//    free(numeDeAfisat);
//
//
//    Biblioteca b4 = initializare("Radu Tudoran", 100, 9);
//
//    inserareLaSfarsit(&cap, b4);
//    afisareLista(cap);
//
//
//
//    stergeLista(&cap);
//
//    free(b1.nume);
//    free(b2.nume);
//    free(b3.nume);
//    free(b4.nume);
//
//
//
//}