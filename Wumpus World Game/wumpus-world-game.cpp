/* Wumpus Game Simulator */

/*
Muhammmad Daffa' Aflah Syarif	05111840000030
Rifki Aulia I.					05111840000142
Anggara Yuda P.					05111840000008
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAPWIDTH 15
#define MAPHEIGHT 15
#define NUM_PITS 3
#define NUM_WUMPUS 5
#define NUM_GOLD 7

void initMap(char [MAPWIDTH][MAPHEIGHT]);
void printMap(char [MAPWIDTH][MAPHEIGHT]);
int move(int,int,int,int,char [MAPWIDTH][MAPHEIGHT],int);
void smell(int,int,char [MAPWIDTH][MAPHEIGHT]);
int shoot(int,int,int,int,int,char [MAPWIDTH][MAPHEIGHT],int);

int main(void){
	int sisagold = 7;
	int sisawum = 5;
    int num_arrows = 6; 			/* Total anak panah yang dimiliki */
    char map[MAPWIDTH][MAPHEIGHT];  /* Map */
    int choice;         			/* Users memasukkan command */
    int x,y;            			/* Posisi player saat ini */
    int dx,dy;          			/* Perubahan arah gerak */
    int flag;           
    int action;         			/* Action 1: -> Gerak */
                    				/* Action 2: -> Tembak */
    int debug = 1;

    /* Inisiasi Map */
    srand(time(NULL));
    initMap(map);
    
    /* Meletakkan pemain di pojok kiri atas */
    flag = 1;
    while(flag == 1){
//      x = (rand() % 5) + 1;
//      y = (rand() % 5) + 1;
		x = 1;
		y = 1;
        if(map[x][y] == '.'){
            map[x][y] = '@';
            flag = 0;
        }
    }
    printf("Selamat datang di permainan Wumpus Simulator ! \n");
    if(debug)				
        printMap(map);		// buat ngeprint mapnya
    smell(x,y,map);

    do {
        printf("Masukkan Command: ");
        fflush(stdout);
        choice = getc(stdin);
        printf("\n");
        /* Menghapus stdin secara manual */
        if(choice != '\n')
            while(getchar() != '\n'); /* statement kosong */
        switch(choice){
            /* Opsi untuk Pergerakan */
            case 'w':				// naik
                    dx = 0;
                    dy = -1;
                    action = 1;
                    break;
            case 's':				// turun
                    dx = 0;
                    dy = +1;
                    action = 1;
                    break;
            case 'd':				// kanan
                    dx = +1;
                    dy = 0;
                    action = 1;
                    break;
            case 'a':				// kiri
                    dx = -1;
                    dy = 0;
                    action = 1;
                    break;
            /* Opsi untuk Menembak */
            case 'W':
                    dx = 0;
                    dy = -1;
                    action = 2;
                    break;
            case 'S':
                    dx = 0;
                    dy = +1;
                    action = 2;
                    break;
            case 'D':
                    dx = +1;
                    dy = 0;
                    action = 2;
                    break;
            case 'A':
                    dx = -1;
                    dy = 0;
                    action = 2;
                    break;
            default:
                    printf("Salah Command!\n");
                    action = 0;
                    break;
        }
	    /* Pergerakan Player */
	    if(action == 1){
	        flag = move(x,y,dx,dy,map,sisagold);
	        if(flag == 1){
	            map[x][y] ='.';
	            x = x + dx;
	            y = y + dy;
	            map[x][y]='@';
	        }
	        else if(flag==2){
	        	map[x][y] ='.';
	            x = x + dx;
	            y = y + dy;
	            map[x][y]='@';
	            if(sisagold>0){
	        	sisagold--;
	        	printf("Sisa Gold %d\n",sisagold);
				}
			}
			else if (flag == 3){
				map[x][y] ='.';
	            x = x + dx;
	            y = y + dy;
	            map[x][y]='@';
	            printf("SELAMAT ANDA MENANG !!!\n");
	            break;
			}
	        else if(flag == -1)
	            break;
	    }
	    /* Shoot */
	    else if(action == 2){
	        flag = shoot(num_arrows--,x,y,dx,dy,map,sisawum);
	        if (flag == 4){
	        	map[x][y] ='.';
	            x = x + dx;
	            y = y + dy;
	            map[x][y]='@';
			}
			else if(flag == -1)
	            break;
	    }
	    if(debug)
	        printMap(map);
	    smell(x,y,map);
	}
	while(choice != 'Q' || choice !='q');

	printf("Press any key to exit..");
	getchar();

	return 0;
}

/* Inisisasi Map yang berisi Pit dan Wumpus yang diletakkan secara acak */
void initMap(char map[MAPWIDTH][MAPHEIGHT]){
    int i,j;
    int x,y;
    for(j=0; j<MAPHEIGHT; j++)
        for(i=0; i<MAPWIDTH; i++)
            map[i][j]='.';
    /* Membuat tembok di pinggir map */
    for(i=0; i<MAPWIDTH; i++){
        map[i][0]='#';
        map[i][MAPHEIGHT-1]='#';
    }
    for(j=1; j<MAPHEIGHT-1; j++){
        map[0][j]='#';
        map[MAPWIDTH-1][j]='#';
    }
    /* Membuat lokasi random Pit */
    for(i=0; i<NUM_PITS; i++){
        x = (rand() % 13) + 1;
        y = (rand() % 13) + 1;
        map[x][y] = 'P';
    }
    /* Membuat lokasi random Wumpus */
	for(i=0; i<NUM_WUMPUS; i++){
	    x = (rand() % 13) + 1;
	    y = (rand() % 13) + 1;
	    map[x][y] = 'W';
	}
	/* Membuat lokasi random Gold*/
	for(i=0; i<NUM_GOLD; i++){
	    x = (rand() % 13) + 1;
	    y = (rand() % 13) + 1;
	    map[x][y] = 'G';
	}
}

/* Merupakan fungsi debug untuk mencetak map tiap langkah */
void printMap(char map[MAPWIDTH][MAPHEIGHT]){
    int i,j;
    for(j=0; j<MAPHEIGHT; j++){
        for(i=0; i<MAPWIDTH; i++)
            printf("%c",map[i][j]);
        printf("\n");
    }
}

/* Player bergerak ke ruang baru */
int move(int x,int y,int dx,int dy,char map[MAPWIDTH][MAPHEIGHT], int sisagold){
    // posisi player saat ini
	x = x + dx;
    y = y + dy;
	if(map[x][y] == 'G'){
        printf("Hore kamu menemukan gold\n");
        if(sisagold == 1){				// sudah nemu semua gold
			return 3;
		}
		else return 2;
	}
    else if(map[x][y] == '#'){
        printf("Salah jalan, \n");
        printf("kamu nabrak tembok !!\n");
        return 0;
    }
    else if(map[x][y] == 'P'){
        printf("Aduh! Kamu jatuh ke dalam jurang !!!\n");
        printf("GAME OVER !!!\n");
        return -1;
    }
    else if(map[x][y] == 'W'){
        printf("Unch... \n");
        printf("Kamu dimakan sama Wumpus. GAME OVER !!!\n");
        return -1;
    }
    else
        return 1;
}

/* Fungsi untuk petunjuk ada wumpus, pit, gold di sekitar */
void smell(int x,int y,char map[MAPWIDTH][MAPHEIGHT]){
    int pit_flag = 0;
    int wumpus_flag = 0;
    int gold_flag = 0;
    int i,j;
    /* Ngecek kanan kiri */
    for(i=x-1; i<=x+1; i++){
        if(map[i][y] == 'P')
            pit_flag = 1;
        else if(map[i][y ]== 'W')
            wumpus_flag =1;
        else if(map[i][y] == 'G')
            gold_flag =1;
    }
    /* Ngecek atas bawah */
    for(j=y-1; j<=y+1; j++){
        if(map[x][j]=='P')
            pit_flag = 1;
        else if(map[x][j] == 'W')
            wumpus_flag = 1;
        else if(map[i][y] == 'G')
            gold_flag =1;
    }
    printf("Anda berada di ruang gelap\n");
    if(wumpus_flag == 1)
        printf("Ada bau busuk di sekitarmu !\n");
    if(pit_flag == 1)
        printf("Anda merasakan hawa dingin.\n");
    if(gold_flag == 1)
    	printf("Ada emas di sekitarmu !\n");
}

/* Menembak anak panah ke arah yang diinginkan */
int shoot(int num_arrows,int x,int y,int dx,int dy,char map[MAPWIDTH][MAPHEIGHT],int sisawum){
    x = x + dx; 
    y = y + dy;
    if(num_arrows > 0){
//        if(map[x][y] == 'W' && sisawum == 0){
//            printf("\a Kamu berhasil membunuh Wumpus !\n");
//            return -1;
//        }
        if(map[x][y] == 'W' && sisawum > 0){
            printf("\a Wumpus mati\n");
            return 4;
        }
        else{
			printf("MISS SHOT\n");
            return 0;
        }
    }
    else {
        printf("Panahmu Habis !!!\n");
        return 0;
    }
}
