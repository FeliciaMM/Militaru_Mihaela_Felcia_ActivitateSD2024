#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

struct Ferma{
	char* nume;
	int nrGrajduri;
	int* Animale;
};

struct Ferma* citire(struct Ferma* f) {

	f->nume = (char*)malloc(100 * sizeof(char));
	printf("Introduceti numele fermei: ");
	scanf("%s", f->nume);

	printf("Introducetu numarul de grajduri: ");
	scanf("%d", &(f->nrGrajduri));

	f->Animale = (int*)malloc(f->nrGrajduri * sizeof(int));
	for (int i = 0; i < f->nrGrajduri; i++) {
		printf("Introduceti numarul de animale din fiecare grajd: ");
		scanf("%d", &(f->Animale[i]));
	}

	return f;

}

int celeMaiPutineAnimale(struct Ferma* f) {
	int minim = f->Animale[0];
	for (int i = 1; i < f->nrGrajduri; i++) {
		if (f->Animale[i] < minim) {
			minim = f->Animale[i];
		}
	}
	printf("Cel mai mic numar de animale din ferma este: %d\n", minim);

	return f;
}

void afisare(struct Ferma f) {
	printf("Nume: %s\n", f.nume);
	printf("Numar grajduri: %d\n", f.nrGrajduri);
	for (int i = 0; i < f.nrGrajduri; i++) {
		printf("Grajdul %d are %d animale\n", i + 1, f.Animale[i]);
	}
}

void modificare(struct Ferma* f, char* nume) {
	free(f->nume);
	f->nume = (char*)malloc((strlen(nume) + 1) * sizeof(char));
	strcpy(f->nume, nume);
	printf("Numele fermei a fost modificat\n");
}


int main() {
	struct Ferma f;
	citire(&f);
	printf("Ferma %s are: \n", f.nume);
	afisare(f);
	modificare(&f, "Ferma cailor");
	afisare(f);
	int minAnimale = celeMaiPutineAnimale(&f);
	return 0;
}