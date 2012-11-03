/*Classification of valid sudoku result*/
#include <stdio.h>
#include <stdlib.h>

#ifdef WIN32
typedef  __int64 longlong;
#define LLD "%I64d"
#else
typedef long long longlong;
#define LLD "%lld"
#endif

#define L0 ((longlong)0)
#define L1 ((longlong)1)
#define MAX_COUNT 36288
#define MAX_CLASS 416
short stack[MAX_COUNT][14];
int stack_count;
int board[9][9];
longlong count;
int class_count;
int class_number;
typedef int template;
#define TEMPLATE_COUNT 5184
#define MASK1 ((1<<12)-1)

template temps[100][9][TEMPLATE_COUNT];
int temps_count[100][9];
int class_id[MAX_COUNT];
int class_elem[MAX_CLASS];
int class_weight[MAX_CLASS];

signed char is_index[9][9];
signed char is_value[9][9];

int index_value[900];
int index_pos[900];
int index_count;
int sort[10][6]={
{0,1,2,3,4,5},
{0,1,3,2,4,5},
{0,1,4,2,3,5},
{0,1,5,2,3,4},
{0,2,3,1,4,5},
{0,2,4,1,3,5},
{0,2,5,1,3,4},
{0,3,4,1,2,5},
{0,3,5,1,2,4},
{0,4,5,1,2,3}
};
int row[6]={4,5,6,7,8,9};
int column[6]={2,3,5,6,8,9};
int sorder[9]={8,3,1,4,2,7,5,6,0};
int class[100][9];

//Decode the compressed representation of the first 3 columns in statck[stack_pointer]
void set_board(int stack_pointer){
    int i,j;
    for(i=0;i<3;i++)for(j=0;j<3;j++){
board[i][j]=i*3+j+1;
    }
    for(i=3;i<9;i++){
board[0][i]=row[sort[stack[stack_pointer][0]][i-3]];
    }
    for(i=1;i<10;i++){
int v=stack[stack_pointer][i];
for(j=0;j<12;j++){
    if(v&(1<<j)){
int u=j/6+1;
int v=j%6+3;
board[u][v]=i;
    }
}
    }
}

int cmp_stack(const void *p,const void *q){
    const short *sp;
    const short *sq;
    int i;
    sp=(const short *)p;
    sq=(const short *)q;
    for(i=10;i<14;i++){
if(sp[i]!=sq[i])
    return sp[i]-sq[i];
    }
    for(i=0;i<10;i++){
if(sp[i]!=sq[i])
    return sp[i]-sq[i];
    }
    return 0;
}

//Classify all 9*9 elements into 2 class.
//The left top 3*3 elements and all elements in first row and first column (total 21 elements)
//  are classified as index elements and their value will be assigned in advance
//1 2 3 * * * * * *
//4 5 6 
//7 8 9
//A
//B
//C
//D
//E
//F
//The array is_index gives the index of each index elements
//The array is_value gives the index of each value elements (Non-index elemetns)
//The number of first 9 index elements and the last 6 index elements are filled in advance
//For the other 6 index elements in first column, it is required that for the 2 triple 
//  index elements vector, all numbers should be in increasing order and the first element
//  of the first triple is smaller than the first element in the secodn triple
//  That's A<B<C, D<E<F and A<D. So there're total 10 possible filling methods
//  Array row[sort[][]] gives the 10 possible fillings.
//For each number from 1 to 9, it could fill 1 or 2 elements of the first 15 index elements.
//  The index_value[] array record all possible patterns
//  The array class[][] record the pattern id of each number in each possible filling method
//For each class, the later searching algorithm will search for the number in value elements
  
void generate_all_index(){
   int i,j;
   int model[21];
   for(i=0;i<3;i++)for(j=0;j<3;j++){
      is_index[i][j]=i*3+j;
      is_value[i][j]=-1;
   }
   for(i=3;i<9;i++){
      is_index[i][0]=12+i;
      is_value[i][0]=-1;
   }
   for(j=3;j<9;j++){
      is_index[0][j]=6+j;
      is_value[0][j]=-1;
   }
   for(i=1;i<3;i++)for(j=3;j<9;j++){
      is_index[i][j]=-1;
      is_value[i][j]=(i-1)*6+(j-3);
   }
   for(i=3;i<9;i++)for(j=1;j<9;j++){
      is_index[i][j]=-1;
      is_value[i][j]=12+(i-3)*8+j-1;
   }
   for(i=0;i<9;i++)model[i]=i+1;
   for(i=0;i<10;i++){
      int k,v[9];
      for(k=0;k<6;k++){
  model[k+9]=row[sort[i][k]];
      }
      for(k=0;k<9;k++)v[k]=0;
      for(k=0;k<15;k++){
  v[model[k]-1]|=1<<k;
      }
      for(k=0;k<9;k++){
  int s;
  for(s=0;s<index_count;s++){
              if(index_value[s]==k+1&&index_pos[s]==v[k])break;
  }
  if(s==index_count){
              if(index_count>=900){
  fprintf(stderr,"index out of range\n");
  exit(-1);
      }
              index_value[s]=k+1;
      index_pos[s]=v[k];
      index_count++;
  }
  class[i][k]=s;
      }
   }
}

#define Row(x,y)     (x)
#define Column(x,y)  (y)
#define Board(x,y)   (((x)/3)*3+((y)/3))
#define Filled(x,y)  board[x][y]
char row_used[9];
char column_used[9];
char board_used[9];
int Can_fill(int x,int y){
    if(row_used[Row(x,y)])return 0;
    if(column_used[Column(x,y)])return 0;
    if(board_used[Board(x,y)])return 0;
    return 1;
}

void set(int x,int y){
    board[x][y]=1;
    row_used[Row(x,y)]=1;
    column_used[Column(x,y)]=1;
    board_used[Board(x,y)]=1;
}

void unset(int x,int y){
    board[x][y]=0;
    row_used[Row(x,y)]=0;
    column_used[Column(x,y)]=0;
    board_used[Board(x,y)]=0;
}

short value[9];
//For each filling method d (0<=d<10), find all possible filling methods 
//for the first 3 columns, save the result in stack[][]
//For each element in stack, it cotains 10 short number
//   The first short number tells the method to be used (pattern for the 15 index elements)
//     it should be in [0,9]
//   The other 9 numbers tells the pattern of number 1,2,3,4,5,6,7,8,9 is filled  
//      each bit of the number represent one value element
void sum(int x, short used, int d){
    int i;
    short used2;
    if(x<0){
if(used!=0xFFF){
    fprintf(stderr,"Invalid used %lx found\n",used);
    exit(-1);
}
stack[stack_count][0]=d;
memcpy(&stack[stack_count][1],value,sizeof(value));
stack_count++;
return;
    }
    for(i=0;i<temps_count[d][x];i++){
if(used&temps[d][x][i])
    continue;
if(temps[d][x][i]==0){
    fprintf(stderr,"Invalid temps <%d,%d,%d> found\n",d,x,i);
    exit(-1);
}
used2=used|temps[d][x][i];
value[x]=temps[d][x][i];
sum(x-1,used2,d);
    }
}

//For each given number, try to fill the number into the first three columns of sudoku
//Find all the possible filling methods, all numbers filled in index elements are 
//  encoded into u (total 15 possible locations) and all numbers filled in value 
//  elements are encoded into v (total 12 possible locations)
//  Create mapping from each filling method and number to pattern v.
void find(int x){
    int i;
    if(x>=3){
int u=0;
long v=0;
int s,t;
for(s=0;s<3;s++)for(t=0;t<9;t++){
    if(board[s][t]){
if(is_index[s][t]>=0){
    u|=1<<is_index[s][t];
}else if(is_value[s][t]>=0){
    if(is_value[s][t]>=12){
fprintf(stderr,"value of of range\n");
exit(-1);
    }
    v|=1<<is_value[s][t];
}
    }
}
for(s=0;s<index_count;s++){
    if(u==index_pos[s]){
int m;
t=index_value[s]-1;
for(m=0;m<10;m++){
   if(temps_count[m][t]>=TEMPLATE_COUNT){
       fprintf(stderr,"out of range for count[%d,%d]\n",m,t+1);
       exit(-1);
   }
   if(class[m][t]==s){
      temps[m][t][temps_count[m][t]]=v;
      temps_count[m][t]++;
   }
}
    }
}
return;
    }
    for(i=0;i<9;i++){
if(Can_fill(x,i)){
    set(x,i);
    find(x+1);
    unset(x,i);
}
    }
}

int order3[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
void normalize(int lboard[3][9]){
    int reorder[9];
    int i,j;
    for(i=0;i<3;i++)for(j=0;j<3;j++){
int u=i*3+j;
reorder[lboard[i][j]-1]=u;
    }
    for(i=0;i<3;i++)for(j=0;j<9;j++){
lboard[i][j]=reorder[lboard[i][j]-1]+1;
    }
    for(i=3;i<9;i++)if(lboard[0][i]==4)break;
    if(i>=9){
fprintf(stderr,"Invalid input\n");
exit(-1);
    }
    if(i>=6){
int tmp,s;
for(j=0;j<3;j++)for(s=0;s<3;s++){
    tmp=lboard[j][s+3];
    lboard[j][s+3]=lboard[j][s+6];
    lboard[j][s+6]=tmp;
}
i-=3;
    }
    if(i>3){
int tmp;
for(j=0;j<3;j++){
    tmp=lboard[j][i];
    lboard[j][i]=lboard[j][3];
    lboard[j][3]=tmp;
}
    }
    if(lboard[0][4]>lboard[0][5]){
int tmp;
for(j=0;j<3;j++){
    tmp=lboard[j][4];
    lboard[j][4]=lboard[j][5];
    lboard[j][5]=tmp;
}
    }
    for(i=6;i<9;i++){
for(j=i+1;j<9;j++){
    if(lboard[0][i]>lboard[0][j]){
int tmp,s;
for(s=0;s<3;s++){
    tmp=lboard[s][i];
    lboard[s][i]=lboard[s][j];
    lboard[s][j]=tmp;
}
    }
}
    }
}
longlong board_number(int lboard[3][9]){
    int i,j;
    short x[6];
    longlong v=L0;
    for(j=3;j<9;j++){
short xx=0;
for(i=0;i<3;i++){
    xx|=1<<lboard[i][j];
}
x[j-3]=xx;
    }
    for(i=0;i<3;i++){
for(j=i+1;j<3;j++){
    if(x[i]>x[j]){
short xx=x[i];
x[i]=x[j];
x[j]=xx;
    }
}
    }
    for(i=3;i<6;i++){
        for(j=i+1;j<6;j++){
            if(x[i]>x[j]){
                short xx=x[i];
                x[i]=x[j];
                x[j]=xx;
            }
        }
    }
    for(i=0;i<3;i++){
if(x[i]!=x[i+3])break;
    }
    if(i<3&&x[i]>x[i+3]){
for(i=0;i<3;i++){
    short xx=x[i];
    x[i]=x[i+3];
    x[i+3]=xx;
}
    }
    for(i=0;i<6;i++){
v|=((longlong)x[i])<<(9*i);
    }
    return v;
}

void set_stack_indexes(){
    int i;
    longlong v;
    for(i=0;i<stack_count;i++){
set_board(i);
v=board_number(board);
memcpy(&stack[i][10],&v,sizeof(longlong));
    }
}

void board_to_list(int lboard[3][9],short v[14]){
     int i,j;
     longlong w;
     for(i=0;i<10;i++){
 for(j=0;j<6;j++){
             if(row[sort[i][j]]!=lboard[0][j+3])
 break;
 }
 if(j==6)break;
     }
     v[0]=i;
     if(i>=10){
 fprintf(stderr,"Invalid board in board to list\n");
 exit(-1);
     }
     for(i=1;i<10;i++)v[i]=0;
     for(i=1;i<3;i++)for(j=3;j<9;j++){
 int u=(i-1)*6+(j-3);
 v[lboard[i][j]]|=1<<u;
     }
     w=board_number(lboard);
     memcpy(&v[10],&w,sizeof(longlong));
}

int find_board(int lboard[3][9]){
    short v[14];
    void *t;
    normalize(lboard);
    board_to_list(lboard,v);
    t=bsearch(v,stack,stack_count,sizeof(short)*14,cmp_stack);
    if(t==NULL){
fprintf(stderr,"Cannot find standard board\n");
exit(-1);
    }
    return ((char *)t-(char *)stack)/(sizeof(short)*14);
}

void I1(int t,int lboard[3][9]){
    int tboard[3][9];
    int i,j;
    for(i=0;i<3;i++)for(j=0;j<9;j++){
tboard[i][j]=lboard[order3[t][i]][j];
    }
    memcpy(lboard,tboard,sizeof(tboard));
}
void I2(int t,int lboard[3][9]){
    int tboard[3][9],i,j;
    for(i=0;i<3;i++)for(j=3;j<9;j++)tboard[i][j]=lboard[i][j];
    for(i=0;i<3;i++)for(j=0;j<3;j++)tboard[i][j]=lboard[i][order3[t][j]];
    memcpy(lboard,tboard,sizeof(tboard));
}
void I3(int t, int lboard[3][9]){
    int tboard[3][9],i,j;
    for(i=0;i<3;i++)for(j=0;j<3;j++)tboard[i][j]=lboard[i][j];
    for(i=0;i<3;i++)for(j=6;j<9;j++)tboard[i][j]=lboard[i][j];
    for(i=0;i<3;i++)for(j=3;j<6;j++)tboard[i][j]=lboard[i][order3[t][j-3]+3];
    memcpy(lboard,tboard,sizeof(tboard));
}
void I4(int t, int lboard[3][9]){
    int tboard[3][9],i,j;
    for(i=0;i<3;i++)for(j=0;j<6;j++)tboard[i][j]=lboard[i][j];
    for(i=0;i<3;i++)for(j=6;j<9;j++)tboard[i][j]=lboard[i][order3[t][j-6]+6];
    memcpy(lboard,tboard,sizeof(tboard));
}
void I5(int t,int lboard[3][9]){
    int tboard[3][9],i,j;
    for(i=0;i<3;i++)for(j=0;j<3;j++){
int u;
for(u=0;u<3;u++){
    tboard[i][j*3+u]=lboard[i][order3[t][j]*3+u];
}
    }
    memcpy(lboard,tboard,sizeof(tboard));
}

//Enumulate all possible transformation of a board only with first 3 columns
//Merging all boards which could transform to each other into same class
//The array class_weight[] tells how much board there're in each class
//I1, I2, I3, I4, I5 are 5 different transformations and each has 6 versions
void mark_transform()
{
    int lboard[3][9];
    int row[9]={0,1,2,3,4,5,6,7,8};
    int i1,i2,i3,i4,i5,i,j;
    int count=1;
    for(i1=0;i1<6;i1++)for(i2=0;i2<6;i2++)for(i3=0;i3<6;i3++)for(i4=0;i4<6;i4++)for(i5=0;i5<6;i5++){
int s;
int row2[9];
memcpy(lboard,board,sizeof(lboard));
I1(i1,lboard);
I2(i2,lboard);
I3(i3,lboard);
I4(i4,lboard);
I5(i5,lboard);
s=find_board(lboard);
if(class_id[s]==-1){
    count++;
    class_id[s]=class_count;
}else if(class_id[s]!=class_count){
    //Merging class class_id[s] into class_count
            fprintf(stderr,"Invalid class id merging,old %d, new %d\n",class_id[s], class_count);
    exit(-1);
}
    }
    class_weight[class_count]+=count;
}
int old_class(int x){
    int i;
    for(i=10;i<14;i++){
if(stack[x][i]!=stack[x-1][i])
    return 0;
    }
    return 1;
}

int main(){
    int i,max=0;
    generate_all_index();
    find(0);
    /*
    for(i=0;i<10;i++){
int j;
for(j=0;j<9;j++){
    printf("count[%d,%d]=%d\n",i,j,temps_count[i][j]);
}
if(max<temps_count[i][j])max=temps_count[i][j];
    }
    printf("max:%d\n",max);
*/
    for(i=0;i<10;i++){
        sum(8,0,i);
    }
    printf("Total %d found\n",stack_count);
    set_stack_indexes();
    qsort(stack,stack_count,sizeof(short)*14,cmp_stack);
    memset(class_id,-1,sizeof(class_id));
    for(i=0;i<stack_count;i++){
if(class_id[i]==-1){
    class_count = class_number;
    if((i>0&&old_class(i))){
class_count = class_id[i-1];
class_number--;
    }else{
class_elem[class_count]=i;
    }
    class_id[i]=class_count;
    set_board(i);
    mark_transform();
    class_number++;
}
    }
    class_count=class_number;
    for(i=1;i<stack_count;i++){
if(old_class(i)&&class_id[i]!=class_id[i-1]){
    int old_id=class_id[i];
    int j;
    fprintf(stderr,"Merging class %d and %d\n",class_id[i-1],class_id[i]);
    for(j=0;j<stack_count;j++){
if(class_id[j]==old_id){
    class_id[j]=class_id[i-1];
}
    }
    class_count--;
    class_elem[old_id]=-1;
    class_weight[class_id[i-1]]+=class_weight[old_id];
}
    }
    printf("Total %d[%d] classes\n",class_number,class_count);
    {
FILE *p=fopen("class.std","wb");
for(i=0;i<class_number;i++){
    if(class_elem[i]>=0){
fwrite(&class_weight[i],sizeof(int),1,p);
    }
}
for(i=0;i<class_number;i++){
    if(class_elem[i]>=0){
        fwrite(stack[class_elem[i]],sizeof(short),10,p);
    }
}
fclose(p);
    }
}

这个程序会产生一个class.std文件，要被第二个程序使用的。

而第二个程序，对于第一个程序中每个类，再根据第一列后6个数字的不同取值，分成10类，所以总共有1001类。

我们对每个类别中的数目进行穷举，最后将结果累加就可以了。

/*used for sudoku count*/
#include <stdio.h>

#ifdef WIN32
typedef  __int64 longlong;
#define LLD "%I64d"
#else
typedef long long longlong;
#define LLD "%lld"
#endif

#define L1 ((longlong)1)
#define CLASSES  101
#define MAX_INDEX 416
int class_weight[CLASSES];
short stack[CLASSES][10];
int board[9][9];
longlong count;

typedef longlong template;
#define TEMPLATE_COUNT 288

template temps[MAX_INDEX][TEMPLATE_COUNT];
int temps_count[MAX_INDEX];

signed char is_index[9][9];
signed char is_value[9][9];

int index_value[MAX_INDEX];
int index_pos[MAX_INDEX];
int index_count;
int sort[10][6]={
{0,1,2,3,4,5},
{0,1,3,2,4,5},
{0,1,4,2,3,5},
{0,1,5,2,3,4},
{0,2,3,1,4,5},
{0,2,4,1,3,5},
{0,2,5,1,3,4},
{0,3,4,1,2,5},
{0,3,5,1,2,4},
{0,4,5,1,2,3}
};
int row[6]={4,5,6,7,8,9};
int column[6]={2,3,5,6,8,9};
int sorder[9]={8,3,1,4,2,7,5,6,0};
int class[CLASSES*10][9];
void read_classes(){
    FILE *p=fopen("class.std","rb");
    if(p==NULL){
fprintf(stderr,"Cannot read in call input\n");
exit(-1);
    }
    fread(class_weight,sizeof(int),CLASSES,p);
    fread(stack,sizeof(short)*10,CLASSES,p);
    fclose(p);
}

void generate_all_index(){
   int i,j;
   int model[33];
   for(i=0;i<3;i++)for(j=0;j<3;j++){
      is_index[i][j]=i*3+j;
      is_value[i][j]=-1;
   }
   for(i=0;i<3;i++)for(j=3;j<9;j++){
      is_index[i][j]=9+i*6+j-3;
      is_value[i][j]=-1;
   }
   for(j=3;j<9;j++){
      is_index[j][0]=24+j;
      is_value[j][0]=-1;
   }
   for(i=3;i<9;i++)for(j=1;j<9;j++){
      is_index[i][j]=-1;
      is_value[i][j]=(i-3)*8+j-1;
   }
   for(i=0;i<9;i++)model[i]=i+1;
   for(i=0;i<CLASSES;i++){
     int s1=stack[i][0];
     int k,h;
     for(k=0;k<6;k++){
 model[k+9]=row[sort[s1][k]];
     }
     for(h=1;h<10;h++){
       int u;
       for(u=0;u<12;u++){
 if(stack[i][h]&(1<<u)){
           model[15+u]=h;
 }
       }
     }
     for(j=0;j<10;j++){
      int k,v[9];
      for(k=0;k<6;k++){
  model[k+27]=column[sort[j][k]];
      }
      for(k=0;k<9;k++)v[k]=0;
      for(k=9;k<33;k++){
  v[model[k]-1]|=1<<(k-9);
      }
      for(k=0;k<9;k++){
  int s;
  for(s=0;s<index_count;s++){
              if(index_value[s]==k+1&&index_pos[s]==v[k])break;
  }
  if(s==index_count){
              if(index_count>=MAX_INDEX){
  fprintf(stderr,"index out of range\n");
  exit(-1);
      }
              index_value[s]=k+1;
      index_pos[s]=v[k];
      index_count++;
  }
  class[i*10+j][k]=s;
      }
     }
   }
   printf("index_count = %d\n",index_count);
}

#define Row(x,y)     (x)
#define Column(x,y)  (y)
#define Board(x,y)   (((x)/3)*3+((y)/3))
#define Filled(x,y)  board[x][y]
char row_used[9];
char column_used[9];
char board_used[9];
int Can_fill(int x,int y){
    if(row_used[Row(x,y)])return 0;
    if(column_used[Column(x,y)])return 0;
    if(board_used[Board(x,y)])return 0;
    return 1;
}

void set(int x,int y){
    board[x][y]=1;
    row_used[Row(x,y)]=1;
    column_used[Column(x,y)]=1;
    board_used[Board(x,y)]=1;
}

void unset(int x,int y){
    board[x][y]=0;
    row_used[Row(x,y)]=0;
    column_used[Column(x,y)]=0;
    board_used[Board(x,y)]=0;
}
void sum2(int d){
    longlong used[9];
    int ii[9];
    int x=8;
    int i,s;
    longlong u;
    used[8]=0LL;
    ii[8]=0;
    while(x<=8){
i=ii[x];
u=used[x];
s=class[d][x];
for(;i<temps_count[s]&&(u&temps[s][i]);i++);
if(i<temps_count[s]){
    ii[x]=i+1;
    if(x>0){
used[x-1]=u|temps[s][i];
ii[x-1]=0;
x--;
    }else{
count++;
x++;
    }
}else{
    x++;
}
    }
}

void sum(int x, longlong used, int d){
    int i,s;
    longlong used2;
    if(x<0){
if(used!=0xFFFFFFFFFFFFLL){
    fprintf(stderr,"Invalid used %llx found\n",used);
    exit(-1);
}
count++;
return;
    }
    s=class[d][x];
    for(i=0;i<temps_count[s];i++){
if(used&temps[s][i])
    continue;
if(temps[s][i]==0){
    fprintf(stderr,"Invalid temps <%d,%d>=0 found\n",s,i);
    exit(-1);
}
used2=used|temps[s][i];
sum(x-1,used2,d);
    }
}
void find(int x){
    int i;
    if(x>=9){
int u=0;
longlong v=0;
int k=0;
int s,t;
for(s=0;s<9;s++)for(t=0;t<9;t++){
    if(board[s][t]){
if(is_index[s][t]>=0){
  if(is_index[s][t]<9){
    if(k!=0){
        fprintf(stderr,"Multiple k\n");
exit(-1);
    }
    k=is_index[s][t]+1;
  }
  else
    u|=1<<(is_index[s][t]-9);
}else if(is_value[s][t]>=0){
    v|=L1<<is_value[s][t];
}
    }
}
if(k==0){
    fprintf(stderr,"Cannot find k\n");
    exit(-1);
}
for(s=0;s<index_count;s++){
    if(u==index_pos[s]&&k==index_value[s]){
int m;
if(temps_count[s]>=TEMPLATE_COUNT){
       fprintf(stderr,"out of range for count[%d]\n",s);
       exit(-1);
}
temps[s][temps_count[s]]=v;
temps_count[s]++;
    }
}
return;
    }
    for(i=0;i<9;i++){
if(Can_fill(x,i)){
    set(x,i);
    find(x+1);
    unset(x,i);
}
    }
}
int main(){
    int i,max=0;
    longlong the_sum=0;
    read_classes();
    generate_all_index();
    printf("Total %d index\n",index_count);
    find(0);
    for(i=0;i<index_count;i++){
printf("count %d=%d\n",i,temps_count[i]);
    }
    for(i=0;i<CLASSES*10;i++){
sum2(i);
//        sum(8,0LL,i);
printf("Class %d, " LLD "*%d\n",i,count,class_weight[i/10]);
the_sum+=count*class_weight[i/10];
printf("Totol " LLD "\n",the_sum);
count=0;
fflush(stdout);
    }
    printf("Total " LLD "\n",the_sum);
}
