#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAX             9

#define _EMPTY          -1
#define _NOT_EMPTY      0
#define _QUIT           20
#define _RUNNING        21
#define _STOP           22
#define _SELECTED       23
#define _NOT_SELECTED   24
#define _IGNORE_INPUT   25
#define _DIR_UP         26
#define _DIR_DOWN       27


#define _up             72
#define _down           80
#define _left           75
#define _right          77
#define _arrow_keys     224
#define _esc            27
#define _enter          13

typedef struct{
    int ** arr;
    char ** vrr;
    int s_x;
    int s_y;
    int bPos[2];
    int b2Pos[2];
    int b2;

}Board;



int ** get2Dintarray(int y, int x);
void delete2Darray(int y, int ** arr);
char ** get2Dchararray(int y, int x);
void delete2Dchararray(int y, char ** arr);
int getRandomNumber(int max, int min);
void initializeArray(Board * b);
void printArray(Board * b);
int getUserInput();
void handleUserInput(Board * b, int input);
int searchForConnections(Board * b);
int findMatching(int my, int mx, Board * b);
int notInThis(int **explored, int ex, int yy, int xx);
int removeRepeats(Board * b);
void settleNumbers(Board * b);
int checkForEmpty(int x, Board * b);
int getLowerempty(int x, Board * b);
void addMissingNumbers(Board * b);


int main()
{
    int input;
    Board b;
    int GAME_STATE = _RUNNING;
    int result = _EMPTY;


    initializeArray(&b);

    while(searchForConnections(&b) == _NOT_EMPTY){
        removeRepeats(&b);
        settleNumbers(&b);
        addMissingNumbers(&b);
    }

    while(GAME_STATE != _STOP){
        if(result == _EMPTY){
            printArray(&b);
            input = getUserInput();
        }
        system("cls");
        if(input == _QUIT){
            GAME_STATE = _STOP;
            break;
        }else{
            result = _EMPTY;
            /* Handle User Input */
            handleUserInput(&b, input);
            if(searchForConnections(&b) == _NOT_EMPTY){
                removeRepeats(&b);
                printArray(&b);
                system("pause") ;
                system("cls") ;
                result = _NOT_EMPTY;
            }
            settleNumbers(&b);
            addMissingNumbers(&b);

        }
    }
    delete2Darray(b.s_y, b.arr);

    return 0;
}





int getRandomNumber(int max, int min){
    static int initiate = 1;
    int random;

    if (initiate == 1){
        initiate = 0;
        srand(time(NULL));
    }
    random = rand() % (max - min + 1) + min;
    return random;
}





int ** get2Dintarray(int y, int x){
    int **arr;
    int i;

    arr = (int**) malloc(y * sizeof(int*));

    for(i = 0; i < y; i++){
        arr[i] = (int*)malloc(x * sizeof(int*));
    }

    return arr;
}

void delete2Darray(int y, int ** arr){
    int i;
    for(i = 0; i < y; i++){
        free(arr[i]);
    }
    free(arr);
}


char ** get2Dchararray(int y, int x){
    char **arr;
    int i;

    arr = (char**) malloc(y * sizeof(char*));

    for(i = 0; i < y; i++){
        arr[i] = (char*)malloc(x * sizeof(char*));
    }

    return arr;
}

void delete2Dchararray(int y, char ** arr){
    int i;
    for(i = 0; i < y; i++){
        free(arr[i]);
    }
    free(arr);
}


void initializeArray(Board * b){
    int i, j;

    b->s_y = 10;
    b->s_x = 10;
    b->bPos[0] = b->s_y/2;
    b->bPos[1] = b->s_x/2;
    b->b2Pos[0] = b->bPos[0];
    b->b2Pos[1] = b->bPos[1];
    b->b2 = _NOT_SELECTED;
    b->arr = get2Dintarray(b->s_y, b->s_x);
    b->vrr = get2Dchararray(b->s_y, b->s_x);


    for(i = 0; i < b->s_y; i++){
        for(j = 0; j < b->s_x; j++){
            b->arr[i][j] = getRandomNumber(MAX, 0);
            b->vrr[i][j] = ' ';
        }
    }
}



void printArray(Board * b){
    int i, j;

    for(i = 0; i < b->s_y; i++){
        for(j = 0; j < b->s_x; j++){
            if(b->arr[i][j] == -1){
                printf(" %c ", 219);
            }
            else if(b->bPos[0] == i && b->bPos[1] == j ){
                printf("[%i]", b->arr[i][j]);
            }
            else  if(b->b2 == _SELECTED && b->b2Pos[0] == i && b->b2Pos[1] == j){
                printf("[%i]", b->arr[i][j]);
            }else{
                printf(" %i ", b->arr[i][j]);
            }
        }
        printf("\n");
    }

    // printf("\n\nArray 2\n\n");

    // for(i = 0; i < b->s_y; i++){
    //     for(j = 0; j < b->s_x; j++){
    //         printf(" %c ", b->vrr[i][j]);
    //     }
    //     printf("\n");
    // }
}


int getUserInput(){

    int input;
    printf("\n\tPlease Enter Your next Direction\n\tDir : ");
    input = getch();
    printf("%i\n", input);

    if(input == _esc){
        return _QUIT;
    }else if(input == _arrow_keys){
        input = getch();
    }
    return input;
}

void handleUserInput(Board * b, int input){
    int temp;
    switch(input){
        case _up:
            if(b->bPos[0] > 0 ){
                /*Move Up*/
                if(b->b2 == _SELECTED){
                    if(b->bPos[0] >= b->b2Pos[0] && b->bPos[1] == b->b2Pos[1]){
                        b->bPos[0]--;
                    }
                }else{
                    b->bPos[0]--;
                }
            }
        break;

        case _down:
            if( b->bPos[0] < (b->s_y - 1)){
                /*Move Down*/
                if(b->b2 == _SELECTED){
                    if(b->bPos[0] <= b->b2Pos[0] && b->bPos[1] == b->b2Pos[1]){
                        b->bPos[0]++;
                    }
                }else{
                    b->bPos[0]++;
                }
            }
        break;

        case _left:
            if(b->bPos[1] > 0 ){
                /*Move Left*/
                if(b->b2 == _SELECTED){
                    if(b->bPos[1] >= b->b2Pos[1] && b->bPos[0] == b->b2Pos[0]){
                        b->bPos[1]--;
                    }
                }else{
                    b->bPos[1]--;
                }
            }
        break;

        case _right:

            if( b->bPos[1] < (b->s_x - 1)){
                /*Move Right*/
                if(b->b2 == _SELECTED){
                    if(b->bPos[1] <= b->b2Pos[1] && b->bPos[0] == b->b2Pos[0]){
                        b->bPos[1]++;
                    }
                }else{
                    b->bPos[1]++;
                }
            }
        break;

        case _enter:

            if(b->b2 == _SELECTED){
                b->b2 = _NOT_SELECTED;
                temp = b->arr[b->bPos[0]][b->bPos[1]];
                b->arr[b->bPos[0]][b->bPos[1]] = b->arr[b->b2Pos[0]][b->b2Pos[1]];
                b->arr[b->b2Pos[0]][b->b2Pos[1]] = temp;
            }
            else if(b->b2 == _NOT_SELECTED){
                b->b2 = _SELECTED;
                b->b2Pos[0] = b->bPos[0];
                b->b2Pos[1] = b->bPos[1];
            }
        break;

        default:
        break;
    }
}
int searchForConnections(Board * b){
    int i, j;
    int size_x = b->s_x;
    int size_y = b->s_y;
    int result= _EMPTY;

    for (i = 0; i < size_y; ++i)
    {
        for (j = 0; j < size_x; ++j)
        {
            if(result == _EMPTY){
                result = findMatching(i, j, b);
            }else{
                findMatching(i, j, b);
            }
        }
    }





    return result;
}

int findMatching(int my, int mx, Board * b){
    int s_y = b->s_y * b->s_x;
    int ySize = b->s_y;
    int xSize = b->s_x;
    int** explored;
    int** unexplored;
    int ex =0, unex=0, i;
    int count = 0;
    int result = _EMPTY;

    explored = (int**) malloc(s_y * sizeof(int*));
    for(i = 0; i < s_y; i++){
        explored[i] = (int*)malloc(2 * sizeof(int*));
    }

    unexplored = (int**) malloc(s_y * sizeof(int*));
    for(i = 0; i < s_y; i++){
        unexplored[i] = (int*)malloc(2 * sizeof(int*));
    }

    for(i = 0; i < s_y; i++){
        explored[i][0] = -1;
        explored[i][1] = -1;
        unexplored[i][0] = -1;
        unexplored[i][1] = -1;
    }

    while(1){
        explored[ex][0] = my;
        explored[ex++][1] = mx;

        /*check left*/
        if(mx > 0 && b->arr[my][mx] == b->arr[my][mx-1] ){
            if(notInThis(explored, ex, my, mx-1) == 1){
                unexplored[unex][0] = my;
                unexplored[unex++][1] = mx-1;
            }

        }

        /*check right*/
        if(mx < (xSize-1) && b->arr[my][mx] == b->arr[my][mx+1] ){
            if(notInThis(explored, ex, my, mx+1) == 1){
                unexplored[unex][0] = my;
                unexplored[unex++][1] = mx+1;
            }
        }

        /*check up*/
        if(my > 0 && b->arr[my][mx] == b->arr[my-1][mx] ){
            if(notInThis(explored, ex, my-1, mx) == 1){
                unexplored[unex][0] = my-1;
                unexplored[unex++][1] = mx;
            }
        }

        /*check down*/
        if(my < (ySize-1) && b->arr[my][mx] == b->arr[my+1][mx]){
            if(notInThis(explored, ex, my+1, mx) == 1){
                unexplored[unex][0] = my+1;
                unexplored[unex++][1] = mx;
            }
        }

        if(unex != 0){
            int ym = my;
            int xm = mx;
            my = unexplored[0][0];
            mx = unexplored[0][1];
            if(count > 0){
                b->vrr[my][mx] = 'x';
                b->vrr[ym][xm] = 'x';
                if(result == _EMPTY){
                    result = _NOT_EMPTY;
                }
            }
            count++;
            for( i = 0; i < unex-1; i++){
                unexplored[i][0] = unexplored[i+1][0];
                unexplored[i][1] = unexplored[i+1][1];
            }

            if(unex == 1){
                unexplored[0][0] = unexplored[1][0];
                unexplored[0][1] = unexplored[1][1];
            }
            unex--;
        }else{
            for(i = 0; i < s_y; i++){
                free(unexplored[i]);
            }
            free(explored);

            for(i = 0; i < s_y; i++){
                free(explored[i]);
            }
            free(explored);
            return result;
        }
    }


    for(i = 0; i < s_y; i++){
        free(unexplored[i]);
    }
    free(explored);

    for(i = 0; i < s_y; i++){
        free(explored[i]);
    }
    free(explored);
    return result;

}
int notInThis(int **explored, int ex, int yy, int xx){
    int i;
    for(i = 0; i < ex; i++){
        if(explored[i][0] == yy && explored[i][1] == xx){
            return 0;
        }
    }
    return 1;
}

int removeRepeats(Board * b){
    int i, j;
    int stable = 0;
    for(i = 0; i < b->s_y; i++){
        for(j = 0; j < b->s_x; j++){
            if(b->vrr[i][j] == 'x'){
                b->arr[i][j] = _EMPTY;
                b->vrr[i][j] = ' ';
                stable = 1;
            }
        }
    }
    return stable;
}

void settleNumbers(Board * b){
    int i, j;
    int lower = 0;


    for(j = 0; j < b->s_x; j++){
        while(checkForEmpty(j, b) == 1){
            lower = getLowerempty(j, b);
            for(i = lower; i > 0; i--){
                b->arr[i][j] = b->arr[i-1][j];
            }
            b->arr[0][j] = _EMPTY;
        }
    }
}
int getLowerempty(int x, Board * b){
    int i;
    int lower = 0;
    for(i = 0; i < b->s_y; i++){
        if(b->arr[i][x] == _EMPTY){
            if(i > lower){
                lower = i;
            }
        }
    }
    return lower;

}
int checkForEmpty(int x, Board * b){
    int i;
    int init = 0;
    for(i = 0; i < b->s_y; i++){
        if(b->arr[i][x] != _EMPTY && init == 0){
            init = 1;
        }
        if(b->arr[i][x] == _EMPTY && init ==1){
            return 1;
        }
    }
    return 0;
}
void addMissingNumbers(Board * b){
    int i, j;
    for( i = 0; i < b->s_y; i++){
        for( j = 0; j < b->s_x; j++){
            if(b->arr[i][j] == _EMPTY){
                b->arr[i][j] = getRandomNumber(MAX, 0);
            }
        }
    }
}


