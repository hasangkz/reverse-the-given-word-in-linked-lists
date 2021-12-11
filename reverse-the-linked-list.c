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



list* push(list *root,char value){						//Linked listimize kelimenin eklenmesi için gerekli olan push fonksiyonu

	if(root==NULL){										//Eðer linked list boþ ise yapýlan kontrol
		root=(list *)malloc(sizeof(list));				//Boþ ise dinamik bellek ile yer ayrýlmasý
		root->value=value;								//O yere harfin eklenmesi
		root->next=NULL;								//Eklenen harften sonraki yerin NULL göstermesini saðlamalýyýz
		return root;									//Link listmizin baþlangýcý deðiþtiði için root return ediyoruz.
	}

	list *iter = root;									//Link list boþ deðil ise yeni eleman eklenmesi için geçici bir root yapýsýnda deðiþken oluþturuyoruz
	while(iter->next!=NULL){							//Listemizin sonuna gitmesi için yapýlan döngü
		iter=iter->next;
	}
	list *temp=(list *)malloc(sizeof(list));			//Listedinin sonuna yeni bellek açýlmasý
	temp->value=value;									//Açýlan belleðe harfin yerleþtirilmesi
	temp->next=NULL;									//Yeni yerden sonraki yerin NULL göstermesi
	iter->next=temp;
	return root;
}






list* pop(list *root,int *tempValue){					//Stack yapýsýndaki link listten eleman silmemize yarayan pop fonksiyonu

	if(root==NULL){										//Link list boþ ise verilen uyarý mesajý
		printf("Empty");
		return root;
	}
	if(root->next==NULL){								//Link listte 1 eleman var ise silmek için yapýlan kontrol
		*tempValue=root->value;							//Geçici deðiþken ile silinip yazdýrýlcak olan harfin tutulmasý
		list *temp=root;
		root=NULL;
		free(temp);										//Link listteki yerin silinmesi
		return root;
	}

	list *iter=root;									//Link listte 1 elemandan fazla eleman var ise listenin sonuna gitmemizi saðlayan döngü
	while(iter->next->next!=NULL){
		iter=iter->next;
	}

	list *temp =iter->next;
	*tempValue=temp->value;								//Listenin sonundaki deðeri geçici bir deðiþkende tutulmasý
	iter->next=NULL;
	free(temp);											//Listenin sonundaki belleðin silinmesi
	return root;
}


void print(list *root){								//Link listteki deðerlerin yazdýrýlmasýný saðlayan fonksiyon

	int i=0;
	int tempValue;
	while(root!=NULL){									//Link listenin sonuna kadar bütün elamanlarý almak için dönen döngü
		root=pop(root,&tempValue);						//Pop fonksiyonun çaðrýlmasý ile stack yapýsýndaki listenin son elemanýnýn alýnmasý
		printf("%c ",tempValue);
		i++;
	}

}

