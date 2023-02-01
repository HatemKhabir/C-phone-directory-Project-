#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "res.h"
#include "liste.h"
int x,y;
LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);
void addmenus(HWND);
HMENU hmenu;
HBITMAP hlogoImage,hgenerateImage;
HWND hLogo;
void addcontrols(HWND);
void loadimages();
HDC hdc;


int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR args,int ncmdshow)
{
    WNDCLASSW wc= {0};
    wc.hbrBackground=(HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance=hInst;
    wc.lpszClassName=L"MyWindowClass";
    wc.lpfnWndProc=WindowProcedure;
    wc.hIcon  = LoadIcon(hInst,MAKEINTRESOURCE(IDI_MYICON));
    if(!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"myWindowClass",L"Repertoire Telephonique",WS_OVERLAPPEDWINDOW | WS_VISIBLE,100,100,1700,1024,
                  NULL,NULL,NULL,NULL);
      MSG msg ={0};

    while (GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }


    return 0;
}
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg,WPARAM wp,LPARAM lp)
{static HBITMAP  hBmp;
struct liste l;
int pos;
FILE* fichier=NULL;
    switch (msg)
    {case WM_COMMAND :
    {
        switch(wp)
        {
    case 1://remplir_liste
        system("color F9");
                ShowWindow(hWnd,SW_HIDE);
                textcolor(4);
                printf("----------------------------------Creation de la Repertoire ----------------------------------\n ");
                creer_liste_vide(&l);
                remplir_liste(&l);
                enregister(&l);
                system("pause");
                ShowWindow(hWnd,SW_NORMAL);
                system("cls");
                break;
    case 2://insere_tete_tel
        system("color F9");
                ShowWindow(hWnd,SW_HIDE);
                textcolor(4);
                printf("----------------------------------Ajout en tete---------------------------------- \n");
                textcolor(12);
                recuperer(&l);
                inserer_tete_tel(&l);
                enregister(&l);
                system("pause");
                ShowWindow(hWnd,SW_NORMAL);
                system("cls");
                break;
    case 3://insere_queue_tel
        system("color F9");
                ShowWindow(hWnd,SW_HIDE);
                textcolor(4);
                printf("----------------------------------Ajout en Queue---------------------------------- \n");
                textcolor(12);
                recuperer(&l);
                inserer_queue_tel(&l);
                enregister(&l);
                system("pause");
                ShowWindow(hWnd,SW_NORMAL);
                system("cls");
                break;
    case 4://insere_pos_tel
        system("color F9");
                ShowWindow(hWnd,SW_HIDE);
                textcolor(4);
                printf("----------------------------------Ajout en Position---------------------------------- \n");
                textcolor(12);
                recuperer(&l);
                insere_pos_tel(&l);
                enregister(&l);
                system("pause");
                ShowWindow(hWnd,SW_NORMAL);
                system("cls");
                break;
    case 5://supprimer_tete_tel
        system("color F9");
                ShowWindow(hWnd,SW_HIDE);
                textcolor(12);
                recuperer(&l);
                supprimer_tete_tel(&l);
                enregister(&l);
                textcolor(4);
                printf("----------------------------------Numero Supprime Avec Succes---------------------------------- \n");
                system("pause");
                ShowWindow(hWnd,SW_NORMAL);
                system("cls");
                break;
    case 6://supprimer_queue_tel
        system("color F9");
                ShowWindow(hWnd,SW_HIDE);
                textcolor(12);
                recuperer(&l);
                supprimer_queue_tel(&l);
                enregister(&l);
                textcolor(4);
                printf("----------------------------------Numero Supprime Avec Succes---------------------------------- \n");
                system("pause");
                ShowWindow(hWnd,SW_NORMAL);
                system("cls");
                break;
    case 7://suppression pos donnée
        system("color F9");
                ShowWindow(hWnd,SW_HIDE);
                textcolor(12);
                 recuperer(&l);
                 do
            {
               printf("donner position : ");
               scanf("%d",&pos);
               }while (pos>taille_liste_rep(l));
                suppression_pos_tel(&l,pos);
                enregister(&l);
                textcolor(4);
                printf("----------------------------------Numero Supprime Avec Succes---------------------------------- \n");
                system("pause");
                ShowWindow(hWnd,SW_NORMAL);
                system("cls");
                break;
    case 8://suppression tel donnée
        system("color F9");
                ShowWindow(hWnd,SW_HIDE);
                textcolor(12);
                recuperer(&l);
                suppression_tel_donne(&l);
                enregister(&l);
                textcolor(4);
                printf("----------------------------------Numero Supprime Avec Succes---------------------------------- \n");
                system("pause");
                ShowWindow(hWnd,SW_NORMAL);
                system("cls");
                break;
    case 9://suppression d'unne ville donnée
        system("color F9");
                ShowWindow(hWnd,SW_HIDE);
                textcolor(12);
                recuperer(&l);
                suppression_ville_donne(&l);
                enregister(&l);

                system("pause");
                ShowWindow(hWnd,SW_NORMAL);
                system("cls");
                break;
    case 10://suppression d'un indicatif
        system("color F9");
                ShowWindow(hWnd,SW_HIDE);

                textcolor(12);
                recuperer(&l);
                suppression_indicatif_donne(&l);
                enregister(&l);
                system("pause");
                ShowWindow(hWnd,SW_NORMAL);
                system("cls");
                break;
    case 11: //modifcation adresse
        system("color F9");
                ShowWindow(hWnd,SW_HIDE);
                 textcolor(12);
                recuperer(&l);
                modifier_address(&l);
                enregister(&l);
                system("pause");
                ShowWindow(hWnd,SW_NORMAL);
                system("cls");
                break;
    case 12://modifcation telephone
        system("color F9");
                ShowWindow(hWnd,SW_HIDE);
                textcolor(12);
                recuperer(&l);
                modifier_num(&l);
                enregister(&l);
                system("pause");
                ShowWindow(hWnd,SW_NORMAL);
                system("cls");
                break;
    case 13: //Affichage
        system("color F9");
        ShowWindow(hWnd,SW_HIDE);
        gotoxy(25,1);
        textcolor(4);
        printf("     Affichage de la liste \n \n");
        recuperer(&l);
        affichage(l);
        system("pause");
        ShowWindow(hWnd,SW_NORMAL);
        system("cls");
        break;
case 14://recherche numero
        system("color F9");
        ShowWindow(hWnd,SW_HIDE);
        recuperer(&l);
        recherche_numero(l);
        enregister(&l);
        system("pause");
        ShowWindow(hWnd,SW_NORMAL);
        system("cls");
        break;
case 15://recherche nom
        system("color F9");
        ShowWindow(hWnd,SW_HIDE);
        recuperer(&l);
        recherche_nom(l);
        enregister(&l);
        system("pause");
        ShowWindow(hWnd,SW_NORMAL);
        system("cls");
        break;
case 16://recherche ind
        system("color F9");
        ShowWindow(hWnd,SW_HIDE);
        recuperer(&l);
        recherche_indicatif(l);
        enregister(&l);
        system("pause");
        ShowWindow(hWnd,SW_NORMAL);
        system("cls");
        break;
case 17://recherche ville
        system("color F9");
        ShowWindow(hWnd,SW_HIDE);
        recuperer(&l);
        recherche_ville(l);
        enregister(&l);
        system("pause");
        ShowWindow(hWnd,SW_NORMAL);
        system("cls");
        break;
case 18:// tri
        system("color F9");
        ShowWindow(hWnd,SW_HIDE);
        gotoxy(25,1);
printf("     Affichage de la liste triee \n \n");
        recuperer(&l);
        tri(&l);
        system("pause");
        ShowWindow(hWnd,SW_NORMAL);
        system("cls");
        break;
case 19:// affichage de text
        system("color F9");
        ShowWindow(hWnd,SW_HIDE);
        gotoxy(25,1);
        ShellExecute(NULL,"open","sauvgarder.txt",NULL,NULL,SW_SHOWNORMAL);
        system("pause");
        ShowWindow(hWnd,SW_NORMAL);
        system("cls");
        break;
case 20:// affichage de enoncé
        system("color F9");
        ShowWindow(hWnd,SW_HIDE);
        gotoxy(25,1);
        ShellExecute(NULL,"open","projet-1.pdf",NULL,NULL,SW_SHOWNORMAL);
        system("pause");
        ShowWindow(hWnd,SW_NORMAL);
        system("cls");
        break;

case 21://Quitter
       if (MessageBox(hWnd,"       Vous voulez quitter ?", "QUITTER", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                {

                    DestroyWindow(hWnd);
                   system("cls");
                }
            break;

    }
    break;
    }
    case WM_CREATE:
        addmenus(hWnd);
        hBmp=LoadImage(NULL,"pr.bmp",IMAGE_BITMAP,1700,1024,LR_LOADFROMFILE);
            break;

        case WM_PAINT :
            {
         PAINTSTRUCT ps;
            hdc = BeginPaint(hWnd, &ps);

            DrawState(hdc,NULL,NULL,(long)hBmp,0,0,0,0,0,DST_BITMAP);

            EndPaint(hWnd, &ps);}
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd,msg,wp,lp);
    }
}
void addmenus(HWND hwnd)
{


    hmenu=CreateMenu();
    HMENU hmaj=CreateMenu();
    HMENU hdel=CreateMenu();
    HMENU hmod=CreateMenu();
    HMENU hajout=CreateMenu();
    HMENU hrech=CreateMenu();
    AppendMenu(hmenu,MF_STRING,1,"Création");
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)hmaj,"MAJ");
    AppendMenu(hmaj,MF_POPUP,(UINT_PTR)hajout,"Ajouter");
              AppendMenu(hajout,MF_STRING,2,"Ajout en tête");
              AppendMenu(hajout,MF_STRING,3,"Ajout en Queue");
              AppendMenu(hajout,MF_STRING,4,"Ajout dans une position");
    AppendMenu(hmaj,MF_POPUP,(UINT_PTR)hdel,"Supprimer");
              AppendMenu(hdel,MF_STRING,5,"Suppression en tête");
              AppendMenu(hdel,MF_STRING,6,"Suppression en queue");
              AppendMenu(hdel,MF_STRING,7,"Suppression à partir d’ une position");
              AppendMenu(hdel,MF_STRING,8,"Suppression d’un téléphone donné");
              AppendMenu(hdel,MF_STRING,9,"Suppression des téléphones d’une ville donnée");
              AppendMenu(hdel,MF_STRING,10,"Suppression des téléphones d’un indicatif donné");
    AppendMenu(hmaj,MF_POPUP,(UINT_PTR)hmod,"Modifier");
                 AppendMenu(hmod,MF_STRING,11,"Adresse");
                 AppendMenu(hmod,MF_STRING,12,"Téléphone");
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)hrech,"Recherche et Affichage");
        AppendMenu(hrech,MF_STRING,13,"Affichage");
        AppendMenu(hrech,MF_STRING,14,"Recherche par numéro téléphone");
        AppendMenu(hrech,MF_STRING,15,"Recherche par nom ");
        AppendMenu(hrech,MF_STRING,16,"Recherche par indicatif téléphone");
        AppendMenu(hrech,MF_STRING,17,"Recherche par ville");
        AppendMenu(hrech,MF_STRING,18,"Tri");
        AppendMenu(hmenu,MF_STRING,19,"Chargement");
    AppendMenu(hmenu,MF_STRING,20,"Enoncé");
    AppendMenu(hmenu,MF_STRING,21,"Quitter");
    SetMenu(hwnd,hmenu);

}
