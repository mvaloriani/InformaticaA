#include <stdio.h>
#include <stdlib.h>
#define check_last() last == NULL? 0 : 1

struct dati_impiegato
{
	char nomi[32];
	struct dati_impiegato *next_struct;
};


struct dati_impiegato *last = NULL;


struct dati_impiegato *creanuovo()
{
	struct dati_impiegato *p =(dati_impiegato*)malloc(sizeof(dati_impiegato));
	if (p == NULL) return NULL;
	else
	{
		p->next_struct = NULL;
		return p;
	}
}

void inserisci()
{
	struct dati_impiegato *p = creanuovo();
	if (p == NULL) printf("Errore");
	else
	{
		printf("Nome: ");
		fgets(p->nomi, 32, stdin);
		if (!check_last()) last = p;
		else
		{
			struct dati_impiegato *a = last;
			last = p;
			last->next_struct = a;
		}
	}
}


void elimina(unsigned int n)
{
	if (!check_last()) printf("Lista non inizializzata");
	else
	{
		struct dati_impiegato *p, *t;
		p = last;
		if (n == 1)
		{
			last = last->next_struct;
			free(p);
		}
		else
		{
			unsigned int x = 1;
			while (1)
			{
				x++;
				t = p;
				p = p->next_struct;
				if (x == n)
				{
					t->next_struct = p->next_struct;
					free(p);
					break;
				}
			}
		}
	}
}

void visualizza()
{
	if (!check_last()) printf("Lista non inizializzata");
	else
	{
		struct dati_impiegato *p = last;
		while (1)
		{
			printf("%s", p->nomi);
			if (p->next_struct == NULL) break;
			p = p->next_struct;
		}
	}
}

void libera()
{
	if (!check_last()) printf("Lista non inizializzata");
	else
	{
		struct dati_impiegato * p = last;
		while (1)
		{
			p = last->next_struct;
			free(last);
			last = p;
			if (last == NULL && p == NULL) break;
		}
	}
}

unsigned int conteggio()
{
	if (!check_last())
	{
		printf("Lista non inizializzata");
		return 0;
	}
	else
	{
		unsigned int cont = 0;
		struct dati_impiegato *p = last;
		while (1)
		{
			cont++;
			p = p->next_struct;
			if (p == NULL) break;
		}
		return cont;
	}

}

struct dati_impiegato *last_one()
{
	if (!check_last())
	{
		printf("Lista non inizializzata");
		return NULL;
	}
	else
	{
		struct dati_impiegato *p = last;
		while (1)
		{
			if (p->next_struct == NULL) break;
			p = p->next_struct;
		}
		return p;
	}
}


void inverti()
{
	if (!check_last()) printf("Lista non inizializzata");
	else
	{
		struct dati_impiegato *p = last, *t, *c;
		unsigned int y = conteggio();
		unsigned int n;
		unsigned int f;
		f = n = y;
		y = ((y*y) - y) / 2;
		c = t = p;
		do
		{
			f--;
			for (n = f; n > 0; y--, n--)
			{
				p = p->next_struct;
				t->next_struct = p->next_struct;
				p->next_struct = t;
				if (n != f) c->next_struct = p;
				c = p;
				if (f == n || (n == 1 && f == 1))last = c;
				p = t;

			}
			p = c = t = last;
		} while (y > 0);
	}
}

int main()
{
	return 0;
}