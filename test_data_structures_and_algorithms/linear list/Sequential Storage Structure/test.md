**线性表类型的定义模版**
```
typedef struct 
    {
        ElemType elem*; --后续可以用malloc和realloc进行动态分配
        int length;
    }Sqlist;

```
**动态内存分配**
```
Sqlist* L;
L.elem=(Sqlist*)malloc(sizeof(ElemType)*MaxSize);

```

**预定义**
```
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef char EleType;

```