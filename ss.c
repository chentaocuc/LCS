#include "stdio.h"
#include "string.h"
char s1[10];
char s2[10];
int ss[10][10]={0};
char out[10]={0};
char out2[10][10];
int i=0,j=0,k=0,m=0,n=0;
int z=0;
int maxlen=0, maxrow = 0;

void aa(){
	int I, J;
	I = strlen(s1);
	J = strlen(s2);
	printf("I = %d, J = %d\n", I,J);
	z = 0;
	m = 0;
	for(i=0;i<I;i++){
		for(j=0;j<J;j++){
			if(s1[i]==s2[j]){
				if(i==0 || j==0)
					ss[i][j] = 1;
				else
					ss[i][j] = ss[i-1][j-1] + 1;
				if(ss[i][j] > z){
					z = ss[i][j];
					k = 0;
					for(n=i-z+1;n<=i;n++){
						out[k++]=s1[n];
//						printf("%c",out[n]);
					}
					if(maxlen<k){
						maxlen = k;
						maxrow = m;
					}
					for(n=0;n<k;n++)
						out2[m][n] = out[n];
					m++;
				}
				else
					if(ss[i][j] == z)
//						continue;
//						strcat(out2, out);
			}
			else
				ss[i][j] = 0;
			}
		}
		
//		for(i=0;i<I;i++){
//			for(j=0;j<J;j++){
//				printf("%d  ",ss[i][j]);
//			}
//				printf("\n");
//		}
		
		printf("maxlen = %d, maxrow = %d\n", maxlen, maxrow);
		for(i=0;i<maxlen;i++){
			printf("%c",out2[maxrow][i]);
		}
	
}

void main(){
	scanf("%s",s1);
	printf("s1 = %s\n", s1);
	scanf("%s",s2);
	printf("s2 = %s\n", s2);
	aa();
}	
