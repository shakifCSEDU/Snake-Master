#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ScreenWidth 1280
#define ScreenHeight 720

void init();

void loadMedia();

SDL_Surface* loadSurface( std::string path );

void close();

SDL_Window* gWindow         = NULL;

SDL_Surface* gScreenSurface = NULL;

SDL_Surface* gPNGSurface    = NULL;

SDL_Renderer *renderer      = NULL;

SDL_Texture* gTexture       = NULL;

SDL_Texture* sTexture       = NULL;
SDL_Surface* ScoreSurface   = NULL;

SDL_Surface* ScS1           = NULL;
SDL_Texture* ScT1           = NULL;

SDL_Surface* ScS2           = NULL;
SDL_Texture* ScT2           = NULL;

SDL_Surface* ScS3           = NULL;
SDL_Texture* ScT3           = NULL;

SDL_Surface* ScS4           = NULL;
SDL_Texture* ScT4           = NULL;

SDL_Surface* ScS5           = NULL;
SDL_Texture* ScT5           = NULL;

SDL_Surface* ScS6           = NULL;
SDL_Texture* ScT6           = NULL;

SDL_Surface* ScS7           = NULL;
SDL_Texture* ScT7           = NULL;

SDL_Surface* ScS8           = NULL;
SDL_Texture* ScT8           = NULL;

SDL_Surface* ScS9           = NULL;
SDL_Texture* ScT9           = NULL;

SDL_Surface* ScS10           = NULL;
SDL_Texture* ScT10           = NULL;

SDL_Surface* ScS11           = NULL;
SDL_Texture* ScT11           = NULL;

SDL_Surface* ScS12           = NULL;
SDL_Texture* ScT12           = NULL;

Mix_Music *gMusic            = NULL;

Mix_Chunk *gEat              = NULL;
Mix_Chunk *gClick            = NULL;
Mix_Chunk *gLC               = NULL;
Mix_Chunk *gGC               = NULL;
Mix_Chunk *gGO               = NULL;

int score      = 0;
  
int screenflag = 0;

int MainFlag   = 0;

int LoopFlag   = 0;

int scoreflag  = 2;

int diflag     = 2;

int levelflag  = 1;

int fx1 = 0 , fx2  = 0;

FILE *scorefile1 = fopen("1.cpp" , "r");
FILE *scorefile2 = fopen("2.cpp" , "r");
FILE *scorefile3 = fopen("3.cpp" , "r");
FILE *scorefile4 = fopen("4.cpp" , "r");
FILE *scorefile5 = fopen("5.cpp" , "r");
FILE *scorefile6 = fopen("6.cpp" , "r");
FILE *scorefile7 = fopen("7.cpp" , "r");
FILE *scorefile8 = fopen("8.cpp" , "r");
FILE *scorefile9 = fopen("9.cpp" , "r");
FILE *scorefile10 = fopen("10.cpp" , "r");
FILE *scorefile11 = fopen("11.cpp" , "r");
FILE *scorefile12 = fopen("12.cpp" , "r");

void ConstructScore1(SDL_Renderer* renderer);

char filestr1[5], gamestr1[5], filestr2[5], gamestr2[5],filestr3[5], gamestr3[5],filestr4[5], gamestr4[5],
 filestr5[5], gamestr5[5], filestr6[5], gamestr6[5],filestr7[5], gamestr7[5],filestr8[5], gamestr8[5],
 filestr9[5], gamestr9[5], filestr10[5], gamestr10[5],filestr11[5], gamestr11[5],filestr12[5], gamestr12[5],
 finalstr[5],scorestring[5];

const int FontSize = 27;


TTF_Font *Scorefont = NULL;

void init()
{

		gWindow = SDL_CreateWindow( "MiniGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
			ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN );

}

void LoadMenu()
{

	SDL_SetRenderDrawColor(renderer , 0x00 , 0x00 , 0x00 , 0x00 );
	SDL_RenderClear(renderer);

	gScreenSurface = SDL_GetWindowSurface(gWindow);

	gPNGSurface = loadSurface( "FinalMenu.png" );

	SDL_BlitSurface( gPNGSurface, NULL, gScreenSurface, NULL );
			
				SDL_UpdateWindowSurface( gWindow );
}

SDL_Texture* loadTexture( std::string path )
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );

        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );

		SDL_FreeSurface( loadedSurface );

	return newTexture;
}

void DifficultyBackground()
{
	SDL_SetRenderDrawColor(renderer , 0x00 , 0x00 , 0x00 , 0x00 );
	SDL_RenderClear(renderer);

	gScreenSurface = SDL_GetWindowSurface(gWindow);

	gPNGSurface = loadSurface( "Difficulty.png" );

	SDL_BlitSurface( gPNGSurface, NULL, gScreenSurface, NULL );
			
				SDL_UpdateWindowSurface( gWindow );
}

void GameBackground()
{

	SDL_SetRenderDrawColor(renderer , 0x00 , 0x00 , 0x00 , 0x00 );
	SDL_RenderClear(renderer);

	gScreenSurface = SDL_GetWindowSurface(gWindow);

	gPNGSurface = loadSurface( "Background.png" );

	SDL_BlitSurface( gPNGSurface, NULL, gScreenSurface, NULL );
			
	SDL_UpdateWindowSurface( gWindow );


}


void ScoreScreen(SDL_Renderer* renderer)
{ 

	SDL_SetRenderDrawColor(renderer , 0x00 , 0x00 , 0x00 , 0x00 );
	SDL_RenderClear(renderer);

	gTexture = loadTexture("Score.png");

	SDL_RenderCopy(renderer , gTexture , NULL ,NULL);

}

void levelscreen()
{
	SDL_SetRenderDrawColor(renderer , 0x00 , 0x00 , 0x00 , 0x00 );
	SDL_RenderClear(renderer);

	gScreenSurface = SDL_GetWindowSurface(gWindow);

	gPNGSurface = loadSurface( "LI.png" );

	SDL_BlitSurface( gPNGSurface, NULL, gScreenSurface, NULL );
			
				SDL_UpdateWindowSurface( gWindow );
}

void Level1(SDL_Renderer* renderer)
{

	SDL_SetRenderDrawColor(renderer , 0x00 , 0x00 , 0x00 , 0x00 );
	SDL_RenderClear(renderer);

	gTexture = loadTexture("BG1.png");

	SDL_RenderCopy(renderer , gTexture , NULL ,NULL);

}

void Level2(SDL_Renderer* renderer)
{

	SDL_SetRenderDrawColor(renderer , 0x00 , 0x00 , 0x00 , 0x00 );
	SDL_RenderClear(renderer);

	gTexture = loadTexture("BG2.png");

	SDL_RenderCopy(renderer , gTexture , NULL ,NULL);

}

void Level3(SDL_Renderer* renderer)
{

	SDL_SetRenderDrawColor(renderer , 0x00 , 0x00 , 0x00 , 0x00 );
	SDL_RenderClear(renderer);

	gTexture = loadTexture("BG3.png");

	SDL_RenderCopy(renderer , gTexture , NULL ,NULL);

}

void Gameover()
{

	SDL_SetRenderDrawColor(renderer , 0x00 , 0x00 , 0x00 , 0x00 );
	SDL_RenderClear(renderer);

	gPNGSurface = loadSurface( "Gameover.png" );

	SDL_BlitSurface( gPNGSurface, NULL, gScreenSurface, NULL );
			
	SDL_UpdateWindowSurface( gWindow );

	SDL_Delay(2000);

	SDL_FreeSurface(gScreenSurface);

}

void LC()
{

    SDL_SetRenderDrawColor(renderer , 0x00 , 0x00 , 0x00 , 0x00 );
    SDL_RenderClear(renderer);

    gPNGSurface = loadSurface( "LC.png" );

    SDL_BlitSurface( gPNGSurface, NULL, gScreenSurface, NULL );
            
    SDL_UpdateWindowSurface( gWindow );

    SDL_Delay(2000);

    SDL_FreeSurface(gScreenSurface);

}

void GC()
{

    SDL_SetRenderDrawColor(renderer , 0x00 , 0x00 , 0x00 , 0x00 );
    SDL_RenderClear(renderer);

    gPNGSurface = loadSurface( "GC.png" );

    SDL_BlitSurface( gPNGSurface, NULL, gScreenSurface, NULL );
            
    SDL_UpdateWindowSurface( gWindow );

    SDL_Delay(5000);

    SDL_FreeSurface(gScreenSurface);

}

SDL_Surface* loadSurface( std::string path )
{

	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );

		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );

		SDL_FreeSurface( loadedSurface );

	return optimizedSurface;
}

void LoadMusic()
{
    gMusic = Mix_LoadMUS("menu.mp3");
    gEat   = Mix_LoadWAV("sound.wav");
    gClick = Mix_LoadWAV("click.wav");
    gGO    = Mix_LoadWAV("boom.wav");
    gLC    = Mix_LoadWAV("lc.wav");
    gGC    = Mix_LoadWAV("gc.wav");

}

void Turntostring(int a , char rep[])
{
	int i=0,j,temp;
	while(a>0)
	{
		rep[i] =(a%10)+48;
		a = a/10;
		i++;
	}
	rep[i]=0;

	for(j=0; j<=(i-1)/2; j++)
	{
		temp=rep[j];
		rep[j]=rep[i-1-j];
		rep[i-1-j]=temp;
	}
}

int Checkbig(char s1[],char s2[])
{
	int a,b,i;
	a = strlen(s1);
	b=  strlen(s2);
	if(a>b)
	{
		return 1;
	}

	else if(a<b)
	{
		return 0;
	}

	else
	{
		for(i=0; i<a; i++)
		{
			if(s1[i]>s2[i])
			{
				return 1;
			}

			else if(s1[i]<s2[i])
			{
				return 0;
			}
		}
	}
	return 0;
}

void GetScore(char filestr[] ,char gamestr[] , int scoreflag)
{
	int m;
	Turntostring(score , gamestr);
	m = Checkbig(gamestr , filestr);
	if(m == 1)
	{
		if(scoreflag == 1)
		{
			FILE *gamefile  = fopen("1.cpp" , "w");
			fprintf(gamefile, "%s" , gamestr);
		}

		if(scoreflag == 2)
		{
			FILE *gamefile  = fopen("2.cpp" , "w");
			fprintf(gamefile, "%s" , gamestr);
		}

		if(scoreflag == 3)
		{
			FILE *gamefile  = fopen("3.cpp" , "w");
			fprintf(gamefile, "%s" , gamestr);
		}

		if(scoreflag == 4)
		{
			FILE *gamefile  = fopen("4.cpp" , "w");
			fprintf(gamefile, "%s" , gamestr);
		}

		if(scoreflag == 5)
		{
			FILE *gamefile  = fopen("5.cpp" , "w");
			fprintf(gamefile, "%s" , gamestr);
		}

		if(scoreflag == 6)
		{
			FILE *gamefile  = fopen("6.cpp" , "w");
			fprintf(gamefile, "%s" , gamestr);
		}

		if(scoreflag == 7)
		{
			FILE *gamefile  = fopen("7.cpp" , "w");
			fprintf(gamefile, "%s" , gamestr);
		}

		if(scoreflag == 8)
		{
			FILE *gamefile  = fopen("8.cpp" , "w");
			fprintf(gamefile, "%s" , gamestr);
		}

		if(scoreflag == 9)
		{
			FILE *gamefile  = fopen("9.cpp" , "w");
			fprintf(gamefile, "%s" , gamestr);
		}

		if(scoreflag == 10)
		{
			FILE *gamefile  = fopen("10.cpp" , "w");
			fprintf(gamefile, "%s" , gamestr);
		}

		if(scoreflag == 11)
		{
			FILE *gamefile  = fopen("11.cpp" , "w");
			fprintf(gamefile, "%s" , gamestr);
		}

		if(scoreflag == 12)
		{
			FILE *gamefile  = fopen("12.cpp" , "w");
			fprintf(gamefile, "%s" , gamestr);
		}
	}
}


void close()
{
	SDL_FreeSurface( gPNGSurface );
	gPNGSurface = NULL;

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = NULL;

	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	SDL_DestroyTexture(sTexture);
	sTexture = NULL;
	SDL_FreeSurface(ScoreSurface);
	ScoreSurface = NULL;

	SDL_DestroyTexture(ScT1);
	ScT1 = NULL;
	SDL_FreeSurface(ScS1);
	ScS1 = NULL;


	SDL_DestroyTexture(ScT2);
	ScT2 = NULL;
	SDL_FreeSurface(ScS2);
	ScS2 = NULL;


	SDL_DestroyTexture(ScT3);
	ScT3 = NULL;
	SDL_FreeSurface(ScS3);
	ScS3 = NULL;


	SDL_DestroyTexture(ScT4);
	ScT4 = NULL;
	SDL_FreeSurface(ScS4);
	ScS4 = NULL;


	SDL_DestroyTexture(ScT5);
	ScT5 = NULL;
	SDL_FreeSurface(ScS5);
	ScS5 = NULL;


	SDL_DestroyTexture(ScT6);
	ScT6 = NULL;
	SDL_FreeSurface(ScS6);
	ScS6 = NULL;


	SDL_DestroyTexture(ScT7);
	ScT7 = NULL;
	SDL_FreeSurface(ScS7);
	ScS7 = NULL;


	SDL_DestroyTexture(ScT8);
	ScT8 = NULL;
	SDL_FreeSurface(ScS8);
	ScS8 = NULL;


	SDL_DestroyTexture(ScT9);
	ScT9 = NULL;
	SDL_FreeSurface(ScS9);
	ScS9 = NULL;


	SDL_DestroyTexture(ScT10);
	ScT10 = NULL;
	SDL_FreeSurface(ScS10);
	ScS10 = NULL;


	SDL_DestroyTexture(ScT11);
	ScT11 = NULL;
	SDL_FreeSurface(ScS11);
	ScS11 = NULL;


	SDL_DestroyTexture(ScT12);
	ScT12 = NULL;
	SDL_FreeSurface(ScS12);
	ScS12 = NULL;

	Mix_FreeChunk(gEat);
	gEat = NULL;

	Mix_FreeChunk(gClick);
	gClick = NULL;

	Mix_FreeChunk(gLC);
	gLC = NULL;

	Mix_FreeChunk(gGC);
	gGC = NULL;

	Mix_FreeChunk(gGO);
	gGO = NULL;

	Mix_FreeMusic(gMusic);
	gMusic = NULL;

	TTF_CloseFont(Scorefont);


	IMG_Quit();
    Mix_Quit();
	SDL_Quit();

}

const SDL_Color SnakeColor       = {.r = 200 , .g = 50  , .b = 50  , .a = 255};
const SDL_Color FoodColor        = {.r = 20  , .g = 200 , .b = 50  , .a = 0  };
const SDL_Color backgroundColor  = {.r = 120 , .g = 50  , .b = 100 , .a = 200};
      SDL_Color FontColor        = { 255 , 255 , 255};
const SDL_Color ObstacleColor    = {.r = 255 , .g = 255 , .b = 255 , .a = 255};


#define FieldWidth 32
#define FieldUnit (ScreenWidth / FieldWidth)
#define FieldHeight (FieldWidth / 16 * 9)

void ConstructField(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, 
    	backgroundColor.a);

    SDL_Rect field =
    {
        0, 0, FieldWidth * FieldUnit, FieldHeight * FieldUnit
    };

    SDL_RenderFillRect(renderer, &field);
}

void L1obs1(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        90, 125, 95, 474
    };

    SDL_RenderFillRect(renderer, &field);
}

void L1obs2(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        290, 643, 710, 35
    };

    SDL_RenderFillRect(renderer, &field);
}

void L1obs3(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        1086, 126, 72, 473
    };

    SDL_RenderFillRect(renderer, &field);
}

void L1obs4(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        287, 82, 710, 33
    };

    SDL_RenderFillRect(renderer, &field);
}

void Level1obs(SDL_Renderer *renderer)
{
	L1obs1(renderer);
	L1obs2(renderer);
	L1obs3(renderer);
	L1obs4(renderer);
}

void L2obs1(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        1085, 45, 110, 230
    };

    SDL_RenderFillRect(renderer, &field);
}

void L2obs2(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        605, 45 , 110, 230
    };

    SDL_RenderFillRect(renderer, &field);
}

void L2obs3(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        85, 45, 110, 230
    };

    SDL_RenderFillRect(renderer, &field);
}

void L2obs4(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        1085, 445, 110, 230
    };

    SDL_RenderFillRect(renderer, &field);
}

void L2obs5(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        605, 445, 110, 230
    };

    SDL_RenderFillRect(renderer, &field);
}

void L2obs6(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        85, 445, 110, 230
    };

    SDL_RenderFillRect(renderer, &field);
}


void L2obs7(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        85, 325, 1110,70 
    };

    SDL_RenderFillRect(renderer, &field);
}

void Level2obs(SDL_Renderer *renderer)
{
	L2obs1(renderer);
	L2obs2(renderer);
	L2obs3(renderer);
	L2obs4(renderer);
	L2obs5(renderer);
	L2obs6(renderer);
	L2obs7(renderer);
}

void L3obs1(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        85, 85 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs2(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        325, 85 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs3(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        565, 85 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs4(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        805, 85 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs5(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        1045, 85 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs6(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        85, 205 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs7(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        325, 205 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs8(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        565, 205 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs9(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        805, 205 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs10(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        1045, 205 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs11(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        85, 325 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs12(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        325, 325 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs13(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        565, 325 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs14(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        805, 325 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs15(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        1045, 325 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs16(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        85, 445 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs17(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        325, 445 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs18(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        565, 445 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs19(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        805, 445 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs20(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        1045, 445 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs21(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        85, 565 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs22(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        325, 565 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs23(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        565, 565 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs24(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        805, 565 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}

void L3obs25(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, ObstacleColor.r, ObstacleColor.g, ObstacleColor.b, 
    	ObstacleColor.a);

    SDL_Rect field =
    {
        1045, 565 , 70, 70
    };

    SDL_RenderFillRect(renderer, &field);
}


void Level3obs(SDL_Renderer* renderer)
{
	L3obs1(renderer);
	L3obs2(renderer);
	L3obs3(renderer);
	L3obs4(renderer);
	L3obs5(renderer);
	L3obs6(renderer);
	L3obs7(renderer);
	L3obs8(renderer);
	L3obs9(renderer);
	L3obs10(renderer);
	L3obs11(renderer);
	L3obs12(renderer);
	L3obs13(renderer);
	L3obs14(renderer);
	L3obs15(renderer);
	L3obs16(renderer);
	L3obs17(renderer);
	L3obs18(renderer);
	L3obs19(renderer);
	L3obs20(renderer);
	L3obs21(renderer);
	L3obs22(renderer);
	L3obs23(renderer);
	L3obs24(renderer);
	L3obs25(renderer);
}

void ConstructScore(SDL_Renderer* renderer)
{
	int len, o = 0 , p = 0;
	Turntostring(score , scorestring);
	len = strlen(scorestring);
	char upto [15];
	upto[0] = 'S';
	upto[1] = 'c';
	upto[2] = 'o';
	upto[3] = 'r';
	upto[4] = 'e';
	upto[5] = ':';
	upto[6] = scorestring[0];
	if(len == 1)
	{
		upto[7] = 0;
	}
	else
	{
		upto[7] = scorestring[1];
		upto[8] = 0;
	}

	SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 0x00 );

	ScoreSurface = TTF_RenderText_Solid(Scorefont , upto , FontColor );

	if(ScoreSurface == NULL)
	{
		printf("*\n");
	}

	sTexture = SDL_CreateTextureFromSurface(renderer , ScoreSurface);
	if(sTexture == NULL)
	{
		printf("**\n");
	}

	SDL_QueryTexture(sTexture , NULL , NULL , &o, &p);

	SDL_Rect ScoreRect = {

		.x = 476,
		.y = 11,
		.w = o,
		.h = p,
	}; 

	SDL_RenderCopy(renderer , sTexture , NULL , &ScoreRect);

}

void ConstructScore1(SDL_Renderer* renderer)
{
	int x1 = 0 , y1 = 0;
	SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 0x00 );

	ScS1 = TTF_RenderText_Solid(Scorefont , filestr1 , FontColor);

	ScT1 = SDL_CreateTextureFromSurface(renderer , ScS1);

	SDL_QueryTexture(ScT1 , NULL , NULL , &x1 , &y1);

	SDL_Rect ScR1 = {
		.x = 193,
		.y = 9,
		.w = x1,
		.h = y1,
	};

	SDL_RenderCopy(renderer , ScT1 , NULL , &ScR1);
}


void ConstructScore2(SDL_Renderer* renderer)
{
	int x1 = 0 , y1 = 0;
	SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 0x00 );

	ScS2 = TTF_RenderText_Solid(Scorefont , filestr2 , FontColor);

	ScT2 = SDL_CreateTextureFromSurface(renderer , ScS2);

	SDL_QueryTexture(ScT2 , NULL , NULL , &x1 , &y1);

	SDL_Rect ScR1 = {
		.x = 234,
		.y = 41,
		.w = x1,
		.h = y1,
	};

	SDL_RenderCopy(renderer , ScT2 , NULL , &ScR1);
}

void ConstructScore3(SDL_Renderer* renderer)
{
	int x1 = 0 , y1 = 0;
	SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 0x00 );

	ScS3 = TTF_RenderText_Solid(Scorefont , filestr3 , FontColor);

	ScT3 = SDL_CreateTextureFromSurface(renderer , ScS3);

	SDL_QueryTexture(ScT3 , NULL , NULL , &x1 , &y1);

	SDL_Rect ScR1 = {
		.x = 203,
		.y = 72,
		.w = x1,
		.h = y1,
	};

	SDL_RenderCopy(renderer , ScT3 , NULL , &ScR1);
}

void ConstructScore4(SDL_Renderer* renderer)
{
	int x1 = 0 , y1 = 0;
	SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 0x00 );

	ScS4 = TTF_RenderText_Solid(Scorefont , filestr4 , FontColor);

	ScT4 = SDL_CreateTextureFromSurface(renderer , ScS4);

	SDL_QueryTexture(ScT4 , NULL , NULL , &x1 , &y1);

	SDL_Rect ScR1 = {
		.x = 188,
		.y = 136,
		.w = x1,
		.h = y1,
	};

	SDL_RenderCopy(renderer , ScT4 , NULL , &ScR1);
}

void ConstructScore5(SDL_Renderer* renderer)
{
	int x1 = 0 , y1 = 0;
	SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 0x00 );

	ScS5 = TTF_RenderText_Solid(Scorefont , filestr5 , FontColor);

	ScT5 = SDL_CreateTextureFromSurface(renderer , ScS5);

	SDL_QueryTexture(ScT5 , NULL , NULL , &x1 , &y1);

	SDL_Rect ScR1 = {
		.x = 229,
		.y = 168,
		.w = x1,
		.h = y1,
	};

	SDL_RenderCopy(renderer , ScT5 , NULL , &ScR1);
}

void ConstructScore6(SDL_Renderer* renderer)
{
	int x1 = 0 , y1 = 0;
	SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 0x00 );

	ScS6 = TTF_RenderText_Solid(Scorefont , filestr6 , FontColor);

	ScT6 = SDL_CreateTextureFromSurface(renderer , ScS6);

	SDL_QueryTexture(ScT6 , NULL , NULL , &x1 , &y1);

	SDL_Rect ScR1 = {
		.x = 188,
		.y = 200,
		.w = x1,
		.h = y1,
	};

	SDL_RenderCopy(renderer , ScT6 , NULL , &ScR1);
}

void ConstructScore7(SDL_Renderer* renderer)
{
	int x1 = 0 , y1 = 0;
	SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 0x00 );

	ScS7 = TTF_RenderText_Solid(Scorefont , filestr7 , FontColor);

	ScT7 = SDL_CreateTextureFromSurface(renderer , ScS7);

	SDL_QueryTexture(ScT7 , NULL , NULL , &x1 , &y1);

	SDL_Rect ScR1 = {
		.x = 188,
		.y = 264,
		.w = x1,
		.h = y1,
	};

	SDL_RenderCopy(renderer , ScT7 , NULL , &ScR1);
}

void ConstructScore8(SDL_Renderer* renderer)
{
	int x1 = 0 , y1 = 0;
	SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 0x00 );

	ScS8 = TTF_RenderText_Solid(Scorefont , filestr8 , FontColor);

	ScT8 = SDL_CreateTextureFromSurface(renderer , ScS8);

	SDL_QueryTexture(ScT8 , NULL , NULL , &x1 , &y1);

	SDL_Rect ScR1 = {
		.x = 229,
		.y = 296,
		.w = x1,
		.h = y1,
	};

	SDL_RenderCopy(renderer , ScT8 , NULL , &ScR1);
}

void ConstructScore9(SDL_Renderer* renderer)
{
	int x1 = 0 , y1 = 0;
	SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 0x00 );

	ScS9 = TTF_RenderText_Solid(Scorefont , filestr9 , FontColor);

	ScT9 = SDL_CreateTextureFromSurface(renderer , ScS9);

	SDL_QueryTexture(ScT9 , NULL , NULL , &x1 , &y1);

	SDL_Rect ScR1 = {
		.x = 188,
		.y = 328,
		.w = x1,
		.h = y1,
	};

	SDL_RenderCopy(renderer , ScT9 , NULL , &ScR1);
}

void ConstructScore10(SDL_Renderer* renderer)
{
	int x1 = 0 , y1 = 0;
	SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 0x00 );

	ScS10 = TTF_RenderText_Solid(Scorefont , filestr10 , FontColor);

	ScT10 = SDL_CreateTextureFromSurface(renderer , ScS10);

	SDL_QueryTexture(ScT10 , NULL , NULL , &x1 , &y1);

	SDL_Rect ScR1 = {
		.x = 188,
		.y = 392,
		.w = x1,
		.h = y1,
	};

	SDL_RenderCopy(renderer , ScT10 , NULL , &ScR1);
}

void ConstructScore11(SDL_Renderer* renderer)
{
	int x1 = 0 , y1 = 0;
	SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 0x00 );

	ScS11 = TTF_RenderText_Solid(Scorefont , filestr11 , FontColor);

	ScT11 = SDL_CreateTextureFromSurface(renderer , ScS11);

	SDL_QueryTexture(ScT11 , NULL , NULL , &x1 , &y1);

	SDL_Rect ScR1 = {
		.x = 229,
		.y = 424,
		.w = x1,
		.h = y1,
	};

	SDL_RenderCopy(renderer , ScT11 , NULL , &ScR1);
}

void ConstructScore12(SDL_Renderer* renderer)
{
	int x1 = 0 , y1 = 0;
	SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 0x00 );

	ScS12 = TTF_RenderText_Solid(Scorefont , filestr12 , FontColor);

	ScT12 = SDL_CreateTextureFromSurface(renderer , ScS12);

	SDL_QueryTexture(ScT12 , NULL , NULL , &x1 , &y1);

	SDL_Rect ScR1 = {
		.x = 188,
		.y = 456,
		.w = x1,
		.h = y1,
	};

	SDL_RenderCopy(renderer , ScT12 , NULL , &ScR1);
}


bool CellOccupationFlag[FieldHeight][FieldWidth];

struct position
{
    int r;
    int c;
};

position Food;

void GenerateFood()
{
    while (CellOccupationFlag[Food.r][Food.c])
    {
    	Food.r = rand() % (FieldHeight);
        Food.c = rand() % (FieldWidth);
    }


    if(levelflag == 1 || levelflag == 4)
    {
    	if(Food.r * FieldUnit>=84 && Food.r * FieldUnit<=599 && Food.c * FieldUnit>=49 && Food.c * FieldUnit<=185)
    	{
    		Food.c = Food.c + 5;
    	}

        else if(Food.r * FieldUnit>=602 && Food.r * FieldUnit<=678 && Food.c * FieldUnit>=249 && Food.c * FieldUnit<=1000)
        {
    		Food.r  = Food.r - 3;
    	}

    	else if(Food.r * FieldUnit>=85 && Food.r * FieldUnit<=599 && Food.c * FieldUnit>=1045 && Food.c * FieldUnit<=1158)
        {
    		Food.c = Food.c - 5;
    	}

    	else if(Food.r * FieldUnit>=41 && Food.r * FieldUnit<=115 && Food.c * FieldUnit>=246 && Food.c * FieldUnit<=997)
        {
    		Food.r = Food.r + 3;
    	}
    }


    if(levelflag == 2 || levelflag == 5)
    {
    	if(Food.r * FieldUnit>=5 && Food.r * FieldUnit<=275 && Food.c * FieldUnit>=1045 && Food.c * FieldUnit<=1195)
    	{
    		Food.c = Food.c - 5;
    	}

        else if(Food.r * FieldUnit>=5 && Food.r * FieldUnit<=275 && Food.c * FieldUnit>=565 && Food.c * FieldUnit<=715)
        {
    		Food.c  = Food.c + 5;
    	}

    	else if(Food.r * FieldUnit>=5 && Food.r * FieldUnit<=275 && Food.c * FieldUnit>=45 && Food.c * FieldUnit<195)
        {
    		Food.c = Food.c + 5;
    	}

    	else if(Food.r * FieldUnit>=405 && Food.r * FieldUnit<=675 && Food.c * FieldUnit>=1045 && Food.c * FieldUnit<=1195)
        {
    		Food.c = Food.c - 5;
    	}

    	else if(Food.r * FieldUnit>=405 && Food.r * FieldUnit<=675 && Food.c * FieldUnit>=565 && Food.c * FieldUnit<=715)
        {
    		Food.c = Food.c + 3;
    	}

    	else if(Food.r * FieldUnit>=405 && Food.r * FieldUnit<=675 && Food.c * FieldUnit>=45 && Food.c * FieldUnit<=195)
        {
    		Food.c = Food.c + 5;
    	}

    	else if(Food.r * FieldUnit>=285 && Food.r * FieldUnit<=395 && Food.c * FieldUnit>=45 && Food.c * FieldUnit<=1195)
        {
    		Food.r = Food.r - 4;

			if(Food.r * FieldUnit>=5 && Food.r * FieldUnit<=275 && Food.c * FieldUnit>=1045 && Food.c * FieldUnit<=1195)
    		{
    			Food.c = Food.c - 5;
    		}

	        else if(Food.r * FieldUnit>=5 && Food.r * FieldUnit<=275 && Food.c * FieldUnit>=565 && Food.c * FieldUnit<=715)
	        {
	    		Food.c  = Food.c + 5;
	    	}

	    	else if(Food.r * FieldUnit>=5 && Food.r * FieldUnit<=275 && Food.c * FieldUnit>=45 && Food.c * FieldUnit<195)
	        {
	    		Food.c = Food.c + 5;
	    	}

    	}
    }


    if(levelflag == 3 || levelflag == 6)
    {
        if(Food.r * FieldUnit>=45 && Food.r * FieldUnit<=155 && Food.c * FieldUnit>=45 && Food.c * FieldUnit<=155)
        {
            Food.c = Food.c + 3;//1
        }

        else if(Food.r * FieldUnit>=45 && Food.r * FieldUnit<=155 && Food.c * FieldUnit>=285 && Food.c * FieldUnit<=395)
        {
            Food.c  = Food.c + 3;//2
        }

        else if(Food.r * FieldUnit>=45 && Food.r * FieldUnit<=155 && Food.c * FieldUnit>=525 && Food.c * FieldUnit<=635)
        {
            Food.c = Food.c + 3;//3
        }

        else if(Food.r * FieldUnit>=45 && Food.r * FieldUnit<=155 && Food.c * FieldUnit>=765 && Food.c * FieldUnit<=875)
        {
            Food.c= Food.c + 3;//4
        }

        else if(Food.r * FieldUnit>=45 && Food.r * FieldUnit<=155 && Food.c * FieldUnit>=1005 && Food.c * FieldUnit<=1115)
        {
            Food.c= Food.c + 3;//5
        }

        else if(Food.r * FieldUnit>=165 && Food.r * FieldUnit<=275 && Food.c * FieldUnit>=45 && Food.c * FieldUnit<=155)
        {
            Food.c = Food.c + 3;//6
        }

        else if(Food.r * FieldUnit>=165 && Food.r * FieldUnit<=275 && Food.c * FieldUnit>=285 && Food.c * FieldUnit<=395)
        {
            Food.c  = Food.c + 3;//7
        }

        else if(Food.r * FieldUnit>=165 && Food.r * FieldUnit<=275 && Food.c * FieldUnit>=525 && Food.c * FieldUnit<=635)
        {
            Food.c = Food.c + 3;//8
        }

        else if(Food.r * FieldUnit>=165 && Food.r * FieldUnit<=275 && Food.c * FieldUnit>=765 && Food.c * FieldUnit<=875)
        {
            Food.c= Food.c + 3;//9
        }

        else if(Food.r * FieldUnit>=165 && Food.r * FieldUnit<=275 && Food.c * FieldUnit>=1005 && Food.c * FieldUnit<=1115)
        {
            Food.c= Food.c + 3;//10
        }

        else if(Food.r * FieldUnit>=285 && Food.r * FieldUnit<=395 && Food.c * FieldUnit>=45 && Food.c * FieldUnit<=155)
        {
            Food.c = Food.c + 3;//11
        }

        else if(Food.r * FieldUnit>=285 && Food.r * FieldUnit<=395 && Food.c * FieldUnit>=285 && Food.c * FieldUnit<=395)
        {
            Food.c  = Food.c + 3;//12
        }

        else if(Food.r * FieldUnit>=285 && Food.r * FieldUnit<=395 && Food.c * FieldUnit>=525 && Food.c * FieldUnit<=635)
        {
            Food.c = Food.c + 3;//13
        }

        else if(Food.r * FieldUnit>=285 && Food.r * FieldUnit<=395 && Food.c * FieldUnit>=765 && Food.c * FieldUnit<=875)
        {
            Food.c= Food.c + 3;//14
        }

        else if(Food.r * FieldUnit>=285 && Food.r * FieldUnit<=515 && Food.c * FieldUnit>=1005 && Food.c * FieldUnit<=1115)
        {
            Food.c= Food.c + 3;//15
        }

        else if(Food.r * FieldUnit>=405 && Food.r * FieldUnit<=515 && Food.c * FieldUnit>=45 && Food.c * FieldUnit<=155)
        {
            Food.c = Food.c + 3;//16
        }

        else if(Food.r * FieldUnit>=405 && Food.r * FieldUnit<=515 && Food.c * FieldUnit>=285 && Food.c * FieldUnit<=395)
        {
            Food.c  = Food.c + 3;//17
        }

        else if(Food.r * FieldUnit>=405 && Food.r * FieldUnit<=515 && Food.c * FieldUnit>=525 && Food.c * FieldUnit<=635)
        {
            Food.c = Food.c + 3;//18
        }

        else if(Food.r * FieldUnit>=405 && Food.r * FieldUnit<=515 && Food.c * FieldUnit>=765 && Food.c * FieldUnit<=875)
        {
            Food.c= Food.c + 3;//19
        }

        else if(Food.r * FieldUnit>=405 && Food.r * FieldUnit<=515 && Food.c * FieldUnit>=1005 && Food.c * FieldUnit<=1115)
        {
            Food.c= Food.c + 3;//20
        }

        else if(Food.r * FieldUnit>=525 && Food.r * FieldUnit<=635 && Food.c * FieldUnit>=45 && Food.c * FieldUnit<=155)
        {
            Food.c = Food.c + 3;//21
        }

        else if(Food.r * FieldUnit>=525 && Food.r * FieldUnit<=635 && Food.c * FieldUnit>=285 && Food.c * FieldUnit<=395)
        {
            Food.c  = Food.c + 3;//22
        }

        else if(Food.r * FieldUnit>=525 && Food.r * FieldUnit<=635 && Food.c * FieldUnit>=525 && Food.c * FieldUnit<=635)
        {
            Food.c = Food.c + 3;//23
        }

        else if(Food.r * FieldUnit>=525 && Food.r * FieldUnit<=635 && Food.c * FieldUnit>=765 && Food.c * FieldUnit<=875)
        {
            Food.c= Food.c + 3;//24
        }

        else if(Food.r * FieldUnit>=525 && Food.r * FieldUnit<=635 && Food.c * FieldUnit>=1005 && Food.c * FieldUnit<=1115)
        {
            Food.c= Food.c + 3;//25
        }

    }
}

void ConstructFood(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, FoodColor.r, FoodColor.g, FoodColor.b, FoodColor.a);

    SDL_Rect FoodCell =
    {
        .x = Food.c * FieldUnit,
        .y = Food.r * FieldUnit,
        .w = FieldUnit,
        .h = FieldUnit
    };

    SDL_RenderFillRect(renderer, &FoodCell);
    SDL_RenderDrawRect(renderer, &FoodCell);
}

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
}; 

void getMovement(int *dr, int *dc, Direction direction)
{
    switch (direction)
    {

    case UP:
        *dr = -1;
        *dc = 0;
        break;

    case DOWN:
        *dr = 1;
        *dc = 0;
        break;

    case RIGHT:
        *dr = 0;
        *dc = 1;
        break;

    case LEFT:
        *dr = 0;
        *dc = -1;
        break;

    default:
        *dr = 0;
        *dc = 0;
        break;

    }
}

 struct SnakeUnit
{
    int r;
    int c;
    Direction direction;
};

#define SnakeMaxArea 10000

struct SnakeFill
{
    SnakeUnit units[SnakeMaxArea];
    int area;
};

SnakeFill Snake;

Direction GetDirection()
{
    if (Snake.area == 0)
    {
        return UP;
    }

    return Snake.units[0].direction;
}

void SetDirection(Direction direction)
{
    if (Snake.area != 0)
    {
        Snake.units[0].direction = direction;
    }
}

void SnakeUnitInitialize(int i)
{
    Snake.units[i] = (SnakeUnit){0, 0, RIGHT};
}

void SnakeInitialize(int area, int r, int c, Direction direction)
{
    Snake.area = area;

    for (int i = 0; i < area; i++)
    {
        if (i == 0)
        {
            Snake.units[i].r = r;
            Snake.units[i].c = c;
        }
        else
        {
            int dr, dc;
            getMovement(&dr, &dc, Snake.units[i - 1].direction);
            Snake.units[i].r = Snake.units[i - 1].r - dr;
            Snake.units[i].c = Snake.units[i - 1].c - dc;
        }
        Snake.units[i].direction = direction;
        CellOccupationFlag[Snake.units[i].r][Snake.units[i].c] = true;
    }
}

void SnakeAreaIncrease(const SnakeUnit *NewUnit)
{
    Snake.units[Snake.area++] = *NewUnit;
}

bool ValidMoveFlag(int NewUnit_r, int NewUnit_c)
{
    if (NewUnit_r >= FieldHeight 
    	|| NewUnit_r < 0 
    	||NewUnit_c >= FieldWidth 
    	|| NewUnit_c < 0 
    	||(CellOccupationFlag[NewUnit_r][NewUnit_c] &&
             !(NewUnit_r == Snake.units[Snake.area - 1].r &&
               NewUnit_c == Snake.units[Snake.area - 1].c)))
    {

        return false;
    }

    if(levelflag == 1 || levelflag == 4)
    {
    	if((NewUnit_r>=3 && NewUnit_r<=14 && NewUnit_c>=2 && NewUnit_c<=4)||(NewUnit_r == 16 && 
    		NewUnit_c>=7 && NewUnit_c<=24)||(NewUnit_r>=3 && NewUnit_r<=14 && NewUnit_c>=27 && NewUnit_c<=28)
    		||(NewUnit_r == 2 && NewUnit_c>=7 && NewUnit_c<=24))
    	{
    		return false;
    	}
    }


    if(levelflag == 2 || levelflag == 5)
    {
    	if((NewUnit_r>=1 && NewUnit_r<=6 && NewUnit_c>=2 && NewUnit_c<=4)||(NewUnit_r>=1 && NewUnit_r<=6 && 
    		NewUnit_c>=15 && NewUnit_c<=17)||(NewUnit_r>=1 && NewUnit_r<=6 && NewUnit_c>=27 && NewUnit_c<=29)
    		||(NewUnit_r>=11 && NewUnit_r<=16 && NewUnit_c>=2 && NewUnit_c<=4)||(NewUnit_r>=11 && NewUnit_r<=16 && 
    			NewUnit_c>=15 && NewUnit_c<=17)||(NewUnit_r>=11 && NewUnit_r<=16 && NewUnit_c>=27 && NewUnit_c<=29)
    		||(NewUnit_r>=8 && NewUnit_r<=9 && NewUnit_c>=2 && NewUnit_c<=29))
    	{
    		return false;
    	}
    }

    if(levelflag == 3 || levelflag == 6)
    {
        if((NewUnit_r>=2 && NewUnit_r<=3 && NewUnit_c>=2 && NewUnit_c<=3)||(NewUnit_r>=2 && NewUnit_r<=3 && NewUnit_c>=8
         && NewUnit_c<=9)||(NewUnit_r>=2 && NewUnit_r<=3 && NewUnit_c>=14 && NewUnit_c<=15)||(NewUnit_r>=2 && 
         NewUnit_r<=3 && NewUnit_c>=20 && NewUnit_c<=21)||(NewUnit_r>=2 && NewUnit_r<=3 && NewUnit_c>=26 && 
         NewUnit_c<=27)||(NewUnit_r>=5 && NewUnit_r<=6 && NewUnit_c>=2 && NewUnit_c<=3)||(NewUnit_r>=5 && NewUnit_r<=6 
         && NewUnit_c>=8 && NewUnit_c<=9)||(NewUnit_r>=5 && NewUnit_r<=6 && NewUnit_c>=14 && NewUnit_c<=15)||
         (NewUnit_r>=5 && NewUnit_r<=6 && NewUnit_c>=20 && NewUnit_c<=21)||(NewUnit_r>=5 && NewUnit_r<=6 && 
            NewUnit_c>=26 && NewUnit_c<=27)||(NewUnit_r>=8 && NewUnit_r<=9 && NewUnit_c>=2 && NewUnit_c<=3)||
         (NewUnit_r>=8 && NewUnit_r<=9 && NewUnit_c>=8 && NewUnit_c<=9)||(NewUnit_r>=8 && NewUnit_r<=9 && NewUnit_c>=14 
            && NewUnit_c<=15)||(NewUnit_r>=8 && NewUnit_r<=9 && NewUnit_c>=20 && NewUnit_c<=21)||(NewUnit_r>=8 && 
            NewUnit_r<=9 && NewUnit_c>=26 && NewUnit_c<=27)||(NewUnit_r>=11 && NewUnit_r<=12 && NewUnit_c>=2 && 
            NewUnit_c<=3)||(NewUnit_r>=11 && NewUnit_r<=12 && NewUnit_c>=8 && NewUnit_c<=9)||(NewUnit_r>=11 && 
            NewUnit_r<=12 && NewUnit_c>=14 && NewUnit_c<=15)||(NewUnit_r>=11 && NewUnit_r<=12 && NewUnit_c>=20 && 
            NewUnit_c<=21)||(NewUnit_r>=11 && NewUnit_r<=12 && NewUnit_c>=26 &&  NewUnit_c<=27)||(NewUnit_r>=14 && 
            NewUnit_r<=15 && NewUnit_c>=2 && NewUnit_c<=3)||(NewUnit_r>=14 && NewUnit_r<=15 && NewUnit_c>=8 && 
            NewUnit_c<=9)||(NewUnit_r>=14 && NewUnit_r<=15 && NewUnit_c>=14 && NewUnit_c<=15)||(NewUnit_r>=14 && 
            NewUnit_r<=15 && NewUnit_c>=20 && NewUnit_c<=21)||(NewUnit_r>=14 && NewUnit_r<=15 && NewUnit_c>=26 && 
            NewUnit_c<=27))
        {
            return false;
        }
    }

    return true;
}

bool SnakeMovement(bool *EatFoodFlag)
{
    *EatFoodFlag = false;
    int dr, dc;

    getMovement(&dr, &dc, Snake.units[0].direction);

    if (!ValidMoveFlag(Snake.units[0].r + dr, Snake.units[0].c + dc))
    {
        return false;
    }

    for (int i = Snake.area- 1; i >= 0; i--)
    {
        if (i == Snake.area - 1)
        {
            CellOccupationFlag[Snake.units[i].r][Snake.units[i].c] = false;

            // get the change of directions
            getMovement(&dr, &dc, Snake.units[0].direction);

            //  eat food, increase area
            if (Snake.units[0].r + dr == Food.r &&
                    Snake.units[0].c + dc == Food.c)
            {
                SnakeAreaIncrease
                (&Snake.units[Snake.area - 1]);

                CellOccupationFlag[Snake.units[i + 1].r][Snake.
                        units[i + 1].c] = true;

                *EatFoodFlag = true;
            }
        }

        getMovement(&dr, &dc, Snake.units[i].direction);
        Snake.units[i].r += dr;
        Snake.units[i].c += dc;

        // for the head
        if (i == 0)
        {
            CellOccupationFlag[Snake.units[i].r][Snake.units[i].c] = true;
        }
    }

    for (int i = Snake.area - 1; i >= 1; i--)
    {
        Snake.units[i].direction = Snake.units[i - 1].direction;
    }

    return true;
}

void ConstructSnake(SDL_Renderer *renderer)
{

    for (int i = 0; i < Snake.area; i++)
    {
        SDL_Rect Snakecell = 
        { 
          Snake.units[i].c * FieldUnit,
          Snake.units[i].r * FieldUnit,
          FieldUnit, 
          FieldUnit
                        };

        SDL_SetRenderDrawColor(renderer, SnakeColor.r, SnakeColor.g, SnakeColor.b, SnakeColor.a);
        SDL_RenderFillRect(renderer, &Snakecell);
        SDL_RenderDrawRect(renderer, &Snakecell);
    }

}

void GenerateScreen(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    ConstructField(renderer);
    if( levelflag == 1 || levelflag == 4 )
    {
    	//Level1(renderer);
    	Level1obs(renderer);
    }
    if(levelflag == 2 || levelflag == 5)
    {
    	//Level2(renderer);
    	Level2obs(renderer);
    }

    if(levelflag == 3 || levelflag == 6)
    {
    	//Level3(renderer);
    	Level3obs(renderer);
    }
    if(screenflag!=3)
    {
        ConstructScore(renderer);
    }   
    ConstructFood(renderer);
    ConstructSnake(renderer);
}

#define FrameRate 60


void Update()
{
    bool eatfoodflag = false;
    int i,j;
    if (!SnakeMovement((&eatfoodflag)))
    {
        Mix_PlayChannel(-1 , gGO , 0);

    	Gameover();

        levelflag = 1;

        for(i=0;i<FieldHeight;i++)
        {
            for(j=0;j<FieldWidth;j++)
            {
                CellOccupationFlag[i][j]=false;
            }
        }

    	if(scoreflag == 1)
    	{
    		GetScore(filestr1 , gamestr1 , scoreflag);
    	}

    	if(scoreflag == 2)
    	{
    		GetScore(filestr2 , gamestr2 , scoreflag);
    	}

    	if(scoreflag == 3)
    	{
    		GetScore(filestr3 , gamestr3 , scoreflag);
    	}

    	if(scoreflag == 4)
    	{
    		GetScore(filestr4 , gamestr4 , scoreflag);
    	}

    	if(scoreflag == 5)
    	{
    		GetScore(filestr5 , gamestr5 , scoreflag);
    	}

    	if(scoreflag == 6)
    	{
    		GetScore(filestr6 , gamestr6 , scoreflag);
    	}

    	if(scoreflag == 7)
    	{
    		GetScore(filestr7 , gamestr7 , scoreflag);
    	}

    	if(scoreflag == 8)
    	{
    		GetScore(filestr8 , gamestr8 , scoreflag);
    	}

    	if(scoreflag == 9)
    	{
    		GetScore(filestr9 , gamestr9 , scoreflag);
    	}

    	if(scoreflag == 10)
    	{
    		GetScore(filestr10 , gamestr10 , scoreflag);
    	}

    	if(scoreflag == 11)
    	{
    		GetScore(filestr11 , gamestr11 , scoreflag);
    	}

    	if(scoreflag == 12)
    	{
    		GetScore(filestr12 , gamestr12 , scoreflag);
    	}

        screenflag = 0;
        LoopFlag   = 0;
        score      = 0;
    }

    if (eatfoodflag)
    {
    	score++;
    	int trueflag = 0;

        Mix_PlayChannel(-1 , gEat , 0);

    	if(levelflag == 1)
    	{
    		if(score == 10)
    		{
                Mix_PlayChannel(-1 , gLC , 0);

                LC();

    			levelflag = 2;

                for(i=0;i<FieldHeight;i++)
                {
                    for(j=0;j<FieldWidth;j++)
                    {
                        CellOccupationFlag[i][j]=false;
                    }
                }

    			LoopFlag  = 0;
    		}
    	}

        if(levelflag == 2)
        {
            if(score == 20)
            {
                Mix_PlayChannel(-1 , gLC , 0);

                LC();

                levelflag = 3;

                for(i=0;i<FieldHeight;i++)
                {
                    for(j=0;j<FieldWidth;j++)
                    {
                        CellOccupationFlag[i][j]=false;
                    }
                }

                LoopFlag  = 0;
            }
        }

        if(levelflag == 3)
        {
            if(score == 30)
            {
                Mix_PlayChannel(-1 , gGC , 0);

                GC();

                screenflag = 0;
                LoopFlag   = 0;
                score      = 0;
                levelflag  = 1;

                for(i=0;i<FieldHeight;i++)
                {
                    for(j=0;j<FieldWidth;j++)
                    {
                        CellOccupationFlag[i][j]=false;
                    }
                } 
            }
        }
        
        GenerateFood();
	}
}

int main( int argc, char* args[])
{
	srand(time(NULL));

    init();

    TTF_Init();

    Mix_OpenAudio( 44100 , MIX_DEFAULT_FORMAT , 2 , 2048);

    LoadMusic();

    atexit(SDL_Quit);

		renderer = SDL_CreateRenderer(gWindow, -1,
                             SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		Scorefont = TTF_OpenFont("DroidSans.ttf", FontSize);

SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    bool LastMove = true;
    int FramesPerMovement = 10;
    int FrameMod  = 0;

    fgets(filestr1, 5 , scorefile1);
    fgets(filestr2, 5 , scorefile2);
    fgets(filestr3, 5 , scorefile3);
    fgets(filestr4, 5 , scorefile4);
    fgets(filestr5, 5 , scorefile5);
    fgets(filestr6, 5 , scorefile6);
    fgets(filestr7, 5 , scorefile7);
    fgets(filestr8, 5 , scorefile8);
    fgets(filestr9, 5 , scorefile9);
    fgets(filestr10, 5 , scorefile10);
    fgets(filestr11, 5 , scorefile11);
    fgets(filestr12, 5 , scorefile12);


    while (!MainFlag)
    {
    	SDL_Event event;

    	if(screenflag == 0)
    	{

    		int musflag = 0;

    		LoadMenu();

    		if(musflag == 0)
    		{
            Mix_PlayMusic(gMusic , -1);
            musflag++;
        	}

    		int x,y;

    		SDL_GetMouseState(&x,&y);
    		//printf("%d %d\n",x,y); 

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            	case SDL_QUIT:
                MainFlag = 1;
                break;
			
			case SDL_MOUSEBUTTONDOWN:

			if(x>=475 && x<=796 && y>=78 && y<=139)
			{
				screenflag = 1;
                Mix_PlayChannel(-1 , gClick , 0);
                Mix_HaltMusic();
                musflag = 0;
                SDL_FreeSurface(gScreenSurface);
				break;
			}

			if(x>=338 && x<=929 && y>=173 && y<=230)
			{
				screenflag = 2;
                Mix_PlayChannel(-1 , gClick , 0);
                Mix_HaltMusic();
                musflag = 0;
                SDL_FreeSurface(gScreenSurface);
				break;
			}


			if(x>=430 && x<=831 && y>=276 && y<=327)
			{
				screenflag = 3;
                Mix_PlayChannel(-1 , gClick , 0);
                Mix_HaltMusic();
                musflag = 0;
                scoreflag  = 13;
                levelflag  = 13;
                SDL_FreeSurface(gScreenSurface);
				break;
			}

			if(x>=385 && x<=868 && y>=362 && y<=440)
			{
				screenflag = 4;
                Mix_PlayChannel(-1 , gClick , 0);
                SDL_FreeSurface(gScreenSurface);
				break;
			}

			if(x>=402 && x<=864 && y>=467 && y<=522)
			{
				screenflag = 5;
                Mix_PlayChannel(-1 , gClick , 0);
                SDL_FreeSurface(gScreenSurface);
				break;
			}

			if(x>=514 && x<=743 && y>=561 && y<=618)
			{
				MainFlag = 1;
				break;
			}

            case SDL_KEYDOWN:    
            	switch (event.key.keysym.sym)
                {
                	case SDLK_ESCAPE:
                    MainFlag = 1;
                    break;
                }
            }
        }
    }

        if(screenflag == 1)
        {

        	//GameBackground();

        	if(diflag == 1)
        	{
        		if(levelflag == 1 || levelflag == 2 || levelflag == 3)
        		{
        			scoreflag = 1;
        		}
        	}

        	if(diflag == 2)
        	{
        		if(levelflag == 1 || levelflag == 2 || levelflag == 3)
        		{
        			scoreflag = 2;
        		}
        	}

        	if(diflag == 3)
        	{
        		if(levelflag == 1 || levelflag == 2 || levelflag == 3)
        		{
        			scoreflag = 3;
        		}
        	}

        	int l1,m1;

        	SDL_GetMouseState(&l1 , &m1 );
        	//printf("%d %d*\n",l1,m1);

        	/*if(levelflag == 1 || levelflag == 4)
        	{
	        	Level1(renderer);
	        	Level1obs(renderer);
	        	ConstructFood(renderer);
	        	ConstructScore(renderer);
	        	ConstructSnake(renderer);
	        }*/

        	if(LoopFlag == 0)
        	{
        		SnakeInitialize(5, 0, 4, RIGHT);
    			GenerateFood();
    			GenerateScreen(renderer);
    			LoopFlag++;
    		}


			while (SDL_PollEvent(&event))
        	{
        		switch (event.type)
        		{
        			case SDL_QUIT:
                	MainFlag = 1;
                	break;
			
            		case SDL_KEYDOWN:
                	switch (event.key.keysym.sym)
                	{
                		case SDLK_ESCAPE:
                        int i , j;
                        LoopFlag = 0;
                    	screenflag = 0;
                        score = 0;
                        levelflag = 1;

                        for(i=0;i<FieldHeight;i++)
                        {
                            for(j=0;j<FieldWidth;j++)
                            {
                                CellOccupationFlag[i][j]=false;
                            }
                        }
                    	break;

                		case SDLK_UP:
                    	if (GetDirection() != DOWN && GetDirection() != UP &&
                            LastMove)
                    	{
                        	SetDirection(UP);
                        	LastMove = false;
                    	}
                    	break;

                		case SDLK_DOWN:
                    	if (GetDirection() != UP && GetDirection() != DOWN &&
                            LastMove)
                    	{
                        	SetDirection(DOWN);
                        	LastMove = false;
                    	}
                    	break;

                		case SDLK_LEFT:
                    	if (GetDirection() != RIGHT && GetDirection() != LEFT &&
                            LastMove)
                    	{
                        	SetDirection(LEFT);
                        	LastMove = false;
                    	}
                    	break;

                		case SDLK_RIGHT:
                    	if (GetDirection() != LEFT && GetDirection() != RIGHT &&
                            LastMove)
                    	{
                        	SetDirection(RIGHT);
                        	LastMove = false;
                    	}
                    	break;
                    
                	default:
                    break;
                }
                break;

            	default:
                break;
            	}
        	}

        	if (FrameMod == 0)
        	{	
            	Update();
            	LastMove = true;
        	}

        	if(screenflag != 0)
        	{
        		GenerateScreen(renderer);
        		SDL_RenderPresent(renderer);
        		FrameMod = (FrameMod + 1) % FramesPerMovement;
    		}
    	}

    	if(screenflag == 2)
    	{
    		levelscreen();

    		int a,s;

    		SDL_GetMouseState(&a,&s);
    		//printf("%d %d\n",a,s);

    		while (SDL_PollEvent(&event))
        	{
    			switch (event.type)
            	{
            		case SDL_QUIT:
                	MainFlag = 1;
                	break;

                	case SDL_KEYDOWN:
                	switch (event.key.keysym.sym)
                	{
                		case SDLK_ESCAPE:
                    	screenflag = 0;
                    	break;
                    }

                    case SDL_MOUSEBUTTONDOWN:

					if(a>=400 && a<=880 && s>=137 && s<=213)
					{
						levelflag = 4;

						if(diflag == 1)
						{
							scoreflag = 4;
						}
						if(diflag == 2)
						{
							scoreflag = 5;
						}
						if(diflag == 3)
						{
							scoreflag = 6;
						}
						screenflag = 1;
						break;
					}

					if(a>=389 && a<=889 && s>=371 && s<=441)
					{	
						levelflag = 5;

						if(diflag == 1)
						{
							scoreflag = 7;
						}
						if(diflag == 2)
						{
							scoreflag = 8;
						}
						if(diflag == 3)
						{
							scoreflag = 9;
						}
						screenflag = 1;
						break;
					}	


					if(a>=389 && a<=892 && s>=604 && s<=663)
					{
						levelflag = 6;

						if(diflag == 1)
						{
							scoreflag = 10;
						}
						if(diflag == 2)
						{
							scoreflag = 11;
						}
						if(diflag == 3)
						{
							scoreflag = 12;
						}
						screenflag = 1;
						break;
					}
                }
            }

    	}

    	if(screenflag == 3)
        {

        	//GameBackground();

        	if(LoopFlag == 0)
        	{
        		SnakeInitialize(5, 0, 4, RIGHT);
    			GenerateFood();
    			GenerateScreen(renderer);
    			LoopFlag++;
    		}


			while (SDL_PollEvent(&event))
        	{
        		switch (event.type)
        		{
        			case SDL_QUIT:
                	MainFlag = 1;
                	break;
			
            		case SDL_KEYDOWN:
                	switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    int i , j;
                        LoopFlag = 0;
                        screenflag = 0;
                        score = 0;
                        levelflag = 1;

                        for(i=0;i<FieldHeight;i++)
                        {
                            for(j=0;j<FieldWidth;j++)
                            {
                                CellOccupationFlag[i][j]=false;
                            }
                        }
                    break;

                case SDLK_UP:
                    if (GetDirection() != DOWN && GetDirection() != UP &&
                            LastMove)
                    {
                        SetDirection(UP);
                        LastMove = false;
                    }
                    break;

                case SDLK_DOWN:
                    if (GetDirection() != UP && GetDirection() != DOWN &&
                            LastMove)
                    {
                        SetDirection(DOWN);
                        LastMove = false;
                    }
                    break;
                case SDLK_LEFT:
                    if (GetDirection() != RIGHT && GetDirection() != LEFT &&
                            LastMove)
                    {
                        SetDirection(LEFT);
                        LastMove = false;
                    }
                    break;
                case SDLK_RIGHT:
                    if (GetDirection() != LEFT && GetDirection() != RIGHT &&
                            LastMove)
                    {
                        SetDirection(RIGHT);
                        LastMove = false;
                    }
                    break;
                    
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }

        if (FrameMod == 0)
        {
            Update();
            LastMove = true;
        }
        if(LoopFlag !=0)
        {
        	GenerateScreen(renderer);
        	SDL_RenderPresent(renderer);
        	FrameMod = (FrameMod + 1) % FramesPerMovement;
    	}
    	}

    	if(screenflag == 4)
    	{
    		DifficultyBackground();

    		int j,k;

    		SDL_GetMouseState(&j,&k);
    		//printf("%d %d\n",j,k);

    		while (SDL_PollEvent(&event))
        	{

    			switch (event.type)
            	{
            		case SDL_QUIT:
                	MainFlag = 1;
                	break;

                	case SDL_KEYDOWN:
                	switch (event.key.keysym.sym)
                	{
                		case SDLK_ESCAPE:
                    	screenflag = 0;
                    	break;
                    }
			
				case SDL_MOUSEBUTTONDOWN:

				if(j>=494 && j<=770 && k>=30 && k<=110)
				{
					FramesPerMovement = 15;
					diflag = 1;
					screenflag = 0;
					break;
				}

				if(j>=437 && j<=845 && k>=263 && k<=325)
				{	
					FramesPerMovement = 10;
					diflag = 2;
					screenflag = 0;
					break;
				}	


				if(j>=503 && j<=779 && k>=487 && k<=557)
				{
					FramesPerMovement = 5;
					diflag = 3;
					screenflag = 0;
					break;
				}

				}
			}
    	}

    	if(screenflag == 5)
    	{
    		ScoreScreen(renderer);

    		ConstructScore1(renderer);
    		ConstructScore2(renderer);
    		ConstructScore3(renderer);
    		ConstructScore4(renderer);
    		ConstructScore5(renderer);
    		ConstructScore6(renderer);
    		ConstructScore7(renderer);
    		ConstructScore8(renderer);
    		ConstructScore9(renderer);
    		ConstructScore10(renderer);
    		ConstructScore11(renderer);
    		ConstructScore12(renderer);

    		int g,h;

    		SDL_GetMouseState(&g,&h);
    		//printf("%d %d\n",g,h);

    		while (SDL_PollEvent(&event))
        	{
    			switch (event.type)
            	{
            		case SDL_QUIT:
                	MainFlag = 1;
                	break;

                	case SDL_KEYDOWN:
                	switch (event.key.keysym.sym)
                	{
                		case SDLK_ESCAPE:
                    	screenflag = 0;
                    	break;
                    }
                }
    		}

    		SDL_RenderPresent(renderer);
		}
	}

	close();

    return 0;

}