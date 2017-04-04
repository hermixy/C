/* 调试代码 */
#define DEBUG 1
#ifdef DEBUG
#define debug(a, b) printf(#a"\n",b)
#else
#define debug(a,b) ;
#endif
#include "common.h"

// 全局变量定义
int b1 = 14;
float PI = 3.14;
Test var = {{0x12345678,0x98765432},0x30};

int main(int argv,char* argc[]){
	switch(*argc[1]){
		case 'a':/*{{{*/
			{
				int *p;
				int (*pa)[3];
				int ar1[2][3];
				int ar2[3][2];
				int *pp;
			}
			break;/*}}}*/

		// 指向多维数组的指针
		case 'b':/*{{{*/
			{
				int zippo[3][2] =
				{
					{2,3},
					{4,5},
					{6,7}
				};
				int (*pz)[2]; // 指向一个含有两个int类型值的数组
				pz = zippo;
				printf("zippo : %p , zippo[0]: %p :zippo[0][0] : %d \n",zippo,zippo[0],zippo[0][0]);
				printf("pz : %p , *pz: %p : **pz: %d \n",pz,*pz,**pz);
				printf("pz = %p,pz + 1:%p \n",pz,pz+1);
				printf("pz[0] = %p,pz[0] + 1:%p \n",pz[0],pz[0]+1);
				printf("*pz = %p,*pz + 1:%p \n",*pz,*pz+1);
				printf("**pz = %d,*(*pz + 1):%d \n",**pz,*(*pz+1));
				printf("**(pz + 1) = %d,*(*(pz + 1) + 1):%d \n",**(pz + 1),*(*(pz + 1)+1));
				printf("pz[0][0] = %d,pz[0][1]:%d \n",pz[0][0],pz[0][1]);
				printf("-----------------\n\n");
			}
			break;/*}}}*/

		// 测试EOF
		case 'c':/*{{{*/
			{
				char test_eof;
				while( (test_eof = getchar()) != EOF){
					putchar(test_eof);
				}
			}
			break;/*}}}*/

		// 测试fgets()
		case 'd':/*{{{*/
			{
				char words[STLEN];
				int i;
				while(fgets(words,STLEN,stdin) != NULL && words[0] != '\n'){
					i = 0;
					while(words[i] != '\n' && words[i] != '\0'){
						i++;
					}
					if(words[i] == '\n'){
						words[i] = '\0';
					}else{
						while(getchar() != '\n'){
							continue;
						}
					}
					fputs(words,stdout);
				}
			}
			break;/*}}}*/

		// 测试下字符串数组
		case 'e':/*{{{*/
			{
				const char *pointer_str[5] = {
					"string1 heheh",
					"string2 ,sdfadf",
					"string3 hdhdhdh",
					"xxixixixi",
					"codsdadfssss"
				};
				char array_str[5][40] = {
					"sdfaiisisis",
					"xixixiix sss",
					"hahah",
					"codekissyoung"
				};
				for(int k = 0;k < 5;k++){
					printf("pointer_str[%d] : %p : %s \n",k,pointer_str[k],pointer_str[k]);
				}
				for(int p = 0;p < 5;p++){
					printf("array_str[%d] : %p : %s \n",p,array_str[p],array_str[p]);
				}
			}
			break;/*}}}*/

		// 数组字符串和指针字符串的区别
		case 'f':/*{{{*/
			{
				char ar[] = MSG;
				char *pt = MSG;
				printf("MSG : %p \n",MSG); // 字面量存储的位置
				printf("ar : %p \n",ar); // 数组存储的位置
				printf("pt : %p \n",pt); // 指针指向的位置
				printf("-----------------\n\n");
			}
			break;/*}}}*/

		// 打印其输入的参数
		case 'g':/*{{{*/
			for(int i = 0;i < argv;i++){
				printf("argc[%d] is %s \n",i,argc[i]);// 依次打印输入的参数
			}
			break;/*}}}*/

		// 处理多维数组的函数
		case 'h':/*{{{*/
			{
				int zippo[3][2] =
				{
					{2,3},
					{4,5},
					{6,7}
				};
				sum_rows(zippo,3);
			}
			break;/*}}}*/

		// 变长数组的使用
		case 'i':/*{{{*/
			{
				int zippo[3][2] =
				{
					{2,3},
					{4,5},
					{6,7}
				};
				int total1 = sum2d(3,2,zippo);
				printf("total1 : %d \n", total1);
			}
			break;/*}}}*/

		// 复合字面量
		case 'j':/*{{{*/
			{
				int total1 = sum2d( 2 , 2 , (int [2][2]){{2,3},{4,5}});
				printf("total2: %d \n",total1);
			}
			break;/*}}}*/

		// 使用预定义宏
		case 'k':/*{{{*/
			printf("File :%s\n", __FILE__ );
			printf("Date :%s\n", __DATE__ );
			printf("Time :%s\n", __TIME__ );
			printf("Line :%d\n", __LINE__ );
			printf("ANSI :%d\n", __STDC__ );
			printf("AUTHOR: %s \n---------------\n\n","codekissyoung");
			break;/*}}}*/

		// 进程相关
		case 'l':/*{{{*/
			printf("当前进程ID : %u\n",getpid());
			printf("当前进程父ID : %u\n",getppid());
			printf("当前用户ID : %u\n",getuid());
			printf("当前有效用户ID : %u\n",geteuid());
			printf("当前组ID : %u\n",getgid());
			printf("当前有效组ID : %u\n",getegid());
			printf("-----------------\n\n");
			break;/*}}}*/

		// 环境变量测试
		case 'm':/*{{{*/
			printf("环境变量测试: \n");
			printf("%s \n",environ[0]);
			printf("%s \n",environ[1]);
			printf("HOME : %s \n",getenv("HOME")); // 获取环境变量HOME
			printf("-----------------\n\n");
			break;/*}}}*/

		// 测试输入
		case 'n':/*{{{*/
			{
				printf("输入字符测试,重复输入的字符，如果读取到q字符，就跳出输入输出\n");
				char ch;
				char left_str[10];
				do{
					ch = getchar();
					if(ch == 'q') break;
					putchar(ch);
				}while (ch != 'q');
				if(scanf("%s",left_str)){
					printf("缓冲区读取到的q后面的字符串:%s \n",left_str);
				}
			}
			break;/*}}}*/

		// 测试读取文件
		case 'o':/*{{{*/
			{
				char ch;
				FILE* fp = fopen("test.txt","r");
				if(fp){
					while((ch = getc(fp)) != EOF){ // 读取文件内容显示
						putchar(ch);
					}
					fclose(fp); // 关闭文件
				}else{
					printf("打开文件失败\n");
					exit(1);
				}
			}
			break;/*}}}*/

		// 打印一个菱形
		case 'p':/*{{{*/
			print_diamond(11);
			break;/*}}}*/

		// 打印99乘法表
		case 'q':/*{{{*/
			plus(9);
			break;/*}}}*/

		// 不定参数
		case 'r':/*{{{*/
			print_args(-1,"hello","world",NULL);
			print_args(-1,"Olympic","china","Beijing",NULL);
			break;/*}}}*/

		default:/*{{{*/
			printf("运行　./cky n (n 为任意数字)\n");
			break;/*}}}*/

	} // end of switch
	return 0;
}
