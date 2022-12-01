//yxvx.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include "Windows.h"
double x0, x1, x; double h, a, b,i;  double Y[80]; double itog,ans;
//Реализуем функции 
//double yx(double a, double b, double x, int* errorcode, int isEr);//Fx1 заменена на f1
double ux(double x);
//double vx(double x, int* errorcode, int isEr); //Fx2   заменена на f2
double f1(double a, double b, double x);     // was yx
double f2(double x);			//was vx
void stroit_graf(int key, double a, double b, double xmin, double xmax);
void clr_kbd(void)
{
	while (getchar() != '\n');
}
int main()
{
	setlocale(LC_ALL, "RUS");
	//double x0, x1; double h;
	//system("cp1251");
	//Реализуем меню
	int quit = 0;
	puts("\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
	puts("\t%    Курсовой проект выполнил:     %");
	puts("\t%   Студент: Фархадов Эрик Юрьевич %");
	puts("\t%         Факультет: ФИКТБ         %");
	puts("\t%         Группа: бИСТ-223         %");
	puts("\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
	system("pause");
	system("cls");
	while (!quit)  //1
	{
	vybor:
		puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
		puts("%\t    Выберите функцию для работы с ней:       %");
		puts("%\t1)Y(x) =  (1+sqrt(bx))/(0.5+sin^2(x)         %");
		puts("%\t                                             %");
		puts("%\t2)  V(x) arccos(0.5*|sin(u-3)|)+3x где       %");
		puts("%\t           (x^2-7x+3)/(x-e^x) x<=2           %");
		puts("%\t    u(x)=>                                   %");
		puts("%\t           arctg^2(x) x>2                    %");
		puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
		int cmd;
		scanf_s("%d", &cmd);
		system("cls");
		while (!quit)  //2
		{
			puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
			puts("%      Что вы хотите сделать с выбранной функцией?      %");
			puts("%1)Рассчитать значение функции при одиночном аргументе x%");
			puts("%2)Рассчитать множество значений функции на промежутке  %");
			puts("%3)Построить график выбранной функции на промежутке     %");
			puts("%4)Вернуться к выбору функции                           %");
			puts("%5)Выйти из программы                                                       %");
			puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
			int cmd2;
			scanf_s("%d", &cmd2);
			system("cls");
			switch (cmd2)
			{
			case 1:
			{
				puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
				puts("%Введите x для рассчета значения функции:%\n");
				puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
				//double x;
				scanf_s("%lE", &x);
				//int err = 1;
				//double itog = 0.0;
				if (cmd == 1)
				{
				snoc1:
					printf("%% Введите значение параметров а и b %%\n");
					//double a, b;
					scanf_s("%lE%lE", &a, &b);
					if (b < 0.0)
					{
						printf("\nb - не должно быть < 0 (sqrt(-))\n"); Sleep(2500); system("cls");  goto snoc1;
					}
					itog = /*yx(a, b, x, &err, 1);*/ f1(a, b, x);
				}
				else if (cmd == 2)
				//{
					itog = /*vx(x, &err, 1);*/ f2(x);
				//}
				puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
				printf("%%    Рассчитанное значение = %10.4lf    %%\n", itog);
				puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
				puts("%Введите промежуток и шаг для рассчета значений функции:%");
				puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
				//fseek(stdin, 0, SEEK_END);
				//char br1, br2;
				//double x0, x1;
				//char buf;
				//double h;
				scanf_s("%lE%lE%lE", &x0, &x1, &h);
				system("cls");
				//printf("\n%c\n%c\n%f\n%f\n%c\n", scob1, scob2, x0, x1, buf);
				if (cmd == 1)
				{snoc2:
					//double a, b;
					printf("Введите значение параметров a и b: \n");
					scanf_s("%lE%lE", &a, &b);
					if (b < 0.0)
					{
						printf("\nb - не должно быть < 0 (sqrt(-))\n"); Sleep(2500); system("cls"); goto snoc2;
					}
					puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
					puts("%          x            %              F(x)         %");
					/*if (true br1 == '(' && br2 == ')')  */
					//{
						for (i = x0; i <= x1; i += h)
							//{
								//int err = 1;
						{
							ans = /*yx(a, b, i, &err, 0);*/ f1(a, b, i);
							/*if (err == 1) */
							printf("%% %20.2f  %% %25.10f %%\n", i, ans);
						}
						/*else*/
						//printf("%% %20.2f  %% %25s %%\n", i, "   ----    ");
						//}
					
			    }  
				//if (br1 == '[' && br2 == ')')
				//{
				//	for (double i = x0; i <=x1; i += h)
				//	{

						//int err = 1;
				//		double ans = /*yx(a, b, i, &err, 0); */ f1(a, b, i);
			//if (err == 1)
			//	printf("%% %20.2f  %% %25.10f %%\n", i, ans);
			//else
			//	printf("%% %20.2f  %% %25s %%\n", i, "   ----    ");
			   //}
		//}  
			/* if (br1 == '[' && br2 == ']')  */
			//{
			//	for (double i = x0; i <= x1; i += h)
			//	{

					//int err = 1;
			//		double ans = /*yx(a, b, i, &err, 0); */ f1(a, b, i);
		//if (err == 1)
		//	printf("%% %20.2f  %% %25.10f %%\n", i, ans);
		//else
		//	printf("%% %20.2f  %% %25s %%\n", i, "   ----    ");
	      //}
         //} */
				//}
				if (cmd == 2)
				{
					puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
					puts("%          x            %              F(x)         %");
					/*if ( br1 == '(' && br2 == ')' true)   */
					//{
					for (i = x0; i <= x1; i += h)
					{

						//int err = 1;
						ans = /*vx(i, &err, 0); */ f2(i);
						//if (err == 1)
						printf("%% %20.2f  %% %25.10f %%\n", i, ans);
					}
					//else
					//printf("%% %20.2f  %% %25s %%\n", i, "   ----    ");

					//}
					/* if (br1 == '(' && br2 == ']')
					{
						for (double i = x0 ; i <= x1; i += h)
						{

							int err = 1;
							double ans = /*vx(i, &err, 0);  f2(x);  */
							//if (err == 1)
							//	printf("%% %20.2f  %% %25.10f %%\n", i, ans);
							//else
							//	printf("%% %20.2f  %% %25s %%\n", i, "   ----    ");
				    //}
					//}  */
					/*	if (br1 == '[' && br2 == ')')
						{
							for (double i = x0; i <= x1; i += h)
							{

								int err = 1;
								double ans = /*vx(i, &err, 0);  f2(x); */
					//if (err == 1)
					//	printf("%% %20.2f  %% %25.10f %%\n", i, ans);
					//else
					//	printf("%% %20.2f  %% %25s %%\n", i, "   ----    ");
					//	}
					//}  
					/*if (br1 == '[' && br2 == ']')
					{
						for (double i = x0; i <= x1; i += h)
						{

							int err = 1;
							double ans =  vx(i, &err, 0);  f2(x); */
					/*if (err == 1)
						printf("%% %20.2f  %% %25.10f %%\n", i, ans);
					else
						printf("%% %20.2f  %% %25s %%\n", i, "   ----    ");
						}
					}  */
				}
				puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
				system("pause");
				system("cls");
				break;
			}
			case 3:
			{
				puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
				puts("%Введите промежуток для построения графика функции%");
				puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
				//fseek(stdin, 0, SEEK_END);
				//char br1;
				//char br2;
				//char buf;
				//double x0;
				//double x1;
				//float xx0,xx1;
				//int rez;
				//scanf_s("%c%f%c%f%c", &br1, &x0, &buf, &x1, &br2);  !!!!
				//clr_kbd();
				//scanf("%*s");
				scanf_s("%lE%lE", &x0, &x1);
				//clr_kbd();
				//rez=scanf("%lg",&x1);
				system("cls");
				if (cmd == 1)
				{
				snoc3:
					//double a, b;
					printf("Введите a и b: ");
					clr_kbd();
					scanf_s("%lE %lE", &a, &b);
					if (b < 0.0)
					{
						printf("\nb - не должно быть < 0 (sqrt(-))\n"); Sleep(2500); system("cls"); goto snoc3;
					}
					stroit_graf(1, a, b, x0, x1);
					//getchar();
					/*
					for (int y = 30; y > -31; y--)
					{
						for (int x = x0; x <= x1; x++)
						{
							if (x == 0)
							{
								printf("|");
							}
							else if (y == 0)
							{
								printf("-");
							}
							else
							{
								int error = 1;
								int ans = yx(a, b, x, &error, 0); f1(a, b, x);
								if (error == 1 && ans == y)
									printf("*");
								else
								{
									printf(" ");
								}
				}

			}
			printf("\n");
					}  */
				}
				if (cmd == 2)
				{
					//double a, b;
					a = 1.0; b = 1.0;    // фиктивно
					stroit_graf(2, a, b, x0, x1);
					//getchar();
				/* {
					for (int y = 30; y > -31; y--)
					{
						for (int x = x0; x <= x1; x++)
						{
							if (x == 0)
							{
								printf("|");
							}
							else if (y == 0)
							{
								printf("-");
							}
							else
							{
								int e = 1;
								int ans =  vx(x, &e, 0);  f2(x);
								if (e == 1 && ans == y)
									printf("*");
								else
								{
									printf(" ");
								}
				}
						}
						printf("\n");
					}  */
				}
				system("pause");
				system("cls");
				cmd2 = 0;
				clr_kbd();
				break;
			  }

			case 4:   //if (cmd2 == 4)
			{   goto vybor;
			break;
			//continue;
			}
			case 5:
			{/*exit(0);*/ quit = 1;
			break; }
		  }  // end switch
		}  //end while (!quit)(2)
	} // end while(!quit) (1)
	return 0;
}
/* double yx(double a, double b, double x, int* errorcode, int isEr)
{
	if (b * x < 0.0)
	{
		*errorcode = -1;
		if (isEr)
			printf("Соблюдайте ОДЗ функции. Ошибка попитка взят квадратный корень с отрецательного числа\n");
		return 0.0;
	}
	if (fabs(0.5 + sin(a * x) * sin(a * x)) == 0.0)//0
	{
		*errorcode = -2;
		if (isEr)
			printf("Соблюдайте ОДЗ функции. Ошибка деление на ноль\n");
		return .0;
	}
	*errorcode = 1;//Все хорошо
	return ((1.0 + sqrt(b * x)) / (0.5 + sin(a * x) * sin(a * x)));
}
*/
double ux(double x)
{
	if (x <= 2)
		return (x * x - 7 * x + 3) / (x - exp(x));  //знаменатель никогда не = 0 !
	else
		return atan(x) * atan(x);
}
/*
double vx(double x, int* errorcode, int isEr)
{
	double rez=0,rr=0;
	if (fabs(x) <= 1.0)     //-1...1
{
	*errorcode = 1;
	//rr = 0.5 * fabs(ux(x) - 3.0);      
	rr = 0.5 * fabs(sin(ux(x) - 3.0));
	 rez = acos(rr) + 3 * x;
} */
/* if (isEr)
{
	printf("ОДЗ арккосинус [-1;1]\n");
	*errorcode = 0;
	return 0.0;
}  
return rez;
}  */
double f1(double a, double b, double x)
{
	return ((1.0 + sqrt(b * x)) / (0.5 + sin(a * x) * sin(a * x)));
}
double f2(double x)
{
	return acos(0.5 * fabs(sin(ux(x) - 3.0))) + 3 * x;
}
// =============
void stroit_graf(int key, double a, double b, double xmin, double xmax)
{ //double a = 1.0, b = 1.0;
	char Scr[80][25];
	//double Y[80];
	double x, ymax, ymin, dx, dy;
	int j, ix, iy;
	//double xmax = 10.0, xmin = -10.0;
	// определяем, график какой функции выводить
	dx = (xmax - xmin) / 80.0;
	if (key == 1)
		// Ищем максимум и минимум функции
		ymax = ymin = f1(a, b, xmin);
	if (key == 2)
		ymax = ymin = f2(xmin);
	j = 0;
	for (x = xmin; x < xmax; x += dx)
	{
		if (key == 1)
			Y[j] = f1(a, b, x);
		if (key == 2)
			Y[j] = f2(x);
		if (Y[j] > ymax) ymax = Y[j];
		if (Y[j] < ymin) ymin = Y[j];
		j++;
	}
	dy = (ymax - ymin) * 0.2;
	ymax = ymax + dy;
	ymin = ymin - dy;
	// Заполняем массив Scr
	for (ix = 0; ix < 80; ix++)
		for (iy = 0; iy < 25; iy++) Scr[ix][iy] = ' ';

	for (ix = 0; ix < 80; ix++)
	{
		iy = (int)((ymax - Y[ix]) * 25.0 / (ymax - ymin));
		if (iy >= 25) iy = 24;
		Scr[ix][iy] = '*';
	}
	// Выводим Scr
	for (iy = 0; iy < 25; iy++)
	{
		for (ix = 0; ix < 80; ix++) printf("%c", Scr[ix][iy]);
		//printf("\n");
	}
	//printf("\n");
}
//==============
