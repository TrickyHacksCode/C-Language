/* Introdução à Programação - Projeto de 2011

   Game.c
 
   
   O Cão Dancarino contra os Carangejos Mutantes Assassinos

   Programa escrito em C/C++ sobre a plataforma wxWidget.
   A plataforma wxWidget funciona em Windows, MacOS e Linux.

   Este ficheiro constitui apenas um ponto de partida para o
   seu trabalho. Todo este ficheiro pode e deve ser alterado
   à vontade, a começar neste comentário.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "GameSupport.h"


/* ATORES - IMAGENS */


/* BitMaps in XPM format -- http://en.wikipedia.org/wiki/X_PixMap */

char *xpm_vazio[] = {
/* columns rows colors chars-per-pixel */
"32 32 2 1",
/* colors */
"X c Black",
"  c White",
/* pixels */
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                "
};

char *xpm_fronteira[] = {
/* columns rows colors chars-per-pixel */
    "32 32 15 1",
/* colors */
"   c #DBFF92",
".  c #DBFF6D",
"+  c #B6FF49",
"@  c #B6FF24",
"#  c #92FF00",
"$  c #92DB00",
"%  c #6DB600",
"&  c #499200",
"*  c #494949",
"=  c #DBFFB6",
"-  c #496D00",
";  c #242424",
">  c #000000",
",  c #244900",
"'  c #242400",
/* pixels */
" ...++@@#$$%%&** ...++@@#$$%%&**",
".=  ..++@#$$&-;*.=  ..++@#$$&-;*",
"+.%%%%%%%%%%-->;+.%%%%%%%%%%-->;",
"@#%%%%%%%%%%,->>@#%%%%%%%%%%,->>",
"$%&-,,,,,,,,'->>$%&-,,,,,,,,'->>",
"&------------,>>&------------,>>",
"*;>>>>>>>>>>>>>>*;>>>>>>>>>>>>>>",
"**;>>>>>>>>>>>>>**;>>>>>>>>>>>>>",
"#$$%%&** ...++@@#$$%%&** ...++@@",
"@#$$&-;*.=  ..++@#$$&-;*.=  ..++",
"%%%%-->;+.%%%%%%%%%%-->;+.%%%%%%",
"%%%%,->>@#%%%%%%%%%%,->>@#%%%%%%",
",,,,'->>$%&-,,,,,,,,'->>$%&-,,,,",
"-----,>>&------------,>>&-------",
">>>>>>>>*;>>>>>>>>>>>>>>*;>>>>>>",
">>>>>>>>**;>>>>>>>>>>>>>**;>>>>>",
" ...++@@#$$%%&** ...++@@#$$%%&**",
".=  ..++@#$$&-;*.=  ..++@#$$&-;*",
"+.%%%%%%%%%%-->;+.%%%%%%%%%%-->;",
"@#%%%%%%%%%%,->>@#%%%%%%%%%%,->>",
"$%&-,,,,,,,,'->>$%&-,,,,,,,,'->>",
"&------------,>>&------------,>>",
"*;>>>>>>>>>>>>>>*;>>>>>>>>>>>>>>",
"**;>>>>>>>>>>>>>**;>>>>>>>>>>>>>",
"#$$%%&** ...++@@#$$%%&** ...++@@",
"@#$$&-;*.=  ..++@#$$&-;*.=  ..++",
"%%%%-->;+.%%%%%%%%%%-->;+.%%%%%%",
"%%%%,->>@#%%%%%%%%%%,->>@#%%%%%%",
",,,,'->>$%&-,,,,,,,,'->>$%&-,,,,",
"-----,>>&------------,>>&-------",
">>>>>>>>*;>>>>>>>>>>>>>>*;>>>>>>",
">>>>>>>>**;>>>>>>>>>>>>>**;>>>>>"
};

char *xpm_defesa[] = {
/* columns rows colors chars-per-pixel */
"32 32 15 1",
/* colors */
"   c White",
".  c #525252",
"+  c #3A3A3A",
"@  c #313131",
"#  c #292929",
"$  c #737373",
"%  c #424242",
"&  c #7B7B7B",
"*  c #4A4A4A",
"=  c #5A5A5A",
"-  c #848484",
";  c #191919",
">  c #212121",
",  c #6B6B6B",
"'  c #636363",
/* pixels */
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"           +@##.$%@+            ",
"        &$+*#+@+*%##+@=-        ",
"      $$=*+@###@@@;>@#%=$&      ",
"     ,-.%@#@#;>@##@#%@@@*-,     ",
"     =&'%+@@%+@+%@++*#+@%&'     ",
"     %.,'%+#>@#>#@+###%=,=%     ",
"     *++*=''.'..=..=''=*++%     ",
"     *%%@##@%**...*%+##@+%*     ",
"    **%%++@@@#@@@##@@@++%%**    ",
"    *%%%+++++++%%%++++++%%%*    ",
"   **%%%+++@+++%%+++@+++%%%**   ",
"  .*%%%++++@++%%%%+++++++%%%*.  ",
"  .*%%%+++++++%%%%+++++++%%%*.  ",
" *.*%%%++++@++%%%%+++++++%%%*.  ",
"  .*%%%+++++++%%%%+++++++%%%*.  ",
"  **%%%+++++++%%%%%++++++%%%**  ",
"  #**%%++++++%%%%%%++++++%%**   ",
"   #**%%++++%%%%%%%%++++%%**    ",
"     +***%%%%%%%%%%%%%%%**%     ",
"       @%**************%+       ",
"          @++%%%%%%%+@          ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                "
};

char *xpm_perseguidor[] = {
/* columns rows colors chars-per-pixel */
"32 32 10 1",
/* colors */
"  c White",
"0 c #656532",
"1 c #CC9866",
"2 c #CC6666",
"3 c Red",
"4 c #986565",
"5 c #663200",
"6 c #653232",
"7 c Black",
"8 c #FFFFFF",
/* pixels */
"                                ",
"                                ",
"                                ",
"                                ",
"  2                           3 ",
" 11  3    222       222    2  33",
"111 23   28773     273 3   11 33",
"111123   28773     273 3   11123",
"111143   28883     28883   11123",
"111133    222       222    11123",
"111133     2         2     21133",
" 1123      22222222222     34233",
"   33     2211111111222     33  ",
"    3   22111111111112222   3   ",
"    3 32221111111111223443333   ",
"3    33222211111111143332333    ",
" 33  2111330321111133633333   33",
"  3332111306032111330603333 333 ",
"    3211130563333333656333333   ",
"     21113056600000665633333    ",
"     21113055555555555033333    ",
"    3211133566033306650333333   ",
"  33331114366333333306333303333 ",
" 23  3111230333443333333330   33",
" 3   3111233322222233333330    3",
" 4   3411111111111124333333    3",
"     33211112333333333333333    ",
"   2    33333333333000333    3  ",
"  22   333             333   33 ",
"  2    3                 3    3 ",
"  2   24                 32   3 ",
"      2                   2     "
};

char *xpm_heroi[] = {
/* columns rows colors chars-per-pixel */
"32 32 3 1",
/* colors */
"   c White",
".  c Black",
"+  c Yellow",
/* pixels */
"                                ",
"                                ",
"                                ",
"    .....              ....     ",
"   ..++++..............++++.    ",
"   .+++++.....++++++++++++++.   ",
"   .++...+....+++++++++...++.   ",
"    .+++.+...++++++++++.+++.    ",
"     ...++++++++++++++++...     ",
"       .+++++.+++++.++++.       ",
"      ..++++++++++++++++.       ",
"      .+++++++.....++++++.      ",
"      .++++++++...+++++++.      ",
"  .. .++++++++++.++++++++. ..   ",
" .++..++++++.+++.+++.++++..++.  ",
" .++..+++++++.++.++.+++++..++.  ",
" .++. .+++++++..+..+++++. .++.  ",
" .+++...+++++++++++++++...+++.  ",
" .++++++...............++++++.  ",
"  .++++++++++++++++....+++++.   ",
"   .+++..+++++++++......+++.    ",
"    ......++++++++.........     ",
"      .....++++++++.....        ",
"      .....+++++++++....        ",
"      ....+++++++++++++.        ",
"     ....+++++++++++++++.       ",
"     .++++++++...+++++++.       ",
"     .+++++++.   .++++++.       ",
"      .......     ......        ",
"                                ",
"                                ",
"                                "
};

int imagem_vazio, imagem_fronteira, imagem_defesa,
    imagem_perseguidor, imagem_heroi;

void criar_imagens(void)
{
    imagem_vazio = CreateImage(xpm_vazio);
    imagem_fronteira = CreateImage(xpm_fronteira);
    imagem_defesa = CreateImage(xpm_defesa);
    imagem_perseguidor = CreateImage(xpm_perseguidor);
    imagem_heroi =  CreateImage(xpm_heroi);
}


/* ATORES - CONSTANTES, TIPOS E VARIÁVEIS */

#define FRONTEIRA    '#'
#define HEROI        'H'
#define PERSEGUIDOR  'P'
#define DEFESA        '.'

#define DISTANCIA      5
#define N_MAX_LINHA   32
#define VIDAS          3
#define NIVEIS         4

#define TAMANHO_ATOR 32

typedef struct {
    char tipo;
    int x, y;
    int imagem;
} AtorStruct;

typedef AtorStruct *Ator;



/* MUNDO - CONSTANTES, TIPOS E VARIÁVEIS */

#define LARGURA_MUNDO   31
#define ALTURA_MUNDO    18

#define N_PERSEGUIDORES  5
#define N_DEFESAS      120

#define VAZIA         NULL

Ator mundo[LARGURA_MUNDO][ALTURA_MUNDO];
Ator perseguidores[N_PERSEGUIDORES];
Ator heroi;
int tempo = 0;


// FUNÇÕES AUXILIARES

void erro(char mensagem[])
{
    char m[2014];
    sprintf(m, "ERRO: %s\n", mensagem);
    Alert("ERRO", m);
    exit(1);
}


/* ATORES - FUNÇÕES */

int n_atores;

void atores_nenhum(void)
{
    n_atores = 0;
}

Ator ator_criar(int tipo, int x, int y, int imagem)
{
    #define MAX_ATOR    256
    static AtorStruct atores[MAX_ATOR];
    if( n_atores > MAX_ATOR )
        erro("Vetor de atores cheio");
    atores[n_atores].tipo = tipo;
    atores[n_atores].x = x;
    atores[n_atores].y = y;
    atores[n_atores].imagem = imagem;
    n_atores++;
    return &atores[n_atores-1];
}

void ator_mostrar(Ator a)
{
    DrawImage(a->imagem, a->x*TAMANHO_ATOR, a->y*TAMANHO_ATOR);
}

void ator_apagar(Ator a)
{
    DrawImage(imagem_vazio, a->x*TAMANHO_ATOR, a->y*TAMANHO_ATOR);
}

bool pode_mover(Ator p,int dx,int dy)
{
	if(mundo[p->x + dx][p->y + dy] == VAZIA)
		return true;
	else
		return false;
}

void fazer_movimento_perseguidor(Ator p, int dx, int dy)
{
	int random = Rand(4);
	if((mundo[p->x + dx][p->y + dy] == VAZIA) || (mundo[p->x + dx][p-> y + dy] -> tipo == HEROI))
	{
		ator_apagar(p);
		mundo[p->x][p->y] = VAZIA;
		p->x += dx;
		p->y += dy;
		ator_mostrar(p);
		mundo[p->x][p->y] = p;
	}
	else if((mundo[p->x + dx][p->y + dy] -> tipo == DEFESA))
	{
		// Em vez de ficarem parados, vao se movimentando ate terem hipotese de ir em direcçao ao heroi.
		switch(random){
			case 0:
			//cima
			dx=0; dy=-1;
			if(pode_mover(p,dx,dy))
			fazer_movimento_perseguidor(p,dx,dy);
			break;
			case 1:
			//baixo
			dx=0; dy=1;
			if(pode_mover(p,dx,dy))
			fazer_movimento_perseguidor(p,dx,dy);
			break;
			case 2:
			//esquerda
			dx=-1; dy=0;
			if(pode_mover(p,dx,dy))
			fazer_movimento_perseguidor(p,dx,dy);
			break;
			case 3:
			//direita
			dx=1; dy=0;
			if(pode_mover(p,dx,dy))
			fazer_movimento_perseguidor(p,dx,dy);
			break;
		}
	}
}


void perseguidor_movimentacao(Ator p)
{
	int dx = 0;
	int dy = 0;
// FAZER: O perseguidor toma uma decisão de movimentação e move-se.
// Para começar os perseguidores andar só para a direita.
// Depois poderá tornar os perseguidores um pouco mais inteligentes.
	if(heroi->x < p->x)
	{
		if( heroi->y > p->y)
		{
			dx = -1;
			dy = +1;
			fazer_movimento_perseguidor(p,dx,dy);
		}
		else if(heroi->y < p->y)
		{
			dx = -1;
			dy = -1;
			fazer_movimento_perseguidor(p,dx,dy);
		}
		else 
		{
			dx = -1;
			dy = 0;
			fazer_movimento_perseguidor(p,dx,dy);
		}
	}
	if(heroi->x > p->x)
	{
		if( heroi->y > p->y)
		{
			dx = +1;
			dy = +1;
			fazer_movimento_perseguidor(p,dx,dy);
		}
		else if (heroi-> y < p-> y)
		{
			dx = +1;
			dy = -1;
			fazer_movimento_perseguidor(p,dx,dy);
		}
		else if (heroi-> y == p->y)
		{
			dx = +1;
			dy = 0;
			fazer_movimento_perseguidor(p,dx,dy);
		}
	}
	if(heroi->x == p->x)
	{
		if( heroi->y > p->y)
		{
			dx = 0;
			dy = +1;
			fazer_movimento_perseguidor(p,dx,dy);
		}
		else if(heroi->y < p->y)
		{
			dx = 0;
			dy = -1;
			fazer_movimento_perseguidor(p,dx,dy);
		}
	}
}

bool defesa_empurrada(Ator d, Direction direction)
{
	int dx, dy;
	bool defesa = true;
    switch( direction ) {
        case UP: dx = 0; dy = -1; break;
        case DOWN: dx = 0; dy = 1; break;
        case LEFT: dx = -1; dy = 0; break;
        case RIGHT: dx = 1; dy = 0; break;
        default: dx = 0; dy = 0; break;
    }    
    if( mundo[d->x + dx][d->y + dy] == VAZIA ) {
        ator_apagar(d);
        mundo[d->x][d->y] = VAZIA;
        d->x += dx;
        d->y += dy;
        ator_mostrar(d);
        mundo[d->x][d->y] = d;
		return defesa;
    }
	else if ( mundo[d-> x + dx][d-> y + dy] -> tipo == DEFESA)
	{
		if (defesa_empurrada(mundo[d-> x + dx][d-> y + dy],direction))
		{
			ator_apagar(d);
			mundo[d->x][d->y] = VAZIA;
			d->x += dx;
			d->y += dy;
			ator_mostrar(d);
			mundo[d->x][d->y] = d;
			return defesa;
		}
	}
	defesa = false;
	return defesa;
}

	


void heroi_reage_a_tecla(Ator h, Direction direction)
{
    int dx, dy;
    switch( direction ) {
        case UP: dx = 0; dy = -1; break;
        case DOWN: dx = 0; dy = 1; break;
        case LEFT: dx = -1; dy = 0; break;
        case RIGHT: dx = 1; dy = 0; break;
        default: dx = 0; dy = 0; break;
    }    
    if( mundo[h->x + dx][h->y + dy] == VAZIA ) {
        ator_apagar(h);
        mundo[h->x][h->y] = VAZIA;
        h->x += dx;
        h->y += dy;
        ator_mostrar(h);
        mundo[h->x][h->y] = h;
    }
	else if ( mundo[h-> x + dx][h-> y + dy] -> tipo == DEFESA)
	{
		if (defesa_empurrada(mundo[h-> x + dx][h-> y + dy],direction))
		{
			ator_apagar(h);
			mundo[h->x][h->y] = VAZIA;
			h->x += dx;
			h->y += dy;
			ator_mostrar(h);
			mundo[h->x][h->y] = h;
		}
	}
}


/* MUNDO - FUNÇÕES */

void mundo_criar_vazio(void)
{
    int x, y;
    for( y = 0; y < ALTURA_MUNDO ; y++ )
        for( x = 0; x < LARGURA_MUNDO ; x++ )
            mundo[x][y] = VAZIA;    
}


void mundo_criar_fronteira(void)
{
    int x, y;
    for( y = 0; y < ALTURA_MUNDO ; y++ )
        for( x = 0; x < LARGURA_MUNDO ; x++ )
            if( x == 0 || x == LARGURA_MUNDO - 1
            || y == 0 || y == ALTURA_MUNDO - 1 ) {
                Ator a = ator_criar(FRONTEIRA, x, y, imagem_fronteira);
                mundo[x][y] = a;
            }
}

void mundo_criar_defesas(void)
{
// FAZER: criar as defesas em posições aleatórias livres
int i,x,y;
for(i = 0; i < N_DEFESAS; i ++)
	{	
	x = Rand(LARGURA_MUNDO);
	y = Rand(ALTURA_MUNDO);
	if(mundo[x][y] == VAZIA)
		mundo[x][y] = ator_criar(DEFESA,x,y,imagem_defesa);
	else 
		i = i - 1;
	}
}

void mundo_criar_perseguidores(void)
{
// FAZER: cria os perseguidores em posições aleatórias livres
int i,x,y;
for( i = 0; i < N_PERSEGUIDORES; i ++)
{
	x = Rand(LARGURA_MUNDO);
	y = Rand(ALTURA_MUNDO);
	if(mundo[x][y] == VAZIA)
	{
		perseguidores[i] = ator_criar(PERSEGUIDOR, x , y, imagem_perseguidor);
		mundo[x][y] = perseguidores[i];
	}
	else i = i -1;
}
}


bool existe_perseguidor(int x, int y)
{   
	bool existe=false;
	int i, j;
	for( i = x - DISTANCIA; i <= x + DISTANCIA; i++)
	{
		if( i>0 && i<LARGURA_MUNDO)
		{
			for(j = y - DISTANCIA; j<= y + DISTANCIA; j ++)
			{
				if(j>0 && j<ALTURA_MUNDO)
				{
					if(mundo[i][j] != VAZIA)
					{
						if(mundo[i][j] -> tipo == PERSEGUIDOR)
						{
							existe=true;
							break;
						}
					}
				}
			}
		}
	if(existe)
		break;
	}
	return existe;
}
	
	
void mundo_criar_heroi(void)
{
	int x,y;
	for(;;)
	{
		x = Rand(LARGURA_MUNDO);
		y = Rand(ALTURA_MUNDO);
		if((mundo [x][y] == VAZIA) && (existe_perseguidor(x,y) == false))
		{
			heroi = ator_criar(HEROI,x,y,imagem_heroi);
			mundo[x][y] = heroi;
			break;
		}
	}
}

void mundo_preparar_novo_jogo(void)
{
    atores_nenhum();
    tempo = 0;
    mundo_criar_vazio();
    mundo_criar_fronteira();
    mundo_criar_defesas();
    mundo_criar_perseguidores();
    mundo_criar_heroi();
}

void mundo_carregar_jogo_inicial(char nome_ficheiro[])
{	
	#define CHARMAX 1024
	
	//apontador para ficheiro
	FILE *file = NULL;
	
	char str[CHARMAX];
	int x = 0, y = 0;
	int i = 0;
	int perseg = 0;
	Ator act = NULL;
	
	//abrir ficheiro
	file = fopen(nome_ficheiro, "r");
	
	if(file == NULL) {
		//no existe ficheiro de jogo
		//mensagem de erro para stderr
		fprintf(stderr,"ERRO: No existe ficheiro de jogo!");
		
		//carrega jogo sem o ficheiro
		mundo_preparar_novo_jogo();
	} else {
		// Inicializar Jogo
		atores_nenhum();
		tempo = 0;
		mundo_criar_vazio();
		
		//carregar ficheiro normalmente
		
		//saltar trs primeiras linhas
		for (i=0; i<3; i++) {
			fgets(str,CHARMAX,file);
		}
		
		y = 0;
		
		//percorrer as varias linhas do ficheiro
		while ((fgets(str,CHARMAX,file) != NULL) && (y<ALTURA_MUNDO)) {
			for (x=0; x < LARGURA_MUNDO; x++) {
				switch (str[x]) {
					case FRONTEIRA:
						act = ator_criar(str[x], x, y, imagem_fronteira);
						mundo[x][y] =  act;
						break;
					case DEFESA:
						act = ator_criar(str[x], x, y, imagem_defesa);
						mundo[x][y] =  act;
						break;
					case PERSEGUIDOR:
						act = ator_criar(str[x], x, y, imagem_perseguidor);
						mundo[x][y] =  act;
						perseguidores[perseg] = act;
						perseg++;
						break;
					case HEROI:
						heroi = ator_criar(str[x], x, y, imagem_heroi);
						mundo[x][y] = heroi;
					default:
						break;
				}
			}
			y++;
		}
		
		//fechar ficheiro
		fclose(file);
	}
}
		

void mundo_redesenhar_tudo(void)
{
    int x, y;
    for( y = 0; y < ALTURA_MUNDO ; y++ )
        for( x = 0; x < LARGURA_MUNDO ; x++ ) {
            Ator ator = mundo[x][y];
            if( ator != VAZIA )
                ator_mostrar(ator);
        }
}

void mundo_movimentacao(void)
{
    char s[256];
    int i;
    sprintf(s, "TIME = %d", ++tempo);
    SetStatusText(2, s);
    // FAZER: chamar perseguidor_movimentacao para cada perseguidor.
	for(i = 0; i < N_PERSEGUIDORES; i ++)
	{
	}
}


void mundo_tecla(Direction direction)
{
    heroi_reage_a_tecla(heroi, direction);
}

void mundo_animacao(void)
{
}


void mooshak(void)
{
	printf("MOOSHAK\n");
	int i,j;
	int posxh = 0;
	int posyh = 0;
	int heroi = 0;
	int perseguidores = 0;
	int fronteira = 0; 
	int defesas = 0;
	int vizinhos = 0;
    for( i = 0; i < ALTURA_MUNDO ; i++ ){
        for( j = 0; j < LARGURA_MUNDO; j++ )
		{
			if(mundo[j][i] == VAZIA){
				printf(" ");}
			else if(mundo[j][i] -> tipo == FRONTEIRA)
			{
				printf("#");
				fronteira += 1;
			}
			else if(mundo[j][i] -> tipo == PERSEGUIDOR)
			{
				printf("P");
				perseguidores +=1;
			}
			else if(mundo[j][i] -> tipo == DEFESA)
			{
				printf(".");
				defesas += 1;
			}
			else if(mundo[j][i] -> tipo == HEROI)
			{
				printf("H");
				posxh = j;
				posyh = i;
				heroi += 1;
			}
		}
		printf("\n");
	}
	if((mundo[posxh + 1][posyh])!= VAZIA)
		vizinhos +=1;
	if((mundo[posxh - 1][posyh])!= VAZIA)
		vizinhos +=1;
	if((mundo[posxh][(posyh) + 1])!= VAZIA)
		vizinhos +=1;
	if((mundo[posxh][(posyh) - 1])!= VAZIA)
		vizinhos +=1;
	if((mundo[(posxh) + 1][(posyh) + 1])!= VAZIA)
		vizinhos +=1;
	if((mundo[(posxh) - 1][(posyh) - 1])!= VAZIA)
		vizinhos +=1;
	if((mundo[(posxh) - 1][(posyh) + 1])!= VAZIA)
		vizinhos +=1;
	if((mundo[(posxh) + 1][(posyh) - 1])!= VAZIA)
		vizinhos +=1;
	// printfs dos valores 
	printf("# = %d\n", fronteira);
	printf("H = %d\n", heroi);
	printf("P = %d\n", perseguidores);
	printf(". = %d\n", defesas);
	printf("vizinhos = %d\n", vizinhos);
}



/* MUNDO - COMANDOS DE MENU */

void comando_about(void)
{
    Alert("About",
             "O Cão Dançarino defende-se dos Carangejos Mutantes Assassinos\n\n"
             "por Otelo e Desdémona\n\nFCT/UNL, 2011");
}

void comando_new_game(void)
{
	//char nome[1024];
	//Query("New Game", "Qual o seu nome?", nome);
	//printf("%s\n", nome);
    mundo_preparar_novo_jogo();
}

void comando_high_scores(void)
{
    Alert("High Scores", "Testando HIGH SCORES");
}

void comando_quit(void)
{
    Alert("Quit", "Adeus.\nVolte sempre!");
}

void comando_open(char nome_ficheiro[])
{
    Alert("Testando OPEN FILE", nome_ficheiro);
}

void comando_save(char nome_ficheiro[])
{
    Alert("Testando SAVE FILE", nome_ficheiro);
}


/* MAIN */

int GameMain(void)
{
    GameSetup(
        "O Cão Dançarino",
        LARGURA_MUNDO * TAMANHO_ATOR, ALTURA_MUNDO * TAMANHO_ATOR,
        mundo_redesenhar_tudo, mundo_movimentacao, mundo_tecla, mundo_animacao,
        comando_about, comando_new_game, comando_high_scores, comando_quit,
        comando_open, comando_save);

    criar_imagens();
    mundo_carregar_jogo_inicial("ddog_start.txt");
    mooshak();
    return 0;
}
