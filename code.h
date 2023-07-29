#define STACKSIZE 65536
#define CODESIZE 65536

void interpret();

struct instruction{
	int f,l,a;
	double d;
	instruction(){}
	instruction(int ff,int ll,int aa):f(ff),l(ll),a(aa),d(0){}
	instruction(int ff,int ll,int aa,int dd):f(ff),l(ll),a(aa),d(double(dd)){}
	instruction(int ff,int ll,double dd):f(ff),l(ll),a(0),d(dd){}
};

#define LIT 1
#define OPR 2
#define LOD 3
#define STO 4
#define CAL 5
#define INI 6
#define JMP 7
#define JPC 8

#define LODD 9
#define STOD 10

#define LODP 13
#define LODPD 14
#define STOP 15
#define STOFP 16
#define STOFPD 17

#define SAVE 11
#define LOAD 12
