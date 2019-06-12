#include <cstdlib>
#include <cstdio>
// https://bbs.csdn.net/topics/390844782
// https://zh.cppreference.com/w/c/memory/aligned_alloc
// 
void test_std_malloc();
void test_aligned_malloc();
int main()
{
    test_std_malloc();
    test_aligned_malloc();
}

void test_pointer_ref()
{
    int val = 12;
    int &n = val;
    printf("%p,%p\n",&val,&n);

    char *ptr = new char[10];
    char *ptr1 = ptr;
    char *&ptr2=ptr;
    printf("%p,%p,%p\n",ptr,ptr1,ptr2);
    printf("%p,%p,%p\n",&ptr,&ptr1,&ptr2);
}

void test_std_malloc()
{
    printf("Test Stand Malloc/Free\n");
    void * p[10];
    for(int i=0;i<10;++i)
    {
        p[i]=malloc(100);
        printf("Adderess is %p\n",p[i]);
    }
    for(int i=0;i<10;++i)
    {
        free(p[i]);
    }
    printf("Test Over\n");
}

// align to 64
void* aligned_alloc(size_t sz)
{
    // sizeof(void* ) store real start address
    void * ptr = malloc(  (sz?sz:1) + 63 + sizeof(void*) );
    if(ptr==NULL)
    {
        return NULL;
    }
    ptr = (char*)ptr + sizeof(void*);
    void** real_ptr = (void**) ( (char*)ptr + 64- ((size_t)(char*)ptr & 63U)  );
    real_ptr[-1] = (char*)ptr -sizeof(void*);
    return real_ptr;
}
void aligned_free(void *p)
{
    if(p)
    {
        free( ((void**)p) [-1]);
    }
}


void test_aligned_malloc()
{
    printf("Test Aligned Malloc/Free\n");
    void * p[10];
    for(int i=0;i<10;++i)
    {
        p[i]=aligned_alloc(100);
        printf("Adderess is %p\n",p[i]);
    }
    for(int i=0;i<10;++i)
    {
        aligned_free(p[i]);
    }
    printf("Test Over\n");
}