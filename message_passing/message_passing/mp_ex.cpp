#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main() {

	int node = 4;

	int line[4][4] = {
	{ 0,1,1,1 },
	{ 1,0,0,0 },
	{ 1,0,0,0 },
	{ 1,0,0,0 }
	};
	// 그래프의 연결 상태를 나타내는 배열 (1은 연결)

	int weight[4] = { 4,2,2,3 };
	// {A, B, C, D} 각각의 weight 값
	// A=4, B=2, C=2, D=3

	int m0[4][4] = { 0, };
	int m_x[4][4] = { 0, };
	int m_y[4][4] = { 0, };

	int i, j;

	for (int x = 1; x < node; x++) {
		printf("m_%d matrix :: \n",x);
		for (i = 0; i < node; i++) {
			for (j = 0; j < node; j++) {
				if (j >= i) {
					if (line[i][j] == 1) {
						if (j%node == 3) {
							m_x[i][j] = MAX(0, weight[i] - (m_y[(j + 2) % node][i] + m_y[(j + 3) % node][i]));
							
						}
						if (j%node == 2) {
							m_x[i][j] = MAX(0, weight[i] - (m_y[(j+1)%node][i] + m_y[(j+3)%node][i]));

						}
						if (j%node ==1) {
							m_x[i][j] = MAX(0, weight[i] - (m_y[(j + 1) % (node)][i] + m_y[(j + 2) % (node)][i]));
						}

						printf("%d", m_x[i][j]);

					}
					else {
						m_x[i][j] = m_y[i][j];
						printf("%d", m_x[i][j]);
					}
				}
				else {
					if (line[i][j] == 1)
					{
						m_x[i][j] = weight[i];
						printf("%d", m_x[i][j]);
					}
					else {
						m_x[i][j] = 0;
						printf("%d", m_x[i][j]);
					}
				}
			}
			printf("\n");

		}
		for (i = 0; i < node; i++) {
			for (j = 0; j < node; j++) {
				m_y[i][j] = m_x[i][j];
			}
		}	
/*
		printf("m_y matrix :: \n");

		for (int a = 0; a < node; a++) {
			for (int b = 0; b < node; b++)
			{
				printf("%d", m_y[a][b]);
			}
			printf("\n");
		}
		*/
	}

	printf("\n>>> Estimate Phase >>> \n");

	int temp[4] = { 0, };
	int estimate[4] = { 0, };

	for (int j = 0; j < node; j++) {
		for (int i = 0; i < node; i++) {
			temp[j] = temp[j] + m_x[i][j];
		}
	}
	/*
	for (int t = 0; t < node; t++) {
		printf("%d", temp[t]);
	}
	*/

	for (int k = 0; k < node; k++) {
		if (temp[k] > weight[k])
			printf("%c : unscheduled \n", 65 + k);
		else
			printf("%c : scheduled \n", 65 + k);
	}

	return 0;
}