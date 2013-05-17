int main(int a,char**b){
int u,v,x,y,S=*b[1]-47;
for(v=S;--v>-S;)
for(u=-S;++u<S||!putchar(10);){
v<=-u^v<u?(x=v,y=u):(x=u,y=v);
x=4*y*y-x-y+1+2*(v<u)*(x-y);
for(y=2;++y<x&&x%y;);
putchar(y^x?32:42);}}
