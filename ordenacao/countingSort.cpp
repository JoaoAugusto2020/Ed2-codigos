#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<ctype.h>

using namespace std;

void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

//complexidade de tempo: O(max(n, m)) onde m é o maior elemento do vetor
//complexidade de espaço: O(m)
void countingSort(int v[], int n, int m) {
    int tmp[m + 1];
    for (int i = 0; i < m + 1; i++) tmp[i] = 0;
    for (int i = 0; i < n; i++) {
        tmp[v[i]]++;
    }
    for(int i=0; i<n; i++){
    	cout<<"i="<<i<<" ";
    	cout<<tmp[i]<<" "<<endl;
	}
    for (int i = 0, j = 0; i < m + 1; i++) {
        while(tmp[i] > 0) {
            v[j++] = i;
            tmp[i]--;
        }
    }
}

int main(){
	int v[] = { 1, 3, 5, 2, 4, 7, 8, 4, 1 };
    countingSort(v, 9, 8);
    cout<<endl;
    imprimir(v, 9);

	return 0;
}

