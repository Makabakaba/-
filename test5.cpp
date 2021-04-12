#include <ctime>
#include <cmath>
#include <iostream>  
#include <algorithm>

using namespace std;

#define INFINITE_DISTANCE 65535    //���޴����
#define COORDINATE_RANGE 100.0    //�������귶ΧΪ[-100,100]

typedef struct Point{  //��ά�����ϵĵ�Point
    double x;
    double y;
}Point;

double Distance(Point a, Point b){  //ƽ�������������֮��ľ��빫ʽ����
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool compareX(Point a, Point b){  //�Զ�������������սṹ���е�x��Ա������������
    return a.x < b.x;
}

bool compareY(Point a, Point b){  //�Զ�������������սṹ���е�x��Ա������������
    return a.y < b.y;
}

float ClosestPair(Point points[], int length, Point &a, Point &b){  // ��������Լ�¼�����������¼��a��b��
    double distance;                   //��¼����points������������ 
    double d1, d2;                     //��¼�ָ�������Ӽ��и�����С��Ծ���
    int i = 0, j = 0, k = 0, x = 0;    //���ڿ���forѭ����ѭ������
    Point a1, b1, a2, b2;              //����ָ�������Ӽ�����С���

    if (length < 2)
        return INFINITE_DISTANCE;    //���Ӽ�����С��2������Ϊ�����룬��ʾ���ɴ�
    else if (length == 2){  //���Ӽ����ȵ���2��ֱ�ӷ��ظ�����ľ���
        a = points[0];
        b = points[1];
        distance = Distance(points[0], points[1]);
    }
    else{  //�Ӽ����ȴ���3�����з������
        Point *pts1 = new Point[length];     //���������Ӽ�
        Point *pts2 = new Point[length];

        sort(points, points + length, compareX);    //����sort������points��������compareXΪ�Զ�����������
        double mid = points[(length - 1) / 2].x;    //���������м��±�ֵ������λ��

        for (i = 0; i < length / 2; i++)
            pts1[i] = points[i];
        for (int j = 0, i = length / 2; i < length; i++)
            pts2[j++] = points[i];

        d1 = ClosestPair(pts1, length / 2, a1, b1);             //���������벿���Ӽ��������  
        d2 = ClosestPair(pts2, length - length / 2, a2, b2);    //��������Ұ벿���Ӽ��������  

        if (d1 < d2) { distance = d1; a = a1; b = b1; }            //��¼����㣬�������
        else { distance = d2; a = a2; b = b2; }

        Point *pts3 = new Point[length];

        for (i = 0, k = 0; i < length; i++)                        //ȡ������2�Ŀ�ȵ����е�Թ�k��    
            if (abs(points[i].x - mid) <= distance)
                pts3[k++] = points[i];

        sort(pts3, pts3 + k, compareY);                                       // ��y����������ڵĵ㼯��

        for (i = 0; i < k; i++){
            if (pts3[j].x - mid >= 0)                                // ֻ�ж���ಿ�ֵĵ�
                continue;
            x = 0;
            for (j = i + 1; j <= i + 6 + x && j < k; j++){     //ֻ�����������ӵĵ�6������бȽ�
                if (pts3[j].x - mid < 0){        //����i����λ��mid�����ֻ���ж���mid�ұߵ�j�㼴��
                    x++;
                    continue;
                }
                if (Distance(pts3[i], pts3[j]) < distance){    //�����ָ��ߵ��������С����֪��С���룬���¼�þ��������
                    distance = Distance(pts3[i], pts3[j]);
                    a = pts3[i];
                    b = pts3[j];
                }
            }
        }
    }
    return distance;
}

void SetPoints(Point *points, int length){  //��������Ե�����points�еĶ�ά����г�ʼ��
    srand(unsigned(time(NULL)));
    for (int i = 0; i < length; i++)
    {
        points[i].x = (rand() % int(COORDINATE_RANGE * 200)) / COORDINATE_RANGE - COORDINATE_RANGE;
        points[i].y = (rand() % int(COORDINATE_RANGE * 200)) / COORDINATE_RANGE - COORDINATE_RANGE;
    }
}

int main()
{
    int num;            //������ɵĵ�Ը���
    Point a, b;            //������
    double diatance;    //��Ծ���

    cout << "�������ά��Ը���:";
    cin >> num;
    if (num < 2)
        cout << "��������ڵ���2�ĵ��������" << endl;
    else
    {
        cout << endl << "������ɵ�" << num << "����ά������£�" << endl;
        Point *points = new Point[num];

        SetPoints(points, num);
        for (int i = 0; i < num; i++)
            cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
        diatance = ClosestPair(points, num, a, b);
        cout << endl << endl << "�������������ĵ��:" << endl;
        for (int i = 0; i < num; i++)
            cout << "(" << points[i].x << "," << points[i].y << ")" << endl;

        cout << endl << "������Ϊ��" << "(" << a.x << "," << a.y << ") �� " << "(" << b.x << "," << b.y << ")" << endl << "�����Ծ���Ϊ��" << diatance << endl;
    }
    system("pause");
}
