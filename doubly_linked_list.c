#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64

typedef struct node
{
    int ogrenci_no;
    char ad[MAX];
    char soyad[MAX];
    char bolum[MAX];
    int sinif;
    struct node *left,*right;
}Node;

Node *newNode(int no, char *ad,char *soyad, char *bolum, int sinif);
Node *addNode(Node *node, int no, char *ad, char *soyad, char *bolum, int sinif);
Node *deleteNode(Node *node, int no);
Node *findMin(Node *node);
Node *searchNode(Node *node, int no);
int size(Node *node);
void printInOrder(Node *node);
Node *createLinkedList(Node *root);
Node *deleteList(Node *root);

int main()
{
    Node *root=NULL;
    int choice=0,no=0,sinif;
    char ad[MAX],soyad[MAX],bolum[MAX];
    while(((choice >= 0) && (choice <= 8)))
    {

        printf("\n\tLutfen gecerli bir sayi giriniz.\n\n");
        printf("\tLinkli liste olusturmak icin 1.\n");
        printf("\tBir ogrenci kaydi silmek icin 2.\n");
        printf("\tOgreni kaydi aramasi yapmak icin 3.\n");
        printf("\tTum kayitlari yazdirmak icin 4.\n");
        printf("\tYeni bir ogrenci kaydi eklemek icin 5.\n");
        printf("\tTum kayitlari silmek icin 6.\n");
        printf("\tProgramdan cikis yapmak icin -1.\n");
        scanf("%d", &choice);

        switch(choice)  {
            case 1:
                root = createLinkedList(root);
                printf("\nLinki liste basarili bir sekilde olusturuldu.\n");
                break;
            case 2:
                printf("Ogreni numarasini giriniz: ");
                scanf("%d",&no);
                root=deleteNode(root, no);
                printf("\nKayit basarili bir sekilde silindi.\n");
                break;
            case 3:
                printf("Ogrenci numarasini giriniz: ");
                scanf("%d",&no);
                searchNode(root, no);
                break;
            case 4:
                printInOrder(root);
                break;
            case 5:

                printf("\nOgrenci numarasini giriniz: ");
                scanf("%d", &no);
                printf("\nOgrencinin adini giriniz: ");
                scanf("%s", ad);
                printf("\nOgrencinin soyadini giriniz: ");
                scanf("%s", soyad);
                printf("\nOgrencinin bolumunu giriniz: ");
                scanf("%s", bolum);
                printf("\nOgrencinin sinifini giriniz: ");
                scanf("%d", &sinif);
                root=addNode(root,no,ad,soyad,bolum,sinif);
                printf("Ogrenci kaydi basarili bir sekilde eklendi.\n");
                printf("Eklenen ogrenci -> Ogrenci no: %d\t ad: %s \t soyad: %s\t bolum: %s\t sinif: %d\n",
                       root->ogrenci_no, root->ad, root->soyad, root->bolum, root->sinif);
                break;
            case 6:
                root=deleteList(root);
                printf("Tum kayitlar basarili bir sekilde silindi.\n");
        }
    }
    return 0;
}

Node *newNode(int no, char *ad,char *soyad, char *bolum, int sinif)
{
    Node *temp=(Node *)malloc(sizeof(Node));

    temp->ogrenci_no=no;
    strcpy(temp->ad, ad);
    strcpy(temp->soyad, soyad);
    strcpy(temp->bolum, bolum);
    temp->sinif=sinif;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

Node *addNode(Node *node, int no, char *ad, char *soyad, char *bolum, int sinif)
{
    if(node == NULL)
    {
        return newNode(no, ad, soyad, bolum, sinif);
    }

    if(no < node->ogrenci_no)
    {
        node->left= addNode(node->left, no, ad, soyad, bolum, sinif);
    }
    else if(no > node->ogrenci_no)
    {
        node->right= addNode(node->right, no, ad, soyad, bolum, sinif);
    }
    else
    {
        printf("Node'a esit tekrar deneyiniz.\n");
    }

    return node;
}

Node *deleteNode(Node *node, int no)
{
    if(node == NULL)
    {
        printf("Liste bos gorunuyor. Lutfen once eleman eklemeyi deneyiniz.\n");
        return node;
    }
    else
    {
        if(no < node->ogrenci_no)
        {
            node->left= deleteNode(node->left, no);
        }
        else if(no > node->ogrenci_no)
        {
            node->right= deleteNode(node->right, no);
        }
        else
        {
            if(node->left == NULL)
            {
                Node *temp=node->right;
                free(node);
                return temp;
            }
            else if(node->right == NULL)
            {
                Node *temp=node->left;
                free(node);
                return temp;
            }
            Node *temp=findMin(node->right);
            node->ogrenci_no=temp->ogrenci_no;
            strcpy(node->ad, temp->ad);
            strcpy(node->soyad, temp->soyad);
            strcpy(node->bolum, temp->bolum);
            node->sinif=temp->sinif;
            node->right= deleteNode(node->right, temp->ogrenci_no);
        }
    }
    return node;
}

Node *findMin(Node *node)
{
    Node *temp=node;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

Node *searchNode(Node *node, int no)
{
    if(node == NULL)
    {
        printf("\nListe bos. Tekrar deneyiniz.\n");
    }
    else
    {
        if(no < node->ogrenci_no)
        {
            return searchNode(node->left, no);
        }
        else if(no > node->ogrenci_no)
        {
            return searchNode(node->right, no);
        }
        else
        {
            printf("Bulunan ogrenci -> Ogrenci no: %d\t ad: %s \t soyad: %s\t bolum: %s\t sinif: %d\n",
                   node->ogrenci_no, node->ad, node->soyad, node->bolum, node->sinif);
            return node;
        }
    }
}

int size(Node *node)
{
    if(node == NULL)
    {
        return 0;
    }
    else
    {
        return ((size(node->left)) + (size(node->right)) + 1);
    }
}

void printInOrder(Node *node)
{
    if(node != NULL)
    {
        printInOrder(node->left);
        printf("\nOgrenci no: %d\t ad: %s \t soyad: %s\t bolum: %s\t sinif: %d",
               node->ogrenci_no, node->ad, node->soyad, node->bolum, node->sinif);
        printInOrder(node->right);
    }

}

Node *createLinkedList(Node *root)
{
    root=NULL;
    return root;
}

Node* deleteList(Node *root)
{
    Node *current=root;
    Node *next;

    while (current != NULL)
    {
        next = current->right;
        free(current);
        current = next;
    }
    root = NULL;
    return root;
}