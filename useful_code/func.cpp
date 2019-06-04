void view_mem(long long& val)
{
    printf("val:%lld,address:%p,memory:",val,&val);
    unsigned char *p = (unsigned char*)&val;
    for(int i=0;i<sizeof(long long);++i)
    {
        printf("%02X",*(p+i));
    }
    printf("\n");
}