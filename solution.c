#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void BSort(double*, int);

int main(void)
{
    FILE* ina;
    FILE* inb;
    
    FILE* out;
    double* A;
    double* B;
    int NA, NB;
    int i;
    double x;
    
    if ((ina=fopen("ina.txt","r"))==NULL) return -1;
    if ((inb=fopen("inb.txt","r"))==NULL) return -1;
    
    while (fscanf(ina,"%lf", &x)==1)  NA++;
    while (fscanf(inb,"%lf", &x)==1)  NB++;
    
    out = fopen("output.txt","w");
    
    printf("%d \n",NA);
    printf("%d \n",NB);
    
    if ((NA>0)&& feof(ina) && (NB>0) && feof(inb)) {
        fseek(ina,0,SEEK_SET);
        A = (double*) malloc(NA*sizeof(double));
        for (i=0;i<NA;i++)  fscanf(ina,"%lf", &A[i]);
        
        
        fseek(inb,0,SEEK_SET);
        B = (double*) malloc(NB*sizeof(double));
        for (int j=0;j<NB;j++)  fscanf(inb,"%lf", &B[j]);
        {
            BSort(A,NA);
            BSort(B,NB);
            
            int dlt;
            int nnn = (NA<NB) ? NA: NB;
            int maxn = NA+NB-nnn;
            double max;
            
            printf("%d \n",nnn);
            printf("%d \n",maxn);
            
            //dlt=A[0]-B[0];
            
            //for(int f=0; f<NA; f++) {
            //        printf("%lf ",A[f]);
            //}
            
            for(int q=0; q<nnn; q++) {
                if (A[q]>B[q]) {
                    fprintf(out,"NO");
                    free(A);
                    free(B);
                    fclose(inb); 
                    fclose(ina); 
                    fclose(out);
                    return 0;
                }
            }
            for (int z=(nnn-1); z<maxn;z++) {
                if (NA==nnn) {
                    if (A[nnn-1]>B[z]) {
                        fprintf(out,"NO");
                        free(A);
                        free(B);
                        fclose(inb); 
                        fclose(ina); 
                        fclose(out);
                        return 0;
                    }
                }
                if (NB==nnn) {
                    max=B[nnn-1];
                    printf("maxB= %lf \n",max);
                    if (A[z]>=max) {
                        fprintf(out,"NO");
                        free(A);
                        free(B);
                        fclose(inb); 
                        fclose(ina); 
                        fclose(out);
                        return 0;
                    }
                }
                printf("%lf %lf \n", A[z], B[z]);
            }
            //printf("%d \n",qa);
            //printf("%d \n",qb);
            fprintf(out,"YES");
            
        }
        free(A);
        free(B);
    } 
    else return -1;
    fclose(inb); fclose(ina); fclose(out);
return 0;
}

void BSort (double a[], int n) {
    int i,j;
    double t;
    
    for (i=0;i<n;i++) {
        for (j=0;j<n-1-i;j++) 
        {
            if (a[j]>a[j+1]) {
               t=a[j];
               a[j]=a[j+1];
               a[j+1]=t;
            }
        }
    }
}