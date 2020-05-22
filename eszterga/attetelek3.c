#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main (int argc , char * argv[]) {
    //int n = atof(argv[1]);
    int n = 0;
    //printf("Adja meg a fogaskerekek.txt fajl sorainak szamat:\n");
    //scanf("%d", &n);

    FILE *nfk = fopen("fogaskerekek.txt", "r");
	if (nfk == 0) {
		printf("Nem lehet megnyitni a fajlt %s.\n","fogaskerekek.txt");
		exit(-1);
	}

    for (int i = 0; i < 1;) {
        int s = -1;
        fscanf(nfk, "%d\n", &s);
        if (s > 0) {
            n++;
        }
        else if (s == 0) {
            i++;
            break;
        }
        else {
            printf("A fogaskerekek.txt nem tartalmaz zaro 0-t.\nIrj a lista vegere egy 0 szamot!\n");
            printf("A kilepeshez nyomjon entert.(2-szer)\n");
            getchar();
            getchar();
            exit(-1);
        }
    }

    fclose(nfk);

    FILE *f = fopen("fogaskerekek.txt", "r");
	if (f == 0) {
		printf("Nem lehet megnyitni a fajlt %s.\n","fogaskerekek.txt");
		exit(-1);
	}

    FILE *out = fopen("attelelek3.txt", "w");
	if (out == 0) {
    	printf("Nem lehet megnyitni a fajlt.\n");
		exit(-1);
	}
    fprintf(out, "1. fk.\t2. fk.\t3. fk.\t4. fk.\telotolas\ttengely\n");
    
    double *fk = (double*)malloc(n * sizeof(double));
    char *fkc = (char*)malloc(n * sizeof(char));
    //memset(fkc, 0, 100);
    //fscanf(f, "%s\n", fkc);
    for (int i = 0; i < n; i++) {
        memset(fkc, 0, n);
        fscanf(f, "%lf\n", &fk[i]);
    }
    //memset(fkc, 0, 100);
    //fscanf(f, "%s\n", fkc);
    int o = 0;
    double q = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    o++;
                    double p = o;
                    printf("%f%c\r", p/(q*q*q*q)*100, 37);
                    //printf("%.0f\t%.0f\t%.0f\t%.0f\t%f\t%f\n", fk[i], fk[j], fk[k], fk[l], fk[i] / fk[l] * 2.1, fk[i]/fk[j]*(fk[k]/fk[l])*2.1);
                    fprintf(out, "%.0f\t%.0f\t%.0f\t%.0f\t%f\tkulon\n", fk[i], fk[j], fk[k], fk[l], fk[i] / fk[l] * 2.1);
                    fprintf(out, "%.0f\t%.0f\t%.0f\t%.0f\t%f\tkozos\n", fk[i], fk[j], fk[k], fk[l], fk[i]/fk[j]*(fk[k]/fk[l])*2.1);
                }
            }
        }
        //printf("%f %f\n", fk[i], fk[i]/fk[i-1]);
    }
    fclose(f);
    fclose(out);
    free(fk);
    printf("A kilepeshez nyomjon entert.(2-szer)\n");
    getchar();
    getchar();
    /*char end;
    for (int i = 0; i < 1;) {
        printf("A kilepeshez irja be az close szot, majd nyomjon entert.\n");
        scanf("%s", &end);
        if (&end ==  "close") {
            printf("1");
            break;
        }
        else {
            printf("2");
        }
    }*/
    return (0);
}