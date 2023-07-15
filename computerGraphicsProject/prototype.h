//
// Created by roomi on 5/15/2023.
//
#include <Windows.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define EXIT 0
#define CLEAR 4
#define COLORWindow 5
#define BLACK 6
#define GREEN 7
#define RED 8
#define BLUE 9
#define SAVE 10
#define LOAD 11
#ifndef COMPUTERGRAPHICSPROJECT_PROTOTYPE_H
#define COMPUTERGRAPHICSPROJECT_PROTOTYPE_H
using namespace std;
#endif //COMPUTERGRAPHICSPROJECT_PROTOTYPE_H
struct EdgeRec
{
    double x;
    double minv;
    int ymax;
    bool operator<(EdgeRec r)
    {
        return x<r.x;
    }
};
struct Vector2
{
    double x,y;
    Vector2(double a=0,double b=0)
    {
        x=a; y=b;
    }
};
class Vector4
{
    double v[4];
public:
    Vector4(double a=0,double b=0,double c=0,double d=0)
    {
        v[0]=a; v[1]=b; v[2]=c; v[3]=d;
    }

    Vector4(double a[])
    {
        memcpy(v,a,4*sizeof(double));
    }

    double& operator[](int i)
    {
        return v[i];
    }
};
struct Vector {
    double v[2];
    Vector(double x = 0, double y = 0)
    {
        v[0] = x; v[1] = y;
    }
    double& operator[](int i) {
        return v[i];
    }
};
class Matrix4
{
    Vector4 M[4];
public:
    Matrix4(double A[])
    {
        memcpy(M,A,16*sizeof(double));
    }
    Vector4& operator[](int i)
    {
        return M[i];
    }
};
struct Point {
    double x;
    double y;
};
struct Circle {
    Point center;
    double radius;
};
union OutCode
{
    unsigned All:4;
    struct{unsigned left:1,top:1,right:1,bottom:1;};
};
struct Vertex
{
    double x, y;
    Vertex(int x1 = 0, int y1 = 0)
    {
        x = x1;
        y = y1;
    }
};
typedef struct{
    int xleft, xright;
}Entity[1000];
#define MAXENTRIES 600
typedef list<EdgeRec> EdgeList;
vector<pair<int,int>> line;
typedef vector<Vertex> VertexList;
typedef bool (*IsInFunc)(Vertex& v, int edge);
typedef Vertex(*IntersectFunc)(Vertex& v1, Vertex& v2, int edge);
void addMenus(HWND);
HMENU hMenu;
void swap(int&, int&);
int Round(double);
///shapes
int determineQuarter(int,int,int,int);
void SimpleDDA(HDC, int, int, int, int, COLORREF);
void DrawLineMidPoint(HDC , int , int , int, int, COLORREF);
void parametricLine(HDC,  int, int, int, int, COLORREF);
void drawLine(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c);
void draw8PointsCircle(HDC ,  int, int, int, int, COLORREF);
void Draw4Points(int xc, int yc, int x, int y);
void Draw_Direct_Ellipse(HDC,int xc, int yc, int A, int B,COLORREF);
void Draw_Polar_Ellipse(HDC,int xc, int yc, int A, int B,COLORREF);
void Draw_Midpoint_Ellipse(HDC,int xc, int yc, int A, int B,COLORREF);
void draw2Points(HDC , int , int , int , int ,int , COLORREF );
void drawQuarter(HDC , int , int , int , int , COLORREF );
//// Circle ProtoType ALG
void CircleDirect(HDC , int , int , int , COLORREF );
void CirclePolar(HDC , int , int , int , COLORREF );
void circleFasterMidPoint(HDC , int , int , int ,int , COLORREF );
void circleIterativePolar(HDC , int , int , int , COLORREF );
void CircleBresenham(HDC , int , int , int , COLORREF );
//// Circle Filling ProtoType ALG
void fillCircleWithCircles(HDC , int , int , int , int , COLORREF );
void fillCircleWithLies(HDC , int , int , int ,int ,int , COLORREF );
/// filling
void FloodFillRecursive(HDC, int, int, COLORREF, COLORREF);
void FloodFillNonRecursive(HDC, int , int , COLORREF, COLORREF);
void InitTable(Entity);
void Edge2Table(POINT, POINT, Entity);
void Polygon2Table(POINT [],int ,Entity);
void Table2Screen(HDC, Entity, COLORREF);
void ConvexFill(HDC,POINT [], int,COLORREF);
EdgeRec InitEdgeRec(POINT&,POINT&);
void InitEdgeTable(POINT *,int,EdgeList []);
void GeneralPolygonFill(HDC,POINT *,int,COLORREF);
///curves
Vector4 operator*(Matrix4 ,Vector4&);
double DotProduct(Vector4&,Vector4&);
Vector4 GetHermiteCoeff(double,double,double,double);
void drawHermiteCurve(HDC ,Vector2& ,Vector2& ,Vector2& ,Vector2& ,int, COLORREF);
void DrawCardinalSpline(HDC ,Vector2 [],int,double,int, COLORREF );
void DrawHermiteCurve(HDC, Vector&, Vector&, Vector&, Vector&, COLORREF, int, int, int, int);
void DrawSquare(HDC , int, int, int, COLORREF, COLORREF);
void PizerCUrveRectangleFail(HDC, int , int , int , int, COLORREF);
void Rectangle(HDC, int, int , int, int, COLORREF, COLORREF );
///clipping
OutCode GetOutCode(double x,double y,int xleft,int ytop,int xright,int ybottom);
void VIntersect(double xs,double ys,double xe,double ye,int x,double *xi,double *yi);
void HIntersect(double xs,double ys,double xe,double ye,int y,double *xi,double *yi);
void Cohen(HDC hdc,int xs,int ys,int xe,int ye,int xleft,int ytop,int xright,int ybottom);
void lineClippingWithCircle(HDC hdc,Circle c, Point p1, Point p2, COLORREF color);
void PointClippingCircle(HDC hdc,int x,int y,int xc,int yc,int r,COLORREF color);
void PointClippingRecSq(HDC hdc,int x,int y,int xleft,int ytop,int xright,int ybottom,COLORREF color);
void PolygonClip(HDC hdc, POINT* p, int n, int xleft, int ytop, int xright, int ybottom);
bool InLeft(Vertex& v, int edge);
bool InRight(Vertex& v, int edge);
bool InTop(Vertex& v, int edge);
bool InBottom(Vertex& v, int edge);
Vertex VIntersect(Vertex& v1, Vertex& v2, int xedge);
Vertex HIntersect(Vertex& v1, Vertex& v2, int yedge);
VertexList ClipWithEdge(VertexList p, int edge, IsInFunc In, IntersectFunc Intersect);
void swap(int& x,int& y)
{
    int tmp=x;
    x=y;
    y=tmp;
}
int Round(double x)
{
    return (int)(x+0.5);
}