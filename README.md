Olteanu Iulia,314
Cerinta 1+Cerinta 2:
Structura Tree pentru implementarea celor 2 cerinte contine: a (matricea asociata fiecarui nod),un vector de pointeri fii care poate avea maxim 9 elemente, un pointer catre parintele unui nod denumit tata, nr reprezinta numarul de fii, jucator ia numai 0 sau 1 in functie de jucatorul initial(X are valoarea 1 si O valoarea 0), nivel reprezinta numarul de nivele ale arborelui,viz este o eticheta daca un nod a fost vizitat sau nu , iar N reprezinta tot o eticheta care ia valoarea 1 daca nodul este true si 0 in cazul nodului false. 

Functia creare_rad construieste radacina arborelui,initializand toate campurile structurii Tree,asociindu-se nivelul 0 . Functia creare construieste arborele de joc pornind de la radacina cat timp matricea nu este completa.Functia gata verifica acest aspect, este luat fiecare caz in parte pentru verificare , pe linie , pe coloana , pe diagonala principala si cea secundara , returnand 1 in cazul in care matricea asociata nodului contine elemente de pe linie/coloana/diagonala principala/diagonala secundara egale fie cu X , fie cu O , in caz contrar returneaza 0.Pentru afisarea arborelui de joc construit pentru prima cerinta , am implementat functia afisare_ad care printeaza in adancime arborele plecand de la radacina , in cadrul functiei se apeleaza functia afisare_mat care afiseaza matricea dintr-un nod in fisier respectand indentarea ceruta in enunt , folosirea \t , iar pentru fiecare nod se vor afisa toti subarborii sai.Functia elibereaza are scopul de a elibera toata memoria alocata.

In main pentru cerinta 1 , am alocat dinamic spatiu matricea asociata unui nod, am citit din fisierul primit ca argument in linia de comanda jucatorul si configuratia initiala a tablei de joc intr-un sir de caractere , jucatorul fiind s[0],iar elementele matricei sunt indicii pari ai sirului s,deoarece dupa fiecare caracter urmeaza un spatiu, am creat radacina si ulterior arborele de joc prin apelul functiei creare, in final se apeleaza functia de afisare a arborelui in fiserul de iesire primit ca argument si se elibereaza toata memoria folosita.

Pentru cerinta a doua, main-ul este aproape identic , doar ca se mai apeleaza functia arbore_si_sau care evalueaza arborele de joc si atribuie fiecarui nod o eticheta.In acesta functie, arbore_si_sau, nodurile sunt etichetate in functie de nivelul pe care se afla,nodurile sau sunt situate pe nivel par , iar cele si pe nivel impar,deoarece jucator care incepe jocul vrea sa-si maximizeze castigul.In cazul nodurilor de tip sau este nevoie ca minim un fiu sa aiba eticheta 1 pentru ca si parintele sa fie etichetat la fel, iar pentru nodurile de tip si toti copiii trebuie sa fie etichetati cu 1 pentru ca si parintele sa fie etichetat la fel , in caz contrar tatal este etichetat cu 0.Functia verif este apelata in interiorul functiei arbore_si_sau , primeste ca parametrii un nod ar arborelui de joc si un caracter care reprezinta jucatorul care incepe jocul (X sau O), returnand 1 in cazul in care jucatorul initial castiga jocul si 0 in caz de remiza sau pierdere in fata adversarului, functia aceasta este asemanatoare cu cea folosita pentru prima cerinta, gata, realizeaza tot o verificare pe linii,coloane , pe diagonala principala si cea secundara.Pentru afisarea arborelui si_sau se apeleaza in main functia afisare_ad_si_sau,asemanatoare cu functia afisare_ad,in cazul in care campul N al unui nod are valoarea 1 se atribuie T,in caz contrar F,iar afisarea in fisier se realizeaza respectand indentarea ceruta

Cerinta 3:
Structura contine urmatoarele campuri:un vector de pointeri catre copii,un pointer catre parinte,nr(nr de fii),niv(nivelul unui nod),tip(0-nod intern si 1-frunza),viz(0 daca un nod nu a fost vizitat in functia ad3 si 1 daca nodul a fost vizitat),vizz(0 daca un nod nu a fost vizitat in functia tip_ad3 si 1 daca nodul a fost vizitat).Functia rad3 este asemanatoare cu cea implementata pt cerintele 1 si 2, sunt initializate toate campurile structurii.Crearea arborelui are loc in functia creare3,similara cu cea pt cerintele 1 si 2.Functia ad3 pune in noduri valoarea corespunzatoare nivelului(in cazul in care nivelul este par se pune minimul dintre valorile nodurilor , in caz contrar maximul).Functiile mini si maxi calculeaza minimul si maximul dintre valoriile nodurilor fii. In main am realizat citirea din fisier in felul urmator : am citit caracter , numar, caracter, iar in functia creare3 citirea se face astfel:caracter,numar,caracter,spatiu sau linie noua.Pentru afisare, am implementat functia tip_ad3 care realizeaza o parcurgere in adancime a arborelui creat.
