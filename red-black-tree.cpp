#include<stdio.h>
#include<stdlib.h>

enum cor {VERMELHO , PRETO};
typedef struct no *p_no;
struct no {
	int chave;
 	enum cor cor;
 	p_no esq, dir;
};

p_no inserir(p_no raiz, int chave);
p_no inserir_rec(p_no raiz, int chave);
void inOrdem(p_no raiz);
int ehPreto(p_no x);
int ehVermelho(p_no x);
void inOrdem(p_no raiz);
p_no rotaciona_para_esquerda(p_no raiz);
p_no rotaciona_para_direita(p_no raiz);

int main(){
	p_no raiz = NULL;
	raiz = inserir(raiz,20);
	raiz = inserir(raiz,30);
	raiz = inserir(raiz,40);
	raiz = inserir(raiz,10);
	raiz = inserir(raiz,12);
	raiz = inserir(raiz,5);
	inOrdem(raiz);
	return 0;
}

void inOrdem(p_no raiz){
	if(raiz != NULL){
		inOrdem(raiz->esq);
		inOrdem(raiz->dir);
		printf("%d (%s) ",raiz->chave,raiz->cor == VERMELHO ? "Vermelho" : "Preto");
	}
}

p_no inserir_rec(p_no raiz, int chave) {
 	p_no novo;
 	if (raiz == NULL) {
 	novo = malloc(sizeof(struct no));
 	novo->esq = novo->dir = NULL;
 	novo->chave = chave;
 	novo->cor = VERMELHO;
 	return novo;
	}
	if (chave < raiz->chave)
 	raiz->esq = inserir_rec(raiz->esq, chave);
 	else
 	raiz->dir = inserir_rec(raiz->dir, chave);
 	if (ehVermelho(raiz->dir) && ehPreto(raiz->esq))
 	raiz = rotaciona_para_esquerda(raiz);
 	if (ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq)) raiz = rotaciona_para_direita(raiz);
 	if (ehVermelho(raiz->esq) && ehVermelho(raiz->dir)) sobe_vermelho(raiz);
 	return raiz;
 }
 
 p_no rotaciona_para_esquerda(p_no raiz) {
 	p_no x = raiz->dir;
 	raiz->dir = x->esq;
 	x->esq = raiz;
 	x->cor = raiz->cor;
 	raiz->cor = VERMELHO;
 	return x;
 }

  p_no rotaciona_para_direita(p_no raiz) {
 	p_no x = raiz->esq;
 	raiz->esq = x->dir;
 	x->dir = raiz;
 	x->cor = raiz->cor;
 	raiz->cor = VERMELHO;
 	return x;
 }
 
void sobe_vermelho(p_no raiz) {
 	raiz->cor = VERMELHO;
 	raiz->esq->cor = PRETO;
 	raiz->dir->cor = PRETO;
 }
 
p_no inserir(p_no raiz, int chave) {
		raiz = inserir_rec(raiz, chave);
 		raiz->cor = PRETO; 
 		return raiz;
 }

 int ehVermelho(p_no x) {
	if (x == NULL)
	return 0;
	return x->cor == VERMELHO;
}

int ehPreto(p_no x) {
	if (x == NULL)
	return 1;
	return x->cor == PRETO;
}
