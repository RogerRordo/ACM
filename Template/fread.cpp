char buf[buff];
char *bs=0,*bt=0;
void iobegin()
{
	int l=fread(buf,1,buff,stdin);
	bs=buf; bt=bs+l;
}
char get()	//替换getchar
{
    if (bs==bt) iobegin();
    return *(bs++);
}
