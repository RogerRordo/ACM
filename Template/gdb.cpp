//g++ -g a.cpp -o a;gdb --args a 1
int main(int gdb)
{
	if (gdb>1)
	{
		freopen("in","r",stdin);
		freopen("out","w",stdout);
	}
	
	//...
	
	return 0;
}
