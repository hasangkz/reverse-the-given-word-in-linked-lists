#include<stdio.h>
#include<stdlib.h>


struct s{
	char value;
	struct s *next;
};

typedef struct s list;

list* push(list *root,char value);
list* pop(list *root,int *tempValue);
void print(list *root);


int main(){

	int i;
	char kelime[100];

	list *root=NULL;

	printf("Kelimeyi Giriniz:");
	scanf("%s",kelime);

	i = 0;
	while(kelime[i] != '\0'){
		root = push(root,kelime[i]);
		i++;
	}


	print(root);

	return 0;
}



list* push(list *root,char value){						//Linked listimize kelimenin eklenmesi i�in gerekli olan push fonksiyonu

	if(root==NULL){										//E�er linked list bo� ise yap�lan kontrol
		root=(list *)malloc(sizeof(list));				//Bo� ise dinamik bellek ile yer ayr�lmas�
		root->value=value;								//O yere harfin eklenmesi
		root->next=NULL;								//Eklenen harften sonraki yerin NULL g�stermesini sa�lamal�y�z
		return root;									//Link listmizin ba�lang�c� de�i�ti�i i�in root return ediyoruz.
	}

	list *iter = root;									//Link list bo� de�il ise yeni eleman eklenmesi i�in ge�ici bir root yap�s�nda de�i�ken olu�turuyoruz
	while(iter->next!=NULL){							//Listemizin sonuna gitmesi i�in yap�lan d�ng�
		iter=iter->next;
	}
	list *temp=(list *)malloc(sizeof(list));			//Listedinin sonuna yeni bellek a��lmas�
	temp->value=value;									//A��lan belle�e harfin yerle�tirilmesi
	temp->next=NULL;									//Yeni yerden sonraki yerin NULL g�stermesi
	iter->next=temp;
	return root;
}






list* pop(list *root,int *tempValue){					//Stack yap�s�ndaki link listten eleman silmemize yarayan pop fonksiyonu

	if(root==NULL){										//Link list bo� ise verilen uyar� mesaj�
		printf("Empty");
		return root;
	}
	if(root->next==NULL){								//Link listte 1 eleman var ise silmek i�in yap�lan kontrol
		*tempValue=root->value;							//Ge�ici de�i�ken ile silinip yazd�r�lcak olan harfin tutulmas�
		list *temp=root;
		root=NULL;
		free(temp);										//Link listteki yerin silinmesi
		return root;
	}

	list *iter=root;									//Link listte 1 elemandan fazla eleman var ise listenin sonuna gitmemizi sa�layan d�ng�
	while(iter->next->next!=NULL){
		iter=iter->next;
	}

	list *temp =iter->next;
	*tempValue=temp->value;								//Listenin sonundaki de�eri ge�ici bir de�i�kende tutulmas�
	iter->next=NULL;
	free(temp);											//Listenin sonundaki belle�in silinmesi
	return root;
}


void print(list *root){								//Link listteki de�erlerin yazd�r�lmas�n� sa�layan fonksiyon

	int i=0;
	int tempValue;
	while(root!=NULL){									//Link listenin sonuna kadar b�t�n elamanlar� almak i�in d�nen d�ng�
		root=pop(root,&tempValue);						//Pop fonksiyonun �a�r�lmas� ile stack yap�s�ndaki listenin son eleman�n�n al�nmas�
		printf("%c ",tempValue);
		i++;
	}

}

