void selectionSort(int *v, int n){
    for(int i = 0 ; i < n; i++){
        int menor = i;
        for (int j = i; j < n; j++){
            if (v[j] < v[menor])
                menor = j;
        }
        int aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

void insertSort(int *v, int n){
    for (int i = 1; i < n; i++){
        int k = v[i];
        int j = i-1;
        while((j >= 0) && (v[j]>k)){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = k;
    }
}

void shellSort(int *v, int n){
    int h = 0;
    while(h < n)
        h = 3*h+1;
    h = h/3;
    while (h>0){
        for(int i = h; i<n; i++){
            int k = v[i];
            int j = i;

            while((j >= h) && (v[j-h]>k)){
                v[j] = v[j-h];
                j = j-h;
            }
            v[j] = k;
        }
        h = h/3;
    }
}

//-------------------------MERGE SORT---------------------------

void merge(int *v, int ini, int m, int n){
    int r[n-ini+1];
    int index = 0;
    int in = ini;
    int me = m;
    while((in < m) && (me < n)){
        if(v[in] <= v[me])
            r[index++] = v[in++];
        else
            r[index++] = v[me++];
    }
    while(in < m)
        r[index++] = v[in++];
    while(me < n)
        r[index++] = v[me++];

    for(int k = 0; k < index; k++)
        v[k+ini] = r[k];
}

void mergeSort(int *v, int ini, int n){
    if(ini != n-1){
        int m = (ini+n)/2;
        mergeSort(v, ini, m);
        mergeSort(v, m, n);
        merge(v, ini, m, n);
    }
}

//--------------------QUICK SORT----------------------------

int separa(int *v, int ini, int n){
    int pivo = v[ini];
    int esq = ini;
    int dir = n;
    int troca;
    while(esq < dir){
        while(v[esq] <= pivo)
          esq++;
        while(v[dir] > pivo)
           dir--;
        if(esq < dir){
            troca = v[esq];
            v[esq] = v[dir];
            v[dir] = troca;
        }
    }

    v[ini] = v[dir];
    v[dir] = pivo;
    return dir;
}
//Recebe o inicio e o fim do vetor
void quickSort(int *v, int ini, int fim){
    if(fim > ini){
        int j = separa(v, ini, fim);
        quickSort(v, ini, j-1);
        quickSort(v, j+1, fim);
    }
}

//----------------HEAP SORT-----------------------------//

void fixDownHeap(int *v, int n, int pos){
    int value = v[pos];
    int j = 2*pos;

    while(j<=n){
        if((j<n)&&(v[j]<v[j+1]))
            j++;
        if(value>v[j])
            break;

        v[j/2] = v[j];
        j*=2;
    }
    v[j/2] = value;


}

void heapify(int *v, int n){
    for(int k = n/2 ; k > 0; k--)
        fixDownHeap(v, n, k);
}

void heapsort(int *v, int n){
    heapify(v, n);

    int aux;
    for(int i = n; i > 1; i--){
        aux = v[1];
        v[1] = v[i];
        v[i] = aux;
        fixDownHeap(v, i-1, 1);
    }
}
