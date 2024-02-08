#include <stdio.h>

int main(void)
{
    float notes[4][4] = {0};
    float averageNotes[4];
    float average;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Enter grades for student %i: ", i + 1);
            scanf("%f", &notes[i][j]);
            average = average + notes[i][j];
        }
        averageNotes[i] = average / 4;
        average = 0;
        printf("\n");
    }

    for (int i = 0; i < 4; i++)
    {
        printf("The average of student %i is %.1f", i + 1, averageNotes[i]);
        printf("\n");
    }
    return 0;
}