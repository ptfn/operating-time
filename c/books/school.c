#include <math.h>
#include <stdio.h>
#include <locale.h>

/* Ввод оценок */
void inputData (int s[][3])
{
    printf("Введите оценки первого студента через пробел\n");
    scanf("%d%d%d", &s[0][0], &s[0][1], &s[0][2]);
    printf("Введите оценки второго студента через пробел\n");
    scanf("%d%d%d", &s[1][0], &s[1][1], &s[1][2]);
    printf("Введите оценки третьего студента через пробел\n");
    scanf("%d%d%d", &s[2][0], &s[2][1], &s[2][2]);
}

/* Подсчёт степендии */
void calcuateScholarship(float S[], int s[][3])
{ 
    for (int i = 0; i <= 2; i++) {
        float sum = s[i][0] + s[i][1] + s[i][2];

        if ((s[i][0] == 5) && (s[i][1] == 5) && (s[i][2] == 5))
            S[i] = sum * 250 + ((sum*250)/100*50);
        
        else if ((s[i][0] >= 4) && (s[i][1] >= 4) && (s[i][2] >= 4))
            S[i] = sum * 250 + ((sum*250)/100*25);
        
        else if ((s[i][0] >= 3) && (s[i][1] >= 3) && (s[i][2] >= 3))
            S[i] = sum * 250;
        
        else
            S[i] = 0;


    }
}

/* Подсчёт Количество успеваемости */
void calculateQuantitivePerformance(float P[], int s[][3])
{
    for (int i = 0; i <= 2; i++) {
        float sum = 0;

        for (int j = 0; j <= 2; j++) {
            if (s[j][i] >= 3)
                sum += 1;
            else
                sum += 0;
        }
        if (sum != 0)
            P[i] = (sum / 3) * 100;
        else
            P[i] = 0.0;
    }
}

/* Подсчёт Качаства успеваемости */
void calculateQualitativePerformance1(float Q[], int s[][3])
{
    for (int i = 0; i <= 2; i++) {
        float sum = 0;

        for (int j = 0; j <= 2; j++) {
            if (s[i][j] == 5)
                sum += 1;
            else if (s[i][j] == 4)
                sum += 0.5;
            else
                sum += 0;
        }
        if (sum != 0)
            Q[i] = (ceil(sum) / 3) * 100;
        else
            Q[i] = 0.0;
    }
}

/* Вывод таблицы */
void printTable(int s[][3], float S[], float P[], float Q[])
{
    printf("№ Студента\tАлгебра   Мат. ан.   ЯМП\tСтипендия, руб\n");

    for (int i = 0; i <= 2; i ++)
        printf("%d %18d %9d %8d %18.2f\n", i+1, s[i][0], s[i][1], s[i][2], S[i]);

    printf("Кол. усп., %%: %9.2f %9.2f %8.2f\n", P[0], P[1], P[2]);
    printf("Кач. усп., %%: %9.2f %9.2f %8.2f\n", Q[0], Q[1], Q[2]);
}

int main()
{ 
    int s[3][3];
    float S[3], P[3], Q[3];

    inputData(s);
    calcuateScholarship(S, s);
    calculateQuantitivePerformance(P, s);
    calculateQualitativePerformance1(Q, s);
    printTable(s, S, P, Q);
}