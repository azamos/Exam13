
#include "exam.h"

int count1=0; // do not change!

void fx1(){
    count1++;
}

int main()
{
    //1
   
    int mat[5][COLS] = { {0,0,3,0} ,{2,0,2,1},{0,0,2,3},{1,4,8,11},{0,-2,9,7} };
    int cnt = getNumFlowers(mat, 5);

    if (cnt != 1)
        printf("getNumFlowers function is wrong for train1_1 (-8)\n");


    int mat2[6][COLS] = { {5,6,7,8},{3,1,2,4},{1,0,-5,6,},{4,2,7,6},{3,3,3,3},{1,0,-3,-5} };
    cnt = getNumFlowers(mat2, 6);

    if (cnt != 2)
        printf("getNumFlowers function is wrong for train1_2 (-8)\n");

    int mat3[4][COLS] = { {5,6,0,8},{3,1,2,4},{1,0,-5,6,},{-4,2,-1,6} };
    cnt = getNumFlowers(mat3, 4);

    if (cnt != 2)
        printf("getNumFlowers function is wrong for train1_3 (-9)\n");

       
	// 2
    ////test1
    //unsigned int res = tobin(6);

    //if (count1 < 2)
    //    printf("tobin function is not recursive (-8)\n");
    //else {
    //    if (res != 110)
    //        printf("tobin function is wrong for train2_1  (-8)\n");
    //}
    ////test2
    //res = tobin(9);

    //if (count1 < 2)
    //    printf("tobin function is not recursive (-8)\n");
    //else {
    //    if (res != 1001)
    //        printf("tobin function is wrong for train2_2  (-8)\n");
    //}
    ////test3
    //res = tobin(15);

    //if (count1 < 2)
    //    printf("tobin function is not recursive (-9)\n");
    //else {
    //    if (res != 1111)
    //        printf("tobin function is wrong for train2_3  (-9)\n");
    //}



	//3
	printf("Question 3 will be checked manually, don't worry (-50)\n");
	printf("done");
    return 0;
}
