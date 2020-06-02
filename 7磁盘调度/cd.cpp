#include "iostream.h"
#include "stdio.h"
#include "stdlib.h"
#define maxsize 100
//�����ȷ�������㷨
void FCFS(int array[], int m)
{
    int sum = 0, j, i;
    for (i = 0; i < m; i++) {
        cout << array[i] << " ";
    }
    for (i = 0, j = 1; j < m; i++, j++) {
        sum += abs(array[j] - array[i]);
    }
    cout << "�ƶ����ܵ����� " << sum << endl;
}
//���Ѱ��ʱ�����ȵ����㷨
void ShortPath(int array[], int m)
{
    int temp;
    int k = 1;
    int now, l, r;
    int i, j, sum = 0;
    for (i = 0; i < m; i++)
        for (j = i + 1; j < m; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    for (i = 0; i < m; i++) {
        cout << array[i] << " ";
    } /*����*/
    cout << "�����뵱ǰ�Ĵŵ��ţ�";
    cin >> now;
    if (array[m - 1] <= now) {
        for (i = m - 1; i >= 0; i--)
            cout << array[i] << " ";
        sum = now - array[0];
    } else if (array[0] >= now) {
        for (i = 0; i < m; i++)
            cout << array[i] << " ";
        sum = array[m - 1] - now;
    } else {
        while (array[k] < now) {
            k++;
        }
        l = k - 1;
        r = k;
        /*ȷ����ǰ�ŵ������ŵ������е�λ�ã�������㷨���õ��ˣ�����ֱ�Ӹ��Ӻ������޸ģ���ʡʱ�䡣*/
        while ((l >= 0) && (r < m)) {
            if ((now - array[l]) <= (array[r] - now)) {
                cout << array[l] << " ";
                sum += now - array[l];
                now = array[l];
                l = l - 1;
            } else {
                cout << array[r] << " ";
                sum += array[r] - now;
                now = array[r];
                r = r + 1;
            }
        }
        if (l = -1) {
            for (j = r; j < m; j++) {
                cout << array[j] << " ";
            }
            sum += array[m - 1] - array[0];
        } else {
            for (j = l; j >= 0; j--) {
                cout << array[j] << " ";
            }
            sum += array[m - 1] - array[0];
        }
    }
    cout << "�ƶ����ܵ����� " << sum << endl;
}
//���ݵ����㷨
void Elevator(int array[], int m) //��</A>Ҫ������ǰ�ŵ��ź��ƶ��۵��ƶ�����
{
    int temp;
    int k = 1;
    int now, l, r, d;
    int i, j, sum = 0;
    for (i = 0; i < m; i++)
        for (j = i + 1; j < m; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    for (i = 0; i < m; i++) {
        cout << array[i] << " ";
    }
    cout << "�����뵱ǰ�Ĵŵ��ţ�";
    cin >> now;
    if (array[m - 1] <= now) {
        for (i = m - 1; i >= 0; i--)
            cout << array[i] << " ";
        sum = now - array[0];
    } else if (array[0] >= now) {
        for (i = 0; i < m; i++)
            cout << array[i] << " ";
        sum = array[m - 1] - now;
    } else {
        while (array[k] < now) {
            k++;
        }
        l = k - 1;
        r = k;
        cout << "�����뵱ǰ�ƶ��۵��ƶ��ķ��� (1 ��ʾ���� ��0��ʾ����) : ";
        cin >> d;
        if (d == 0) {
            for (j = l; j >= 0; j--) {
                cout << array[j] << " ";
            }
            for (j = r; j < m; j++) {
                cout << array[j] << " ";
            }
            sum = now - 2 * array[0] + array[m - 1];
        } else {
            for (j = r; j < m; j++) {
                cout << array[j] << " ";
            }
            for (j = l; j >= 0; j--) {
                cout << array[j] << " ";
            }

            sum = -now - array[0] + 2 * array[m - 1];
        }
    }
    cout << "�ƶ����ܵ����� " << sum << endl;
}

void main()
{
    int c;
    FILE* fp;
    int cidao[maxsize];
    int i = 0, count;
    fp = fopen("cidao.txt", "r+");
    if (fp == NULL) {
        cout << "�ļ��򲻿�!" << endl;
        exit(0);
    }
    while (!feof(fp)) {
        fscanf(fp, "%d", &cidao[i]);
        i++;
    }
    count = i;

    for (i = 0; i < count; i++) {
        printf("%5d", cidao[i]);
    }
    cout << endl;
    while (1) {
        cout << endl
             << "ϵͳ�Ĳ˵����£�" << endl;
        printf("1. �����ȷ���     2. ���Ѱ��ʱ������     3. ���ݵ���");
        cout << endl;
        printf("4. �˳�");
        cout << endl;
        cout << "��ѡ��";
        cin >> c;
        if (c > 3)
            break;
        switch (c) {
        case 1:
            FCFS(cidao, count);
            break;
        case 2:
            ShortPath(cidao, count);
            break;
        case 3:
            Elevator(cidao, count);
            break;
        }
    }
}
