#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int a[10000][7], max, t, row;
	int(*p)[7] = a;
	
		puts("lotto 번호 생성기\t\t\t [제작자 : 김태영]\n", stdout);
		printf("lotto를 몇 장 구매하시겠습니까? : ");
		scanf("%d", &row); row *= 5;
		
		if (row * 1000 >= 1000000) {
			int x = row * 1000 / 1000000;
			int y = (row * 1000 - x * 1000000) / 1000;
			printf("가격은 %d,%d,000원 입니다.\n", x, y);
		}
		else
			printf("가격은 %d\b\b\b,000원 입니다.\n", row * 1000);

		srand(time(NULL));
		for(int i=0; i<row; i++) {
			for (int j = 0; j < 7; j++) {
				p[i][j] = (rand() % 45)+1;		
			}
		}
	
		for (register int i = 0; i < 100; i++) {
			for (register int k = 0; k < row; k++) {
				for (register int j = 0; j < 6; j++) {
					max = p[k][j];
					if (max == p[k][j + 1])
						p[k][j+1] = (rand() % 45) + 1;
		
					else if (max > p[k][j + 1])
					{
						t = p[k][j + 1];
						p[k][j + 1] = max;
						p[k][j] = t;
					}
				}
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < 7; j++) {
			
				if (j == 6)
					printf("+\t%2d", p[i][j]);
				else
					printf("%2d \t", p[i][j]);
			}
			puts("");
			if ((i%5 == 4)&&(i>1))
				puts("");
		}
	system("pause");
	return 0;
}