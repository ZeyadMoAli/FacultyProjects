#include "Switches.h"
struct Pixel
{
    int x;
    int y;
    COLORREF color;
};
static Pixel pixels[500000];
static int numPixels = 0;
void getPixel(int x, int y, COLORREF color)
{
    pixels[numPixels].x = x;
    pixels[numPixels].y = y;
    pixels[numPixels].color = color;
    numPixels++;
}
int  a, b;
double  alpha ,beta;
int num;
/// WinAPI
LRESULT WINAPI WndProc(HWND hWnd, UINT m, WPARAM wp, LPARAM lp)
{
    HDC hdc;
    static std::vector<Vector2> points;
    static RECT rect = { 100, 100, 200, 200 }; // create a RECT with the specified coordinates
    static int x1, y1, x2, y2, x3, y3, x4, y4, r, cnt = 0, cnt2 = 0;
    const int n = 5;

    static POINT p[n];
    switch (m) {
        case WM_COMMAND:
            switch (wp) {
                case COLORWindow:
                    SetClassLongPtr(hWnd, GCLP_HBRBACKGROUND, (LONG_PTR)CreateSolidBrush(RGB(255, 255, 255)));
                    InvalidateRect(hWnd, NULL, TRUE);
                    break;
                case BLACK:
                    selectedColor =  RGB(0, 0, 0);
                    break;
                case RED:
                    selectedColor = RGB(255, 0, 0);
                    break;
                case GREEN:
                    selectedColor = RGB(0, 255, 0);
                    break;
                case BLUE:
                    selectedColor = RGB(0, 0, 255);
                    break;
                case EXIT:
                    DestroyWindow(hWnd);
                    break;
                case CLEAR:
                    InvalidateRect(hWnd, NULL, TRUE);
                    break;
                case SAVE:
                {
                    // Change the file name and path as needed
                    string fileName = R"(D:\MariamFCAI\1-ThirdYear\Second Semester\Computer Graphics\Project\ComputerGraphicsProject\output.txt)";
                    ofstream outputFile(fileName);
                    if (outputFile.is_open())
                    {
                        for (int i = 0; i < numPixels; i++)
                        {
                            outputFile << pixels[i].x << " " << pixels[i].y << " " << pixels[i].color << endl;
                        }
                        outputFile.close();
                        //MessageBox(hWnd, "Data saved successfully!", "Save", MB_OK | MB_ICONINFORMATION);
                    }
                    break;

                }
                case LOAD:
                {
                    // Change the file name and path as needed
                    string loadFileName = "C://Users//roomi//Desktop//output.txt";
                    ifstream inputFile(loadFileName);
                    if (inputFile.is_open())
                    {
                        numPixels = 0;
                        int x, y;
                        COLORREF color;
                        while (inputFile >> x >> y >> color)
                        {

                            hdc = GetDC(hWnd);
                            SetPixel(hdc, x, y, color);
                            ReleaseDC(hWnd, hdc);

                            pixels[numPixels].x = x;
                            pixels[numPixels].y = y;
                            pixels[numPixels].color = color;
                            numPixels++;
                        }
                        inputFile.close();
                        //MessageBox(hWnd, "Data loaded successfully!", "Load", MB_OK | MB_ICONINFORMATION);
                    }
                    break;

                }
                case TRANSFORM:
                    cout<<"Enter transform value for x and y: \n";
                    cin>>a>>b;
                    x1 = x1 + a;
                    y1 = y1 + b;
                    x2+=a;
                    y2+=b;
                    DrawLineMidPoint(hdc, x1, y1, x2, y2, selectedColor);
                    break;
                case SCALE:
                    int midX, midY;
                    midX= (x1 + x2) / 2;
                    midY = ( y1 + y2 ) / 2;
                    cout<<"Enter transform scale for x and y: \n";
                    cin>>alpha>>beta;
                    x1 -= midX; y1 -=midY;
                    x2 -= midX; y2 -=midY;
                    x1 = alpha * x1;
                    y1 = beta * y1;
                    x2 = alpha * x2;
                    y2 = beta * y2;
                    x1 += midX; y1+=midY;
                    x2 += midX; y2+=midY;
                    DrawLineMidPoint(hdc, x1, y1, x2, y2, selectedColor);
                    break;
            }
            break;
        case WM_CREATE:
            addMenus(hWnd);
            break;
        case WM_LBUTTONDOWN:
            hdc = GetDC(hWnd);
            if (num >= 1 && num <= 10 || num == 25 || num == 26 || num == 28|| num == 29) {

                if (cnt  % 2 == 0) {
                    x1 = LOWORD(lp);
                    y1 = HIWORD(lp);
                }
                else if(cnt % 2 == 1) {
                    x2 = LOWORD(lp);
                    y2 = HIWORD(lp);
                    if (num == 25 || num == 26) {
                        rect = {x1, y1, x2, y2};
                    }
                    if (num == 10) {
                        Rectangle(hdc, x1, y1, x2, y1);
                    }
                    switch2Clicks(num, hdc, x1, y1, x2, y2, selectedColor);
                    cnt = -1;
                    ReleaseDC(hWnd, hdc);
                }
                cnt++;
            }
            else if (num >= 11 && num <= 18)
            {
                if (cnt % 3 == 0) {
                    x1 = LOWORD(lp);
                    y1 = HIWORD(lp);
                } else if (cnt % 3 == 1) {
                    x2 = LOWORD(lp);
                    y2 = HIWORD(lp);
                    if (num >= 14 && num <= 17)
                    {
                        int R = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
                        if (num == 17) {
                            Rectangle(hdc, x1, y1, x1 + R, y1 + R);
                        }
                        else {
                            circleFasterMidPoint(hdc, x1, y1, R, 0, selectedColor);
                        }
                    }
                    if (num == 18) {
                        Rectangle(hdc, x1, y1, x2, y2);
                    }
                } else {
                    x3 = LOWORD(lp);
                    y3 = HIWORD(lp);
                    switch3Clicks(num, hdc, x1, y1, x2, y2, x3, y3, selectedColor);
                    cnt = -1;
                    ReleaseDC(hWnd, hdc);
                }
                cnt++;
            }
            else if (num >= 19 && num <= 21) {
                if (cnt % 4 == 0) {
                    x1 = LOWORD(lp);
                    y1 = HIWORD(lp);
                } else if (cnt % 4 == 1) {
                    x2 = LOWORD(lp);
                    y2 = HIWORD(lp);
                    r = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
                    if (num == 21) {
                        Rectangle(hdc, x1, y1, x2, y2);
                    } else if (num == 20) {
                        Rectangle(hdc, x1, y1, x1 + r, y1 + r);
                    } else {
                        circleFasterMidPoint(hdc, x1, y1, r, 0, selectedColor);
                    }
                } else if (cnt % 4 == 2) {
                    x3 = LOWORD(lp);
                    y3 = HIWORD(lp);
                } else {
                    x4 = LOWORD(lp);
                    y4 = HIWORD(lp);
                    switch4Clicks(num, hdc, x1, y1, x2, y2, x3, y3, x4, y4, selectedColor);
                    cnt = -1;
                    ReleaseDC(hWnd, hdc);
                }
                cnt++;
            }
            else if (num >= 22 && num <= 23) {
                p[cnt].x = LOWORD(lp);
                p[cnt].y = HIWORD(lp);
                if (cnt == n - 1) {
                    Polygon(hdc, p, 5);
                    switchNClicks(num, hdc, p, n);
                    cnt = -1;
                    ReleaseDC(hWnd, hdc);
                } else {
                    cnt++;
                }
            }
            else if(num == 24) {
                if (cnt2 == 0) {
                    x1 = LOWORD(lp);
                    y1 = HIWORD(lp);
                    getPixel(x1, y1, selectedColor);
                } else if (cnt2 == 1) {
                    x2 = LOWORD(lp);
                    y2 = HIWORD(lp);
                    getPixel(x2, y2, selectedColor);
                    Rectangle(hdc, x1, y1, x2, y2, selectedColor);
                    cnt2 = -1;
                } else {
                    p[cnt].x = LOWORD(lp);
                    p[cnt].y = HIWORD(lp);
                    if (cnt == n - 1) {
                        PolygonClip(hdc, p, n, x1, y1, x2, y2);
                        cnt = -1;
                        ReleaseDC(hWnd, hdc);
                    } else {
                        cnt++;
                    }
                }
                cnt2++;
            }
            else if (num == 27) {
                int x = LOWORD(lp);
                int y = HIWORD(lp);
                Vector2 pt(x, y);
                points.push_back(pt);
                InvalidateRect(hWnd, NULL, TRUE);
                ReleaseDC(hWnd, hdc);
            }
            ReleaseDC(hWnd, hdc);
            break;
        case WM_PAINT: {

            if(num == 25 || num == 26)
            {
                PAINTSTRUCT ps;
                hdc = BeginPaint(hWnd, &ps);
                HBRUSH hBrush = CreateSolidBrush(selectedColor);
                HGDIOBJ hOldBrush = SelectObject(hdc, hBrush);
                Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
                if(num == 26)
                    FloodFillNonRecursive(hdc, rect.left + 1, rect.top + 1, selectedColor, RGB(255, 255, 255));
                else
                    FloodFillRecursive(hdc, rect.left + 1, rect.top + 1, selectedColor, RGB(255, 255, 255)); // fill the rectangle with white using recursive flood fill
                SelectObject(hdc, hOldBrush);
                DeleteObject(hBrush);
                EndPaint(hWnd, &ps);
            }
            else if(num == 27)
            {
                PAINTSTRUCT ps;
                hdc = BeginPaint(hWnd, &ps);
                SetBkMode(hdc, TRANSPARENT);
                RECT rc;
                GetClientRect(hWnd, &rc);
                int width = rc.right - rc.left;
                int height = rc.bottom - rc.top;
                // Draw a cardinal spline curve
                if(points.size()>1)
                    DrawCardinalSpline(hdc, &points[0], points.size(), 0.5, 1000, RGB(255, 0, 0));
                EndPaint(hWnd, &ps);
            }

            break;
        }
        case WM_KEYDOWN:
            if (wp == VK_SPACE)
                num = console();
            break;

        case WM_RBUTTONDOWN:
            ReleaseDC(hWnd, hdc);
            break;
        case WM_CLOSE:
            DestroyWindow(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
        default:
            return DefWindowProc(hWnd, m, wp, lp);
    }

    return 0;
}
int APIENTRY WinMain(HINSTANCE h, HINSTANCE p, LPSTR cmd, int csh)
{
    WNDCLASS wc;
    wc.lpszClassName = "MyClass";
    wc.lpszMenuName = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_HAND);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);    wc.hbrBackground =(HBRUSH) GetStockObject(LTGRAY_BRUSH);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = h;
    RegisterClass(&wc);
    HWND hWnd = CreateWindow("MyClass", "Hello", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, h, 0);
    ShowWindow(hWnd, csh);
    UpdateWindow(hWnd);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
///line
void SimpleDDA(HDC hdc,int xs,int ys,int xe,int ye,COLORREF color)
{
    int dx=xe-xs;
    int dy=ye-ys;
    SetPixel(hdc,xs,ys,color);
    getPixel(xs, ys, color);
    if(abs(dx)>=abs(dy))
    {
        int x=xs,xinc= dx>0?1:-1;
        double y=ys,yinc=(double)dy/dx*xinc;
        while(x!=xe)
        {
            x+=xinc;
            y+=yinc;
            SetPixel(hdc,x,round(y),color);
            getPixel(x, y, color);
        }
    }
    else
    {
        int y=ys,yinc= dy>0?1:-1;
        double x=xs,xinc=(double)dx/dy*yinc;
        while(y!=ye)
        {
            x+=xinc;
            y+=yinc;
            SetPixel(hdc,round(x),y,color);
            getPixel(x, y, color);

        }
    }
}
void parametricLine(HDC hdc,int xs,int ys,int xe,int ye,COLORREF color)
{
    int dx=xe-xs;
    int dy=ye-ys;
    if(abs(dy)<=abs(dx))
    {
        double slope=(double)dy/dx;
        if(xs>xe)
        {
            swap(xs,xe);
            swap(ys,ye);
        }
        for(int x=xs;x<=xe;x++)
        {
            int y=round(ys+(x-xs)*slope);
            SetPixel(hdc,x,y,color);
            getPixel(x,y,color);
        }
    } else
    {
        double islope=(double)dx/dy;
        if(ys>ye)
        {
            swap(xs,xe);
            swap(ys,ye);
        }
        for(int y=ys;y<=ye;y++)
        {
            int x=round(xs+(y-ys)*islope);
            SetPixel(hdc,x,y,color);
            getPixel(x,y,color);
        }
    }
}
void DrawLineMidPoint(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c) {
    int x = x1, y = y1;
    double dx = x2 - x1, dy = y2 - y1;
    SetPixel(hdc, x, y, c);
    getPixel(x,y,c);
    if ((dx == 0 || dy / dx > 1) && dy > 0 && dx >= 0)
    {
        int d = 2 * dx - dy, d1 = 2 * dx, d2 = 2 * dx - 2 * dy;
        while (y != y2)
        {
            if (d <= 0)
            {
                y++;
                d += d1;
            }
            else
            {
                x++;
                y++;
                d += d2;
            }
            SetPixel(hdc, x, y, c);
            getPixel(x,y,c);
        }
    }
    else if (dy / dx >= 0 && dy / dx <= 1 && dy >= 0 && dx > 0)
    {
        int d = dx - 2 * dy, d1 = -2 * dy, d2 = 2 * dx - 2 * dy;
        while (x != x2)
        {
            if (d > 0)
            {
                x++;
                d += d1;
            }
            else
            {
                x++;
                y++;
                d += d2;
            }
            SetPixel(hdc, x, y, c);
            getPixel(x,y,c);
        }
    }
    else if (dy / dx < 0 && dy / dx >= -1 && dy <= 0 && dx>0)
    {
        int d = -dx - 2 * dy, d1 = -2 * dy, d2 = -2 * dx - 2 * dy;
        while (x != x2)
        {
            if (d <= 0)
            {
                x++;
                d += d1;
            }
            else
            {
                x++;
                y--;
                d += d2;
            }
            SetPixel(hdc, x, y, c);
            getPixel(x,y,c);
        }
    }
    else if ((dx == 0 || dy / dx < -1) && dy < 0 && dx >= 0)
    {
        int d = -2 * dx - dy, d1 = -2 * dx, d2 = -2 * dx - 2 * dy;
        while (y != y2)
        {
            if (d > 0)
            {
                y--;
                d += d1;
            }
            else
            {
                x++;
                y--;
                d += d2;
            }
            SetPixel(hdc, x, y, c);
            getPixel(x,y,c);
        }
    }
    else if ((dx == 0 || dy / dx > 1) && dy < 0 && dx <= 0)
    {
        int d = -2 * dx + dy, d1 = -2 * dx, d2 = -2 * dx + 2 * dy;
        while (y != y2)
        {
            if (d <= 0)
            {
                y--;
                d += d1;
            }
            else
            {
                x--;
                y--;
                d += d2;
            }
            SetPixel(hdc, x, y, c);
            getPixel(x,y,c);
        }
    }
    else if (dy / dx >= 0 && dy / dx <= 1 && dy <= 0 && dx < 0)
    {
        int d = -dx + 2 * dy, d1 = 2 * dy, d2 = -2 * dx + 2 * dy;
        while (x != x2)
        {
            if (d > 0)
            {
                x--;
                d += d1;
            }
            else
            {
                x--;
                y--;
                d += d2;
            }
            SetPixel(hdc, x, y, c);
            getPixel(x,y,c);
        }
    }
    else if (dy / dx < 0 && dy / dx >= -1 && dy >= 0 && dx < 0)
    {
        int d = dx + 2 * dy, d1 = 2 * dy, d2 = 2 * dx + 2 * dy;
        while (x != x2)
        {
            if (d <= 0)
            {
                x--;
                d += d1;
            }
            else
            {
                x--;
                y++;
                d += d2;
            }
            SetPixel(hdc, x, y, c);
            getPixel(x,y,c);
        }
    }
    else if ((dx == 0 || dy / dx < -1) && dy > 0 && dx <= 0)
    {
        int d = 2 * dx + dy, d1 = 2 * dx, d2 = 2 * dx + 2 * dy;
        while (y != y2)
        {
            if (d > 0)
            {
                y++;
                d += d1;
            }
            else
            {
                x--;
                y++;
                d += d2;
            }
            SetPixel(hdc, x, y, c);
            getPixel(x,y,c);
        }
    }
}
void drawLine(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        SetPixel(hdc, x1, y1, c);
        getPixel(x1,y1,c);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}
///circle
void draw8PointsCircle(HDC hdc, int xc, int yc, int a, int b, COLORREF c)
{
    SetPixel(hdc, xc + a, yc + b, c);
    getPixel(xc + a, yc + b,c);
    SetPixel(hdc, xc + a, yc - b, c);
    getPixel(xc + a, yc - b, c);
    SetPixel(hdc, xc - a, yc + b, c);
    getPixel(xc - a, yc + b, c);
    SetPixel(hdc, xc - a, yc - b, c);
    getPixel(xc - a, yc - b, c);
    SetPixel(hdc, xc + b, yc + a, c);
    getPixel(xc + b, yc + a, c);
    SetPixel(hdc, xc + b, yc - a, c);
    getPixel(xc + b, yc - a, c);
    SetPixel(hdc, xc - b, yc + a, c);
    getPixel(xc - b, yc + a, c);
    SetPixel(hdc, xc - b, yc - a, c);
    getPixel(xc - b, yc - a, c);
}
void CircleDirect(HDC hdc,int xc,int yc, int R,COLORREF color)
{
    int x=0,y=R;
    int R2=R*R;
    draw8PointsCircle(hdc,xc,yc,x,y,color);
    while(x<y)
    {
        x++;
        y=round(sqrt((double)(R2-x*x)));
        draw8PointsCircle(hdc,xc,yc,x,y,color);
    }
}
void CirclePolar(HDC hdc,int xc,int yc, int R,COLORREF color)
{
    int x=R,y=0;
    double theta=0,dtheta=1.0/R;
    draw8PointsCircle(hdc,xc,yc,x,y,color);
    while(x>y)
    {
        theta+=dtheta;
        x=round(R*cos(theta));
        y=round(R*sin(theta));
        draw8PointsCircle(hdc,xc,yc,x,y,color);
    }
}
void circleIterativePolar(HDC hdc, int xc, int yc, int r, COLORREF c)
{
    double x = r, y = 0;
    double dTheta = 1.0 / r;
    double cosinedTheta = cos(dTheta);
    double sinedTheata = sin(dTheta);
    draw8PointsCircle(hdc, xc, yc, r, 0, c);
    while (x > y)
    {
        double x1 = x * cosinedTheta - y * sinedTheata;
        y = x * sinedTheata + y * cosinedTheta;
        x = x1;
        draw8PointsCircle(hdc, xc, yc, round(x), round(y),c);
    }
}
void CircleBresenham(HDC hdc,int xc,int yc, int R,COLORREF color)
{
    int x=0,y=R;
    int d=1-R;
    draw8PointsCircle(hdc,xc,yc,x,y,color);
    while(x<y)
    {
        if(d<0)
            d+=2*x+2;
        else
        {
            d+=2*(x-y)+5;
            y--;
        }
        x++;
        draw8PointsCircle(hdc,xc,yc,x,y,color);
    }
}
void circleFasterMidPoint(HDC hdc, int xc, int yc, int R, int quarter, COLORREF color)
{
    int x=0,y=R;
    int d=1-R;
    int c1=3, c2=5-2*R;
    draw8PointsCircle(hdc,xc,yc,x,y,color);
    while(x<y)
    {
        if(d<0)
        {
            d+=c1;
            c2+=2;
        }
        else
        {
            d+=c2;
            c2+=4;
            y--;
        }
        c1+=2;
        x++;
        draw8PointsCircle(hdc,xc,yc,x,y,color);
        fillCircleWithLies(hdc,xc,yc,x,y,quarter,color);
    }
}
///filling circle
int determineQuarter(int x3, int y3 ,int x1, int y1 )
{
    if (x3 >= x1 && y3 < y1)
    {
        return 1; // top-right quarter
    }
    else if (x3 >= x1 && y3 >= y1)
    {
        return 4; // bottom-right quarter
    }
    else if (x3 < x1 && y3 >= y1)
    {
        return 3; // bottom-left quarter
    }
    else
    {
        return  2; // top-left quarter
    }
}
void fillCircleWithCircles(HDC hdc, int xc, int yc, int r, int quarter, COLORREF c)
{
    if(quarter > 0)
    {
        while (r >= 0)
        {
            drawQuarter(hdc, xc, yc,r,quarter, c);
            r-=1;
        }
    }
}
void fillCircleWithLies(HDC hdc, int xc, int yc, int x,int y,int quarter, COLORREF c)
{
    switch (quarter) {
        case 4:
            drawLine(hdc,  xc, yc,xc + x, yc + y, c);
            drawLine(hdc, xc, yc, xc + y, yc + x, c);
            break;
        case 3:
            drawLine(hdc,xc, yc, xc - x, yc + y, c);
            drawLine(hdc, xc, yc,xc - y, yc + x, c);
            break;
        case 2:
            drawLine(hdc, xc, yc,xc - x, yc - y, c);
            drawLine(hdc, xc, yc,xc - y, yc - x, c);
            break;
        case 1:
            drawLine(hdc, xc, yc,xc + x, yc - y, c);
            drawLine(hdc, xc, yc,xc + y, yc - x, c);
            break;
    }
}
void drawQuarter(HDC hdc, int xc, int yc, int r, int quarter, COLORREF c)
{
    int x = 0, y = r;
    int mid = 1 - r;
    int change1 = 3, change2 = 5 - 2 * r;
    draw8PointsCircle(hdc, xc, yc, x, y, c);
    while (x < y) {
        if (mid < 0) {
            mid += change1;
            change2 += 2;
        } else {
            mid += change2;
            change2 += 4;
            y--;
        }
        change1 += 2;
        x++;
        switch (quarter) {
            case 4:
                SetPixel(hdc, xc + x, yc + y, c);
                getPixel(xc + x, yc + y, c);
                SetPixel(hdc, xc + y, yc + x, c);
                getPixel(xc + y, yc + x, c);
                break;
            case 3:
                SetPixel(hdc, xc - x, yc + y, c);
                getPixel(xc - y, yc + x, c);
                SetPixel(hdc, xc - y, yc + x, c);
                getPixel(xc - y, yc + x, c);
                break;
            case 2:
                SetPixel(hdc, xc - x, yc - y, c);
                getPixel(xc - y, yc - x, c);
                SetPixel(hdc, xc - y, yc - x, c);
                getPixel(xc - y, yc - x, c);
                break;
            case 1:
                SetPixel(hdc, xc + x, yc - y, c);
                getPixel(xc + y, yc - x, c);
                SetPixel(hdc, xc + y, yc - x, c);
                getPixel(xc + y, yc - x, c);
                break;
        }
    }
}
///ELlips
void Draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF color) {

    SetPixel(hdc, xc + x, yc + y, color);
    getPixel(xc + x, yc + y, color);
    SetPixel(hdc, xc - x, yc + y, color);
    getPixel(xc - x, yc + y, color);
    SetPixel(hdc, xc - x, yc - y, color);
    getPixel(xc - x, yc - y, color);
    SetPixel(hdc, xc + x, yc - y, color);
    getPixel(xc + x, yc - y, color);
}
void Draw_Direct_Ellipse(HDC hdc, int xc, int yc, int A, int B, COLORREF c)
{

    int x = 0;
    double y = B;
    Draw4Points(hdc, xc, yc, 0, B, c);

    while (x * B * B < y * A * A)
    {
        x++;
        y = B * sqrt(1 - (double)x * x / (A * A));
        Draw4Points(hdc, xc, yc, x, Round(y), c);
    }
    int x1 = A;
    double y1 = 0;
    Draw4Points(hdc, xc, yc, A, 0, c);

    while (x1 * B * B > y1 * A * A)
    {
        y1++;
        x1 = A * sqrt(1 - (double)y1 * y1 / (B * B));
        Draw4Points(hdc, xc, yc, Round(x1), y1, c);
    }

}
void Draw_Polar_Ellipse(HDC hdc, int xc, int yc, int A, int B, COLORREF c)
{

    double theta = 1.0 / max(A, B), x = 0, y = A;
    double st = sin(theta);
    double ct = cos(theta);

    while (x < y)
    {

        double x1 = x * ct - (double)A / B * y * st;
        y = (double)B / A * x * st + y * ct;
        x = x1;
        Draw4Points(hdc, xc, yc, Round(x), Round(y), c);
    }
    while (x > y)
    {
        double x1 = x * ct - (double)A / B * y * st;
        y = (double)B / A * x * st + y * ct;
        x = x1;
        Draw4Points(hdc, xc, yc, Round(x), Round(y), c);
    }
}
void Draw_Midpoint_Ellipse(HDC hdc, int xc, int yc, int A, int B, COLORREF color)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = B;
    d1 = (B * B) - (A * A * B) + (0.25 * A * A);
    dx = 2 * B * B * x;
    dy = 2 * A * A * y;
    while (dx < dy)
    {
        Draw4Points(hdc, xc, yc, x, y, color);
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * B * B);
            d1 = d1 + dx + (B * B);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * B * B);
            dy = dy - (2 * A * A);
            d1 = d1 + dx - dy + (B * B);
        }
    }
    d2 = ((B * B) * ((x + 0.5) * (x + 0.5))) +
         ((A * A) * ((y - 1) * (y - 1))) -
         (A * A * B * B);
    while (y >= 0)
    {
        Draw4Points(hdc, xc, yc, x, y, color);
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * A * A);
            d2 = d2 + (A * A) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * B * B);
            dy = dy - (2 * A * A);
            d2 = d2 + dx - dy + (A * A);
        }
    }

}

///filling
void InitTable(Entity t){
    for(int i =0; i< 1000; i++){
        t[i].xleft = INT_MAX;
        t[i].xright = -INT_MAX;
    }
}
void Edge2Table(POINT p1, POINT p2, Entity t){
    if(p1.y == p2.y){
        return;
    }
    if(p1.y > p2.y){
        swap(p1,p2);
    }
    double x  = p1.x;
    int y = p1.y;
    double minv =  (double)(p2.x-p1.x)/(p2.y-p1.y);
    while(y<p2.y){
        if(x<t[y].xleft) t[y].xleft = (int) ceil(x);
        if(x>t[y].xright) t[y].xright = (int) floor(x);
        y++;
        x += minv;
    }
}
void Polygon2Table(POINT p[],int n,Entity t){

    POINT v1 = p[n-1];
    for(int i = 0; i<n ;i++){
        POINT v2 = p[i];
        Edge2Table(v1,v2,t);
        v1 = p[i];
    }
}
void Table2Screen(HDC hdc, Entity t, COLORREF c){
    for(int i =0; i<1000; i++){
        if(t[i].xleft<t[i].xright){
            for(int x = t[i].xleft; x<= t[i].xright;x++){
                SetPixel(hdc,x,i,c);
                getPixel(x, i, c);
            }
        }
    }
}
void ConvexFill(HDC hdc,POINT p[], int n,COLORREF c){
    Entity t;
    InitTable(t);
    Polygon2Table(p,n,t);
    Table2Screen(hdc,t,c);

}

EdgeRec InitEdgeRec(POINT& v1,POINT& v2)
{
    if(v1.y>v2.y)swap(v1,v2);
    EdgeRec rec;
    rec.x=v1.x;
    rec.ymax=v2.y;
    rec.minv=(double)(v2.x-v1.x)/(v2.y-v1.y);
    return rec;
}
void InitEdgeTable(POINT *polygon,int n,EdgeList table[])
{
    POINT v1=polygon[n-1];
    for(int i=0;i<n;i++)
    {
        POINT v2=polygon[i];
        if(v1.y==v2.y){v1=v2;continue;}
        EdgeRec rec=InitEdgeRec(v1, v2);
        table[v1.y].push_back(rec);
        v1=polygon[i];
    }
}
void GeneralPolygonFill(HDC hdc,POINT polygon[],int n,COLORREF c)
{
    EdgeList *table=new EdgeList [MAXENTRIES];
    InitEdgeTable(polygon,n,table);
    int y=0;
    while(y<MAXENTRIES && table[y].size()==0)y++;
    if(y==MAXENTRIES)return;
    EdgeList ActiveList=table[y];
    while (ActiveList.size()>0)
    {
        ActiveList.sort();
        for(EdgeList::iterator it=ActiveList.begin();it!=ActiveList.end();it++)
        {
            int x1=(int)ceil(it->x);
            it++;
            int x2=(int)floor(it->x);
            for(int x=x1;x<=x2;x++) {
                SetPixel(hdc, x, y, c);
                getPixel(x, y, c);
            }
        }
        y++;
        EdgeList::iterator it=ActiveList.begin();
        while(it!=ActiveList.end())
            if(y==it->ymax) it=ActiveList.erase(it); else it++;
        for(EdgeList::iterator it=ActiveList.begin();it!=ActiveList.end();it++)
            it->x+=it->minv;
        ActiveList.insert(ActiveList.end(),table[y].begin(),table[y].end());
    }
    delete[] table;
}

void FloodFillRecursive(HDC hdc, int x, int y, COLORREF targetColor, COLORREF fillColor) {
    COLORREF currentColor = GetPixel(hdc, x, y);
    if (currentColor == targetColor && currentColor != fillColor) {
        SetPixel(hdc, x, y, fillColor);
        getPixel(x,y,fillColor);
        FloodFillRecursive(hdc, x + 1, y, targetColor, fillColor);
        FloodFillRecursive(hdc, x - 1, y, targetColor, fillColor);
        FloodFillRecursive(hdc, x, y + 1, targetColor, fillColor);
        FloodFillRecursive(hdc, x, y - 1, targetColor, fillColor);
    }
}
void FloodFillNonRecursive(HDC hdc, int x, int y, COLORREF targetColor, COLORREF fillColor) {
    std::queue<POINT> pixelsQueue;
    POINT pixel = { x, y };
    pixelsQueue.push(pixel);
    while (!pixelsQueue.empty()) {
        POINT currentPixel = pixelsQueue.front();
        pixelsQueue.pop();
        COLORREF currentColor = GetPixel(hdc, currentPixel.x, currentPixel.y);
        if (currentColor == targetColor && currentColor != fillColor) {
            SetPixel(hdc, currentPixel.x, currentPixel.y, fillColor);
            POINT leftPixel = { currentPixel.x - 1, currentPixel.y };
            if (leftPixel.x >= 0) pixelsQueue.push(leftPixel);
            POINT rightPixel = { currentPixel.x + 1, currentPixel.y };
            if (rightPixel.x < GetDeviceCaps(hdc, HORZRES)) pixelsQueue.push(rightPixel);
            POINT upPixel = { currentPixel.x, currentPixel.y - 1 };
            if (upPixel.y >= 0) pixelsQueue.push(upPixel);
            POINT downPixel = { currentPixel.x, currentPixel.y + 1 };
            if (downPixel.y < GetDeviceCaps(hdc, VERTRES)) pixelsQueue.push(downPixel);
        }
    }
}

///curves
Vector4 operator*(Matrix4 M,Vector4& b) // right multiplication of M by b
{
    Vector4 res;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            res[i]+=M[i][j]*b[j];

    return res;
}
double DotProduct(Vector4& a,Vector4& b) //multiplying a raw vector by a column vector
{
    return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]+a[3]*b[3];
}
Vector4 GetHermiteCoeff(double x0,double s0,double x1,double s1)
{
    static double H[16]={2,1,-2,1,-3,-2,3,-1,0,1,0,0,1,0,0,0};
    static Matrix4 basis(H);
    Vector4 v(x0,s0,x1,s1);
    return basis*v;
}
void drawHermiteCurve(HDC hdc,Vector2& P0,Vector2& T0,Vector2& P1,Vector2& T1 ,int numpoints, COLORREF color)
{
    Vector4 xcoeff=GetHermiteCoeff(P0.x,T0.x,P1.x,T1.x);
    Vector4 ycoeff=GetHermiteCoeff(P0.y,T0.y,P1.y,T1.y);
    if(numpoints<2)return;
    double dt=1.0/(numpoints-1);
    for(double t=0;t<=1;t+=dt)
    {
        Vector4 vt;
        vt[3]=1;
        for(int i=2;i>=0;i--)vt[i]=vt[i+1]*t;
        int x=round(DotProduct(xcoeff,vt));
        int y=round(DotProduct(ycoeff,vt));
        if(t==0)MoveToEx(hdc,x,y,NULL);else LineTo(hdc,x,y);
    }
}
void DrawCardinalSpline(HDC hdc,Vector2 P[],int n,double c,int numpix, COLORREF color)
{
    double c1=1-c;
    Vector2 T0(c1*(P[2].x-P[0].x),c1*(P[2].y-P[0].y));
    for(int i=2;i<n-1;i++)
    {
        Vector2 T1(c1*(P[i+1].x-P[i-1].x),c1*(P[i+1].y-P[i-1].y));
        drawHermiteCurve(hdc,P[i-1],T0,P[i],T1,numpix, color);
        T0=T1;
    }
}
void DrawHermiteCurve(HDC hdc, Vector& p1, Vector& T1, Vector& p2, Vector& T2, COLORREF c, int top, int botton, int right, int left)
{
    double a0 = p1[0], a1 = T1[0],
            a2 = -3 * p1[0] - 2 * T1[0] + 3 * p2[0] - T2[0],
            a3 = 2 * p1[0] + T1[0] - 2 * p2[0] + T2[0];
    double b0 = p1[1], b1 = T1[1],
            b2 = -3 * p1[1] - 2 * T1[1] + 3 * p2[1] - T2[1],
            b3 = 2 * p1[1] + T1[1] - 2 * p2[1] + T2[1];
    for (double t = 0; t <= 1; t += 0.001)
    {
        double t2 = t * t, t3 = t2 * t;
        double x = a0 + a1 * t + a2 * t2 + a3 * t3;
        double y = b0 + b1 * t + b2 * t2 + b3 * t3;
        if (x < left && y < botton) {
            SetPixel(hdc, Round(x), Round(y), c);
            getPixel(Round(x), Round(y), c);
        }

    }
}
void DrawSquare(HDC hdc, int top, int left, int Reduis, COLORREF c, COLORREF fillColor)
{
    int right = left + Reduis;

    int botton = top + Reduis;

    if (botton < top) {
        swap(top, botton);
    }
    if (right < left) {
        swap(left, right);
    }
    int Distance = abs(top - botton);;
    int counter = abs(left - right);

    DrawLineMidPoint(hdc, right, top, left, top, c);
    DrawLineMidPoint(hdc, right, botton, left, botton, c);
    DrawLineMidPoint(hdc, right, top, right, botton, c);
    DrawLineMidPoint(hdc, left, top, left, botton, c);

    static Vector p[4];
    while (counter > 0) {
        p[0] = Vector(left + 1, top + 1);
        p[1] = Vector(left + 1, top + (Distance / 4));
        p[2] = Vector(left + 1, top + (Distance / 8));
        p[3] = Vector(left + 1, botton - 1);

        Vector T1(3 * (p[1][0] - p[0][0]), 3 * (p[1][1] - p[0][1]));
        Vector T2(3 * (p[3][0] - p[2][0]), 3 * (p[3][1] - p[2][1]));
        DrawHermiteCurve(hdc, p[0], T1, p[3], T2, selectedColor, top, botton, left, right);
        left++;
        counter--;
    }

}
void PizerCUrveRectangleFail(HDC hdc, int top, int botton, int left, int right, COLORREF c)
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int  Distance;
    if (botton < top) {
        swap(top, botton);
    }
    if (right < left) {
        swap(left, right);
    }
    Distance = abs(right - left);
    int countt = abs(top - botton);


    x1 = left + 1;
    y1 = top + 1;

    x2 = left + (Distance / 4);
    y2 = top + 1;

    x3 = left + (Distance / 8);
    y3 = top + 1;

    x4 = right - 1;
    y4 = top + 1;
    while (countt > 0) {
        for (double t = 0.0; t <= 1; t += 0.001)
        {
            double x = pow(1 - t, 3) * x1 + 3 * t * pow(1 - t, 2) * x2 + 3 * t * t * (1 - t) * x3 + pow(t, 3) * x4;
            double y = pow(1 - t, 3) * y1 + 3 * t * pow(1 - t, 2) * y2 + 3 * t * t * (1 - t) * y3 + pow(t, 3) * y4;
            if ((x > left && x < right) && (y<botton && y>top)) {
                SetPixel(hdc, Round(x), Round(y), c);
                getPixel(Round(x), Round(y), c);
            }
        }
        countt--;
        y1++;
        y2++;
        y3++;
        y4++;

    }
}
void Rectangle(HDC hdc, int top, int botton, int left, int right, COLORREF RECcolor) {


    DrawLineMidPoint(hdc, right, top, left, top, RECcolor);
    DrawLineMidPoint(hdc, right, botton, left, botton, RECcolor);
    DrawLineMidPoint(hdc, right, top, right, botton, RECcolor);
    DrawLineMidPoint(hdc, left, top, left, botton, RECcolor);
    PizerCUrveRectangleFail(hdc, top, botton, left, right, RECcolor);
}

/// clipping
OutCode GetOutCode(double x,double y,int xleft,int ytop,int xright,int ybottom)
{
    OutCode out;
    out.All=0;
    if(x<xleft)out.left=1;else if(x>xright)out.right=1;
    if(y<ytop)out.top=1;else if(y>ybottom)out.bottom=1;
    return out;
}
void VIntersect(double xs,double ys,double xe,double ye,int x,double *xi,double *yi)
{
    *xi=x;
    *yi=ys+(x-xs)*(ye-ys)/(xe-xs);
}
void HIntersect(double xs,double ys,double xe,double ye,int y,double *xi,double *yi)
{
    *yi=y;
    *xi=xs+(y-ys)*(xe-xs)/(ye-ys);
}
void Cohen(HDC hdc,int xs,int ys,int xe,int ye,int xleft,int ytop,int xright,int ybottom)
{
    double x1=xs,y1=ys,x2=xe,y2=ye;
    OutCode out1=GetOutCode(x1,y1,xleft,ytop,xright,ybottom);
    OutCode out2=GetOutCode(x2,y2,xleft,ytop,xright,ybottom);
    while( (out1.All || out2.All) && !(out1.All & out2.All))
    {
        double xi,yi;
        if(out1.All)
        {
            if(out1.left)VIntersect(x1,y1,x2,y2,xleft,&xi,&yi);
            else if(out1.top)HIntersect(x1,y1,x2,y2,ytop,&xi,&yi);
            else if(out1.right)VIntersect(x1,y1,x2,y2,xright,&xi,&yi);
            else HIntersect(x1,y1,x2,y2,ybottom,&xi,&yi);
            x1=xi;
            y1=yi;
            out1=GetOutCode(x1,y1,xleft,ytop,xright,ybottom);
        } else
        {
            if(out2.left)VIntersect(x1,y1,x2,y2,xleft,&xi,&yi);
            else if(out2.top)HIntersect(x1,y1,x2,y2,ytop,&xi,&yi);
            else if(out2.right)VIntersect(x1,y1,x2,y2,xright,&xi,&yi);
            else HIntersect(x1,y1,x2,y2,ybottom,&xi,&yi);
            x2=xi;
            y2=yi;
            out2=GetOutCode(x2,y2,xleft,ytop,xright,ybottom);
        }
    }
    if(!out1.All && !out2.All)
    {
        DrawLineMidPoint(hdc, x1, y1, x2, y2, selectedColor);
    }
}
void PointClippingRecSq(HDC hdc,int x,int y,int xleft,int ytop,int xright,int ybottom,COLORREF color)
{
    if(x>=xleft && x<= xright && y>=ytop && y<=ybottom) {
        SetPixel(hdc, x, y, color);
        getPixel(x, y, color);
    }
}
void PointClippingCircle(HDC hdc,int x,int y,int xc,int yc,int r,COLORREF color)
{
    int R = sqrt( pow(x-xc,2)+pow(y-yc, 2));
    if(R<=r) {
        SetPixel(hdc, x, y, color);
        getPixel(x, y, color);
    }
}
void lineClippingWithCircle(HDC hdc,Circle c, Point p1, Point p2, COLORREF color) {
    // Initialize a variable to store the number of intersection points
    int count = 0;
    int distPoint1 = sqrt(pow(p1.x - c.center.x, 2) + pow(p1.y - c.center.y, 2));

    int distPoint2 = sqrt(pow(p2.x - c.center.x, 2) + pow(p2.y - c.center.y, 2));

    if (distPoint1 <= c.radius) {
        line.emplace_back(p1.x, p1.y);
    }
    if (distPoint2 <= c.radius) {
        line.emplace_back(p2.x, p2.y);
    }
    if (p1.x == p2.x) {
        // Check if the line passes through the circle
        if (abs(p1.x - c.center.x) > c.radius) {
            cout << "No intersection" << endl;
            return;
        }
    } else {
        // Find the slope and intercept of the line
        double m = (p2.y - p1.y) / (p2.x - p1.x);
        double d = p1.y - m * p1.x;
        // Find the coefficients of the quadratic equation
        double a = m * m + 1;
        double b = 2 * (m * d - m * c.center.y - c.center.x); //2*(m*b)
        double e = d * d + c.center.y * c.center.y + c.center.x * c.center.x - c.radius * c.radius -
                   2 * d * c.center.y;
        // Find the discriminant of the quadratic equation
        double D = b * b - 4 * a * e;
        // Check if the discriminant is negative
        if (D < 0) {
            cout << "No intersection" << endl;
            return;
        }
        // Find the x-coordinates of the intersection points
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        // Find the y-coordinates of the intersection points
        double y1 = m * x1 + d;
        double y2 = m * x2 + d;
        // Print the intersection points
        bool within_segment1 = (x1 >= p1.x && x1 <= p2.x) || (x1 >= p2.x && x1 <= p1.x);
        bool within_segment2 = (x2 >= p1.x && x2 <= p2.x) || (x2 >= p2.x && x2 <= p1.x);
        // Update the count of intersection points and the intersection point if there is only one
        if (D == 0) {
            line.emplace_back(x1, y1);
        } else {
            if (within_segment1 && within_segment2) {
                line.emplace_back(x1, y1);
                line.emplace_back(x2, y2);

            } else if (within_segment1) {
                line.emplace_back(x1, y1);
            } else if (within_segment2) {
                line.emplace_back(x2, y2);
            } else {
                cout << "No intersection points within the line segment" << endl;
            }
        }

    }
    // two point two draw
    if (line.size() == 2) {
        drawLine(hdc, line[0].first, line[0].second, line[1].first, line[1].second, color);
        line.clear();
    }

}

void PolygonClip(HDC hdc, POINT* p, int n, int xleft, int ytop, int xright, int ybottom)
{
    VertexList vlist;
    for (int i = 0; i < n; i++)vlist.push_back(Vertex(p[i].x, p[i].y));
    vlist = ClipWithEdge(vlist, xleft, InLeft, VIntersect);
    vlist = ClipWithEdge(vlist, ytop, InTop, HIntersect);
    vlist = ClipWithEdge(vlist, xright, InRight, VIntersect);
    vlist = ClipWithEdge(vlist, ybottom, InBottom, HIntersect);
    Vertex v1 = vlist[vlist.size() - 1];
    for (int i = 0; i < (int)vlist.size(); i++)
    {
        Vertex v2 = vlist[i];
        DrawLineMidPoint(hdc, round(v1.x), round(v1.y),round(v2.x), round(v2.y), selectedColor);
        v1 = v2;
    }
}
VertexList ClipWithEdge(VertexList p, int edge, IsInFunc In, IntersectFunc Intersect)
{
    VertexList OutList;
    Vertex v1 = p[p.size() - 1];
    bool v1_in = In(v1, edge);
    for (int i = 0; i < (int)p.size(); i++)
    {
        Vertex v2 = p[i];
        bool v2_in = In(v2, edge);
        if (!v1_in && v2_in)
        {
            OutList.push_back(Intersect(v1, v2, edge));
            OutList.push_back(v2);
        }
        else if (v1_in && v2_in) OutList.push_back(v2);
        else if (v1_in) OutList.push_back(Intersect(v1, v2, edge));
        v1 = v2;
        v1_in = v2_in;
    }
    return OutList;
}
bool InLeft(Vertex& v, int edge)
{
    return v.x >= edge;
}
bool InRight(Vertex& v, int edge)
{
    return v.x <= edge;
}
bool InTop(Vertex& v, int edge)
{
    return v.y >= edge;
}
bool InBottom(Vertex& v, int edge)
{
    return v.y <= edge;
}
Vertex VIntersect(Vertex& v1, Vertex& v2, int xedge)
{
    Vertex res;
    res.x = xedge;
    res.y = v1.y + (xedge - v1.x) * (v2.y - v1.y) / (v2.x - v1.x);
    return res;
}
Vertex HIntersect(Vertex& v1, Vertex& v2, int yedge)
{
    Vertex res;
    res.y = yedge;
    res.x = v1.x + (yedge - v1.y) * (v2.x - v1.x) / (v2.y - v1.y);
    return res;
}
