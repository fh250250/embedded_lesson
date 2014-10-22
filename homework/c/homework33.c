/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 
   找出一个二维数组的鞍点
    例如：
	    19 23 21 13
		61 25 34 45
		67 32 39 29
		39 98 27 56
	(行上最大，列上最小)
	如果没有，打印 I can't find it


 */

#include "apue.h"

int main(int argc, char* argv[]){

	int arr[4][4] = {
		{19, 23, 21, 13},
		{61, 25, 34, 45},
		{67, 32, 39, 29},
		{39, 98, 27, 56}
	};

	int row, col, tmp_index;
	int max, min;
	int count = 0;

	for(row = 0; row < 4; row++){

		max = arr[row][0];		// 行上最大
		for(tmp_index = 0; tmp_index < 4; tmp_index++){
			if(arr[row][tmp_index] > max){
				max = arr[row][tmp_index];
			}
		}

		for(col = 0; col < 4; col++){
			
			min = arr[0][col];	// 列上最小
			for(tmp_index = 0; tmp_index < 4; tmp_index++){
				if(arr[tmp_index][col] < min){
					min = arr[tmp_index][col];
				}
			}

			if(arr[row][col] == max && arr[row][col] == min){
				printf("鞍点[%d][%d]\n", row, col);
				count++;
			}
		}
	}

	if(count == 0){
		printf("I can't find it\n");
	}

	return 0;
}
