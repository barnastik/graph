#include "clGraph.h"
clGraph::clGraph(): arr_node(new clNode[N]) //, edge(new clLineWithWeight[N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat_c[i][j] = 0;
            mat_r[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) //записали координаты в массив
    {
        float angle = i*360/N * PI/180;
        int r = 200;
        int x = round(300 +  cos(angle) * r);
        int y = round(300 - sin(angle) * r);
        arr_node[i].Setx(x);
        arr_node[i].Sety(y);
        //arr_node[i].Setx_1(x-3);
        //arr_node[i].Sety_1(y-35);
        arr_node[i].Setnum(i+1);
    }
}

void clGraph::Show()
{
    int i,j;
    long double cos_t, sin_t;
    char str[4];
    //settextstyle(8, HORIZ_DIR, 7);
    for (int i = 0; i < N; i++)
    {
        //cout<<arr_node[i].Getx()<<"  "<<arr_node[i].Gety()<<endl;
        arr_node[i].Show();
    }

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
    for (j = 0; j < N-1; j++)
    {
        for (i = j+1; i < N; i++)
        {
            if (matr[i][j] && mat_r[i][j] == 0) {
                sprintf(str, "%d", matr[i][j]);
                setcolor(15);
                clLineWithWeight e(arr_node[i].Getx(),arr_node[i].Gety(),arr_node[j].Getx(),arr_node[j].Gety(), matr[i][j]);
                e.Show();
                //cos_t = (arr_node[j].Getx() - arr_node[i].Getx()) / sqrt(pow(arr_node[j].Getx() - arr_node[i].Getx(), 2) + pow(arr_node[j].Gety() - arr_node[i].Gety(), 2));
                //sin_t = (arr_node[j].Gety() - arr_node[i].Gety()) / sqrt(pow(arr_node[j].Getx() - arr_node[i].Getx(), 2) + pow(arr_node[j].Gety() - arr_node[i].Gety(), 2));
                //line(arr_node[i].Getx() + 35 * cos_t, arr_node[i].Gety() + 35 * sin_t, arr_node[j].Getx() - 35 * cos_t, arr_node[j].Gety() - 35 * sin_t);
                //outtextxy((arr_node[i].Getx() + arr_node[j].Getx()) / 2, (arr_node[i].Gety() + arr_node[j].Gety()) / 2, str);
            }
        }
    }

    for (j = 0; j < N - 1; j++) {
        for (i = j + 1; i < N; i++) {
            if (mat_r[i][j] > 0) {
                sprintf(str, "%d", matr[i][j]);
                clLineWithWeight e(arr_node[i].Getx(),arr_node[i].Gety(),arr_node[j].Getx(),arr_node[j].Gety(), matr[i][j]);
                setcolor(3);
                e.Show();
                //cos_t = (arr_node[j].Getx() - arr_node[i].Getx()) / sqrt(pow(arr_node[j].Getx() - arr_node[i].Getx(), 2) + pow(arr_node[j].Gety() - arr_node[i].Gety(), 2));
                //sin_t = (arr_node[j].Gety() - arr_node[i].Gety()) / sqrt(pow(arr_node[j].Getx() - arr_node[i].Getx(), 2) + pow(arr_node[j].Gety() - arr_node[i].Gety(), 2));
                //setcolor(3);
                //line(arr_node[i].Getx() + 35 * cos_t, arr_node[i].Gety() + 35 * sin_t, arr_node[j].Getx() - 35 * cos_t, arr_node[j].Gety() - 35 * sin_t);
                //setcolor(15);
                //outtextxy((arr_node[i].Getx() + arr_node[j].Getx()) / 2, (arr_node[i].Gety() + arr_node[j].Gety()) / 2, str);
            }
        }
    }

}

void clGraph::tran(int mat_c[][N], int rang)
{
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (mat_c[i][j])
                mat_c[j][i] = mat_c[i][j];
        }
    }
}

void clGraph::Boruvka()
{

    //int mat_c[N][N];
    long double top_x[10], top_y[10];
    int comp = 2, i, j, k, v, flag = 0, flazh = 1, min_t = 1000, prov = 0, min_i = 0, min_stb, min_str, min_comp, comp_b;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            mat_c[i][j] = 0;
            mat_r[i][j] = 0;
        }
    }



    // Assuming arr_node is a member variable of clGraph
    for (i = 0; i < N; i++) {
        top_x[i] = arr_node[i].Getx();
        top_y[i] = arr_node[i].Gety();
    } //массивы top_x и top_y для хранения координат узлов.
    //координаты узлов на окружности с использованием тригонометрических функций.

     /*for (i = 0; i < rang; i++) {
        top_x[i] = (int) (320 + trunc(200 * cos(-1 * M_PI / 2 + i * ang / rang)));
        top_y[i] = (int) (240 + trunc(200 * sin(-1 * M_PI / 2 + i * ang / rang)));
    }*/

    int rang = N;
    // Boruvka's algorithm
    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++) {
            if ((matr[i][j] > 0) && (matr[i][j] < min_t)) {
                min_t = matr[i][j];
                min_i = i;
            }
        }
        mat_c[min_i][j] = matr[min_i][j];
        min_t = 1000;
    }

    for (i = 0; i < rang; i++) {
        if (mat_c[i][0] > 0) mat_c[i][0] = 1;
    }
    for (j = 1; j < rang; j++) {
        for (i = 0; i < rang; i++) {
            if (mat_c[i][j] > 0) {
                if (i > j) {
                    mat_c[i][j] = comp;
                    comp++;
                    flag = 1;
                }
                else {
                    for (k = 0; k < rang; k++) {
                        if (mat_c[k][i] > 0)
                            mat_c[i][j] = mat_c[k][i];
                    }
                }
            }
        }
    }
    tran(mat_c, rang);

    while (flag) {
        for (j = 0; j < rang; j++) {
            for (i = 0; i < rang; i++) {
                if (flazh) {
                    for (v = 0; v < rang; v++) {
                        if (mat_c[v][j]) {
                            comp_b = mat_c[v][j];
                            break;
                        }
                    }
                    flazh = 0;
                }
                if (mat_c[i][j] == 0 && matr[i][j] > 0) {
                    for (k = 0; k < rang; k++) {
                        if ((mat_c[k][i] > 0) && (mat_c[k][i] != comp_b) && (matr[i][j] < min_t)) {
                            min_t = matr[i][j];
                            min_stb = j;
                            min_str = i;
                            min_comp = mat_c[k][i];
                        }
                    }
                }
                flazh = 1;
            }
        }
        mat_c[min_str][min_stb] = min_comp;
        tran(mat_c, rang);
        for (i = 0; i < rang; i++) {
            for (j = 0; j < rang; j++) {
                if (mat_c[i][j] == comp_b)
                    mat_c[i][j] = min_comp;
            }
        }
        flag = 0;
        for (i = 0; i < rang; i++) {
            for (j = 0; j < rang; j++) {
                if ((mat_c[i][j] > 0) && (mat_c[i][j] != min_comp))
                    flag = 1;
            }
        }
        for (j = 0; j < rang; j++) {
            for (i = 0; i < rang; i++) {
                if (mat_c[i][j]) {
                    if (prov == 0)
                        prov = mat_c[i][j];
                    else {
                        flag = 0;
                        break;
                    }
                }
            }
            prov = 0;
        }
        min_t = 1000;
    }


    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (mat_c[i][j]) {
                mat_r[i][j] = matr[i][j];
            }
        }
    }
}


clGraph::~clGraph()
{
    delete[] arr_node;//dtor
}
