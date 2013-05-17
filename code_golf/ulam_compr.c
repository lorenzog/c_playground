main(int a,char**v){
	int l=atoi(v[1]),o=2*l-1,z=o*o,n=2*l*(l-1),c=1,i,s=1,d;
	char*m=malloc(z);
	m[n]=1;
	for(;;s++)do{
			for(i=0;i<s;i++){
				if(d==0)n++;
				else if(d==1)n-=o;
				else if(d==2)n--;
				else n+=o;
				int j=++c;
				while(c%--j);
				if(j>1)m[n]=' ';else m[n]='*';
				if(c>=z)goto g;
			}d=++d%4;}while(d%2);
g:for(i=0;i<z;i++){
		putchar(m[i]);
		if(!((i+1)%o))putchar('\n');
	}
}
