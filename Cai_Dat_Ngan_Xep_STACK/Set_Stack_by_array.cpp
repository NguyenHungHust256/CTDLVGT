// cai dat ngan xep (Stack)
// Cai dat tren mang
#define MAX 100
typedef int item;
typedef struct STACK
{
	int Top;
	item Data[MAX];
}Stack;

// Khoi tao danh sach rong , kiem tra danh sach rong day
void Init(Stack S)
{
	S.Top=0;
}

int Isempty(Stack S)
{
	return (S.Top==0);
}

int Isfull(Stack S)
{
	return (S.Top==MAX);
}

//Them phan tu vao Stack (PUSH)
void Push(Stack S, item x)
{
	if(!Isfull(S))
	{
		S.Data[S.Top]=x;
		S.Top++;
	}
}

// Lay du lieu tai Top nhung khong xoa (Peak)
int Peak(Stack S)
{
	return S.Data[S.Top-1];  // Lay du lieu tai Top
}

// Xoa va Lay du lieu tai Top(POP)
int Pop(Stack S)
{
	if(!Isempty(S))
	{
		S.Top --;
		return S.Data[S.Top];
	}
}
int main(){
	
}
