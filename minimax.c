#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structura cerinta 1 + cerinta 2
typedef struct tree {
	char **a;
	struct tree *fii[9];
	struct tree *tata;
	int nr,jucator;
	int nivel,viz;
    int N;
} Tree;

// structura cerinta 3
typedef struct tree3 {
    struct tree3 *fii[20];
    struct tree3 *tata;
    int nr,niv,tip,val,viz,vizz;
} Tree3;

/// creaza nod radacina
Tree* creare_rad(char c,char **a) {
    Tree *rad=(Tree*)malloc(sizeof(Tree));
    rad->nr=0;
    rad->nivel=0;
    rad->viz=0;
    rad->N=0;
    rad->tata=NULL;
    int i,j;
    rad->a = malloc(3*sizeof(char *));
    if(c=='X') rad->jucator=1;
    else rad->jucator=0;
    for(i=0;i<3;i++) {
        rad->a[i]=(char *)malloc(3*sizeof(char));
        for(j=0;j<3;j++) {
            rad->a[i][j]=a[i][j];
        }
    }
    return rad;
}

/// afisaza matricea dintr-un nod
void afisare_mat(int nivel, Tree *nod, FILE *fout) {
    char s[100]="";
    int i,j;
    for(i=1;i<=nivel;i++)
        strcat(s,"\t");
    for(i=0;i<3;i++) {
        fprintf(fout,"%s",s);
        for(j=0;j<2;j++) fprintf(fout,"%c ",nod->a[i][j]);
        fprintf(fout,"%c",nod->a[i][2]);
        fprintf(fout,"\n");
    }
    fprintf(fout,"\n");
}

/// afisaza matricea dintr-un nod pe ecran
void afisare_ecr(int nivel, Tree *nod) {
    char s[100]="";
    int i,j;
    for(i=1;i<=nivel;i++)
        strcat(s,"\t");

    for(i=0;i<3;i++) {
        printf("%s",s);
        for(j=0;j<3;j++) printf("%c ",nod->a[i][j]);
        printf("\n");
    }
    printf("\n");
}

int gata(Tree *nod) {
    int i,j,sem;
    /// caut pe linii
    for(i=0;i<3;i++){
        sem=1;
        for(j=1;j<3;j++)
            if(nod->a[i][0]!=nod->a[i][j]) sem=0;
        if(sem==1) {
            if(nod->a[i][0]=='-') sem=0;
            else return 1;
        }
    }
    /// caut pe coloane
    for(j=0;j<3;j++) {
        sem=1;
        for(i=1;i<3;i++)
            if(nod->a[0][j]!=nod->a[i][j]) sem=0;
        if(sem==1) {
            if(nod->a[0][j]=='-') sem=0;
            else return 1;
        }
    }
    /// caut pe diag principala
    sem=1;
    for(i=1;i<3;i++)
        if(nod->a[i][i]!=nod->a[0][0]) sem=0;
    if(sem==1) {
        if(nod->a[0][0]=='-') sem=0;
        else return 1;
    }
    /// caut pe diagonala secundara
    sem=1;
    for(i=1;i<3;i++)
        if(nod->a[i][2-i]!=nod->a[0][2]) sem=0;
    if(sem==1){
        if(nod->a[0][2]=='-') sem=0;
        else return 1;
    }
    return 0;
}

/// creare arbore pornind de la radacina
void creare(Tree *rad, FILE *fout) {
    Tree **C;
    Tree *ad,*cr;

    C=(Tree **)malloc(100000*sizeof(Tree*));

    int p,u,i,j,ii,jj;

    p=u=1;
    C[u]=rad;

    while(p<=u) {
        cr=C[p];
        p++;

        if(gata(cr)==0){

        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                if(cr->a[i][j]=='-') {
                    ad=(Tree *)malloc(sizeof(Tree));
                    ad->nr=0;
                    ad->viz=0;
                    ad->N=0;
                    ad->a=malloc(3 *sizeof(char *));
                    for(ii=0;ii<3;ii++) {
                        ad->a[ii]=(char *)malloc(3*sizeof(char));
                        for(jj=0;jj<3;jj++)
                        ad->a[ii][jj]=cr->a[ii][jj];
                    }

                    ad->jucator=1-cr->jucator;
                    ad->nivel=cr->nivel+1;

                    if(cr->jucator==1) ad->a[i][j]='X';
                    else ad->a[i][j]='O';

                    ad->tata=cr;
                    cr->nr++;
                    cr->fii[cr->nr-1]=ad;
                    u++;
                    C[u]=ad;
                }
        }
        else {
            if(cr->jucator!=rad->jucator)cr->N=1;
            else cr->N=0;
        }
    }
    free(C);
}

/// afisare arbore din rad  in adancime
void afisare_ad(Tree *rad, FILE *fout) {
    Tree **ST;
    Tree *cr;

    ST=(Tree **)malloc(100000*sizeof(Tree*));

    int vf,i,gas;

    vf=1;
    ST[vf]=rad;
    afisare_mat(rad->nivel,rad,fout);
    rad->viz=1;

    while(vf>0) {
        cr=ST[vf];
        gas=0;

        for(i=0;i<=cr->nr-1&&gas==0;i++)
            if(cr->fii[i]->viz==0) {
                vf++;
                ST[vf]=cr->fii[i];
                afisare_mat(ST[vf]->nivel,ST[vf],fout);
                cr->fii[i]->viz=1;
                gas=1;
            }

        if(gas==0)vf--;
    }
    free(ST);
}

 void afisare_lat(Tree *rad) {
    Tree **C;
    Tree *cr;

    C=(Tree **)malloc(81*sizeof(Tree*));

    int p,u,i;

    p=u=1;
    C[u]=rad;
    afisare_ecr(rad->nivel,rad);
    while(p<=u) {
        cr=C[p];p++;
        for(i=0;i<=cr->nr-1;i++) {
            u++;
            C[u]=cr->fii[i];
            printf("\nNivel %d\n",C[u]->nivel);
            afisare_ecr(C[u]->nivel,C[u]);
        }
    }
    free(C);
}

void eliberez(Tree *rad) {
    Tree **C;
    Tree *cr;

    C=(Tree **)malloc(100000*sizeof(Tree*));

    int p,u,i;

    p=u=1;
    C[u]=rad;

    while(p<=u) {
        cr=C[p];p++;

        for(i=0;i<=cr->nr-1;i++) {
            u++;
            C[u]=cr->fii[i];

        }
    }
    int k;
    for(k=u;k>=1;k--) {
        for(i=0;i<3;i++)
            free(C[k]->a[i]);
        free(C[k]->a);
        free(C[k]);
    }
    free(C);
}

void afisare_ad_si_sau(Tree *rad,FILE *fout) {
    Tree **ST;
    Tree *cr;
    char ch,s[100]="";

    ST=(Tree **)malloc(100000*sizeof(Tree*));

    int vf,i,gas,k;

    vf=1;
    ST[vf]=rad;
    rad->viz=1;

    if(rad->N==1)ch='T';
    else ch='F';
    fprintf(fout,"%c\n",ch);

    while(vf>0) {
        cr=ST[vf];
        gas=0;
        for(i=0;i<=cr->nr-1&&gas==0;i++)
            if(cr->fii[i]->viz==0) {
                vf++;
                ST[vf]=cr->fii[i];
                strcpy(s,"");
                for(k=1;k<=ST[vf]->nivel;k++)
                    strcat(s,"\t");
                if(ST[vf]->N==1)ch='T';
                else ch='F';
                fprintf(fout,"%s%c\n",s,ch);

                cr->fii[i]->viz=1;
                gas=1;
            }

        if(gas==0)vf--;
    }
    free(ST);
}

// 1=castig ; 0=pierdere sau remiza
int verif(Tree *nod,char c) {
     int i,j,sem;
    /// caut pe linii
    for(i=0;i<3;i++) {
        sem=1;
        for(j=1;j<3;j++)
            if(nod->a[i][0]!=nod->a[i][j]) sem=0;
        if(sem==1) {
            if(nod->a[i][0]=='-') sem=0;
            else {
                if(nod->a[i][0]!=c) return 0;
                else return 1;
            }
        }
    }
    /// caut pe coloane
    for(j=0;j<3;j++) {
        sem=1;
        for(i=1;i<3;i++)
            if(nod->a[0][j]!=nod->a[i][j]) sem=0;
        if(sem==1){
            if(nod->a[0][j]=='-') sem=0;
            else {
                if(nod->a[0][j]!=c) return 0;
                else return 1;
            }
        }
    }
    /// pe diag principala
    sem=1;
    for(i=1;i<3;i++)
        if(nod->a[i][i]!=nod->a[0][0]) sem=0;
    if(sem==1) {
        if(nod->a[0][0]=='-') sem=0;
        else {
            if(nod->a[0][0]!=c) return 0;
            else return 1;
        }
    }
    /// pe sec
    sem=1;
    for(i=1;i<3;i++)
       if(nod->a[i][2-i]!=nod->a[0][2])sem=0;
    if(sem==1) {
        if(nod->a[0][2]=='-') sem=0;
        else {
            if(nod->a[0][2]!=c) return 0;
            else return 1;
        }
    }
    return 0;
}
void arbore_si_sau(Tree *rad,char c) {
    int i;
    if(rad->nr==0) {
        rad->N=verif(rad,c);
        return ;
    }
    for(i=0;i<rad->nr;i++) {
        arbore_si_sau(rad->fii[i],c);
    }
    for(i=0;i<rad->nr;i++) {
        // noduri sau->nivel par
        if(rad->nivel%2==0) {
            if(rad->fii[i]->N==1) {
                rad->N=1;
                return;
            }
        }
        // noduri si->nivel impar
        else {
            if(rad->fii[i]->N==0) {
                rad->N=0;
                return;
            }
        }
    }
    if(rad->nivel%2==0) rad->N=0;
    else rad->N=1;
}

///cerinta 3
Tree3* creare_rad3(int x) {
    Tree3 *rad3=(Tree3*)malloc(sizeof(Tree3));
    rad3->nr=x;
    rad3->niv=0;
    rad3->val=0;
    rad3->tip=0;     ///0 nod intern, 1 frunza
    rad3->tata=NULL;
    rad3->viz=0;
    rad3->vizz=0;
    return rad3;
}

int mini(Tree3 *cr) {
    int  i,x;

    x=cr->fii[0]->val;
    for(i=1;i<=cr->nr-1;i++)
         if(cr->fii[i]->val<x)x=cr->fii[i]->val;

    return x;
}

int maxi(Tree3 *cr) {
    int  i,x;

    x=cr->fii[0]->val;
    for(i=1;i<=cr->nr-1;i++)
         if(cr->fii[i]->val>x)x=cr->fii[i]->val;

    return x;
}

/// creare arbore pornind de la radacina
void creare3(Tree3 *rad3, FILE *fin) {
    Tree3 **C3;
    Tree3 *ad,*cr;
    char c,c1;
    int x;

    C3=(Tree3 **)malloc(200000*sizeof(Tree3*));

    int p,u,i;

    p=u=1;
    C3[u]=rad3;

    while(p<=u) {
        cr=C3[p];
        p++;

        if(cr->tip==0) {
 
            for(i=0;i<=cr->nr-1;i++) {

                ad=(Tree3 *)malloc(sizeof(Tree3));
                fscanf(fin,"%c",&c);
                fscanf(fin,"%d",&x);
                fscanf(fin,"%c%c",&c,&c1);
                ad->niv=cr->niv+1;
                ad->tata=cr;
                cr->fii[i]=ad;

                if(c==')') ad->tip=0;
                else ad->tip=1;

                if(ad->tip==0) {
                    ad->val=0;
                    ad->nr=x;
                    ad->viz=0;
                }
                else {
                    ad->val=x;
                    ad->nr=0;
                    ad->viz=1;
                }
                ad->vizz=0;
                u++;
                C3[u]=ad;
                if(c1==EOF)break;
            }
        }

    }
    free(C3);
}

void eliberare3(Tree3 *nod) {
    int i;
    for(i=0;i<nod->nr;i++)
        eliberare3(nod->fii[i]);
    free(nod);
}

void tip_ad3(Tree3 *cr,FILE *fout) {
    int i,j;
    char s[100]="";
    if(cr!=NULL) {

        if(cr->vizz==0) {
            strcpy(s,"");
            for(j=1;j<=cr->niv;j++)
                strcat(s,"\t");
            fprintf(fout,"%s",s);
            fprintf(fout,"%d\n",cr->val);
            cr->vizz=1;
        }
        for(i=0;i<=cr->nr-1;i++)
            tip_ad3(cr->fii[i],fout);
    }
}

void ad3(Tree3 *cr) {
    int i,ok;
    if(cr!=NULL){
        for(i=0;i<=cr->nr-1;i++)
            if(cr->fii[i]->viz==0) ad3(cr->fii[i]);

        ok=1;
        for(i=0;i<=cr->nr-1;i++)
            if(cr->fii[i]->viz==0) ok=0;

        if(ok==1) {
            if(cr->niv%2==1) cr->val=mini(cr);
            else cr->val=maxi(cr);
            cr->viz=1;
        }
    }
}

int main(int argc,char *argv[]) {
   FILE *fin, *fout;
   Tree *rad;
   Tree3 *rad3;
   char c,s[10];
   char **a;
   int i,j,lg,x;

// cerinta 1
	if (strcmp(argv[1],"-c1") == 0) {

		fin = fopen(argv[2], "r");
		fout = fopen(argv[3], "w");

		fgets(s,10,fin);
	    c=s[0];

		a =(char **)malloc(3*sizeof(char *));

		for(i=0;i<3;i++) {
            fgets(s,10,fin);
            a[i]=(char *)malloc(3*sizeof(char));
            for(j=0;j<3;j++)
                a[i][j]=s[2*j];
        }

	    rad=creare_rad(c,a);
	    creare(rad,fout);
		afisare_ad(rad,fout);

        eliberez(rad);
 	    fclose(fin);
 	    fclose(fout);
        for(i=0;i<3;i++) {
            free(a[i]);
        }
        free(a);
    }
// cerinta 2
    if (strcmp(argv[1],"-c2") == 0) {

		fin = fopen(argv[2], "r");
		fout = fopen(argv[3], "w");

		fgets(s,10,fin);
	    c=s[0];

		a =(char **)malloc(3*sizeof(char *));

		for(i=0;i<3;i++) {
            fgets(s,10,fin);
            a[i]=(char *)malloc(3*sizeof(char));
            for(j=0;j<3;j++)
                a[i][j]=s[2*j];
        }
	    rad=creare_rad(c,a);
	    creare(rad,fout);
		arbore_si_sau(rad,c);
        afisare_ad_si_sau(rad,fout);
        eliberez(rad);
 	    fclose(fin);
 	    fclose(fout);
        for(i=0;i<3;i++) {
            free(a[i]);
        }
        free(a);
    }
// cerinta 3
    if(strcmp(argv[1],"-c3")==0) {
   
        fin = fopen(argv[2], "r");
        fout = fopen(argv[3], "w");
        fscanf(fin,"%d",&lg);
        fgetc(fin);

        fscanf(fin,"%c",&c);
        fscanf(fin,"%d",&x);

        fscanf(fin,"%c",&c);
        fgetc(fin);

        rad3=creare_rad3(x);

        creare3(rad3,fin);

        ad3(rad3);

        tip_ad3(rad3,fout);
        eliberare3(rad3);

        fclose(fin);
        fclose(fout);
   }

return 0;
}
